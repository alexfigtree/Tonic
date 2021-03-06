//
//  ControlMultiplier.h
//  Tonic 
//
//  Created by Nick Donaldson on 2/25/13.

//
// See LICENSE.txt for license and usage information.
//


#ifndef __Tonic__ControlMultiplier__
#define __Tonic__ControlMultiplier__

#include <vector>
#include "ControlGenerator.h"
#include "ControlValue.h"

using std::vector;

namespace Tonic {
  
  namespace Tonic_ {
    
    class ControlMultiplier_ : public ControlGenerator_{
      
    public:
      
      void in( ControlGenerator input );
      
      ControlGenerator & getInput(unsigned int index) { return inputs[index]; };
      unsigned int numInputs() { return inputs.size(); };
      
    protected:
      
      void computeOutput( const SynthesisContext_ & context );
      
      vector<ControlGenerator> inputs;
      
    };
    
  }
  
  class ControlMultiplier : public TemplatedControlGenerator<Tonic_::ControlMultiplier_>{
    
  public:
    
    void in( ControlGenerator input ){
      gen()->in( input );
    }
    
    ControlGenerator & operator[](unsigned int index){
      return gen()->getInput(index);
    }
    
    unsigned int numInputs(){
      return gen()->numInputs();
    }
  };
  
  static ControlMultiplier operator*(ControlGenerator a, ControlGenerator b){
    ControlMultiplier mult;
    mult.in(a);
    mult.in(b);
    return mult;
  }
  
  static ControlMultiplier operator*(ControlGenerator a, float b){
    ControlMultiplier mult;
    mult.in(a);
    mult.in(ControlValue(b));
    return mult;
  }
  
  static ControlMultiplier operator*(float a, ControlGenerator b){
    ControlMultiplier mult;
    mult.in(ControlValue(a));
    mult.in(ControlGenerator(b));
    return mult;
  }
  
  static ControlMultiplier operator*(ControlMultiplier a, ControlGenerator b){
    a.in(b);
    return a;
  }
  
  static ControlMultiplier operator*(ControlGenerator a, ControlMultiplier b){
    b.in(a);
    return b;
  }
  
  static ControlMultiplier operator*(ControlMultiplier a, float b){
    a.in(ControlValue(b));
    return a;
  }
  
  static ControlMultiplier operator*(float a, ControlMultiplier b){
    b.in(ControlValue(a));
    return b;
  }
  
  static ControlMultiplier operator*(ControlMultiplier a, ControlMultiplier b){
    for (unsigned int i=0; i<b.numInputs(); i++){
      a.in(b[i]);
    }
    return a;
  }
}


#endif /* defined(__Tonic__ControlMultiplier__) */


