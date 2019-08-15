// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char** argv) {
	string name;//Crystal name
	string CL; 	//plating load
	string Co;	//Shunt Capacitance
	string Rm;	//Motional Resistance
	string Lm;  //Motional Inductance
	string Cm;  //Motional Frequency
	string freq;//Specified frequency
	string sweep_start;	//sweep start frequency
	string sweep_end;	//sweep end frequuency 
	ofstream myfile;
	string line;
	
	//Text file or user input
	if(argv[1])
	{
		ifstream myfile(argv[1]);
		if (myfile.is_open()){
			getline(myfile,name);
			getline(myfile,freq);
			getline(myfile,CL);
			getline(myfile,Co);
			getline(myfile,Rm);
			getline(myfile,Lm);
			getline(myfile,Cm);
			getline(myfile,sweep_start);
			getline(myfile,sweep_end);
			cout << "Crystal name = " 	+ name << endl; 
			cout << "Frequency = "		+ freq << endl; 
			cout << "Plating Load = "   + CL << endl;
			cout << "Co = "             + Co << endl;
			cout << "Rm = "             + Rm << endl;
			cout << "Lm = "             + Lm << endl;
			cout << "Cm = "             + Cm << endl;
			cout << "Sweep start frequency = " + sweep_start << endl;
			cout << "Sweep end frequency = "   + sweep_end << endl;  
			myfile.close();
		}
		else cout << "Unable to open file";
	}
	else{
		cout << "Crystal name = "; cin >> name;
		cout << "Frequency = "; cin  >> freq;
		cout << "Plating Load = ";  cin >> CL;
		cout << "Co = "; cin  >> Co;
		cout << "Rm = "; cin  >> Rm;
		cout << "Lm = "; cin  >> Lm;
		cout << "Cm = "; cin  >> Cm;
		cout << "Warning! For MHz, type in MegaHz\n";
		cout << "Sweep start frequency = "; cin >> sweep_start;
		cout << "Sweep end frequency = ";   cin >> sweep_end;
	}
	
	//Netlist Creation
	myfile.open (name + ".net");
	myfile << "* Auto generated net list for "+ name +"\n";
	myfile << "Rm Vout N002 "+ Rm +"\n";
	myfile << "Cm N002 N001 "+ Cm +"\n";
	myfile << "Co Vout Vin "+ Co +"\n";
	myfile << "Lm Vin N001 "+ Lm +"\n";
	myfile << "* Plating Load: "+ CL +"\n";
	myfile << "* Frequency: "+ freq +"\n";
	myfile << ".backanno\n";
	myfile << ".end";
	myfile.close();
	
	//.asc generation
	myfile.open(name + ".asc");
	myfile << "Version 4\n";
	myfile << "SHEET 1 880 680\n";
	myfile << "WIRE 144 48 -16 48\n";
	myfile << "WIRE 432 48 208 48\n";
	myfile << "WIRE -16 112 -16 48\n";
	myfile << "WIRE -16 112 -96 112\n";
	myfile << "WIRE 432 112 432 48\n";
	myfile << "WIRE 480 112 432 112\n";
	myfile << "WIRE -16 192 -16 112\n";
	myfile << "WIRE 0 192 -16 192\n";
	myfile << "WIRE 144 192 80 192\n";
	myfile << "WIRE 256 192 208 192\n";
	myfile << "WIRE 432 192 432 112\n";
	myfile << "WIRE 432 192 336 192\n";
	myfile << "FLAG -96 112 Vin\n";
	myfile << "IOPIN -96 112 BiDir\n";
	myfile << "FLAG 480 112 Vout\n";
	myfile << "IOPIN 480 112 BiDir\n";
	myfile << "SYMBOL res 352 176 R90\n";
	myfile << "WINDOW 0 0 56 VBottom 2\n";
	myfile << "WINDOW 3 32 56 VTop 2\n";
	myfile << "SYMATTR InstName Rm\n";
	myfile << "SYMATTR Value "+ Rm +"\n";
	myfile << "SYMBOL cap 208 176 R90\n";
	myfile << "WINDOW 0 0 32 VBottom 2\n";
	myfile << "WINDOW 3 32 32 VTop 2\n";
	myfile << "SYMATTR InstName Cm\n";
	myfile << "SYMATTR Value "+ Cm +"\n";
	myfile << "SYMBOL cap 208 32 R90\n";
	myfile << "WINDOW 0 0 32 VBottom 2\n";
	myfile << "WINDOW 3 32 32 VTop 2\n";
	myfile << "SYMATTR InstName Co\n";
	myfile << "SYMATTR Value "+ Co +"\n";
	myfile << "SYMBOL ind -16 208 R270\n";
	myfile << "WINDOW 0 32 56 VTop 2\n";
	myfile << "WINDOW 3 5 56 VBottom 2\n";
	myfile << "SYMATTR InstName Lm\n";
	myfile << "SYMATTR Value "+ Lm +"\n";
	myfile << "TEXT 96 -56 Left 2 ;Plating Load: "+ CL +"\n";
	myfile << "TEXT 64 -88 Left 2 ;Frequency: " + freq;
	myfile.close();
	
	//Crystal icon maker -|▅|-
	myfile.open(name+".asy");
	myfile << "Version 4\n";
	myfile << "SymbolType BLOCK\n";
	myfile << "LINE Normal -16 16 -16 -16\n";
	myfile << "LINE Normal 16 16 -16 16\n";
	myfile << "LINE Normal 16 -16 16 16\n";
	myfile << "LINE Normal -16 -16 16 -16\n";
	myfile << "LINE Normal -32 32 -32 -32\n";
	myfile << "LINE Normal 32 32 32 -32\n";
	myfile << "LINE Normal 64 0 32 0\n";
	myfile << "LINE Normal -64 0 -32 0\n";
	myfile << "TEXT 0 -48 Center 1 "+ name +"\n";
	myfile << "PIN 64 0 NONE 8\n";
	myfile << "PINATTR PinName Vout\n";
	myfile << "PINATTR SpiceOrder 1\n";
	myfile << "PIN -64 0 NONE 8\n";
	myfile << "PINATTR PinName Vin\n";
	myfile << "PINATTR SpiceOrder 2";
	myfile.close();
	
	//Crystal Impedance Tester
	//Theory: 1V AC -> Vout = Z_xtal
	myfile.open(name + " Impedance.asc");
	myfile << "Version 4\n";
	myfile << "SHEET 1 880 680\n";
	myfile << "WIRE 208 160 160 160\n";
	myfile << "FLAG 288 160 0\n";
	myfile << "FLAG 32 160 0\n";
	myfile << "SYMBOL current 288 160 R90\n";
	myfile << "WINDOW 0 -32 40 VBottom 2\n";
	myfile << "WINDOW 3 32 40 VTop 2\n";
	myfile << "SYMATTR InstName I1\n";
	myfile << "SYMATTR Value 1\n";
	myfile << "SYMATTR Value2 AC 1\n";
	myfile << "SYMBOL "+ name +" 96 160 R0\n";
	myfile << "SYMATTR InstName X2\n";
	myfile << "TEXT -8 312 Left 2 !.ac dec 100000 "+ sweep_start +" "+ sweep_end;
	myfile.close();
	
	//Amplifier for testbench
	myfile.open("Inverting Amplifier.asy");
	myfile << "Version 4\n";
	myfile << "SymbolType CELL\n";
	myfile << "LINE Normal 0 -17 0 -28\n";
	myfile << "LINE Normal 5 -23 -6 -23\n";
	myfile << "LINE Normal 3 23 -2 23\n";
	myfile << "LINE Normal 0 -48 0 -32\n";
	myfile << "LINE Normal 0 48 0 32\n";
	myfile << "CIRCLE Normal 32 32 -32 -32\n";
	myfile << "WINDOW 3 46 43 Left 0\n";
	myfile << "WINDOW 0 16 -48 Left 0\n";
	myfile << "SYMATTR Value V=F(...)\n";
	myfile << "SYMATTR Prefix B\n";
	myfile << "PIN 0 -48 NONE 8\n";
	myfile << "PINATTR PinName +\n";
	myfile << "PINATTR SpiceOrder 1\n";
	myfile << "PIN 0 48 NONE 8\n";
	myfile << "PINATTR PinName -\n";
	myfile << "PINATTR SpiceOrder 2\n";
	myfile.close();
	
	//testbench
	myfile.open(name + " Testbench.asc"); 
	myfile << "Version 4                                            \n";
	myfile << "SHEET 1 1520 736                                     \n";
	myfile << "WIRE 784 240 256 240                                 \n";
	myfile << "WIRE 1200 240 1040 240                               \n";
	myfile << "WIRE 256 304 256 240                                 \n";
	myfile << "WIRE 368 304 256 304                                 \n";
	myfile << "WIRE 656 304 448 304                                 \n";
	myfile << "WIRE 256 432 256 304                                 \n";
	myfile << "WIRE 320 432 256 432                                 \n";
	myfile << "WIRE 352 432 320 432                                 \n";
	myfile << "WIRE 528 432 480 432                                 \n";
	myfile << "WIRE 576 432 528 432                                 \n";
	myfile << "WIRE 656 432 656 304                                 \n";
	myfile << "WIRE 656 432 576 432                                 \n";
	myfile << "WIRE 816 432 656 432                                 \n";
	myfile << "WIRE 1040 432 1040 240                               \n";
	myfile << "WIRE 1040 432 896 432                                \n";
	myfile << "WIRE 1040 448 1040 432                               \n";
	myfile << "WIRE 320 464 320 432                                 \n";
	myfile << "WIRE 528 464 528 432                                 \n";
	myfile << "WIRE 656 464 656 432                                 \n";
	myfile << "WIRE 1040 464 1040 448                               \n";
	myfile << "WIRE 320 560 320 528                                 \n";
	myfile << "WIRE 528 560 528 528                                 \n";
	myfile << "WIRE 656 560 656 544                                 \n";
	myfile << "WIRE 1040 560 1040 544                               \n";
	myfile << "FLAG 320 560 0                                       \n";
	myfile << "FLAG 528 560 0                                       \n";
	myfile << "FLAG 656 560 0                                       \n";
	myfile << "FLAG 1040 560 0                                      \n";
	myfile << "FLAG 1200 240 XTAL_OUT                               \n";
	myfile << "IOPIN 1200 240 Out                                   \n";
	myfile << "FLAG 784 240 XTAL_IN                                 \n";
	myfile << "IOPIN 784 240 Out                                    \n";
	myfile << "FLAG 576 432 A                                       \n";
	myfile << "SYMBOL cap 304 464 R0                                \n";
	myfile << "WINDOW 0 24 8 Left 1                                 \n";
	myfile << "WINDOW 3 24 56 Left 1                                \n";
	myfile << "SYMATTR InstName C1                                  \n";
	myfile << "SYMATTR Value "+ CL +"                               \n";
	myfile << "SYMBOL cap 512 464 R0                                \n";
	myfile << "WINDOW 0 24 8 Left 1                                 \n";
	myfile << "WINDOW 3 24 56 Left 1                                \n";
	myfile << "SYMATTR InstName C2                                  \n";
	myfile << "SYMATTR Value "+ CL +"                               \n";
	myfile << "SYMBOL current 656 464 R0                            \n";
	myfile << "WINDOW 0 30 60 Left 1                                \n";
	myfile << "WINDOW 3 30 79 Left 1                                \n";
	myfile << "WINDOW 123 0 0 Left 0                                \n";
	myfile << "WINDOW 39 0 0 Left 0                                 \n";
	myfile << "SYMATTR InstName Kickstart                           \n";
	myfile << "SYMATTR Value PULSE(0 1m 0 1n 1n 1n)                 \n";
	myfile << "SYMBOL res 912 416 R90                               \n";
	myfile << "WINDOW 0 0 56 VBottom 2                              \n";
	myfile << "WINDOW 3 32 56 VTop 2                                \n";
	myfile << "SYMATTR InstName Rs                                  \n";
	myfile << "SYMATTR Value 3k                                     \n";
	myfile << "SYMBOL res 464 288 R90                               \n";
	myfile << "WINDOW 0 0 56 VBottom 1                              \n";
	myfile << "WINDOW 3 32 56 VTop 1                                \n";
	myfile << "SYMATTR InstName Rf                                  \n";
	myfile << "SYMATTR Value 10e6                                   \n";
	myfile << "SYMBOL "+ name +" 416 432 R0                         \n";
	myfile << "SYMATTR InstName X1                                  \n";
	myfile << "SYMBOL Inverting\\ Amplifier 1040 496 R0             \n";
	myfile << "SYMATTR Value V=1.66-1.66*tanh(30*(V(xtal_in)-1.66)) \n";
	myfile << "SYMATTR InstName B1                                  \n";
	myfile << "TEXT 320 640 Left 2 !.tran 0 400u 1u                 \n";
	myfile << "TEXT 600 640 Left 2 !.options plotwinsize=0          \n";
	myfile << "TEXT 328 672 Left 2 !;tran 0 950u 949.88u 2n         \n";
	myfile.close();                                                 
	
	return 0;
}