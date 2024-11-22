#pragma once
#include <string>
using namespace std;
class Car
{private:
	int  car_id, busytime, return_T, assigned_time, pickup_time, finish_time;
	 int speed;
	char Type;
	string Status;
	patient* Assignedpatient;
public:
	Car(int ID, char T);
	Car();
	void setStatus(string T);
	string getStatus();
	void setreturnTime(int T);
	void setbusytime(int T);
	void setAssignedpatient(patient*p);
	int getreturnTime();
	int getbusytime();
	void setasgtime(int T);
	void setpickuptime();
	void setfinishtime();
	void printtemp();

};

