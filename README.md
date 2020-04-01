# SpiceCrystal
1. Finds the impedance of the standalone crystal for drive, bandwidth, and transconductance calculations  
2. Creates a Pierce Oscillator testbench ciruit for startup, ideal noise figure, and drive level approximations

![Demo Video](example.gif)

## Impedance Measurement Theory
The test bench represents an ideal pierce oscillator circuit. An ideal positive feedback 3.3V CMOS inverting amplifier is included. It's modeled with a hyperbolic tangent function that can be manipulated to your desire. The large feedback resistor throws the inverter into the linear region. A kickstart pulse is included to create the necessary noise to excite the crystal. You have a noise floor in real life to do this for you, but it has to be created in LTSpice. This test bench can be used to guesstimate the appropriate series resistor to bring the drive level within specification, model ideal phase noise to compare your current design, guess the minimum transconductance necessary for an amplifier design, and more. It's a test bench, so go probe around and learn how these things work!

The crystal's impedance is assignable to the voltage across the crystal in the Impedance.asc file.  
V=IR -> R = V/I  
1A AC Current Source -> R = Vcrystal/1A = Vcrystal  

The points between series resonance (the dip towards a short across the crystal) and anti-resonance (the peak towards infinant impedance) is range (bandwidth of parallel resonance) where the crystal will operate in with a pierce oscillator. As you can tell by analyzing the phase, it's the area where it introduces the necessary phase shift to satisfy the Barkhausen criteria. The series resistor, inverter, and the loop capacitors in the testbench provide a propper demonstration.

## Getting Started

Determine the parasitic elements of a crystal. These are usually found in the data sheets like [this one for Abracon's ABM13W](https://abracon.com/datasheets/ABM13W.pdf). 

## Prerequisites

1. GCC Compiler   
   - OSX: Install [XCode](https://developer.apple.com/xcode/) for OSX  
   - Windows: Refer to the instructions further down.

2. [LTSpice](https://www.analog.com/en/design-center/design-tools-and-calculators/ltspice-simulator.html)


## Installing
### OSX
```
cd <the directory you want your program to be>
git clone https://github.com/rthomp10/SpiceCrystal.git
```
### Windows

For now, install the [Windows Sub System for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and work in there.  
Once you install some version of Linux, install gcc on your linux distro by opening up Command Prompt and typing in
```
bash
sudo apt-get update
sudo apt-get install g++
```

To access the program foler, run the explorer command. It will open your current directory in explorer.
```
explorer . 
```

## Running
```
./configure
./main
```
OR
```
./configure
./main [.txt with input parameters] 
```  
The parameter .txt file has to be formatted exactly how the example files are.

## Clean-up 
Cleans up all the files that the program has made.
```
./configure -c 
```
## Authors

* **Ryan Thompson** - *Initial work* - [LinkedIn Page](https://www.linkedin.com/in/rthomp10/)
