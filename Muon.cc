// main for Muon
// 13/03/2018 balazsdemeter92@gmail.com

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "PhysicsList.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include "QGSP_BIC_HP.hh"
#include "G4UImanager.hh"
#include "QBBC.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"
#include "G4StepLimiterPhysics.hh"
#include "Randomize.hh"
#include "QGSP_BIC.hh"

//---------------------------------------

int main(int argc,char** argv)
{
  // parameter from command line
  int NoE=0;
  int plTYpe=2;
  int cut=3;
  if (argc==2) NoE=atoi(argv[1]);

#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  unsigned nthreads = 1;
  runManager->SetNumberOfThreads(nthreads);
#else
  G4RunManager* runManager = new G4RunManager;
#endif
  
  //you will modify this part ///////////
  runManager->SetUserInitialization(new DetectorConstruction());
   runManager->SetUserInitialization(new PhysicsList(plTYpe,cut));
  runManager->SetUserInitialization(new QGSP_BIC);
  runManager->SetUserInitialization(new ActionInitialization());
  ///////////////

  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if (argc==2) { 
    // batch mode
   runManager->Initialize();
   runManager->BeamOn(NoE);
  }
  else { 
    // interactive mode
    G4UIExecutive* ui = 0;
    if ( argc == 1 ) {
      ui = new G4UIExecutive(argc, argv);
    }
    UImanager->ApplyCommand("/control/execute gui.mac");
    ui->SessionStart();
    delete ui;
  }
  
  
  delete visManager;
  delete runManager;
}

//---------------------------------------
