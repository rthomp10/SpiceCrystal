# Crystal to SPICE

This is a simple and (temporarily) crude solution to converting crystal parasitic elements into useful SPICE files.

## Getting Started

Determine the parasitic elements of a crystal you have in mind. These are usually found in the data sheets like [this] one for the ABM13W IoT crystal. 

### Prerequisites

Install a SPICE program
[LTSpice](https://www.analog.com/en/design-center/design-tools-and-calculators/ltspice-simulator.html)
[MacSpice](https://www.macspice.com/Download.html)
PSpice
etc.


### Installing

GCC Compiler: just run *apt install g++* or **

## Running

Linux/OSX
1. Carefully modify the example inputs to your parameters.
2. Open terminal
3. ./configure
4. Type *./main [drag and drop input file here]* OR just type in *./main* and input your parameters in the terminal.
5. Your done! Check out the files it made and run the test one.

Windows
Install the [Windows Sub System for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and follow the directions above.

## Authors

* **Ryan Thompson** - *Initial work* - [LinkedIn Page](https://www.linkedin.com/in/rthomp10/)
