#pragma once
#include "LinkedQueue.h"
#include"patient_request.h"
#include "Car.h"
//template<class T>
class Hospital
{
private:
	int  patientID,NSc,NNc;
	int HospitalID, distance;
	LinkedQueue<Car*> NC_list;
	LinkedQueue<Car*> SC_list;
public:
	Hospital();
	Hospital(int HID ,int nc,int sc);
	void setid(int id);
	void setPatientid(int n);
	void setNCnumbers(int c);
	void setSCnumbers(int x);
	void setdistance(int d);
	int getid();
	int getPatientid();
	int getNCnumbers();
	int getSCnumbers();
	int getdistance();
	void enQNClist(Car* c);
	void enQSClist(Car* c);
	void deQNClist(Car* c);
	void deQSClist(Car* c);
	LinkedQueue<Car*> getnc();
	LinkedQueue<Car*> getsc();
};

