#pragma once
#include"patient_request.h"
#include"LinkedQueue.h"
#include "priQueue.h"
#include"Car.h"
#include"Hospital.h"
class Organizer
{
private:
	LinkedQueue<patient*> Sp_list;
	LinkedQueue<patient*> Np_list;
	LinkedQueue<patient*> NpWaitinglist;
	LinkedQueue<patient*> SpWaitinglist;
	priQueue<patient*> Ep_list;
	LinkedQueue<patient*>AllPReqs;
	LinkedQueue<patient*>CancellationList;
	priQueue<Car*>OutCars;
	priQueue<Car*>BackCars;
	LinkedQueue<patient*>FinishedpatientList;
	int TNH, SPR, EPR, NPR, TRQN, OC, BC, FC;
	Hospital* Hospitallist;
	int distancematrix[4][4];
	int cancelledreq;
	int countWaitN;
	int countWaitS;
	Hospital* thishospital;
public:
	Organizer();
	Organizer(int NH);
	void setmatrix(int row, int col, int num);
	void setTNH(int x);
	int getTNH();
	void setSPR(int x);
	int getSPR();
	void setEPR(int x);
	int getEPR();
	void setNPR(int x);
	int getNPR();
	void setTRQN(int x);
	int getTRQN();
	void setOC(int x);
	int getOC();
	void setBC(int x);
	int getBC();
	int getfinishlistnumber();
	Hospital* gethospital(int i);
	bool Isoutcarempty();
	bool Isbackcarempty();
	bool IsNPlistempty();
	bool IsSPlistempty();
	bool IsEPlistempty();
	int getSPlistnumber();
	int getNPlistnumber();
	int getEPlistnumber();
	void handlecancelledcars(patient*& temppatient);
	void enQSplist(patient*& Req);
	void enQNplist(patient*& Req);
	void enQEplist(patient*& Req);
	void deQSplist(patient*& Req);
	void enQAllPlist(patient*& Req);
	void deQAllPlist(patient*& Req);
	void enQCancellist(patient*& Req);
	void deQCancellist(patient*& Req);
	void enQoutcars(Car* c, int sev);
	void deQoutcars(Car* c, int sev);
	void enQbackcars(Car* c, int sev);
	void deQbackcars(Car* c, int sev);
	void enQFinishedpatientlist(patient*& Req);
	void deQFinishedpatientlist(patient*& Req);
	void deQNplist(patient*& Req);
	void deQEplist(patient*& Req);
	void HandleEP(patient*& req);//required to handle ep request if no room in current hospital
	void requesthandle(patient*& req);//function to handle all types of requests
	void requestsave(patient*& req);
	void sendtoOUTcars(Car*& C);
	void returnCartoBACKcars(int timestep);
	void cancelreqcheck(int time);
	void HandleWaiting(int timestep);
	void printcars();
	void handlefinishedpatients(int timestep);
	void printfinishedpatients();
	int getwaitN();
	patient*& searchreq(int& id); // Can return nullptr if patient not found
	int getwaitS();
	void InteractiveMode(int timeStep);
	void InputRead(string text);
	void fileoutput();
	void assignEPreq(int pid, int TNH, Hospital** Hospitallist);
};
