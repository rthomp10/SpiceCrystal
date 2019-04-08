# SpiceCrystal

A simple and (temporarily) crude solution to converting crystal parasitic elements into useful SPICE files.

![Demo Video](trimmed.webm)

## Getting Started

Determine the parasitic elements of a crystal. These are usually found in the data sheets like [this](https://abracon.com/datasheets/ABM13W.pdf) one for the ABM13W IoT crystal. 

## Prerequisites

GCC Compiler: just run *apt install g++* on Ubuntu. Install [XCode](https://developer.apple.com/xcode/) for OSX.

Install a SPICE program: [LTSpice](https://www.analog.com/en/design-center/design-tools-and-calculators/ltspice-simulator.html), [MacSpice](https://www.macspice.com/Download.html), PSpice, etc.


## Installing

### Windows

For now, install the [Windows Sub System for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and work in there.
Once installed, you can access all your files at 

```
C:\Users\<username>\AppData\Local\Packages\CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc\LocalState 
```

### Linux/OSX

```
git clone https://github.com/rthomp10/SpiceCrystal.git
./configure
```

## Running

1. Carefully modify the example inputs to your parameters

2. ./main [drag and drop input file here] OR ./main and input your parameters in the terminal

## Authors

* **Ryan Thompson** - *Initial work* - [LinkedIn Page](https://www.linkedin.com/in/rthomp10/)
