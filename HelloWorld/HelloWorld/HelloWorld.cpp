/*
* Quelle.cpp
*
*  Created on: 28.09.2017
*      Author: mario
*/
#include <stdio.h> //für getchar()
#include <iostream> //für std
#include <vector> //Für Vector
#include "NN1.h"

namespace mine {
	int x;
}

using namespace std;
using std::vector;

int main() {
	mine::x = 5;

	std::cout << "Hello" << "world" << mine::x << std::endl;

	vector<double> v1;

	v1.push_back(0.0);
	v1.push_back(1.0);

	cout << v1.size();



	vector<double> v3{ 0.0,1.0,2.0,3.0 };

	int x{ 0 };

	vector<int> topologie{ 2,3,1 };

	N n; //nicht in Java
	N* pn = new N(); //in Java ohne Pointer(*)

	int* px = new int();
	*px = 5;
	x = *px;

	cout << "\nPointer x: " << x;

	getchar();
	return 0;
}


