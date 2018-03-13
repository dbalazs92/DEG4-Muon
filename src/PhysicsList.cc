// physics list for EM processes
// 13/03/2018 balazsdemeter92@gmail.com

//---------------------------------------

#include "PhysicsList.hh"

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


//---------------------------------------

//PhysicsList::PhysicsList(int plType_in,int cut_in) : G4VModularPhysicsList(),
PhysicsList::PhysicsList(int plType_in,int cut_in):  G4VUserPhysicsList(),
  fEmPhysicsList(0),
  fDecayPhysicsList(0)
{
  plType=plType_in;
  cut=cut_in;

  // Decay Physics is always defined
  fDecayPhysicsList = new G4DecayPhysics();

  // EM physics
  fEmPhysicsList = new G4EmStandardPhysics(1);

 
  switch(plType){
    
  case 0:
	delete fEmPhysicsList;
	fEmPhysicsList = new G4EmStandardPhysics(1);
	break;
	
	case 1:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmStandardPhysics_option1();
	break;
	
	case 2:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmStandardPhysics_option2();
	break;
	
	case 3:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmStandardPhysics_option3();
	break;
	
	case 4:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmStandardPhysics_option4();
	break;
	
	case 5:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmLivermorePhysics();
	break;
	
	case 6:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmPenelopePhysics();
	break;
	
	case 7:
	delete fEmPhysicsList;
    fEmPhysicsList = new G4EmLowEPPhysics();
	break;
	
	default:
	delete fEmPhysicsList;
	fEmPhysicsList = new G4EmStandardPhysics(1);
	break;
  }

  SetVerboseLevel(1);

}

//---------------------------------------

PhysicsList::~PhysicsList()
{
  delete fDecayPhysicsList;
  delete fEmPhysicsList;
}

//---------------------------------------

void PhysicsList::ConstructParticle()
{
  fDecayPhysicsList->ConstructParticle();
}

//---------------------------------------

void PhysicsList::ConstructProcess()
{
 
  AddTransportation();
  fEmPhysicsList->ConstructProcess();
  fDecayPhysicsList->ConstructProcess();
  
 
  G4double particleCut=1000;
  G4double lowEnergyEnd=1000*eV;
  // Deexcitation
  G4VAtomDeexcitation* de = new G4UAtomicDeexcitation();
  de->SetFluo(false);
  de->SetAuger(false);   
  de->SetPIXE(false);
  
  switch(cut){
  case 0:
    particleCut=pow(10,2);
    de->SetFluo(true);
    de->SetAuger(true);   
    de->SetPIXE(true); 
    lowEnergyEnd=1*keV;
    break;
    
  case 1:
    particleCut=pow(10,2);
    de->SetFluo(true);
    de->SetAuger(false);   
    de->SetPIXE(false); 
    lowEnergyEnd=10*keV;
    break;
    
  case 2:
    particleCut=pow(10,3);
    de->SetFluo(true);
    de->SetAuger(false);   
    de->SetPIXE(false); 
    lowEnergyEnd=100*keV;
    break;
    
  case 3:
    particleCut=pow(10,3);
    de->SetFluo(false);
    de->SetAuger(false);   
    de->SetPIXE(false); 
    lowEnergyEnd=100*keV;
    break;

  }
  
  
  G4LossTableManager::Instance()->SetAtomDeexcitation(de);
  
  defaultCutValue = particleCut*micrometer;
  cutForGamma     = defaultCutValue;
  cutForElectron  = defaultCutValue;
  cutForPositron  = defaultCutValue;

    
  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(lowEnergyEnd, 1*GeV);
  
  
  G4EmProcessOptions emOptions;
  emOptions.SetMinEnergy(lowEnergyEnd);        //default 100 eV   
  emOptions.SetMaxEnergy(10*TeV);       //default 100 TeV 
  emOptions.SetDEDXBinning(12*10);      //default=12*7
  emOptions.SetLambdaBinning(12*10);    //default=12*7
  
  SetCutValue(cutForGamma, "gamma");
  SetCutValue(cutForElectron, "e-");
  SetCutValue(cutForPositron, "e+");

 
}
void PhysicsList::SetCuts()
{
  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(100.*eV,1e5);
  if ( verboseLevel > 0 ) { DumpCutValuesTable(); }
}

//---------------------------------------



