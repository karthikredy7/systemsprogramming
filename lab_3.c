#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEBUG 1
void str_print(char *);
void str_sort(char *);
int main(char argc,char *argv[])
{
	int iSize_of_array 	= 0;
	char *cString_Array	= NULL;

		printf("Enter the Size of the Array:");
		
		scanf("%d",&iSize_of_array);

		cString_Array	= (char *) malloc(iSize_of_array * sizeof(char));

			if(cString_Array == NULL)
			{
				printf("Error in memory creation\n");
				return 0;
			}
		printf("Enter the string: ");
		scanf("%s",cString_Array);

#ifdef DEBUG
		printf("%s\n",cString_Array);
#endif
		str_sort(cString_Array);
		str_print(cString_Array);
return 0;
}
void str_sort(char *cString_Array)
{
		int i=0;
		for(i=0; cString_Array[i]!='\0';i++)
	       printf("%c ",cString_Array[i]);

#ifdef DEBUG
			printf(" size =%d\n",i);
#endif
	       for(int j=0; j<i;j++)
		       for(int k=j; k<i;k++)
		       {
		       		if(cString_Array[j] > cString_Array[k])
				{
					char temp = cString_Array[j];
					cString_Array[j] = cString_Array[k];
					cString_Array[k] = temp;

				}
		       }

}
void str_print(char *cString_Array)
{
		printf("Sorted string:   ")
		printf("%s\n",cString_Array);

}
