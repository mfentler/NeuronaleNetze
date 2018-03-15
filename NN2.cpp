#include "NN2.h"

inline void eins_durch_ehoch(double * p_val) {
	//2.718 ... Euler'sche Zahl
	//pow ... power also hoch funktion
	*p_val = 1.0 / (1 + pow(2.718, -1.0 * * p_val));

	return;
}

//Konstruktor
Nu::Nu(std::initializer_list<int>& topol, double LearnRate, activationMethodchoosen act_method_recieved):
	top{ topol }, LearnRate{ LearnRate }, act_method{act_method_recieved}
{
	if (act_method == activationMethodchoosen::eins_durch_ehoch)
		p_activationfunction = eins_durch_ehoch;

	Nnod = 0;
	cout << "topologie ";
	for (auto e : top) { //holt sich auto...matisch den Integer
		cout << e << " ";

		Nnod += e;
	}
	cout << endl;

	Nlay = static_cast<int>(top.size()); //(int)
	cout << "Nlayer = " << Nlay << endl;

	if (Nlay < 3) {
		cout << "A neuronal network must have at least 3 layers. The program will terminate";
		exit(0);
	}

	nod = new double*[Nlay];
	err = new double*[Nlay];

	for (int nlay = 0; nlay < Nlay; ++nlay) {
		nod[nlay] = new double[top[nlay] + 1]; //+1 is for D which is always 1.0
		err[nlay] = new double[top[nlay]];
	}

	Nwij = 0;
	wij = new double **[Nlay - 1]; //Nur 2 weil die wij sind ja zwischen den Layern

	for (int nlay = 0; nlay < Nlay - 1; ++nlay) {
		wij[nlay] = new double*[top[nlay] + 1]; //+1 is for D which is always 1.0
	}

	for (int nlay = 0; nlay < Nlay - 1; ++nlay) {
		for (int i = 0; i < top[nlay] + 1; i++) {
			wij[nlay][i] = new double[top[nlay + 1]];
			Nwij += top[nlay + 1];
		}	
	}

	cout << "Nnod = " << Nnod << endl;
	cout << "Nwij = " << Nwij << endl;

	auto random_d = std::bind(std::uniform_real_distribution<double>(-1.0, 1.0), std::default_random_engine{});

	for (int nlay = 0; nlay < Nlay - 1; ++nlay) 
		for (int i = 0; i < top[nlay + 1]; ++i) 
			for(int j = 0; j < top[nlay + 1]; ++j)
				wij[nlay][i][j] = random_d();
		
	for (int nlay = 0; nlay < Nlay; ++nlay) 
		nod[nlay][top[nlay]] = 1.0; //+1 is for D which is always 1.0
	
	/** Set the input nodes to 0*/
	for (int i = 0; i < top[0]; i++)
		nod[0][i] = 0.0;

	/** Vector for true Values*/
	tru = new double[top[Nlay - 1]];
	for (int i = 0; i < top[Nlay - 1]; ++i) {
		tru[i] = 0.0;
	}

	cout << "Neuronal Net is up and ready!" << endl;
}

double Nu::calc() {
	//
	// Forward Calculation
	//

	/** Starts with layer i sind lyer 0 needs input but no calculation */
	for (int nlay = 1; nlay < Nlay; ++nlay)
		for (int n = 0; n < top[nlay]; ++n) {
			
			nod[nlay][n] = 0.0;

			for (int nprev = 0; nprev <= top[nlay - 1]; ++nprev) {
				nod[nlay][n] += nod[nlay - 1][nprev] * wij[nlay - 1][nprev][n];
			}

			(*p_activationfunction)((double *)(&(nod[nlay][n])));
		}


	//
	// Backward Calculation
	//

	for (int n = 0; n < top[Nlay - 1]; ++n) {
		err[Nlay - 1][n] = nod[Nlay - 1][n] * (1 - nod[Nlay - 1][n])*(tru[n] - nod[Nlay - 1][n]);
	}

	for (int nlay = Nlay - 2; nlay > 0; --nlay) {
		for (int n = 0; n < top[nlay]; ++n) {
			err[nlay][n] = 0.0;

			for (int nnext = 0; nnext < top[nlay + 1]; ++nnext) {
				err[nlay][n] += err[nlay + 1][nnext] * wij[nlay][n][nnext];
			}

			err[nlay][n] *= nod[nlay][n] * (1 - nod[nlay][n]);
		}
	}

	for (int nlay = 1; nlay < Nlay; ++nlay)
		for (int n = 0; n < top[nlay]; ++n) {
		
			for (int nprev = 0; nprev <= top[nlay - 1]; ++nprev)
				wij[nlay - 1][nprev][n] += LearnRate * nod[nlay - 1][nprev] * err[nlay][n];
		}


	return nod[Nlay - 1][0];
}