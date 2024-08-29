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

//Our functon creating double numbers in between two doubles
double random_number(double,double);

// a function that swaps the elements of a double type vector
void swap_dvector(double *vector , int , int);

void selection_sorting_dvector(double *vector , int , int);

void print_sorted_list(double *vector, int, int);


int main(int argc, char **argv)
{
	
	int n,i;
   
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
   
   selection_sorting_dvector(random_numbers,1,n);
   
   
   /* Sorted list  is printed*/
   print_sorted_list(random_numbers, 1, n);
	
	//The space alocated by the vector random_numbers is freed
	free_dvector(random_numbers,1,n);

   return(0);
}




//Swaping 
void swap_dvector(double *vector, int i, int j){
	double temp;
	
	temp=vector[i];
	
	vector[i]=vector[j];
	
	vector[j]=temp;
	
	
}
//The selection sorting algorithm (initial is the first elaement of the vector while final is the last)
void selection_sorting_dvector(double *vector , int initial , int final){
	
	int min_index, i,j;
	
	// We find the index of the smallest element of the unsorted part of the list (i...end) and we swap it with the element in position i
	for(i=initial ; i <=final-1; i++){
    min_index=i; // We assume that the element i is the minimum. In each iteration i moves forword thus it's always the index of the first unsorted element
	
	
    for( j= i+1;j <=final; j++ )
	{//For every element to the right of the first unsorted element
    
   	if (vector[j]<vector[min_index])
	   {//If the element with index j is smaller than that with index min_index
   	
   		min_index=j; //The index of the minimum element of the unsorted list becomes j
    	}
   
	}
	
	
   	if (min_index!=i)
	   {// If an element was smaler than the first element of the unsorted list
   		
		// we call the swap function and we change the elements i and min_index of the vector random_numbers
		swap_dvector(vector,i,min_index);   
 
		}
 }
	
	
}
// Creating rundom numbers from min_float to max_float
double  random_number(double min_float,double max_float){
	  
	  float random;
	
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

void free_dvector(double *v, long nl, long nh)
/* free a double vector allocated with dvector() */
{
	free((FREE_ARG) (v+nl-NR_END));
}

//This function prints a sorted list /vector
void print_sorted_list(double *vector, int initial, int final){
	
	printf("\n\n\n Our List After it's sorted using the Selection sorting method: \n\n\n");
	
		int i;
	
   	   for( i = initial ; i <= final; i++)
   {
			printf("Our sorted vector is random_number[%d] = %fl \n",i,vector[i]);;	
   }
}


