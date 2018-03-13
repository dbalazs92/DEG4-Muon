// DetectorConstruction
// here you can create and place your experiment
// 13/03/2018 balazsdemeter92@gmail.com

#include "DetectorConstruction.hh"
#include "G4RotationMatrix.hh"



//---------------------------------------

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

//---------------------------------------

DetectorConstruction::~DetectorConstruction()
{ }

//---------------------------------------

G4VPhysicalVolume* DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
	int i=0,j=0;
   float bz=210.5;
   G4RotationMatrix rotm  = G4RotationMatrix();
   rotm.rotateY(90*deg); 
  // Option to switch on/off checking of volumes overlaps
  G4bool checkOverlaps = true;

  //     
  // World
  //
  G4double world_sizeXY = 1.2*m;
  G4double world_sizeZ  = 1.2*m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
 
 

  //     
  // Up
  //
  G4Material* up_mat = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
  G4ThreeVector posUp = G4ThreeVector(0, 0*cm, (200-0.75)*mm);

  // box shape       
  G4double up_sizeX = 221*mm;
  G4double up_sizeY = 221*mm;
  G4double up_sizeZ = 1.5*mm;      
  G4Box* solidUp =    
    new G4Box("Up",                      //its name
              0.5*up_sizeX, 0.5*up_sizeY, 
              0.5*up_sizeZ); //its size
                
  G4LogicalVolume* logicUp =                         
    new G4LogicalVolume(solidUp,         //its solid
                        up_mat,          //its material
                        "Up");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posUp,                    //at position
                    logicUp,             //its logical volume
                    "Up",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

	//     
  // Down
  //
  G4Material* down_mat = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
  G4ThreeVector posDown = G4ThreeVector(0, 0*mm, (221+0.75)*mm);

  // box shape       
  G4double down_sizeX = 221*mm;
  G4double down_sizeY = 221*mm;
  G4double down_sizeZ = 1.5*mm;      
  G4Box* solidDown =    
    new G4Box("Down",                      //its name
              0.5*down_sizeX, 0.5*down_sizeY, 
              0.5*down_sizeZ); //its size
                
  G4LogicalVolume* logicDown =                         
    new G4LogicalVolume(solidDown,         //its solid
                        down_mat,          //its material
                        "Down");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posDown,                    //at position
                    logicDown,             //its logical volume
                    "Down",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
 
//     
  // Wall-A
  //
  G4Material* walla_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallA = G4ThreeVector(0, (105-4.5)*mm, 210.5*mm);

  // box shape       
  G4double walla_sizeX = 178*mm;
  G4double walla_sizeY = 10*mm;
  G4double walla_sizeZ = 21*mm;      
  G4Box* solidWallA =    
    new G4Box("Wall-A",                      //its name
              0.5*walla_sizeX, 0.5*walla_sizeY, 
              0.5*walla_sizeZ); //its size
                
  G4LogicalVolume* logicWallA =                         
    new G4LogicalVolume(solidWallA,         //its solid
                        walla_mat,          //its material
                        "Wall-A");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallA,                    //at position
                    logicWallA,             //its logical volume
                    "Wall-A",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
	//     
  // Wall-C
  //
  G4Material* wallc_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallC = G4ThreeVector(0, -(105-4.5)*mm, 210.5*mm);

  // box shape       
  G4double wallc_sizeX = 178*mm;
  G4double wallc_sizeY = 10*mm;
  G4double wallc_sizeZ = 21*mm;      
  G4Box* solidWallC =    
    new G4Box("Wall-C",                      //its name
              0.5*wallc_sizeX, 0.5*wallc_sizeY, 
              0.5*wallc_sizeZ); //its size
                
  G4LogicalVolume* logicWallC =                         
    new G4LogicalVolume(solidWallC,         //its solid
                        wallc_mat,          //its material
                        "Wall-C");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallC,                    //at position
                    logicWallC,             //its logical volume
                    "Wall-C",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
