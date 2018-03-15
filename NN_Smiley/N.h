#pragma once

#include "Header.h"

class N {
public:

	N(std::initializer_list<int>& t, double LearnRate, activationMethodchoosen act_method_received);

	std::vector<int> top;
	double LearnRate;
	activationMethodchoosen act_method;

	void(*p_activationfunction)(double * val);

	double ** nod;
	double ** err;
	double *** wij;
	double * tru; // true Values

	int Nlay;
	int Nnod;
	int Nwij;

	double calc();

	~N();

};

