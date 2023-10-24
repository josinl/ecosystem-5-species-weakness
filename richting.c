#include "parameters.h"


double *alloc(int);



//void taxis();
int main(){


	double  *den_species1, *den_species2, *den_species3, *den_species4, *den_species5, *den_species0;//population
	double *risk_predation1;
	double *risk_predation2;
	double *risk_predation3;
	double *risk_predation4;
	double *risk_predation5;



	//densities of individuals and vacancies

	den_species1 = alloc(num_generations);
	den_species2 = alloc(num_generations);
        den_species3 = alloc(num_generations);
	den_species4 = alloc(num_generations);
	den_species5 = alloc(num_generations);
        den_species0 = alloc(num_generations);

	risk_predation1 = alloc(num_generations);
	risk_predation2 = alloc(num_generations);
	risk_predation3 = alloc(num_generations);
	risk_predation4 = alloc(num_generations);
	risk_predation5 = alloc(num_generations);


		mda1=0.0;
		mda2=0.0;
		mda3=0.0;
		mda4=0.0;
		mda5=0.0;




	double *phi; //Rede
	phi = alloc(Nx*Ny);

	// initial conditions
	init_cond(phi);

	// difinitions random GSL
        const gsl_rng_type *T;
        gsl_rng *r;
        gsl_rng_env_setup();
        T=gsl_rng_default;
        r=gsl_rng_alloc(T);
				gsl_rng_set(r,seed);

	int i,j,k; // auxiliary coordinate variables
	//int x,y, dx,dy;

	int key; // auxiliary variable for successful interactions
	double temp; // temporary variable to mobility of the species
	double gsl_action,xi_1,xi_2,xi_3;
	double gsl_passive, gsl_weakness,gsl_antipredatory,relative_density;

	int counter_interac = 0; // interactions counter
	int count1=0, count2=0; // auxiliary variable for successful interactions
	int counter1=initial_population, counter2=initial_population, counter3=initial_population, counter4=initial_population,counter5=initial_population; // desities counters

	    // initial population for predation risk

	    int n1_0, n2_0, n3_0,n4_0,n5_0,dx,dy,sum_1,sum_2,sum_3, sum_4, sum_5,x,y;
	    n1_0 = counter1;
	    n2_0 = counter2;
	    n3_0 = counter3;
	    n4_0 = counter4;
	    n5_0 = counter5;

	    int n_predations1, n_predations2, n_predations3, n_predations4,n_predations5;
	    n_predations1=0;
	    n_predations2=0;
	    n_predations3=0;
	    n_predations4=0;
	    n_predations5=0;





	while(counter_interac < num_interactions){ //inicio


		// choosing the active individual
		do{
			i = gsl_rng_uniform(r)*Nx;
			j = gsl_rng_uniform(r)*Ny;

			active = j*Nx+i;

		}while(phi[active] == 0.0);


		// sorting the passive position
		gsl_passive = gsl_rng_uniform(r);


		if(gsl_passive<0.125)
			passive=((j+1)%Ny)*Nx+i;

		else if(gsl_passive>=0.125 && gsl_passive<0.250)
			passive=((j-1+Ny)%Ny)*Nx+i;

		else if(gsl_passive>=0.250 && gsl_passive<0.375)
			passive=j*Nx+(i+1)%Nx;

		else if(gsl_passive>=0.375 && gsl_passive<0.500)
			passive=j*Nx+(i-1+Nx)%Nx;

		else if(gsl_passive>=0.500 && gsl_passive<0.625)
			passive=((j+1)%Ny)*Nx+(i+1)%Nx;

		else if(gsl_passive>=0.625 && gsl_passive<0.750)
			passive=((j-1+Ny)%Ny)*Nx+(i-1+Nx)%Nx;

		else if(gsl_passive>=0.750 && gsl_passive<0.875)
			passive=((j+1)%Ny)*Nx+(i-1+Nx)%Nx;

		else
			passive=((j-1+Ny)%Ny)*Nx+(i+1)%Nx;
    //printf("%e\n" , pa1);

		key = counter_interac;

		//calcular o efeito antipredatorio



    //calcular o efeito antipredatorio





		// sorting the action of active
		gsl_action=gsl_rng_uniform(r);
	 gsl_antipredatory=gsl_rng_uniform(r);
  gsl_weakness=gsl_rng_uniform(r);


		if(phi[active]==1.0){ // species 1

			if(gsl_action<pa){ // reproduction

				if(phi[passive]==0.0){

					phi[passive]=1.0; //reproduziu
					counter_interac++; //conta a interacao
					counter1++; //aumentou um individuo 1
			}
		}

		else if(gsl_action>=pa && gsl_action<(pa+pc)){ // selecao  = predacao = competition

			if(gsl_weakness<weakness1){



				if(phi[passive]==2.0){ //1 consegue matar o 2

					phi[passive]=0.0;
					counter_interac++; //conta a interacao = acontecer alguma coisa
					counter2--; //diminuiu um individuo 2
					n_predations2++; //+ uma predacao do 2

				}
			}   
		}



			else{  // mobility - entre nessa caixinha com 80%

				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;


	}// end of mobility
}// end of species 1

		 else if(phi[active]==2.0){ // species 2


			 			if(gsl_action<pa){ // reproduction

			 				if(phi[passive]==0.0){

			 					phi[passive]=2.0;
			 					counter_interac++;
			 					counter2++;
			 			}
			 		}

			 		else	if(gsl_action>=pa && gsl_action<(pa+pc)){ // competition

			 				if(phi[passive]==3.0){

			 					phi[passive]=0.0;
			 					counter_interac++;
			 					counter3--;
			 					n_predations3++;

			 			}

			 		}


			else{

				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;

			}

			}




		else if(phi[active]==3.0){ // species 3



						if(gsl_action<pa){ // reproduction

							if(phi[passive]==0.0){

								phi[passive]=3.0;
								counter_interac++;
								counter3++;
						}
					}

					else	if(gsl_action>=pa && gsl_action<(pa+pc)){ // competition

					if(gsl_weakness<weakness3){



								if(phi[passive]==4.0){

								phi[passive]=0.0;
								counter_interac++;
								counter4--; //diminuir na populacao do 4
								n_predations4++;

							}
						}
					}




		    else{ // mobility
					//kinesis here

		        temp=phi[passive];
		        phi[passive]=phi[active];
		        phi[active]=temp;
		        counter_interac++;

			}

		}



		///nova do codigo

		else if(phi[active]==4.0){ // species 4



						if(gsl_action<pa){ // reproduction

							if(phi[passive]==0.0){

								phi[passive]=4.0;
								counter_interac++;
								counter4++;
						}
					}

					else	if(gsl_action>=pa && gsl_action<(pa+pc)){ // competition

								if(phi[passive]==5.0){

								phi[passive]=0.0;
								counter_interac++;
								counter5--; //diminuir na populacao do 4
								n_predations5++;

						}

					}




		    else{ // mobility
					//kinesis here

		        temp=phi[passive];
		        phi[passive]=phi[active];
		        phi[active]=temp;
		        counter_interac++;

			}

		}


			///nova do codigo - specie 5 

		else if(phi[active]==5.0){ // species 5



						if(gsl_action<pa){ // reproduction

							if(phi[passive]==0.0){

								phi[passive]=5.0;
								counter_interac++;
								counter5++;
						}
					}

					else	if(gsl_action>=pa && gsl_action<(pa+pc)){ // competition

								if(phi[passive]==1.0){

								phi[passive]=0.0;
								counter_interac++;
								counter1--; //diminuir na populacao do 4
								n_predations1++;

						}

					}




		    else{ // mobility
					//kinesis here

		        temp=phi[passive];
		        phi[passive]=phi[active];
		        phi[active]=temp;
		        counter_interac++;

			}

		}




		// condition for a successful interaction
		if(counter_interac != key){

			// condition to the number of files allowed
			if((counter_interac % (num_interactions/num_files)) == 0.0){
				// recording the grid data
				output_grid(phi,count1);

				count1++;
			}

			// condition to the number of data allowed
			if((counter_interac % (Nx*Ny)) == 0.0){
				den_species1[count2] = (double)counter1/(Nx*Ny);
				den_species2[count2] = (double)counter2/(Nx*Ny);
        			den_species3[count2] = (double)counter3/(Nx*Ny);
				den_species4[count2] = (double)counter4/(Nx*Ny);
				den_species5[count2] = (double)counter5/(Nx*Ny);
        den_species0[count2] = 1.0 - (double)counter1/(Nx*Ny) - (double)counter2/(Nx*Ny) - (double)counter3/(Nx*Ny)-(double)counter4/(Nx*Ny)- (double)counter5/(Nx*Ny);

				risk_predation1[count2]=(double)n_predations1/(n1_0);
				risk_predation2[count2]=(double)n_predations2/(n2_0);
				risk_predation3[count2]=(double)n_predations3/(n3_0);
				risk_predation4[count2]=(double)n_predations4/(n4_0);
				risk_predation5[count2]=(double)n_predations5/(n5_0);

					count2++;
				n_predations1=0;
				n1_0 = counter1;
				n_predations2=0;
				n2_0 = counter2;
				n_predations3=0;
				n3_0 = counter3;
				n_predations4=0;
				n4_0 = counter4;
				n_predations5=0;
				n5_0 = counter5;



			}

		}

	} // while-key

				int xx;
		            xx=0;
		mda1=0.0;
		mda2=0.0;
		mda3=0.0;





			for(xx=(num_generations/2); xx<num_generations; xx++){
				mda1 += risk_predation1[xx]/(num_generations/2);
				mda2 += risk_predation2[xx]/(num_generations/2);
				mda3 += risk_predation3[xx]/(num_generations/2);
		        }

		 printf("%f %f %f %d %d \n" , mda1, mda2, mda3, seed, count2);




	// recording the densities data
	output_densities(den_species0, den_species1, den_species2, den_species3, den_species4,den_species5,risk_predation1, risk_predation2, risk_predation3, risk_predation4,risk_predation5);
	gsl_rng_free(r);

	free(risk_predation1);
	free(risk_predation2);
	free(risk_predation3);
	free(risk_predation4);
	free(risk_predation5);


	free(phi);
	free(den_species1);
	free(den_species2);
	free(den_species3);
	free(den_species4);
	free(den_species5);
	free(den_species0);

}
