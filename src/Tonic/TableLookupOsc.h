//
//  TableLookupOsc.h
//  Tonic 
//
//  Created by Nick Donaldson on 2/8/13.

//
// See LICENSE.txt for license and usage information.
//


/*
 This class is heavily borrowed from the PD implementation of a table-lookup oscillator.
 Necessary attribution/license TBD.
*/

#ifndef __Tonic__TableLookupOsc__
#define __Tonic__TableLookupOsc__

#include "Generator.h"

namespace Tonic {
  
  namespace Tonic_ {
    
    const unsigned long TABLE_SIZE = 2048;
    
    class TableLookupOsc_ : public Generator_{
      
      
      //------------------------------------
      //
      // Many of the original STK methods are not applicable in our use case
      // (direct phase/freq manipulation) and have been removed for optimization.
      // In the future, phase inputs may be added, but will be optimized and made
      // Tonic-friendly for universal routing.
      //
      //-----------------------------------
      
    protected:

      //! Subclasses MUST override to provide pointer to table
      /*
        Necessary to maintain efficient memory usage by only
        using one set of static wavetable data per subclss, regardless
        of number of instances.
       
        Subclasses should return static member variable.
      */
      virtual TonicFrames & tableReference() = 0;
      
      //! Subclasses implement this to fill the wavetable
      /*
          Subclasses should ALWAYS call this method from their constructor!
      */
      virtual void fillTable() = 0;
      
      double phase_;
      
      Generator frequencyGenerator_;
      TonicFrames modFrames_;
      
    public:
      
      TableLookupOsc_();
      ~TableLookupOsc_();

      
      void computeSynthesisBlock( const SynthesisContext_ & context );
      
      //! Clear output and reset time pointer to zero.
      void reset( void );
      
      //! Set frequency generator input
      void setFrequency( Generator & genArg){
        frequencyGenerator_ = genArg;
      };

    };

  }

}

#endif /* defined(__Tonic__TableLookupOsc__) */

