#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float random_number(float,float);
int main()
{
   int n=50,i,j;
   
   time_t t; 
   
   float max,min,temp;
   float random_numbers[n];
   srand((unsigned) time(&t));
   
   do
   {
		printf("Dvse ton megisto: ");
		scanf("%f",&max);

   		printf("Dvse ton elaxisto: ");
   		scanf("%f",&min);
   		
   }while(max<min);
   
   
   

   /* Print n random numbers from 0min to max */
   for(i=0 ;i<n;i++)
   {
		random_numbers[i]=random_number(min,max);
		printf("%f \n",random_numbers[i]);
   }
   
   
   /*Bubble Short*/
   for(i=0;i<n;i++)
{
   
    for(j=n-1;j>=i+1; j--)
   {
   	if (random_numbers[j]<random_numbers[j-1])
	   {
   		
   		temp=random_numbers[j];
   		
   		random_numbers[j]=random_numbers[j-1];
   			
   		random_numbers[j-1]=temp;
   		
   	   }  
   }
   
}
   	
   
   /* Sorted list */
   	printf("\n\nAfter sort: \n\n");
   	   for( i = 0 ; i <n;i++)
   {
		printf("%f \n",random_numbers[i]);
		
	
   }
 
   	
   
   
   return(0);
}

float  random_number(float min_float,float max_float){
	  
	  float random;
	
	
	random=min_float+(float)(rand())/((float)(RAND_MAX)/(max_float-min_float));
	return random;
}
