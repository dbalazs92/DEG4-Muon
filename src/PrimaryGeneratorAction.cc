// particle, energy, momentum, position...
// 13/03/2018 balazsdemeter92@gmail.com

#include "PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//---------------------------------------

PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0), fBoxMuller(true)
{
  G4int n_particle = 1;   //particles per event
  fParticleGun  = new G4ParticleGun(n_particle);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName="mu-");
  fParticleGun->SetParticleDefinition(particle);
  if(fBoxMuller==false){fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));}
  fParticleGun->SetParticleEnergy(1.*GeV);
}

//---------------------------------------

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//---------------------------------------

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  if(fBoxMuller==true)
	{
	G4double phi, r,rRand,ux,uy;
	phi=((double)rand()/(double)RAND_MAX)*M_PI*2;
	rRand=((double)rand()/(double)RAND_MAX);
	r=8.8*rRand;  
	ux=r*cos(phi);
	uy=r*sin(phi);  
	fParticleGun->SetParticlePosition(G4ThreeVector(ux,uy,0));
	fParticleGun->GeneratePrimaryVertex(anEvent);
	fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
	}
	else
	{
	fParticleGun->SetParticlePosition(G4ThreeVector(0,0,0));
    fParticleGun->GeneratePrimaryVertex(anEvent);
	}
}

//---------------------------------------

