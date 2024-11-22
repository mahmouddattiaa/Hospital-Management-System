#include <iostream>
#include<fstream>
//#include<ifstream>
#include<string>
#include"patient_request.h"
#include"Car.h"
#include"Hospital.h"
#include"priQueue.h"
#include"LinkedQueue.h"
#include"Organizer.h"
//#include"windows.data.text.h"
using namespace std;
int pickuptime(int AT, int d)
{
	int PT = AT + (d / 1);   // d/speed
}
int Waittime(int PT, int QT)
{
	int WT = PT - QT;
}
/*void looponoutcars() {
	int unitstep = 1000;
	Organizer org;
	for (int i = 0; i < unitstep; i++) {
		LinkedQueue<patient*> temp = org.get
	}

}*/
void fileloadfunc(string filname, LinkedQueue<Car>& nclist) {
	fstream myfile;
	myfile.open("data.txt", ios::in);
	int id;
	char t;
	if (!myfile.is_open()) {
		cerr << "unable to open file " << filname << endl;
		return;
	}
	if (myfile.is_open()) {
		while (myfile >> id >> t) {
			nclist.enqueue(Car(id, t));
		}
		myfile.close();
	}


}





void main() {
	LinkedQueue<Car>nclist;
	string file = "data.txt";
	fileloadfunc(file, nclist);
	while (nclist.isEmpty() == false) {
		Car temp;
		nclist.dequeue(temp);
		temp.printtemp();
	}
	//system("pause>0");

}
