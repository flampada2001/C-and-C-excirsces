#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define NR_END 1
#define FREE_ARG char*
#include <time.h>

// We call the function *dvector and a double type pointer random numbers that we will turn into a double type vector (THis is the first step!!)
double *dvector(),*random_numbers;

//The function free_dvector clears
void free_dvector();

void merge_sort(double *,int,int);

void merge_sub_vectors(double *, int, int, int);

//Our functon creating double numbers in between two doubles
double random_number(double,double);


void print_sorted_list(double *vector, int, int);


int main(int argc, char **argv)
{
	
	int n,i,l,r;
   
	time_t t; 
   
	double max,min;
   
   
	srand((unsigned) time(&t));
   
   do
   {
		printf("Dwse ton megisto: ");
		scanf("%lf",&max);

   		printf("Dwse ton elaxisto: ");
   		scanf("%lf",&min);
   		
   } while(max<min);
   
   printf("Dwse arithmo stoixeiwn: ");
   scanf("%d",&n);
   
   random_numbers=dvector(1,n);
   
   
   /* Print 10 random numbers from min to max */
   for( i = 1 ; i <= n; i++)
   {
		random_numbers[i]=random_number(min,max);
		printf("\nOur unsorted vector is random_number[%d] = %fl",i,random_numbers[i]);
	
   }
   
   
   l=1;
   r=n;
   
   merge_sort(random_numbers,l,r);
   
   
   
   /* Sorted list  is printed*/
   print_sorted_list(random_numbers, 1, n);
	
	//The space alocated by the vector random_numbers is freed
	free_dvector(random_numbers,1,n);

   return(0);
}


// Creating rundom numbers from min_float to max_float
double  random_number(double min_float,double max_float){
	  
	  double random;
	
	random=min_float+(double) (rand())/( (double) (RAND_MAX)/(max_float-min_float));
	return random;
}


//Used in dvector
void nrerror(char error_text[])
/*Numerical Recipes standard error handler */
{
	fprintf(stderr,"Numerical Recipes run-time error...\n");
	fprintf(stderr,"%s\n",error_text);
	fprintf(stderr,"...now exiting to system...\n");
	exit(1);
}


//It creates a vector out of a pointer with elements fom nl to nh
double *dvector(nl,nh)
long nh,nl;
/* allocate a double vector with subscript range v[nl..nh] */
{
	double *v;
	v=(double *)malloc((unsigned int) ((nh-nl+1+NR_END)*sizeof(double)));
	if (!v) nrerror("allocation failure in dvector()");
	return v-nl+NR_END;
}
//This function merges and sorts all the sub vectors created
void merge_sub_vectors(double *vector, int left_index, int right_index, int mean_index){
	// Defining the limits of the Left and Right temp vectors
	 int L_limit=mean_index-left_index+1;
	 int R_limit=right_index-mean_index;
	 
	 int i,j,k;
	 
	 double *L_vector,*R_vector;
	 
	 // Defining L and R vectors
	 L_vector=dvector(1,L_limit);
	 R_vector=dvector(1,R_limit);
	 
	 // the left half of vector is saved in L_vector
	 for (i=1; i<=L_limit; i++){
	 	L_vector[i]=vector[(left_index-1)+i];
	 	
	 }
	 // the Right half of vector is saved in R_vector
	 for (j=1 ; j<=R_limit ; j++){
	 	R_vector[j]=vector[mean_index+j];
	 	
	 }
	
	//We normalise i and j at the starting index of L and R_Vector
	i=1;
	j=1;
	
	//We set k as the left index
	k=left_index;
	
	//While both the L_Vector and R_vector are filled
	while(i<=L_limit && j<=R_limit){
		
		if (L_vector[i]<R_vector[j]){ //If the first element of L is smaller that the first element of R
			//We dump it in the k position of our vector
			vector[k]=L_vector[i];
			
			//We assume that the first element of L is the next one
			i=i+1;
		}
		
		else{//If the first element of R is smaller that the first element of L
		//We dump it in the k position of our vector
			vector[k]=R_vector[j];
			
			//We assume that the first element of R is the next one
			j=j+1;
		}
		//We will be calculating the next shorting of vector	
		k=k+1;
			
	}
	
	//If the list with the remainig elements is L we dumb it in the end of vector
	while(i<= L_limit){
		vector[k]=L_vector[i];
		i=i+1;
		k=k+1;
		
	}
	//If the list with the remainig elements is R we dumb it in the end of vector
		while(j<= R_limit){
		vector[k]=R_vector[j];
		j=j+1;
		k=k+1;
		
	}
	
	
}


void merge_sort(double *vector,int left_index,int right_index){
	int mean_index;
	
	//As long as we have more than one elements in our subvector
	if (left_index<right_index){
		
		//We calculate the mean index
		mean_index=(right_index+left_index)/2;
		
		//And we sort it in a left and right half
		merge_sort(vector,left_index,mean_index);
		merge_sort(vector,mean_index+1,right_index);
		
		
		//Then we merge and sort each one of its subvectors
		merge_sub_vectors(vector,left_index,right_index,mean_index);
		
	}
	
}

void free_dvector(double *v, long nl, long nh)
/* free a double vector allocated with dvector() */
{
	free((FREE_ARG) (v+nl-NR_END));
}

//This function prints a sorted list /vector
void print_sorted_list(double *vector, int initial, int final){
	
	printf("\n\n\n Our List After it's sorted using the Merge sorting method: \n\n\n");
	
		int i;
	
   	   for( i = initial ; i <= final; i++)
   {
			printf("Our sorted vector is random_number[%d] = %fl \n",i,vector[i]);;	
   }
}


