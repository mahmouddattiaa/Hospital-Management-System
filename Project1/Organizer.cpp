#include "Organizer.h"
#include"Hospital.h"
#include"LinkedQueue.h"
Organizer::Organizer(int NH)
{
	TNH = NH;
	for (int i = 0; i < TNH; i++) {
		Hospitallist[i] = new Hospital();
	}
}
void Organizer::enQSplist(patient* Req)
{
	Sp_list.enqueue(Req);
}
void Organizer::enQNplist(patient* Req)
{
	Np_list.enqueue(Req);
}
void Organizer::enQEplist(patient* Req)
{
	Ep_list.enqueue(Req);
}
void Organizer::deQEplist(patient* Req)
{
	Ep_list.dequeue(Req);
}
void Organizer::deQNplist(patient* Req)
{
	Np_list.dequeue(Req);
}
void Organizer::deQSplist(patient* Req)
{
	Sp_list.dequeue(Req);
}
void Organizer :: requesthandle(patient * req) {
	int hid = req->getNearestHID();
	for (int i = 0; i < 6; i++)
	{
		if (Hospitallist[i].getid() == hid)
		{
			LinkedQueue < Car*>N = Hospitallist[i].getnc();
			LinkedQueue < Car*>S= Hospitallist[i].getsc();
			Car* x;
			if (req->getType() == "EP")
			{
				if (!N.isEmpty())
				{
					Hospitallist[i].deQNClist(x);
					OutCars.enqueue(x,req->getdistance());
					x->setasgtime(req->getRequestTime());
				}
				else if (!S.isEmpty())
				{
						Hospitallist[i].deQSClist(x);
						OutCars.enqueue(x, req->getdistance());
						x->setasgtime(req->getRequestTime());
				}
				else if (N.isEmpty() && S.isEmpty())
				{
					HandleEP( req);
				}
			}
			else if (req->getType() == "NP")
			{
				if (!N.isEmpty())
				{
					Hospitallist[i].deQNClist(x);
					OutCars.enqueue(x, req->getdistance());
					x->setasgtime(req->getRequestTime());
				}
			}
			else if(req->getType() == "SP")
			{
				if (!S.isEmpty())
				{
					Hospitallist[i].deQSClist(x);
					OutCars.enqueue(x, req->getdistance());
				}
			}

		}
	}
}

void Organizer::HandleEP(patient* req)
{
	for (int i = 0; i < TNH;i++) {
		Hospital* temphospital = Hospitallist[i];
		LinkedQueue<Car*> tempcar= temphospital->getnc();
		if (!tempcar.isEmpty()) {
			Car* x;
			temphospital->deQNClist(x);
			OutCars.enqueue(x, req->getdistance());
			x->setasgtime(req->getRequestTime());

		}
	}
}
