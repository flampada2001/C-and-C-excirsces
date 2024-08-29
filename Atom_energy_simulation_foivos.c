#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define NR_END 1
#define FREE_ARG char*
#include <time.h>

//Create a stucture named atom that stores every important aspect of one and calculate its total energy Kinetic + gravitational between every atom.


//Our functon creating double numbers in between two doubles
double random_number(double,double);

//The stuctore of each atom where we hold its' mass energies, position and velocity
struct atom{
	double mass;
	
	double kinetic_energy;
	double potential_energy;
	double total_energy;
	
	
	struct position{
		double rx;
		double ry;
		double rz;
	};
	struct velocity{
		double vx;
		double vy;
		double vz;
		
	};
	
};

int main(int argc, char **argv)
{
	int i,j;
	//We make ATOMS that includes 100 type of atom structures
	struct atom ATOMS[100];
	/*Mmax and Mmax_u is the maximum mass of the atoms in this simulation in kg and u units rmax and vmax are the maximum dinstance
	and velocity in each of the 3 dimentions, while r_ij will wepresent the distance between atoms*/
	double Mmax,Mmax_u, rmax, vmax, r_ij;
	
	//Contang G and the multiplication to turn mass from u to kg is defined
	const double G=6.67430e-11;
	const double u_to_kg=1.660539e-27;
	
	//maximum mass is given from the user in u and then turned into kg
	printf("Give the maximum value of the atoms' mass in unified atom mass units (u): ");
	scanf("%lf",&Mmax_u);
	Mmax=Mmax_u*u_to_kg;

	//Maximum distance and velocity of this simulation is given from the user
	printf("Give the maximum value of the atoms' position (absolute value) in meters: ");
	scanf("%lf",&rmax);
	printf("Give the maximum value of the atoms' velocity (absolute value) in m/s: ");
	scanf("%lf",&vmax);
	
	printf("\n\n\n--------------------------\n\n\n");
	
	//For every atom we generate nandom numbers for its' mass coordinated and velocity acording to the maximum values. Also the kinetic energy of each atom is calculated
	for(i=0;i<100;i++){
		
		ATOMS[i].mass=random_number(0,Mmax);
		
		ATOMS[i].rx=random_number(-rmax,rmax);
		ATOMS[i].ry=random_number(-rmax,rmax);
		ATOMS[i].rz=random_number(-rmax,rmax);
		
		ATOMS[i].vx=random_number(-vmax,vmax);
		ATOMS[i].vy=random_number(-vmax,vmax);
		ATOMS[i].vz=random_number(-vmax,vmax);
		
		ATOMS[i].kinetic_energy=0.5*ATOMS[i].mass*(ATOMS[i].vx*ATOMS[i].vx+ATOMS[i].vy*ATOMS[i].vy+ATOMS[i].vz*ATOMS[i].vz);
		
	}
	
	/*We attempt to calculate the potential energy of each atom*/
	for (i=0;i<100;i++){
		/*We normalize the potential energy to 0*/
		ATOMS[i].potential_energy=0;
		
		//For every other atom in the system j
		for(j=0;j<100;j++)
		{
			
		//The isn't ant potential energy of the itom i with it's self
			if(i==j){
				continue;
		}
			else{
				//We calculate the distance between atom i and atom j r^2=(rxi-rxj)^2+(ryi-ryj)^2+(rzi-rzj)^2
				r_ij=sqrt(((ATOMS[i].rx-ATOMS[j].rx)*(ATOMS[i].rx-ATOMS[j].rx)+(ATOMS[i].ry-ATOMS[j].ry)*(ATOMS[i].ry-ATOMS[j].ry)+(ATOMS[i].rz-ATOMS[j].rz)*(ATOMS[i].rz-ATOMS[j].rz)));
			
			//We add the potential energy of atom i due to the existance of atom j
			ATOMS[i].potential_energy=ATOMS[i].potential_energy+G*ATOMS[i].mass*G*ATOMS[j].mass/(r_ij);
			
		}
	
	}
	//We calculate the total energy of each atom and print the information asked
	ATOMS[i].total_energy=ATOMS[i].kinetic_energy+ATOMS[i].potential_energy;
	printf("Atom %d has mass= %.4e kg, position r=(%.4lf,%.4lf,%.4lf) m, velocity v=(%.4lf,%.4lf,%.4lf) m/s,\nkinetic energy %.4e J and potential energy %.4e J.\nIt's total energy is %.4e J\n\n",i+1,ATOMS[i].mass,ATOMS[i].rx,ATOMS[i].ry,ATOMS[i].rz,ATOMS[i].vx,ATOMS[i].vy,ATOMS[i].vz,ATOMS[i].kinetic_energy,ATOMS[i].potential_energy,ATOMS[i].total_energy);
		
	
}
}
// Creating rundom numbers from min_float to max_float
double  random_number(double min_float,double max_float){
	  
	  double random;
	
	random=min_float+(double) (rand())/( (double) (RAND_MAX)/(max_float-min_float));
	return random;
}