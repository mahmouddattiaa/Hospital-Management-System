#pragma once
#include"patient_request.h"
#include"LinkedQueue.h"
#include "priQueue.h"
#include"Car.h"
class Organizer
{
private:
	LinkedQueue<patient*> Sp_list;
	LinkedQueue<patient*> Np_list;
	LinkedQueue<patient*> Ep_list;
	LinkedQueue<patient*>Allpatientrequestlist;
	LinkedQueue<patient*>CancellationList;
	priQueue<Car*>OutCars;
	priQueue<Car*>BackCars;
	LinkedQueue<patient*>FinishedpatientList;
	int TNH;//total number of hospitals
	Hospital* Hospitallist;
	
public:
	Organizer(int NH);
	void enQSplist(patient* Req);
	void enQNplist(patient* Req);
	void enQEplist(patient* Req);
	void deQSplist(patient* Req);
	void deQNplist(patient* Req);
	void deQEplist(patient* Req);
	void HandleEP(patient* req);//required to handle ep request if no room in current hospital
	void requesthandle(patient* req);//function to handle all types of requests
};

