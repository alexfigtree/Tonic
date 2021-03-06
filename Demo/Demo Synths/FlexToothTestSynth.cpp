//
//  FlexToothTestSynth.h
//  TonicDemo
//
//  Created by Nick Donaldson on 3/2/13.

//

/*
Because of the fancy registerSynth macro, and because this synth has the same interface
as Synth it's not necessary to create a header file. You can create an instance of this synth using 
SynthFactory::createInstance(SYNTH_NAME), where SYNTH_NAME is the name supplied to registerSynth.
*/

#ifndef TonicDemo_FlexToothTestSynth_h
#define TonicDemo_FlexToothTestSynth_h

#include "Tonic.h"

using namespace Tonic;

class FlexToothTestSynth : public Synth {
  
public:
  
  FlexToothTestSynth(){
    
    FlexToothWave flexTooth = FlexToothWave().freq( addParameter("freq", 0.5).smoothed() ).slope( addParameter("slope", 0).smoothed() );
    outputGen = flexTooth * 0.2;
    
  }
  
};

registerSynth(FlexToothTestSynth);

#endif