//     
  // Wall-B_down
  //
  G4Material* wallbd_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallBd = G4ThreeVector(-(110.5-8)+14.5*mm, 0, (bz+4.25+0.75)*mm);

  // box shape       
  G4double wallbd_sizeX = 16*mm;
  G4double wallbd_sizeY = 192*mm;
  G4double wallbd_sizeZ = 8.5*mm;      
  G4Box* solidWallBd =    
    new G4Box("Wall-B_down",                      //its name
              0.5*wallbd_sizeX, 0.5*wallbd_sizeY, 
              0.5*wallbd_sizeZ); //its size
                
  G4LogicalVolume* logicWallBd =                         
    new G4LogicalVolume(solidWallBd,         //its solid
                        wallbd_mat,          //its material
                        "Wall-B_down");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallBd,                    //at position
                    logicWallBd,             //its logical volume
                    "Wall-B_down",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
  //     
  // Wall-B_nyak
  //
  G4Material* wallbn_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallBn = G4ThreeVector(-(110.5-8)-3+14.5*mm, 0*mm, (bz)*mm);

  // box shape       
  G4double wallbn_sizeX = 22*mm;
  G4double wallbn_sizeY = 192*mm;
  G4double wallbn_sizeZ = 1.5*mm;      
  G4Box* solidWallBn =    
    new G4Box("Wall-B_nyak",                      //its name
              0.5*wallbn_sizeX, 0.5*wallbn_sizeY, 
              0.5*wallbn_sizeZ); //its size
                
  G4LogicalVolume* logicWallBn =                         
    new G4LogicalVolume(solidWallBn,         //its solid
                        wallbn_mat,          //its material
                        "Wall-B_nyak");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallBn,                    //at position
                    logicWallBn,             //its logical volume
                    "Wall-B_nyak",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
  //     
  // Wall-B_up
  //
  G4Material* wallbu_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallBu = G4ThreeVector(-(110.5-8)+14.5*mm, 0, bz-0.75-5.5*mm);
	
  // box shape       
  G4double wallbu_sizeX = 10*mm;
  G4double wallbu_sizeY = 192*mm;
  G4double wallbu_sizeZ = 11*mm;      
  G4Box* solidWallBu =    
    new G4Box("Wall-B_up",                      //its name
              0.5*wallbu_sizeX, 0.5*wallbu_sizeY, 
              0.5*wallbu_sizeZ); //its size
                
  G4LogicalVolume* logicWallBu =                         
    new G4LogicalVolume(solidWallBu,         //its solid
                        wallbu_mat,          //its material
                        "Wall-B_up");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallBu,                    //at position
                    logicWallBu,             //its logical volume
                    "Wall-B_up",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
//     
  // Wall-D_down
  //
  G4Material* walldd_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallDd = G4ThreeVector((110.5-8)-14.5*mm, 0, (bz+4.25+0.75)*mm);

  // box shape       
  G4double walldd_sizeX = 16*mm;
  G4double walldd_sizeY = 192*mm;
  G4double walldd_sizeZ = 8.5*mm;      
  G4Box* solidWallDd =    
    new G4Box("Wall-D_down",                      //its name
              0.5*walldd_sizeX, 0.5*walldd_sizeY, 
              0.5*walldd_sizeZ); //its size
                
  G4LogicalVolume* logicWallDd =                         
    new G4LogicalVolume(solidWallDd,         //its solid
                        walldd_mat,          //its material
                        "Wall-D_down");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallDd,                    //at position
                    logicWallDd,             //its logical volume
                    "Wall-D_down",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
  //     
  // Wall-D_nyak
  //
  G4Material* walldn_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallDn = G4ThreeVector(((110.5-8)+3-14.5)*mm, 0*mm, (bz)*mm);

  // box shape       
  G4double walldn_sizeX = 22*mm;
  G4double walldn_sizeY = 192*mm;
  G4double walldn_sizeZ = 1.5*mm;      
  G4Box* solidWallDn =    
    new G4Box("Wall-D_nyak",                      //its name
              0.5*walldn_sizeX, 0.5*walldn_sizeY, 
              0.5*walldn_sizeZ); //its size
                
  G4LogicalVolume* logicWallDn =                         
    new G4LogicalVolume(solidWallDn,         //its solid
                        walldn_mat,          //its material
                        "Wall-D_nyak");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallDn,                    //at position
                    logicWallDn,             //its logical volume
                    "Wall-D_nyak",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
  //     
  // Wall-D_up
  //
  G4Material* walldu_mat = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
  G4ThreeVector posWallDu = G4ThreeVector((110.5-8)-14.5*mm, 0, bz-0.75-5.5*mm);
	
  // box shape       
  G4double walldu_sizeX = 10*mm;
  G4double walldu_sizeY = 192*mm;
  G4double walldu_sizeZ = 11*mm;      
  G4Box* solidWallDu =    
    new G4Box("Wall-D_up",                      //its name
              0.5*walldu_sizeX, 0.5*walldu_sizeY, 
              0.5*walldu_sizeZ); //its size
                
  G4LogicalVolume* logicWallDu =                         
    new G4LogicalVolume(solidWallDu,         //its solid
                        walldu_mat,          //its material
                        "Wall-D_up");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    posWallDu,                    //at position
                    logicWallDu,             //its logical volume
                    "Wall-D_up",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                    
  // Vekony Szalak
  //
  G4Material* szal_material = nist->FindOrBuildMaterial("G4_Au");
  G4ThreeVector szal_pos = G4ThreeVector(0, (105-2.5-6-(i*6))*mm, bz-0.75*mm);

  // torus shape       
  G4double szal_rmin = 0*cm;
  G4double szal_rmax = 24*(0.001)*mm;
  G4double szal_len  = 160*mm;
  G4double szal_deg = 0*deg;
  G4double szal_deg2 = 360*deg;      
  G4Tubs* szalbarrel =    
    new G4Tubs("Szal",                      //its name
              szal_rmin, szal_rmax, 0.5*szal_len, szal_deg, szal_deg2); //its size
                
  G4LogicalVolume* lvszal =                         
    new G4LogicalVolume(szalbarrel,         //its solid
                        szal_material,          //its material
                        "Szal");           //its name
  /*for(i=0;i<30;i++){
	G4Transform3D transforms = G4Transform3D(rotm, G4ThreeVector(0, (105-21.5-(i*6))*mm, bz-0.75*mm));       
  new G4PVPlacement(transforms,                    //at position and rotation 
                    lvszal,             //its logical volume
                    "Szal",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    i+1,                       //copy number
                    checkOverlaps);}          //overlaps checking*/
                    
