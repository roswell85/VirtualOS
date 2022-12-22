#pragma once
#include <iostream>
#include <string>
using namespace std;
class CSObject
{

public :
	
	CSObject(string n, string p, long s) :name(n), path(p), size(s) {

	}

	string getName() {
		return name;
	}


private:
	string name;
	string path;
	long size;

	
};

