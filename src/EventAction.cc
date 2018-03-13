// event, like one gamma from start till leaving the world
// collect event-level information, like total energy deposit of one gamma
// 13/03/2018 balazsdemeter92@gmail.com

#include "EventAction.hh"


//---------------------------------------

EventAction::EventAction()
: G4UserEventAction()
{} 

//---------------------------------------

EventAction::~EventAction()
{}

//---------------------------------------

void EventAction::BeginOfEventAction(const G4Event*)
{    
  fEdep = 0.0;
}

//---------------------------------------

void EventAction::EndOfEventAction(const G4Event*)
{   
  // accumulate statistics in Run
  Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  run->AddEdep(fEdep);
}

//---------------------------------------
