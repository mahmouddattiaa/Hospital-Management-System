#include "patient_request.h"
#include"string"
using namespace std;
#include<iostream>
patient::patient(string type,int PID,int HID, int Dist, int REQT)
{
	picked = false;
	Type = type;
	PatientId = PID;
	Severity_number = 0;
    distance=Dist;
	request_time = REQT;
	HospitalID = HID;
}
patient::patient(int PID, int HID, int Cancel)
{
	picked = false;
	
	PatientId = PID;
	Severity_number = 0;
	CanceLRQT= Cancel;
	HospitalID = HID;
	distance = 0;
}
patient::patient()
{
	picked = false;
    FinishTime=0, assigned_time=0;
	CanceLRQT = 0;
	PatientId = 0;
	Severity_number = 0;
	HospitalID = 0;
	distance = 0;
}
void patient::setcarid(int x)
{
	carid = x;
}
int patient::getcarid()
{
	return carid;
}
patient::patient(string type,int PID,int HID, int SNU, int Dist, int REQT)
{
	picked = false;
	Type = type;
	PatientId = PID;
	Severity_number = SNU;
	distance = Dist;
	request_time = REQT;
	HospitalID = HID;
}
void patient::setpatientID(int ID)
{
	PatientId = ID;
}

void patient::setHID(int HID)
{
	HospitalID = HID;
}

void patient::setSeverity(int S)
{
	Severity_number = S;
}

void patient::setpickedstatus(bool s)
{
	picked = s;
}

bool patient::getpickedstatus()
{
	return picked;
}


void patient::setRequestTime(int RT)
{
	request_time = RT;
}

void patient::setPickupTime(int PT)
{
	pickup_time = PT;
}

void patient::setdistance(int D)
{
	distance = D;
}

void patient::setType(string T)
{
	Type = T;
}
void patient::setassignedtime(int t)
{
	assigned_time = t;
}
void patient::setcanceltime(int z)
{
	CanceLRQT = z;
}
int patient::getcanceltime()
{
	return CanceLRQT;
}
int patient::getassignedtime()
{
	return assigned_time;
}
int patient::getpatientID()
{
	return PatientId;
}

int patient::getHID()
{
	return HospitalID;
}

int patient::getSeverity()
{
	return Severity_number ;
}

int patient::getRequestTime()
{
	return request_time ;
}

int patient::getdistance()
{
	return distance ;
}

string patient::getType()
{
	return Type ;
}

void patient::setFinishT(int FT)
{
	FinishTime = FT;
}

int patient::getFinishT()
{
	return FinishTime;
}

bool patient::operator<(const patient& other) const
{
	return false;
}

