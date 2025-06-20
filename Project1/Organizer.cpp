#include "Organizer.h"
#include"Hospital.h"
#include"LinkedQueue.h"
#include"Car.h"
#include"UI.h"
#include <iostream>
#include"Organizer.h"
using namespace std;
#include<fstream>
#include"patient_request.h"
Organizer::Organizer()
{
	cancelledreq = 0;
	TNH = 0;
	SPR = 0, EPR = 0, NPR = 0,FC=0,BC=0,OC=0;
	countWaitN = 0;
	countWaitS = 0;
	
}
Organizer::Organizer(int NH)
{
	TNH = NH;
	countWaitN = 0;
	countWaitS= 0;
	SPR = 0, EPR = 0, NPR = 0, FC = 0, BC = 0, OC = 0;
	Hospitallist = new Hospital[TNH+1];
	for (int i =1 ; i <= TNH; i++) {

		Hospitallist[i].setid(i+0);
	}
}
void Organizer::setmatrix(int row,int col,int num)
{
	distancematrix[row][col] = num;
}



void Organizer::setTNH(int x)
{
	TNH = x;
}
int Organizer::getTNH()
{
	return TNH;
}
void Organizer::setSPR(int x)
{
	SPR = x;

}
int Organizer::getSPR()
{
	return SPR;
}
int Organizer::getEPR()
{
	return EPR;
}
int Organizer::getNPR()
{
	return NPR;
}
void Organizer::setTRQN(int x)
{
	TRQN = x;
}
int Organizer::getTRQN()
{
	return TRQN;
}

void Organizer::setOC(int x)
{
	OC = x;
}
int Organizer::getOC()
{
	return OC;
}
int Organizer::getBC()
{
	return BC;
}
void Organizer::setBC(int x)
{
	BC = x;
}

