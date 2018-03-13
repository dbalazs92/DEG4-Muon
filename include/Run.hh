// Run for threads
// 13/03/2018 balazsdemeter92@gmail.com

#ifndef Run_h
#define Run_h 1

#include "G4Run.hh"
#include "globals.hh"

class Run : public G4Run
{
public:
  Run();
  virtual ~Run();
  
  virtual void Merge(const G4Run*);
  
  void AddEdep (G4double edep); 
  
  G4double GetEdep()  const { return fEdep; }
  
private:
  G4double  fEdep;
};

//---------------------------------------

#endif

