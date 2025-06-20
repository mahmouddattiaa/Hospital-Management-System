#pragma once
#include <string>
#include"patient_request.h"
using namespace std;
class Car
{private:
	int  car_id, busytime, return_T, assigned_time, pickup_time, finish_time,waittime,Carbusytime;
	int speed;
	char Type;
	string Status;
	int dumb;
	patient* Assignedpatient;
public:
	Car(int ID, char T,int s);
	Car();
	void setStatus(string T);
	string getStatus();
	void setreturnTime(int T);
	void setbusytime(int T);
	void setAssignedpatient(patient*& p);
	void setType(char t);
	char getType();
	patient*& getAssignedPatient();
	int getcarid();
	int getreturnTime();
	int getbusytime();
	void setasgtime(int T);
	void setpickuptime();
	void setfinishtime();
	int getfinishtime();
	void printtemp();
	int getspeed();
	int getwaittime();
	int carbusytime();
	int getpickuptime();
	bool operator<(const Car& other) const;
};