// Vastag Szalak
  //
  G4Material* vszal_material = nist->FindOrBuildMaterial("G4_Cu");
  G4ThreeVector vszal_pos = G4ThreeVector(0, (105-15.5)-(j*6)*mm, bz-0.75*mm); //6mm-re A-tól
  

  // torus shape       
  G4double vszal_rmin = 0*cm;
  G4double vszal_rmax = 100*(0.001)*mm;
  G4double vszal_len  = 160*mm;
  G4double vszal_deg = 0*deg;
  G4double vszal_deg2 = 360*deg;      
  G4Tubs* vszalbarrel =    
    new G4Tubs("vSzal",                      //its name
              vszal_rmin, vszal_rmax, 0.5*vszal_len, vszal_deg, vszal_deg2); //its size
                
  G4LogicalVolume* lvszalv =                         
    new G4LogicalVolume(vszalbarrel,         //its solid
                        vszal_material,          //its material
                        "vSzal");           //its name
  for(j=0;j<31;j++){
	  G4Transform3D transformvx = G4Transform3D(rotm, G4ThreeVector(0, (105-15.5)-(j*6)*mm, bz-0.75*mm));
	  if(j%2==0){
  new G4PVPlacement(transformvx,              //at position and rotation 
                    lvszalv,             //its logical volume
                    "vSzal",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    j,                       //copy number
                    checkOverlaps);       //overlaps checking
                }
                else{
					new G4PVPlacement(transformvx,                    //at position and rotation 
                    lvszal,             //its logical volume
                    "Szal",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    j,                       //copy number
                    checkOverlaps);          //overlaps checking*/
					}
				}
				
                    
  //
  G4Colour UpColour( 1.0, 1.0, 1.0, 0.6 ); //Up colour
  G4VisAttributes* UpVisAtt = new G4VisAttributes( UpColour );
  logicUp->SetVisAttributes(UpVisAtt);
  
  G4Colour DownColour( 1.0, 1.0, 1.0, 0.6 ); //Down colour
  G4VisAttributes* DownVisAtt = new G4VisAttributes( DownColour );
  logicDown->SetVisAttributes(DownVisAtt);
  
  G4Colour WallAColour( 0.5, 0.5, 0.5, 1.0 ); //Wall-A colour
  G4VisAttributes* WallAVisAtt = new G4VisAttributes( WallAColour );
  logicWallA->SetVisAttributes(WallAVisAtt);
  
  G4Colour WallBColour( 0.5, 0.5, 0.5, 1.0 ); //Wall-Bu colour
  G4VisAttributes* WallBVisAtt = new G4VisAttributes( WallBColour );
  logicWallBu->SetVisAttributes(WallBVisAtt);
  
  G4Colour WallDColour( 0.5, 0.5, 0.5, 1.0 ); //Wall-Du colour
  G4VisAttributes* WallDVisAtt = new G4VisAttributes( WallDColour );
  logicWallDu->SetVisAttributes(WallDVisAtt);
  
  G4Colour WallBnColour( 0.0, 1.0, 0.0, 1.0 ); //Wall-Bn colour
  G4VisAttributes* WallBnVisAtt = new G4VisAttributes( WallBnColour );
  logicWallBn->SetVisAttributes(WallBnVisAtt);
  
  G4Colour WallDnColour( 0.0, 1.0, 0.0, 1.0 ); //Wall-Dn colour
  G4VisAttributes* WallDnVisAtt = new G4VisAttributes( WallDnColour );
  logicWallDn->SetVisAttributes(WallDnVisAtt);
  
  G4Colour WallCColour( 0.5, 0.5, 0.5, 1.0 ); //Wall-C colour
  G4VisAttributes* WallCVisAtt = new G4VisAttributes( WallCColour );
  logicWallC->SetVisAttributes(WallCVisAtt);
  
  G4Colour szalColour( 0.54, 0.27, 0.07, 1.0 ); //Szal colour
  G4VisAttributes* szalVisAtt = new G4VisAttributes( szalColour );
  lvszal->SetVisAttributes(szalVisAtt);
  return physWorld;
}

//---------------------------------------
