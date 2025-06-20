#include"UI.h"
#include <iostream>
#include"Organizer.h"
using namespace std;
#include<fstream>
#include"patient_request.h"

UI::UI()
{
}

/*void UI::fileinput(string text, Organizer& org)
{
	fstream input;
	input.open("data.txt", ios::in);
	if (!input.is_open()) {
		cout << "unable to open file " << text << endl;
		return;
	}
	if (input.is_open()) {
		int HN=0;
		input >> HN;
		Organizer org2(HN);
		org = org2;
		//org.setTNH(HN);
		int SSC=0, SNC=0;
		input >> SSC >> SNC;
		//cars
		int num=0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				input >> num;
				org.setmatrix(i, j, num);
			}
		}
		
		for (int i = 1; i <= HN; i++)
		{
			Hospital* H = org.gethospital(i);
			int NC, SC;
			input >> SC >> NC;
			H->setSCnumbers(SC);
			H->setNCnumbers(NC);
			for (int j = 0; j < SC; j++)
			{
				Car* m=new Car (i,'S', SSC);
			    H->enQSClist(m);
			}
			for (int j = 0; j < NC; j++)
			{
				Car* n=new Car(i, 'N', SNC);
				H->enQNClist(n);
			}
		}
		int NoOfReq=0;
		input >> NoOfReq;
		org.setTRQN(NoOfReq);
		for (int i = 0; i < NoOfReq; i++)
		{
			string type;
			input >> type;
			int TimeStep=0;
			int PID = 0;
			int HID = 0;
			int distance = 0;
			int Severity = 0;
			
			if(type=="EP")
			{ 
				input >> TimeStep >> PID >> HID >> distance >>Severity;
				patient* p =new patient(type,PID,HID,Severity, distance, TimeStep);
				org.enQAllPlist(p);
				
			}
			else{
			
				input >> TimeStep >> PID >> HID >> distance;
				patient* p =new patient(type,PID,HID, distance, TimeStep);
				org.enQAllPlist(p);
				
			}
		}
		int cancelNum=0;
		input >> cancelNum;
		for (int i = 0; i < cancelNum; i++) {
			int cunitstep = 0, pid = 0, hid = 0;
			input >> cunitstep >> pid >> hid;
			patient* p3=org.searchreq(pid);
			p3->setcanceltime(cunitstep);
			org.enQCancellist(p3);
		}
		input.close();
	}
}*/

void UI::printUI(Organizer& org)
{
	int x = 0;
	patient* temp;
	Hospital* tempH = nullptr;
	x = org.getTNH();
	
	//u1.printUI(org1);
	
	for (int i = 1; i <= x; i++) {
		tempH = org.gethospital(i);
		tempH->printH();
	}
	org.printcars();
	org.printfinishedpatients();
	cout << endl;
	cout << "=========================================================================================" << endl;

}
