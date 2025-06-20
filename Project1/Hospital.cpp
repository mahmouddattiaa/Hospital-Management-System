#include "Hospital.h"
//template<class T>
Hospital::Hospital()
{
	patientID = 0;
	HospitalID=0 ;
	NNc = 0;
	NSc = 0;
	NPcount = 0;
	EPcount = 0;
	SPcount = 0;
	//Hcount++;
}
Hospital::Hospital(int hid)
{
	patientID = 0;
	HospitalID = hid;
	NNc = 0;
	NSc = 0;
	NPcount = 0;
	EPcount = 0;
	SPcount = 0;
	//Hcount++;
}

Hospital::Hospital(int HID, int nc, int sc)
{
	patientID = 0;
	HospitalID = HID;
	NNc = nc;
	NSc = sc;
	Hcount++;
	NPcount = 0;
	EPcount = 0;
	SPcount = 0;
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

int Hospital::getEPcount()
{
	return EPcount;
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
void Hospital::enQNClist(Car*& c)
{
	NC_list.enqueue(c);
	//NNc++;
}
void Hospital::enQSClist(Car*& c)
{
	SC_list.enqueue(c);
	//NSc++;
}
void Hospital::deQNClist(Car*& c)
{
	NC_list.dequeue(c);
	//NNc--;
}
void Hospital::deQSClist(Car*& c)
{
	SC_list.dequeue(c);
	//NSc--;
}

LinkedQueue<Car*> Hospital::getnc()
{
	return NC_list;
}
LinkedQueue<Car*> Hospital::getsc()
{
	return SC_list;
}


void Hospital::enNPREQ(int& x)
{
	NPREQ.enqueue(x);
	NPcount++;
}
void Hospital::enSPREQ(int& x)
{
	SPREQ.enqueue(x);
	SPcount++;
}
void Hospital::enEPREQ(int& x)
{
	EPREQ.enqueue(x);
	EPcount++;
}
void Hospital::deNPREQ(int x)
{
	NPREQ.dequeue(x);
	NPcount--;
}
void Hospital::deSPREQ(int x)
{
	SPREQ.dequeue(x);
	SPcount--;
}
void Hospital::deEPREQ(int x)
{
	EPREQ.dequeue(x);
	EPcount--;
}

void Hospital::searchandDelete(int& id)
{
	SPREQ.searchanddelete(id);
	EPREQ.searchanddelete(id);
	NPREQ.searchanddelete(id);
}

void Hospital::freeSCtoOUTcars(patient* P, Car* tempSCcar)
{
	if (!SC_list.isEmpty()) {
		SC_list.dequeue(tempSCcar);
		tempSCcar->setAssignedpatient(P);
	}
}

void Hospital::freeNCtoOUTcars(patient* P, Car* tempNCcar)
{
	if (!NC_list.isEmpty()) {
		NC_list.dequeue(tempNCcar);
		tempNCcar->setAssignedpatient(P);
	}
}

void Hospital::returnFREEcars(Car* c)
{
	char type = c->getType();
	if (type == 'S') {
		SC_list.enqueue(c);
	}
	NC_list.enqueue(c);
	patient* tempPatient = c->getAssignedPatient();
	int id = tempPatient->getpatientID();
	search_DeleteReq(id);

}

void Hospital::search_DeleteReq(int& x)
{
	bool found= false;
	int y = 0;
	LinkedQueue<int> tempQ;
	if(!EPREQ.isEmpty()) {
		found=EPREQ.searchanddelete(x);

	}
	if (found) {
		return;
	}

	if (!SPREQ.isEmpty()) {
		found = SPREQ.searchanddelete(x);
	}
	if (found) {
		return;
	}
	if (!NPREQ.isEmpty()) {
		found = NPREQ.searchanddelete(x);
	}
	if (found) {
		return;
	}
}

void Hospital::printH()
{
	LinkedQueue<int> tempQ;
	int x = 0;
	int y = 0;
	cout << "======== HOSPITAL #" << HospitalID << " DATA   ===========" << endl;
	cout << EPREQ.getcount() << " EP requests : ";
	y = EPREQ.getcount();
	for (int i = 0; i < y; i++) {
		if (!EPREQ.isEmpty()) {
			EPREQ.dequeue(x);
			tempQ.enqueue(x);
		}

		cout << x << " ";
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(x);
		EPREQ.enqueue(x);
	}
	cout << endl;
	y = SPREQ.getcount();
	cout << SPREQ.getcount() << " SP requests : ";
	for (int i = 0; i < y; i++) {
		if (!SPREQ.isEmpty()) {
			SPREQ.dequeue(x);
			tempQ.enqueue(x);
		}
		cout << x << " ";
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(x);
		SPREQ.enqueue(x);
	}
	cout << endl;
	y = NPREQ.getcount();
	cout << NPREQ.getcount() << " NP requests : ";
	for (int i = 0; i < y; i++) {
		if (!NPREQ.isEmpty()) {
			NPREQ.dequeue(x);
			tempQ.enqueue(x);
		}
		cout << x << " ";
	}
	while (!tempQ.isEmpty()) {
		tempQ.dequeue(x);
		NPREQ.enqueue(x);
	}
	cout << endl;
	cout << "Free Cars: " << SC_list.getcount() << " Scars," << NC_list.getcount() << " Ncars" << endl;
}
bool Hospital::operator<(const Hospital& other) const
{
	return this->HospitalID < other.HospitalID;
}
