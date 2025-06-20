#include "Car.h"
#include"patient_request.h"
Car::Car(int ID, char T,int s) 
{
	speed = s;
	car_id = ID;
	Type = T;
}

Car::Car()
{
	speed = 1;
	car_id = 0;
	Type = 0;
	Assignedpatient = nullptr;
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

void Car::setAssignedpatient(patient*& p)
{
	Assignedpatient = p;
}

void Car::setType(char t)
{
	Type = t;
}

char Car::getType()
{
	return Type;
}

patient*& Car::getAssignedPatient()
{
	return Assignedpatient;
}

int Car::getcarid()
{
	return car_id;
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
	Assignedpatient->setassignedtime(T);
}

void Car::setpickuptime()
{
	pickup_time = assigned_time + (Assignedpatient->getdistance() / speed);
	Assignedpatient->setPickupTime(pickup_time);
}

void Car::setfinishtime()
{
	finish_time = pickup_time + (Assignedpatient->getdistance() / speed);
	Assignedpatient->setFinishT(finish_time);
}

int Car::getfinishtime()
{
	return finish_time;
}

void Car::printtemp()
{
	cout << "car id: " << car_id << " " << "car type" << Type << endl;
}

int Car::getspeed()
{
	return speed;
}

int Car::getwaittime()
{
	waittime = pickup_time - Assignedpatient->getRequestTime();
	return waittime;
}

int Car::carbusytime()
{
	Carbusytime = finish_time - assigned_time;

	return Carbusytime;
}

int Car::getpickuptime()
{
	return pickup_time;
}
bool Car::operator<(const Car& other) const
{
	return this->car_id < other.car_id;
}