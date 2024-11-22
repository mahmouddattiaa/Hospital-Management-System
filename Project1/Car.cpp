#include "Car.h"
#include"patient_request.h"
Car::Car(int ID, char T) :speed(0)
{
	car_id = ID;
	Type = T;
}

Car::Car():speed(0)
{
	car_id = 0;
	Type = 0;
}


void Car::setStatus(string T)
{
	Status = T;
}

string Car::getStatus()
{
	return Status;
}

void Car::setreturnTime(int T)
{
	return_T = T;
}

void Car::setbusytime(int T)
{
	busytime = T;
}

void Car::setAssignedpatient(patient* p)
{
	Assignedpatient = p;
}



int Car::getreturnTime()
{
	return return_T;
}

int Car::getbusytime()
{
	return busytime ;
}

void Car::setasgtime(int T)
{
	assigned_time = T;
}

void Car::setpickuptime()
{
	pickup_time = assigned_time + (Assignedpatient->getdistance() / speed);
}

void Car::setfinishtime()
{
	finish_time = pickup_time + (Assignedpatient->getdistance() / speed);
}

void Car::printtemp()
{
	cout << "car id: " << car_id << " " << "car type" << Type << endl;
}
