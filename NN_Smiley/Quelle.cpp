

#include "N.h" 

int main() {
	N n{ topologie{144,14,2}, 0.9, activationMethodchoosen::eins_durch_ehoch };

	std::chrono::high_resolution_clock::time_point timex;
	std::chrono::nanoseconds elapsed;

	timex = std::chrono::high_resolution_clock::now();

	/**
	Die nachfolgenden Smileys wurden in Excel erstellt und dann hier händisch eingefügt.
	Überall wo ein 1.0 ist, dort ist quasi das Gesicht vom Smiley, also ein Auge oder so.
	*/
	double lachsmiley[144] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	};
	double trausmiley[144] = { 0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0
	};
	double normsmiley[144] = { 0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0,	0.0
	};

	if (1) // proper sequence for teaching
		for (int it = 0; it < 1000; ++it) {
			for (int arri = 0; arri < 144; ++arri) {
				n.nod[0][arri] = lachsmiley[arri];
			}
			n.tru[0] = 1.0;
			n.calc();
			for (int arri2 = 0; arri2 < 144; ++arri2) {
				n.nod[0][arri2] = trausmiley[arri2];
			}
			n.tru[0] = 0.0;
			n.calc();
			for (int arri3 = 0; arri3 < 144; ++arri3) {
				n.nod[0][arri3] = normsmiley[arri3];
			}
			n.tru[0] = 0.5;
			n.calc();
		}
	elapsed = std::chrono::high_resolution_clock::now() - timex;

	if (1) {
		cout << "Ergebnis mit 1000 Iteration:\n" << endl;
		
		for (int arri = 0; arri < 144; ++arri) {
			n.nod[0][arri] = lachsmiley[arri];
		}
		n.tru[0] = 1.0;
		double gesicht = n.calc();
		if (gesicht > 0.8) {
			cout << "Wert vom Smiley 1: " << gesicht << "\nDas Smiley: = " << "lacht\n" << endl;
		}
		else if (gesicht > 0.2 && gesicht < 0.8) {
			cout << "Wert vom Smiley 1: " << gesicht << "\nDas Smiley: = " << "ist normal\n" << endl;
		}
		else if (gesicht < 0.2) {
			cout << "Wert vom Smiley 1: " << gesicht << "\nDas Smiley: = " << "weint\n" << endl;
		}



		for (int arri2 = 0; arri2 < 144; ++arri2) {
			n.nod[0][arri2] = trausmiley[arri2];
		}
		n.tru[0] = 0.0;
		gesicht = n.calc();
		if (gesicht > 0.8) {
			cout << "Wert vom Smiley 2: " << gesicht << "\nDas Smiley: = " << "lacht\n" << endl;
		}
		else if (gesicht > 0.2 && gesicht < 0.8) {
			cout << "Wert vom Smiley 2: " << gesicht << "\nDas Smiley: = " << "ist normal\n" << endl;
		}
		else if (gesicht < 0.2) {
			cout << "Wert vom Smiley 2: " << gesicht << "\nDas Smiley: = " << "weint\n" << endl;
		}


		for (int arri3 = 0; arri3 < 144; ++arri3) {
			n.nod[0][arri3] = normsmiley[arri3];
		}
		n.tru[0] = 0.0;
		gesicht = n.calc();
		if (gesicht > 0.8) {
			cout << "Wert vom Smiley 3: " << gesicht << "\nDas Smiley: = " << "lacht\n" << endl;
		}
		else if (gesicht > 0.2 && gesicht < 0.8) {
			cout << "Wert vom Smiley 3: " << gesicht << "\nDas Smiley: = " << "ist normal\n" << endl;
		}
		else if (gesicht < 0.2) {
			cout << "Wert vom Smiley 3: " << gesicht << "\nDas Smiley: = " << "weint\n" << endl;
		}
		
	}

	std::cout << "\nElapsed time in seconds = " << elapsed.count() / 1000000000.0 << std::endl;

	getchar();
	return 0;
}

