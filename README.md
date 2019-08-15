# SpiceCrystal
1. Finds the impedance of the standalone crystal for drive, bandwidth, and transconductance calculations  
2. Creates a Pierce Oscillator testbench ciruit for startup, ideal noise analysis, and drive level approximations

![Demo Video](example.gif)

## Impedance Measurement Theory
The crystal's impedance is assignable to the voltage across the crystal in the Impedance.asc file.  
V=IR -> R = V/I  
1A AC Current Source -> R = Vcrystal/1 = Vcrystal  

The points between series resonance (the dip towards a short across the crystal) and anti-resonance (the peak towards infinant impedance) is range (bandwidth of parallel resonance) where the crystal will operate in with a pierce oscillator. As you can tell by analyzing the phase, it's the area where it introduces the necessary phase shift to satisfy the Barkhausen criteria. The series resistor, inverter, and the loop capacitors in the testbench provide a propper demonstration.

## Getting Started

Determine the parasitic elements of a crystal. These are usually found in the data sheets like [this one for Abracon's ABM13W](https://abracon.com/datasheets/ABM13W.pdf). 

## Prerequisites

1. GCC Compiler   
   - OSX: Install [XCode](https://developer.apple.com/xcode/) for OSX  
   - Windows: Refer to the instructions further down.

2. [LTSpice](https://www.analog.com/en/design-center/design-tools-and-calculators/ltspice-simulator.html)


## Installing

### Windows

For now, install the [Windows Sub System for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and work in there.

Once you install some version of Linux, install gcc on your linux distro by opening up Command Prompt and typing in
```
bash
sudo apt-get update
sudo apt-get install g++
```

You can access all your files at 
```
C:\Users\<username>\AppData\Local\Packages\CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc\LocalState 
```
Now you can follow the directions for OSX.

### OSX
Go to the directory you want to have the program at and clone it.
```
cd <the directory you want your program to be>
git clone https://github.com/rthomp10/SpiceCrystal.git
```

## Running

1. ./configure
2. ./main [drag and drop input file here] OR ./main and input your parameters  
3. ./configure -c will clean all the output files that the program has made

## Authors

* **Ryan Thompson** - *Initial work* - [LinkedIn Page](https://www.linkedin.com/in/rthomp10/)
