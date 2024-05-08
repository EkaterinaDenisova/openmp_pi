#pragma once
// author: ƒенисова ≈катерина

#include <omp.h>
#include <random>

// функци€ дл€ вычислени€ значени€ pi, использу€ библиотеку OpenMP
double count_pi_parallel(const int num_points);

// функци€ дл€ вычислени€ значени€ pi в одном потоке
double count_pi(const int num_points);

