#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include"patient_request.h"
#include"Car.h"
#include"Hospital.h"
#include"priQueue.h"
#include"LinkedQueue.h"
#include"Organizer.h"
#include"UI.h"
using namespace std;

void main(){
	Organizer org1;
	UI ui1;
	int timestep = 0;
	string filename = "";
	
	// File input handling with error retry
	bool fileLoadSuccess = false;
	while (!fileLoadSuccess) {
		cout << "Enter File Name (e.g., data.txt): ";
		cin >> filename;
		
		// Clear any potential error flags if the user had an invalid input previously
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		try {
			org1.InputRead(filename);
			fileLoadSuccess = true;
		} catch (...) {
			cout << "Error loading file. Please try again." << endl;
		}
	}
	
	int mode = 0;
	cout << "please enter <1> for interactive mode or <2> for silent mode :  ";
	cin >> mode;
	cout << endl;
	while (mode > 2 || mode < 1)
	{
		cout << "please re-enter your mode correctly" << endl;
		cout << "please reenter <1> for interactive mode or <2> for silent mode :  ";
		cin >> mode;
		cout << endl;
	}
	
	if (mode == 1) {
		cout << "================interactive mode is selected===============" << endl;
		while (timestep < 100) {
			cout << "the current timestep: " << timestep;
			cout << endl;
			org1.InteractiveMode(timestep);
			ui1.printUI(org1);
			timestep++;
			cin.get();
		}
	}
	else if (mode == 2) {
		cout << "================silent mode is selected===============" << endl;

		while (timestep < 100)
		{
			org1.InteractiveMode(timestep);
			timestep++;
		}
		cout << "Silent Mode, Simulation Starts..." << endl;
		cout << "Simulation ends," << endl;
		cout << "Output file created." << endl;
		org1.fileoutput();
	}
	
	return;
}


