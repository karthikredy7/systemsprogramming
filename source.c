#include<stdio.h>
#include<string.h>
int main(char argc,char *argv[])
{

	FILE *F1=NULL,*F2=NULL;
  	
	if(argc < 3) /* minimum 3 argumenrs required*/
	{
	  printf("Please Provide the Proper arguments\n");
		  return 0;
	}
	if(strcmp(argv[1],argv[2]) ==0) /*both files are same */
	{
	   printf("both files having same name\n");
	   return 0;
	}
	F2 = fopen(argv[2],"r");

	if(F2 != NULL)
		printf("%s open successfully\n",argv[2]);
	F1 = fopen(argv[1],"a");

	if(F1 != NULL)
		printf("%s open successfully\n",argv[1]);


	char *line;
	size_t size;
	int ss=0;
	while(!feof(F2))
		{
			ss=getline(&line,&size,F2); /* read the line by line from file */
		//	printf("%d %s %d \n",ss,line,size);
			if(ss >0)
			fwrite(line,ss,1,F1);
		}
	fclose(F1);
	fclose(F2);
	return 0;

}
