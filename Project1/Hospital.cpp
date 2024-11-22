#include "Hospital.h"
//template<class T>
Hospital::Hospital()
{
	HospitalID = 0;
	NNc = 0;
	NSc = 0;
}

Hospital::Hospital(int HID, int nc, int sc)
{
	HospitalID = HID;
	NNc = nc;
	NSc = sc;
}

void Hospital::setid(int id)
{
	HospitalID = id;
}

void Hospital::setPatientid(int n)
{
	patientID = n;
}

void Hospital::setNCnumbers(int c)
{
	NNc = c;
}

void Hospital::setSCnumbers(int x)
{
	NSc = x;
}

void Hospital::setdistance(int d)
{
	distance = d;
}

int Hospital::getid()
{
	return HospitalID;
}

int Hospital::getPatientid()
{
	return patientID;
}

int Hospital::getNCnumbers()
{
	return NNc;
}

int Hospital::getSCnumbers()
{
	return NSc;
}

int Hospital::getdistance()
{
	return distance;
}
void Hospital::enQNClist(Car* c)
{
	NC_list.enqueue(c);
}
void Hospital::enQSClist(Car* c)
{
	SC_list.enqueue(c);
}
void Hospital::deQNClist(Car* c)
{
	NC_list.dequeue(c);
}
void Hospital::deQSClist(Car* c)
{
	SC_list.dequeue(c);
}

LinkedQueue<Car*> Hospital::getnc()
{
	return NC_list;
}
LinkedQueue<Car*> Hospital::getsc()
{
	return SC_list;
}
