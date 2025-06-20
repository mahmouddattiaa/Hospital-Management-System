#pragma once
#include"string.h"
#include<iostream>
using namespace std;
class patient
{
private:
	int PatientId, Severity_number, request_time, pickup_time, HospitalID, FinishTime, assigned_time,carid;
	int distance, CanceLRQT;
	string Type;
	bool picked;


public:
	patient(string type,int PID,int HID,int SNU,int Dist,int REQT);
	patient(string type,int PID, int HID, int Dist,int REQT);
	patient(int PID, int HID, int Cancel);
	patient();
	void setcarid(int x);
	int getcarid();
	void setpatientID(int ID);
	void setHID(int HID);
	void setSeverity(int S);
	void setpickedstatus(bool S);
	bool getpickedstatus();
	void setRequestTime(int RT);
	void setPickupTime(int PT);
	void setdistance(int D);
	void setType(string T);
	void setassignedtime(int t);
	void setcanceltime(int z);
	int getcanceltime();
	int getassignedtime();
	int getpatientID();
	int getHID();
	int getSeverity();
	int getRequestTime();
	int getdistance();
	string getType();
	void setFinishT(int FT);
	int getFinishT();
	bool operator<(const patient& other) const;

};

