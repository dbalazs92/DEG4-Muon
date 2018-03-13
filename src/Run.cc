// Run for threads
// 13/03/2018 balazsdemeter92@gmail.com


#include "Run.hh"

//---------------------------------------

Run::Run()
: G4Run()
{fEdep=0.0;} 

//---------------------------------------

Run::~Run()
{} 
 
//---------------------------------------

void Run::Merge(const G4Run* run)
{
  const Run* localRun = static_cast<const Run*>(run);
  fEdep  += localRun->fEdep;

  G4Run::Merge(run); 
} 

//---------------------------------------

void Run::AddEdep (G4double edep)
{
  fEdep  += edep;
}

//---------------------------------------


