#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *Array_pointer,SIze_of_Array=0,icount=0,icount2=0,temp=0;
     
	printf("Enter the Size of Array: ");

	scanf("%d",&SIze_of_Array);
	
	Array_pointer= (int*) calloc(SIze_of_Array,sizeof(SIze_of_Array));	

	printf("Please enter the array elements\n");
	for(icount =0; icount < SIze_of_Array ; icount++ )
	{
		scanf("%d",&Array_pointer[icount]);
	}
	
	for(icount =0; icount < SIze_of_Array ; icount++)
	   for(icount2 =icount; icount2 < SIze_of_Array ; icount2++)
		if(!(Array_pointer[icount] < Array_pointer[icount2]))
		    {
		temp = Array_pointer[icount];
		Array_pointer[icount] = Array_pointer[icount2];
		Array_pointer[icount2]= temp;
		    }
	   	
  	printf("Sorted  Array is : ");
	for(icount =0; icount < SIze_of_Array ; icount++ )
	    printf("%d ",Array_pointer[icount]);
 
 printf("\n");
 free(Array_pointer);
 Array_pointer = NULL;
 return 0;
     
}