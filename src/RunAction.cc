// RunAction global
// 13/03/2018 balazsdemeter92@gmail.com

#include "RunAction.hh"

//---------------------------------------

RunAction::RunAction()
: G4UserRunAction()
{ }

//---------------------------------------

RunAction::~RunAction()
{}

//---------------------------------------

G4Run* RunAction::GenerateRun()
{
  return new Run; 
}

//---------------------------------------

void RunAction::BeginOfRunAction(const G4Run*)
{ }

//---------------------------------------

void RunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;
  
  const Run* dERun = static_cast<const Run*>(run);
  G4double edepInRuns  = dERun->GetEdep();

  // Print
  //  
  if (IsMaster()) {
    G4cout
     << G4endl
     << "--------------------End of Global Run-----------------------";
  }
  else {
    G4cout
     << G4endl
     << "--------------------End of Local Run------------------------";
  }
  
  G4cout
     << G4endl
     << " The run consists of " << nofEvents << " edep: "<< edepInRuns/keV
     << G4endl;

}

//---------------------------------------
