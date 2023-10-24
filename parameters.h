
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <complex.h>
#include <fftw3.h>
#include <gsl/gsl_rng.h>

#include "prototype.h"

// controls:


#define Nx 600 //tamanho Nx*Ny
#define Ny 600
#define num_generations 1000
#define initial_population (Nx*Ny)/5 //numero inicial de individuos de cada especie
#define num_interactions (num_generations*Nx*Ny)
#define num_files 50

#define seed 223

#define radius 3	// computing radius of local density
#define epsilon 0.0
#define dispersion 0.0

#define kappa_kinesis_1 0.0
#define kappa_kinesis_2 0.0
#define kappa_kinesis_3 0.0
// control keys

#define ic_key       0 	// (0 → randomic, 1 →  specific) initial condition
#define c_key        0 	// correlation key (1 → on, 0 →  off)
#define mobility_5ey 0  // (0 → constant, 1 → taxis active, 2 → clever)


#define num_correlation 1 // number of output
#define Np 99 		  // number of points of the function C(r)

#define percent_interac 0.0	// (percentage of interactions) in 'percent_interac' of interactions the infection begins.
#define percent_infec   0.0 	// percentage of infected for both species.

// intrinsic rate of growth of species

#define a1 1.0
#define a2 1.0
#define a3 1.0
#define a4 1.0
#define a5 1.0

// intraspecific competition parameter

#define b1 0.000
#define b2 0.000
#define b3 0.000

// interspecific competition parameter

#define c1 1.0
#define c2 1.0
#define c3 1.0
#define c4 1.0
#define c5 1.0

// mobility

#define mb 1.0
#define m1 mb
#define m2 mb
#define m3 mb
#define mi mb
#define m5 mb
#define weakness1 0.7 //potencial de força, por exemplo 0.9 significa 90% de poder e 10% de fraqueza (pode variar de 0 a 1.0)
#define weakness2 0.7
#define weakness3 1.0
#define weakness4 1.0
#define weakness5 1.0  
// Probability



// probability parameters - species 1
#define pa 0.35 //reproduction
#define pc 0.35//selection
#define pm 1.0-pa-pc //mobility


// probability parameters - species 2
#define pa1 a1/(a1+c1+mb) //reproduction
#define pc1 c1/(a1+c1+mb) //selection
#define pm1 mb/(a1+c1+mb) //mobility


// probability parameters - species 3
#define pa1 a1/(a1+c1+mb) //reproduction
#define pc1 c1/(a1+c1+mb) //selection
#define pm1 mb/(a1+c1+mb) //mobility


// probability parameters - species 4
#define pa4 a4/(a4+c4+mb)
#define pm4 mb/(a4+c4+mb)
#define pc4 c4/(a4+c4+mb)

// probability parameters - species 5
#define pa5 a5/(a5+c5+mb)
#define pm5 mb/(a5+c5+mb)
#define pc5 c5/(a5+c5+mb)
