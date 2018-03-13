// User actions like Run,Event,Stepping
//                   Stacking
//                   PrimaryGenerator
// for master and threads 
// 13/03/2018 balazsdemeter92@gmail.com

#include "ActionInitialization.hh"


//---------------------------------------

ActionInitialization::ActionInitialization()
 : G4VUserActionInitialization()
{}

//---------------------------------------

ActionInitialization::~ActionInitialization()
{}

//---------------------------------------

void ActionInitialization::BuildForMaster() const
{
  SetUserAction(new RunAction);
}

//---------------------------------------

void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);
  SetUserAction(new RunAction);
  
  EventAction* eventAction = new EventAction;
  SetUserAction(eventAction);
  
  SetUserAction(new SteppingAction(eventAction));
}  

//---------------------------------------
