#pragma once
#include <iostream>
#include"Organizer.h"
using namespace std;
#include<fstream>
#include<string>
class UI
{
private:
	string filetext;
public:
	UI();
	void fileinput(string text,Organizer& org);
	void printUI(Organizer& org);

};