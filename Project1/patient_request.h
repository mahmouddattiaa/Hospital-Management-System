#pragma once
#include"string.h"
#include<iostream>
using namespace std;
class patient
{
private:
	int PatientId, Severity_number, NHID, request_time, pickup_time;
	int distance;
	string Type;


public:
	patient(int PID,int SNU,int Dist,int REQT);
	patient(int PID, int Dist,int REQT);
	void setpatientID(int ID);
	void setSeverity(int S);
	void setNearestHID(int HID);
	void setRequestTime(int RT);
	void setPickupTime(int PT);
	void setdistance(int D);
	void setType(string T);
	int getpatientID();
	int getSeverity();
	int getNearestHID();
	int getRequestTime();
	int getPickupTime();
	int getdistance();
	string getType();




};