/*
int main() {

	N n{ topologie{ 2,3,1 }, 0.9, activationMethodchoosen::eins_durch_ehoch };
	
	// or on the heap
	// N* pn = new N{ topologie{ 2,3,1 }, 0.9, activationMethodchoosen::eins_durch_ehoch };
	// which requires pn->nod[0][0]

	std::chrono::high_resolution_clock::time_point timex;
	std::chrono::nanoseconds elapsed;
	// … 1 sec == 1 000 000 000 Nanosekunden

	timex = std::chrono::high_resolution_clock::now();
	if (1) // proper sequence for teaching
		for (int it = 0; it < 1000; ++it) {
			n.nod[0][0] = 0.0;
			n.nod[0][1] = 0.0;
			n.tru[0] = 0.0;
			n.calc();
			n.nod[0][0] = 0.0;
			n.nod[0][1] = 1.0;
			n.tru[0] = 1.0;
			n.calc();
			n.nod[0][0] = 1.0;
			n.nod[0][1] = 0.0;
			n.tru[0] = 1.0;
			n.calc();
			n.nod[0][0] = 1.0;
			n.nod[0][1] = 1.0;
			n.tru[0] = 0.0;
			n.calc();
		}
	elapsed = std::chrono::high_resolution_clock::now() - timex;


	if (1) {
		cout << "Ergebnis mit 1000 Iteration:" << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 0.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 1.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 1.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 0.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
	}

	std::cout << "Elapsed time in seconds = " << elapsed.count() / 1000000000.0 << std::endl;


	timex = std::chrono::high_resolution_clock::now();
	if (1) // proper sequence for teaching
		for (int it = 0; it < 1000000; ++it) {
			n.nod[0][0] = 0.0;
			n.nod[0][1] = 0.0;
			n.tru[0] = 0.0;
			n.calc();
			n.nod[0][0] = 0.0;
			n.nod[0][1] = 1.0;
			n.tru[0] = 1.0;
			n.calc();
			n.nod[0][0] = 1.0;
			n.nod[0][1] = 0.0;
			n.tru[0] = 1.0;
			n.calc();
			n.nod[0][0] = 1.0;
			n.nod[0][1] = 1.0;
			n.tru[0] = 0.0;
			n.calc();
		}
	elapsed = std::chrono::high_resolution_clock::now() - timex;


	if (1) {
		cout << "Ergebnis mit x1000000 Iteration:" << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 0.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 1.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 1.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 0.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
	}

	std::cout << "Elapsed time in seconds = " << elapsed.count() / 1000000000.0 << std::endl;

	timex = std::chrono::high_resolution_clock::now();
	if (1) // proper sequence for teaching
		for (int it = 0; it < 40000000; ++it) {
			n.nod[0][0] = 0.0;
			n.nod[0][1] = 0.0;
			n.tru[0] = 0.0;
			n.calc();
			n.nod[0][0] = 0.0;
			n.nod[0][1] = 1.0;
			n.tru[0] = 1.0;
			n.calc();
			n.nod[0][0] = 1.0;
			n.nod[0][1] = 0.0;
			n.tru[0] = 1.0;
			n.calc();
			n.nod[0][0] = 1.0;
			n.nod[0][1] = 1.0;
			n.tru[0] = 0.0;
			n.calc();
		}
	elapsed = std::chrono::high_resolution_clock::now() - timex;


	if (1) {
		cout << "Ergebnis mit 40000000 Iteration:" << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 0.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 1.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 1.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 0.0;
		cout << n.nod[0][0] << n.nod[0][1] << " -> " << n.tru[0] << " return = " << n.calc() << endl;
	}

	std::cout << "Elapsed time in seconds = " << elapsed.count() / 1000000000.0 << std::endl;

	getchar();
	return 0;
}

*/