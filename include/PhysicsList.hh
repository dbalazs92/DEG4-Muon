// physics list for EM processes
// 13/03/2018 balazsdemeter92@gmail.com

//---------------------------------------

#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"
#include "G4EmConfigurator.hh"
#include "G4EmProcessOptions.hh"


#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option1.hh"
#include "G4EmStandardPhysics_option2.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmLowEPPhysics.hh"
#include "G4DecayPhysics.hh"

#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4Proton.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4LossTableManager.hh"
#include "G4ProductionCutsTable.hh"

#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4UAtomicDeexcitation.hh"

class G4VPhysicsConstructor;

//---------------------------------------

//class PhysicsList: public G4VModularPhysicsList
class PhysicsList: public G4VUserPhysicsList
{
public:

  PhysicsList(int plType_in,int cut_in);
  virtual ~PhysicsList();

   virtual void ConstructParticle();
    
  virtual void SetCuts();
        
  void AddPhysicsList();
  virtual void ConstructProcess();
    

private:
  G4EmConfigurator* fConfig;

  G4VPhysicsConstructor*  fEmPhysicsList;
  G4VPhysicsConstructor*  fDecayPhysicsList;
  std::vector<G4VPhysicsConstructor*> fHadronPhys;
  int plType,cut;
  G4double cutForGamma;
  G4double cutForElectron;
  G4double cutForPositron;
  G4double cutForProton;
  G4String fEmName;
  
  
};

//---------------------------------------

#endif

