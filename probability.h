#include "parameters.h"

//double m_eff, pa1, pb1, pc2, pm1, pa2, pb2, pc1, pm2, pa3, pb3, pc3, pm3, pbeta1, pbeta2, pmi, pgamma;

// probability parameters - species 1
#define pa1 a1/(a1+b1+c2+mb)
#define pb1 b1/(a1+b1+c2+mb)
#define pc2 c2/(a1+b1+c2+mb)
#define pm1 mb/(a1+b1+c2+mb)

// probability parameters - species 2
#define pa2 a2/(a2+b2+c1+mb)
#define pb2 b2/(a2+b2+c1+mb)
#define pc1 c1/(a2+b2+c1+mb)
#define pm2 mb/(a2+b2+c1+mb)

// probability parameters - species 3
#define pa3 a2/(a3+b3+c1+mb)
#define pb3 b2/(a3+b3+c1+mb)
#define pc3 c1/(a3+b3+c1+mb)
#define pm3 mb/(a3+b3+c1+mb)

// probability parameters - infected individuals
#define pbeta1 beta1/(beta1+beta2+mi+gamma)
#define pbeta2 beta2/(beta1+beta2+mi+gamma)
#define pmi mi/(beta1+beta2+mi+gamma)
#define pgamma gamma/(beta1+beta2+mi+gamma)
