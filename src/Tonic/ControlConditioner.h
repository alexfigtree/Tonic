//
//  ControlConditioner.h
//  TonicDemo
//
//  Created by Morgan Packard on 3/4/13.

//

#ifndef __TonicDemo__ControlConditioner__
#define __TonicDemo__ControlConditioner__


#include <vector>
#include "ControlGenerator.h"

using std::vector;

namespace Tonic {
  
  namespace Tonic_ {
    
    class ControlConditioner_ : public ControlGenerator_{
      
    public:
      
      void in( ControlGenerator & input );
      
    protected:
    
      ControlGenerator input_;
      
    };
    
  }
  
  // The Tonic:: component of the controlconditioner (the smart pointer wrapper) must subclass the
  // following template, in the form <class Wrapper, class PrivateControlGenerator>
  
  template<class ControlConditionerType, class ControlConditionerType_>
  class TemplatedControlConditioner : public TemplatedControlGenerator<ControlConditionerType_>{
    
  public:
    
    ControlConditionerType & in( ControlGenerator input ){
      // why doesn't this compile without 'this' ?
      this->gen()->in( input );
      return static_cast<ControlConditionerType&>(*this);
    }
    
  };
  
    // signal flow operator - sets lhs as input to rhs
  template<class ControlConditionerType, class ControlConditionerType_>
  static ControlConditionerType & operator>>(ControlGenerator lhs, TemplatedControlConditioner<ControlConditionerType, ControlConditionerType_> rhs){
    return rhs.in( lhs );
  }
  
}

#endif /* defined(__TonicDemo__ControlConditioner__) */
