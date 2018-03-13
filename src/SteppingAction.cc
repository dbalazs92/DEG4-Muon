// step
// 13/03/2018 balazsdemeter92@gmail.com

#include "SteppingAction.hh"
#include "G4Track.hh"
#include <cmath>


//---------------------------------------

SteppingAction::SteppingAction(EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction)
{}

//---------------------------------------

SteppingAction::~SteppingAction()
{}

//---------------------------------------

void SteppingAction::UserSteppingAction(const G4Step* fStep)
{


  // collect energy deposited in this step
  G4double edepStep = fStep->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);
  G4Track * fTrack = fStep->GetTrack();
  // check if it is alive
  if(fTrack->GetTrackStatus()!=fAlive) { return; }
  
  G4ParticleDefinition *particle=fTrack->GetDefinition();

  G4VPhysicalVolume* prevolume  =
    fStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  G4VPhysicalVolume* postvolume  =
    fStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume();

  G4double preX = fStep->GetPreStepPoint()->GetPosition().x();
  G4double preY = fStep->GetPreStepPoint()->GetPosition().y();
  G4double preZ  = fStep->GetPreStepPoint()->GetPosition().z();
  G4double prekinE  = fStep->GetPreStepPoint()->GetKineticEnergy();

  G4double postX = fStep->GetPostStepPoint()->GetPosition().x();
  G4double postY = fStep->GetPostStepPoint()->GetPosition().y();
  G4double postZ = fStep->GetPostStepPoint()->GetPosition().z();
  //G4double postkinE  = fStep->GetPostStepPoint()->GetKineticEnergy();

  G4ThreeVector momentumdirection = fTrack->GetMomentumDirection();
  //G4double theta = momentumdirection.theta();
  G4String particleName = particle->GetParticleName();
  G4String preName=prevolume->GetName();
  G4String postName=postvolume->GetName();
  if(((preX<=(110.5-8)-14.5*mm)&&(preX>=-(110.5-8)+14.5*mm))||((postX<=(110.5-8)-14.5*mm)&&(postX>=-(110.5-8)+14.5*mm))){
	  if(((preY<=100.5*mm)&&(preY>=-100.5*mm))||((postY<=100.5*mm)&&(postY>=-100.5*mm))){
		  if(((preZ<=221*mm)&&(preZ>=200*mm))||((postZ<=221*mm)&&(postZ>=200*mm))){
			  if(particleName=="e-"){
		G4cout<<"particle_"<<particleName<<" "<<momentumdirection.x()<<" "
	<<momentumdirection.y()<<" "<<momentumdirection.z()<<" "<< prekinE/keV<<" "<<preX/cm<<" "<<preY/cm<<" "<<preZ/cm<<" "
	<<momentumdirection.theta()<<" "<<momentumdirection.phi()<<" "<<postX/cm<<" "<<postY/cm<<" "<<postZ/cm<<" "
	<<prevolume->GetName()<<" "<<postvolume->GetName()<<G4endl;
	}}}}
 
}

//---------------------------------------

