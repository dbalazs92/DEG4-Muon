// event, like one gamma from start till leaving the world
// collect event-level information, like total energy deposit of one gamma
// 13/03/2018 balazsdemeter92@gmail.com

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "Run.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

/// Event action class

class EventAction : public G4UserEventAction
{
  public:
    EventAction();
    virtual ~EventAction();
    
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEdep(G4double edep) { fEdep += edep; }

  private:
    G4double  fEdep;
};

//---------------------------------------

#endif

    
