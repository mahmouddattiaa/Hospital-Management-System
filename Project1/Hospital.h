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
	int Hcount ;
	int NPcount;
	int EPcount;
	int SPcount;
	LinkedQueue<int> NPREQ;
	LinkedQueue<int> EPREQ;
	LinkedQueue<int> SPREQ;
	LinkedQueue<Car*> NC_list;
	LinkedQueue<Car*> SC_list;
public:
	Hospital();
	Hospital(int hid);
	Hospital(int HID ,int nc,int sc);
	void setid(int id);
	void setPatientid(int n);
	void setNCnumbers(int c);
	void setSCnumbers(int x);
	void setdistance(int d);
	int getid();
	int getPatientid();
	int getEPcount();
	int getNCnumbers();
	int getSCnumbers();
	int getdistance();
	void enQNClist(Car*& c);
	void enQSClist(Car*& c);
	void deQNClist(Car*& c);
	void deQSClist(Car*& c);
	LinkedQueue<Car*> getnc();
	LinkedQueue<Car*> getsc();
	void enNPREQ(int& x);
	void enSPREQ(int& x);
	void enEPREQ(int& x);
	void deNPREQ(int x);
	void deSPREQ(int x);
	void deEPREQ(int x);
	void searchandDelete(int& id);
	void freeSCtoOUTcars(patient* P, Car* tempSCcar);
	void freeNCtoOUTcars(patient* P, Car* tempNCcar);
	void returnFREEcars(Car* c);
	void search_DeleteReq(int& x);
	void printH();
	bool operator<(const Hospital& other) const;
};

