#pragma once
#include"patient_request.h"
#include"LinkedQueue.h"
#include "priQueue.h"
#include"Car.h"
#include"Hospital.h"

/**
 * @class Organizer
 * @brief Main controller class that orchestrates the hospital management system
 */
class Organizer
{
private:
	// Patient Lists
	LinkedQueue<patient*> Sp_list;           // Serious patients list
	LinkedQueue<patient*> Np_list;           // Normal patients list
	LinkedQueue<patient*> NpWaitinglist;     // Normal patients waiting list
	LinkedQueue<patient*> SpWaitinglist;     // Serious patients waiting list
	priQueue<patient*> Ep_list;              // Emergency patients list (priority queue)
	LinkedQueue<patient*> AllPReqs;          // All patient requests
	LinkedQueue<patient*> CancellationList;  // Cancelled requests
	LinkedQueue<patient*> FinishedpatientList; // Patients who completed treatment
	
	// Ambulance car lists
	priQueue<Car*> OutCars;                  // Cars on the way to patients
	priQueue<Car*> BackCars;                 // Cars on the way back with patients
	
	// System parameters
	int TNH;            // Total number of hospitals
	int SPR;            // Serious patient requests count
	int EPR;            // Emergency patient requests count
	int NPR;            // Normal patient requests count
	int TRQN;           // Total request number
	int OC;             // Out cars count
	int BC;             // Back cars count
	int FC;             // Finished cars count
	
	// Hospital data
	Hospital* Hospitallist;                  // List of all hospitals
	int distancematrix[4][4];                // Matrix of distances between hospitals
	
	// Tracking data
	int cancelledreq;                        // Number of cancelled requests
	int countWaitN;                          // Count of waiting normal patients
	int countWaitS;                          // Count of waiting serious patients
	Hospital* thishospital;                  // Current hospital being processed

public:
	// Constructors
	Organizer();
	Organizer(int NH);
	
	// System parameters - getters and setters
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
	void setmatrix(int row, int col, int num);
	
	// Hospital management
	Hospital* gethospital(int i);
	
	// Status checking methods
	bool Isoutcarempty();
	bool Isbackcarempty();
	bool IsNPlistempty();
	bool IsSPlistempty();
	bool IsEPlistempty();
	int getSPlistnumber();
	int getNPlistnumber();
	int getEPlistnumber();
	int getwaitN();
	int getwaitS();
	
	// Queue management methods
	void enQSplist(patient*& Req);
	void enQNplist(patient*& Req);
	void enQEplist(patient*& Req);
	void deQSplist(patient*& Req);
	void deQAllPlist(patient*& Req);
	void enQAllPlist(patient*& Req);
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
	
	// Request handling
	void HandleEP(patient*& req);          //required to handle ep request if no room in current hospital
	void requesthandle(patient*& req);     //function to handle all types of requests
	void requestsave(patient*& req);
	patient*& searchreq(int& id);          // Can return nullptr if patient not found
	void handlecancelledcars(patient*& temppatient);
	void cancelreqcheck(int time);
	
	// Car management
	void sendtoOUTcars(Car*& C);
	void returnCartoBACKcars(int timestep);
	void printcars();
	void HandleWaiting(int timestep);
	
	// Patient management
	void handlefinishedpatients(int timestep);
	void printfinishedpatients();
	void assignEPreq(int pid, int TNH, Hospital** Hospitallist);
	
	// Simulation control
	void InteractiveMode(int timeStep);
	void InputRead(string text);
	void fileoutput();
};