void Organizer::setEPR(int x)
{
	EPR = x;
}
void Organizer::setNPR(int x)
{
	NPR = x;
}
Hospital* Organizer::gethospital(int i)
{
	
	return &Hospitallist[i];
}
bool Organizer::Isoutcarempty()
{
	return OutCars.isEmpty();
}
bool Organizer::Isbackcarempty()
{
	return BackCars.isEmpty();
}
bool Organizer::IsNPlistempty()
{
	return Np_list.isEmpty();
}
bool Organizer::IsSPlistempty()
{
	return Sp_list.isEmpty();
}
bool Organizer::IsEPlistempty()
{
	return Ep_list.isEmpty();
}
int Organizer::getSPlistnumber()
{
	SPR = 0;
	LinkedQueue<patient*> tempQ;
	patient* temp;
	while(!IsSPlistempty()) {
		
		Sp_list.dequeue(temp);
		tempQ.enqueue(temp);
		SPR++;
	}
	//Sp_list = tempQ;
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(temp);
		Sp_list.enqueue(temp);
	}
	return SPR;
}
int Organizer::getEPlistnumber()
{
	int x = 0;
	EPR = 0;
	patient* temp;
	LinkedQueue<patient*> tempQ;
	while (!IsEPlistempty()) {
		

		Ep_list.dequeue(temp,x);
		tempQ.enqueue(temp);
		EPR++;
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(temp);
		Ep_list.enqueue(temp,x);
	}
	return EPR;
}
void Organizer::handlecancelledcars(patient*& tempPatient)
{
	priQueue<Car*>tempQC;
	Car* car = new  Car();
	int pri = 0;
	while (!OutCars.isEmpty()) {

		OutCars.dequeue(car, pri);
		if (car->getAssignedPatient()->getpatientID() == tempPatient->getpatientID()) {
			//OutCars.dequeue(car, pri);
			if (car->getType() == 'S') {
				Hospitallist[tempPatient->getHID()].enQSClist(car);
				AllPReqs.searchanddelete(tempPatient);
			}
			else {

				Hospitallist[tempPatient->getHID()].enQNClist(car);
				AllPReqs.searchanddelete(tempPatient);
			}
		}
		else {

			//OutCars.dequeue(car, pri);
			tempQC.enqueue(car, pri);
		}
	}
	

	while (!tempQC.isEmpty()) {
		tempQC.dequeue(car, pri);
		OutCars.enqueue(car, pri);
	}
}
int Organizer::getNPlistnumber()
{
	NPR = 0;
	patient* temp;
	LinkedQueue<patient*> tempQ;
	while (!IsNPlistempty()) {
		Np_list.dequeue(temp);
		tempQ.enqueue(temp);
		NPR++;
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(temp);
		Np_list.enqueue(temp);
	}
	return NPR;
}
int Organizer::getfinishlistnumber()
{
	FC = 0;
	patient* temp;
	LinkedQueue<patient*> tempQ;
	while (!FinishedpatientList.isEmpty()) {
		FinishedpatientList.dequeue(temp);
		tempQ.enqueue(temp);
		FC++;
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(temp);
		FinishedpatientList.enqueue(temp);
	}
	return FC;
}
void Organizer::enQSplist(patient*& Req)
{
	Sp_list.enqueue(Req);
	
}
void Organizer::enQNplist(patient*& Req)
{
	Np_list.enqueue(Req);
	
}
void Organizer::enQEplist(patient*& Req)
{
	int x = Req->getSeverity();
	Ep_list.enqueue(Req,x);
	
}
void Organizer::deQEplist(patient*& Req)
{
	int x = 0;
	Ep_list.dequeue(Req,x);
	
}
void Organizer::enQCancellist(patient*& Req)
{
	CancellationList.enqueue(Req);
}
void Organizer::deQCancellist(patient*& Req)
{
   CancellationList.dequeue(Req);
}
void Organizer::enQoutcars(Car* c, int sev)
{
	OutCars.enqueue(c, sev);
	OC++;
}
void Organizer::deQoutcars(Car* c, int sev)
{
	OutCars.dequeue(c, sev);
	OC--;
}
void Organizer::enQbackcars(Car* c, int sev)
{
	BackCars.enqueue(c, sev);
	BC++;
}
void Organizer::deQbackcars(Car* c, int sev)
{
	BackCars.dequeue(c, sev);
	BC--;
}
void Organizer::enQFinishedpatientlist(patient*& Req)
{
	FinishedpatientList.enqueue(Req);
	FC++;
}
void Organizer::deQFinishedpatientlist(patient*& Req)
{
	FinishedpatientList.dequeue(Req);
	//FC--;
}
void Organizer::deQNplist(patient*& Req)
{
	Np_list.dequeue(Req);
	
}
void Organizer::deQSplist(patient*& Req)
{
	Sp_list.dequeue(Req);
	
}
void Organizer::enQAllPlist(patient*& Req)
{
	AllPReqs.enqueue(Req);
}
void Organizer::deQAllPlist(patient*& Req)
{
	AllPReqs.dequeue(Req);
}
void Organizer :: requesthandle(patient*&  req) {
	int hid = req->getHID();
	for (int i = 1; i < TNH+1; i++)
	{
		Car*  x=new Car () ;
		int id;
		if ((id=Hospitallist[i].getid()) == hid)
		{
			LinkedQueue  < Car*> N = Hospitallist[i].getnc();
			LinkedQueue  < Car*> S= Hospitallist[i].getsc();
			
			if (req->getType() == "EP")
			{
				if (!N.isEmpty())
				{
					
					Hospitallist[i].deQNClist(x);
					x->setAssignedpatient(req);
					sendtoOUTcars(x);
					int carid = x->getcarid();
					req->setcarid(carid);
					x->setasgtime(req->getRequestTime());
					x->setpickuptime();
					x->setfinishtime();
				}
				else if (!S.isEmpty())
				{
						Hospitallist[i].deQSClist(x);
						x->setAssignedpatient(req);
						sendtoOUTcars(x);
						int carid = x->getcarid();
						req->setcarid(carid);
						x->setasgtime(req->getRequestTime());
						x->setpickuptime();
						x->setfinishtime();
				}
				else if (N.isEmpty() && S.isEmpty())
				{
					HandleEP( req);
				}
			}
	
     		 if (req->getType() == "NP")
			{
				if (!N.isEmpty())
				{
					Hospitallist[i].deQNClist(x);
					x->setAssignedpatient(req);
					sendtoOUTcars(x);
					int carid = x->getcarid();
					req->setcarid(carid);
					x->setasgtime(req->getRequestTime());
					x->setpickuptime();
					x->setfinishtime();
				}
				else {
					NpWaitinglist.enqueue(req);
					countWaitN++;
				}

			}
			 if(req->getType() == "SP")
			{
				if (!S.isEmpty())
				{
					Hospital* H = &Hospitallist[i];
					Hospitallist[i].deQSClist(x);
					
					x->setAssignedpatient(req);
					sendtoOUTcars(x);
					int carid = x->getcarid();
					req->setcarid(carid);
					x->setasgtime(req->getRequestTime());
					x->setpickuptime();
					x->setfinishtime();
				}
				else {
					SpWaitinglist.enqueue(req);
					countWaitS++;
				}
			}
			 


		}
	}
}
void Organizer::HandleWaiting(int timestep)
{
	patient* req;
	int k = NpWaitinglist.getcount();
	LinkedQueue<patient*>TempW;
	while (!NpWaitinglist.isEmpty()&&k>0) {
		NpWaitinglist.peek(req);
		int hid = req->getHID();
		for (int i = 0; i < TNH+1; i++)
		{
			Car* x = new Car();
			int id;
			if ((id = Hospitallist[i].getid()) == hid)
			{
				LinkedQueue  < Car*> N = Hospitallist[i].getnc();

				if (!N.isEmpty())
				{
					Hospitallist[i].deQNClist(x);
					
					x->setAssignedpatient(req);
					sendtoOUTcars(x);
					int carid = x->getcarid();
					req->setcarid(carid);
					req->setassignedtime(timestep);
					x->setasgtime(req->getassignedtime());
					x->setpickuptime();
					x->setfinishtime();
					NpWaitinglist.dequeue(req);
					countWaitN--;
				}
				else {
					NpWaitinglist.dequeue(req);
					TempW.enqueue(req);
				}
			}
		}
		k--;
	}
	while (!TempW.isEmpty())
	{
		TempW.dequeue(req);
		NpWaitinglist.enqueue(req);
	}
	k = SpWaitinglist.getcount();
	LinkedQueue<patient*>TempWS;
	while (!SpWaitinglist.isEmpty()&&k>0) {
		SpWaitinglist.peek(req);
		int hid = req->getHID();
		for (int i = 0; i < TNH; i++)
		{
			Car* m = new Car();
			int id;
			if ((id = Hospitallist[i].getid()) == hid)
			{
				LinkedQueue  < Car*> S = Hospitallist[i].getsc();

				if (!S.isEmpty())
				{
					Hospitallist[i].deQSClist(m);
					m->setAssignedpatient(req);
					sendtoOUTcars(m);
					int carid = m->getcarid();
					req->setcarid(carid);
					req->setassignedtime(timestep);
					m->setasgtime(req->getassignedtime());
					m->setpickuptime();
					m->setfinishtime();
					SpWaitinglist.dequeue(req);
					countWaitS--;
				}
				else {
					SpWaitinglist.dequeue(req);
					TempWS.enqueue(req);
				}
			}
		}
		k--;
	}
	while (!TempWS.isEmpty())
	{
		TempWS.dequeue(req);
		SpWaitinglist.enqueue(req);
	}
}
	

