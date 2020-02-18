// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	string name;        //Crystal name
	string CL; 	        //plating load
	string Co;	        //Shunt Capacitance
	string Rm;	        //Motional Resistance
	string Lm;          //Motional Inductance
	string Cm;          //Motional Frequency
	string freq;        //Specified frequency
	string sweep_start;	//sweep start frequency
	string sweep_end;	//sweep end frequuency 
	ofstream myfile;
	string line;

    CL = "30";
    cout << stoi(CL)*2 << endl;

	return 0;
}