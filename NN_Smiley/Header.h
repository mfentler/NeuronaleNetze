#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

using topologie = std::initializer_list<int>;

enum class activationMethodchoosen { tanh_sigmoid, eins_durch_ehoch, no_formula }; // Attention, it always needs an activation method, 

inline void eins_durch_ehoch(double * p_val);




