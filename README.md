# DEG4-Muon

Close Cathode Chamber Geant4 simulation for Detector Simulation course (TFML4601).

## Authors

* **Balázs Demeter** - *University of Debrecen* - [E-mail](mailto:balazsdemeter92@gmail.com)

## Download and build

### Requirements

* Qt4 (Tested on version 5.9.1) 

* GEANT 4.10.03 or newer

* CLHEP 2.4.0.1 or newer

### Download Link

Via Git:

```
git clone https://github.com/dbalazs92/DEG4-Muon.git
```

Direct link:

```
https://github.com/dbalazs92/DEG4-Muon/archive/master.zip
```

### Build

In the directory of program (DEG4-Muon), open a terminal window and enter:

```
mkdir build && cd build
```

In build directory:

```
cmake ../ && make
``` 

### Running the simulation
 
#### Run in batch mode

After build, in build directory, open a terminal window and enter:

```
./Muon <numberofevents>
```

#### Run in interactive mode

After build, in build directory, open a terminal window and enter:

```
./Muon
```

## Updates

* 2018/03/13 - 'v0.3' - Creation of program and it's repository