void Organizer::requestsave(patient*& req)
{
	int s = req->getSeverity();
	string type= req->getType();
	int hid = req->getHID(), pid = req->getpatientID();
		if (type == "EP") {
			Hospitallist[hid].enEPREQ(pid);

		Ep_list.enqueue(req,s);
	}
	if (type == "SP") {
		Hospitallist[hid].enSPREQ(pid);
		Sp_list.enqueue(req);
	}
	if (type == "NP") {
		Hospitallist[hid].enNPREQ(pid);
		Np_list.enqueue(req);
	}
}
void Organizer::sendtoOUTcars(Car*& C)
{
	patient* tempPatient = C->getAssignedPatient();
	int dist = tempPatient->getdistance();
	OutCars.enqueue(C,dist);
}
void Organizer::returnCartoBACKcars(int timestep)
{
	Car* tempCar=new Car();
	int dist = 0;
	priQueue<Car*>tempc;
	int y = 0;
	while (!OutCars.isEmpty())
	{
		OutCars.dequeue(tempCar, dist);
		if (timestep == tempCar->getpickuptime())
		{
			BackCars.enqueue(tempCar, dist);
			patient* tempPatient = tempCar->getAssignedPatient();
			tempPatient->setpickedstatus(true);
		}
		else
		{
		tempc.enqueue(tempCar,y);
		}
	}
	while (!tempc.isEmpty())
	{
		tempc.dequeue(tempCar, y);
		OutCars.enqueue(tempCar, y);
	}
}
void Organizer::handlefinishedpatients(int timestep)
{
	
	Car* x = new Car();
	int y = 0;
	priQueue<Car*>tempc;
	while (!BackCars.isEmpty())
	{

		BackCars.dequeue(x,y);
		if (timestep == x->getfinishtime())
		{
			
			patient* tempP = x->getAssignedPatient();
			FinishedpatientList.enqueue(tempP);
			char type=x->getType();
			int PatientHID=tempP->getHID();
			if (type == 'S') {
				Hospitallist[PatientHID].enQSClist(x);
				int pid = tempP->getpatientID();
				Hospitallist[PatientHID].searchandDelete(pid);
			}
			else {
				Hospitallist[PatientHID].enQNClist(x);
				int pid = tempP->getpatientID();
				Hospitallist[PatientHID].searchandDelete(pid);
			}
			
		}
		else {
			tempc.enqueue(x,y);
		}
	}
	while (!tempc.isEmpty())
	{
		tempc.dequeue(x,y);
		BackCars.enqueue(x,y);
	}

}
void Organizer::cancelreqcheck(int time)
{
	patient* tempPatient;
	LinkedQueue<patient*>tempQ;
	int x = 0;
	while (!CancellationList.isEmpty()) {
		CancellationList.peek(tempPatient);
		x = tempPatient->getcanceltime();
		if (x == time) {

			int hid = tempPatient->getHID();
			int pid = tempPatient->getpatientID();
			bool status = tempPatient->getpickedstatus();
			if (!status) {
				Hospitallist[hid].search_DeleteReq(pid);
				handlecancelledcars(tempPatient);
				CancellationList.dequeue(tempPatient);
				TRQN--;
			}
		}
		else {
			CancellationList.dequeue(tempPatient);
			tempQ.enqueue(tempPatient);
		}
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(tempPatient);
		CancellationList.enqueue(tempPatient);
	}

	return ;
}
void Organizer::printcars()
{
	OC = OutCars.getcount();
	priQueue<Car*>tempQ;
	int j = 0;
	Car* tempC;
		cout << OC << "==> Out cars: ";
		if (OC != 0 && !OutCars.isEmpty())
		{
		for (int i = 0; i < OC; i++)
		{
			
			OutCars.dequeue(tempC,j);
			int carid = tempC->getcarid();
			cout << tempC->getType() << carid << "_"<<"H"<<tempC->getAssignedPatient()->getHID()<<"_"<<"P"<< tempC->getAssignedPatient()->getpatientID()<<", ";
			tempQ.enqueue(tempC,j);
		}
		while (!tempQ.isEmpty()) {
			tempQ.dequeue(tempC, j);
			OutCars.enqueue(tempC, j);
		}
	}
		cout << endl;
		BC = BackCars.getcount();
		cout << BC << "<== Back cars: ";
		if (BC != 0 && !BackCars.isEmpty())
		{
		for (int i = 0; i < BC; i++)
		{

			BackCars.dequeue(tempC, j);
			int carid = tempC->getcarid();
			cout << tempC->getType() << carid << "_"<<"H"<<tempC->getAssignedPatient()->getHID()<<"_"<<"P"<< tempC->getAssignedPatient()->getpatientID()<<", ";
			tempQ.enqueue(tempC, j);
		}
		while (!tempQ.isEmpty()) {
			tempQ.dequeue(tempC, j);
			BackCars.enqueue(tempC, j);
		}
	}
		cout << endl;

}

