#include "patient_request.h"

patient::patient(int PID, int Dist, int REQT)
{
	PatientId = PID;
	Severity_number = 0;
    distance=Dist;
	request_time = REQT;
}
patient::patient(int PID, int SNU, int Dist, int REQT)
{
	PatientId = PID;
	Severity_number = SNU;
	distance = Dist;
	request_time = REQT;
}
void patient::setpatientID(int ID)
{
	PatientId = ID;
}

void patient::setSeverity(int S)
{
	Severity_number = S;
}

void patient::setNearestHID(int HID)
{
	NHID = HID;
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
int patient::getpatientID()
{
	return PatientId;
}

int patient::getSeverity()
{
	return Severity_number ;
}

int patient::getNearestHID()
{
	return NHID;
}

int patient::getRequestTime()
{
	return request_time ;
}

int patient::getPickupTime()
{
	return pickup_time;
}

int patient::getdistance()
{
	return distance ;
}

string patient::getType()
{
	return Type ;
}