void Organizer::printfinishedpatients()
{
	LinkedQueue<patient*> tempQ;
	patient* tempP;
	int FPN =FinishedpatientList.getcount();
	cout << FPN << " finished patients: ";
	if (FPN > 0 && !FinishedpatientList.isEmpty()) {
		
		for (int i = 0; i < FPN; i++) { 
			FinishedpatientList.dequeue(tempP);
			int x = tempP->getpatientID();
			cout << x << " ";
			
			tempQ.enqueue(tempP);
		}
		while (!tempQ.isEmpty()) {
			tempQ.dequeue(tempP);
			FinishedpatientList.enqueue(tempP);
		}
		cout << endl;
	}

}
int Organizer::getwaitN()
{
	return countWaitN;
}
patient*& Organizer::searchreq(int& id)
{
	LinkedQueue<patient*> tempQ;
	static patient* p1 = nullptr;
	patient* p2 = nullptr;
	bool found = false;
	
	// Reset p1 to nullptr before searching
	p1 = nullptr;
	
	while (!AllPReqs.isEmpty()) {
		AllPReqs.peek(p2);
		if (p2->getpatientID() == id) {
			AllPReqs.dequeue(p1);
			tempQ.enqueue(p1);
			found = true;
		}
		else {
			AllPReqs.dequeue(p2);
			tempQ.enqueue(p2);
		}
	}
	
	// Restore the queue
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(p2);
		AllPReqs.enqueue(p2);
	}
	
	// Return nullptr if patient not found
	if (!found) {
		return p1; // p1 is nullptr here
	}
	
	return p1;
}
int Organizer::getwaitS()
{
	return countWaitS;
}
void Organizer::InteractiveMode(int timeStep)
{
	
	int tempR = 0;
	int FT = 0;
	int tempTRN = getTRQN();
	patient* tempP;
	
		cancelreqcheck(timeStep);
		returnCartoBACKcars(timeStep);
		handlefinishedpatients(timeStep);
		int m = getwaitN();
		int b = getwaitS();
		if (m > 0 || b > 0) {
			int h = getTNH();
			for (int i = 0; i < h; i++) {

				Hospital* H = gethospital(i);
				LinkedQueue  < Car*> N = H->getnc();
				LinkedQueue  < Car*> S = H->getsc();
				if (!N.isEmpty() || !S.isEmpty()) {
					HandleWaiting(timeStep);
				}

			}
		}
		LinkedQueue<patient*> tempQ;
		for (int i = 0; i <tempTRN; i++) {
			deQAllPlist(tempP);
			tempR = tempP->getRequestTime();

			if (tempR == timeStep) {
				requestsave(tempP);
				requesthandle(tempP);
			}
			tempQ.enqueue(tempP);
		}


		while (!tempQ.isEmpty()) {
			tempQ.dequeue(tempP);
			enQAllPlist(tempP);
		}
		
	}
void Organizer::InputRead(string text)
{
	// Construct proper file path - search in current directory and parent directories
	fstream input;
	string filePath = text;
	
	// Try to open the file directly
	input.open(filePath, ios::in);
	
	// If file not found, try with Project1/ prefix
	if (!input.is_open()) {
		filePath = "Project1/" + text;
		input.open(filePath, ios::in);
	}
	
	// If still not found, try with ../ prefix
	if (!input.is_open()) {
		filePath = "../" + text;
		input.open(filePath, ios::in);
	}
	
	// Final attempt with full path
	if (!input.is_open()) {
		cout << "Unable to open file " << text << endl;
		cout << "Please make sure the file exists and is accessible." << endl;
		cout << "Try providing the full path to the file." << endl;
		return;
	}
	
	cout << "Successfully opened file: " << filePath << endl;
	
	try {
		int HN = 0;
		input >> HN;
		
		setTNH(HN);
		Hospitallist = new Hospital[TNH+1];
		for (int i = 1; i <= TNH; i++) {
			Hospitallist[i].setid(i);
		}

		int SSC = 0, SNC = 0;
		input >> SSC >> SNC;
		
		int num = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				input >> num;
				setmatrix(i, j, num);
			}
		}

		for (int i = 1; i <= HN; i++)
		{
			Hospital* H = gethospital(i);
			int NC, SC;
			input >> SC >> NC;
			H->setSCnumbers(SC);
			H->setNCnumbers(NC);
			for (int j = 0; j < SC; j++)
			{
				Car* m = new Car(i, 'S', SSC);
				H->enQSClist(m);
			}
			for (int j = 0; j < NC; j++)
			{
				Car* n = new Car(i, 'N', SNC);
				H->enQNClist(n);
			}
		}
		int NoOfReq = 0;
		input >> NoOfReq;
		setTRQN(NoOfReq);
		for (int i = 0; i < NoOfReq; i++)
		{
			string type;
			input >> type;
			int TimeStep = 0;
			int PID = 0;
			int HID = 0;
			int distance = 0;
			int Severity = 0;

			if (type == "EP")
			{
				input >> TimeStep >> PID >> HID >> distance >> Severity;
				patient* p = new patient(type, PID, HID, Severity, distance, TimeStep);
				enQAllPlist(p);
			}
			else {
				input >> TimeStep >> PID >> HID >> distance;
				patient* p = new patient(type, PID, HID, distance, TimeStep);
				enQAllPlist(p);
			}
		}
		int cancelNum = 0;
		input >> cancelNum;
		for (int i = 0; i < cancelNum; i++) {
			int cunitstep = 0, pid = 0, hid = 0;
			input >> cunitstep >> pid >> hid;
			patient* p3 = searchreq(pid);
			if (p3 != nullptr) {
				p3->setcanceltime(cunitstep);
				enQCancellist(p3);
			} else {
				cout << "Warning: Could not find patient with ID " << pid << " for cancellation." << endl;
			}
		}
		cout << "File data loaded successfully!" << endl;
	} catch (const exception& e) {
		cout << "Error reading file data: " << e.what() << endl;
	}
	
	input.close();
}
void Organizer::fileoutput()
{
	try {
		int totalHos = getTNH();
		int totalPa = getTRQN();
		int totalNP = getNPR();
		int totalSP = getSPR();
		int totalEP = getEPR();
		// Fix: totalSC and totalNC should not both be equal to totalEP
		int totalSC = 0;
		int totalNC = 0;
		
		// Count actual cars per hospital
		for (int i = 1; i <= totalHos; i++) {
			Hospital* H = gethospital(i);
			totalSC += H->getSCnumbers();
			totalNC += H->getNCnumbers();
		}
		
		int totalC = totalSC + totalNC;

		int PID = 0;
		int TotBusyT = 0;
		int TotWaitingT = 0;

		string outputPath = "output.txt";
		ofstream output;
		output.open(outputPath, ios::out);
		if (!output.is_open()) {
			cout << "Error: Unable to open file " << outputPath << " for writing." << endl;
			cout << "Please make sure the directory is writable." << endl;
			return;
		}
		
		cout << "Writing output to " << outputPath << "..." << endl;
		
		output << "FT" << "\t" << "PID" << "\t" << "OT" << "\t" << "WT" << endl;
		
		// Handle case where no patients are processed
		if (totalPa <= 0) {
			output << "No patients were processed." << endl;
		} else {
			for (int i = 0; i < totalPa; i++) {
				// Check if there are any patients left to process
				if (AllPReqs.isEmpty()) {
					cout << "Warning: Reached end of patient list before expected." << endl;
					break;
				}
				
				Car* c = new Car();
				patient* p = nullptr;
				
				// Safely dequeue a patient
				deQAllPlist(p);
				
				if (p != nullptr) {
					output << p->getFinishT() << "\t"
						<< p->getpatientID() << "\t"
						<< p->getRequestTime() << "\t"
						<< c->getwaittime() << endl;
					TotWaitingT = TotWaitingT + c->getwaittime();
					TotBusyT = TotBusyT + c->getbusytime();
				} else {
					cout << "Warning: Found null patient during output generation." << endl;
				}
				
				delete c; // Clean up the car object we created
			}
			
			// Avoid division by zero
			float AvgWait = (totalPa > 0) ? (float)TotWaitingT / totalPa : 0;
			float AvgBusy = (totalC > 0) ? (float)TotBusyT / totalC : 0;
			float AvgUti = (totalC > 0) ? ((float)TotBusyT / 50) * 100 : 0;

			output << "Patients: " << totalPa << "\t" << "[NP: " << totalNP << ",SP: " << totalSP << ",EP: " << totalEP << "]" << endl;
			output << "Hospitals: " << totalHos << endl;
			output << "Cars: " << totalC << "\t" << "[SC: " << totalSC << ",NC: " << totalNC << "]" << endl;
			output << "Avg wait time: " << AvgWait << endl;
			output << "Avg busy time: " << AvgBusy << endl;
			output << "Avg utilization: " << AvgUti << "%" << endl;
		}

		output.close();
		cout << "Output file created successfully!" << endl;
		
	} catch (const exception& e) {
		cout << "Error generating output file: " << e.what() << endl;
	}
}
void Organizer::assignEPreq(int pid, int TNH, Hospital** Hospitallist)
{
	Hospital* selectedH = nullptr;
	int minCount = 100000;
	for (int i = 0; i < TNH; i++)
	{
		Hospital* currentH = Hospitallist[i];
		int epCount = currentH->getEPcount();

		if (epCount < minCount) {
			minCount = epCount;
			selectedH = currentH;
		}
		else if (epCount == minCount) {
			int currentDistance = currentH->getdistance();
			int selectedDistance = selectedH->getdistance();

			if (currentDistance < selectedDistance) {
				selectedH = currentH;
			}
		}
	}
	if (selectedH != NULL)
		selectedH->enEPREQ(pid);
}
void Organizer::HandleEP(patient*& req)
{
	for (int i = 0; i < TNH;i++) {
		if (i != req->getHID())
		{
			Hospital temphospital = Hospitallist[i];
			LinkedQueue<Car*> tempNcar = temphospital.getnc();
			LinkedQueue<Car*> tempScar = temphospital.getsc();
			Car* x = new Car();
			if (!tempNcar.isEmpty()) {

				temphospital.deQNClist(x);
				x->setAssignedpatient(req);
				sendtoOUTcars(x);
				int carid = x->getcarid();
				req->setcarid(carid);
				x->setasgtime(req->getRequestTime());
				x->setpickuptime();
				x->setfinishtime();

			}
			else if (!tempScar.isEmpty()) {

					temphospital.deQSClist(x);
					x->setAssignedpatient(req);
					sendtoOUTcars(x);
					int carid = x->getcarid();
					req->setcarid(carid);
					x->setasgtime(req->getRequestTime());
					x->setpickuptime();
					x->setfinishtime();

			}

		}
		
	}
}
