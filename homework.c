#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char file_read();
char init_table(short int count,char **pointer);
int str_to_word(char *str);

int iloop=0,Argc_Count;
typedef struct key_table{
	char *key;
	int  key_count;
}KEY;/* define the structure for key words*/
KEY *PKEY;
int main(int argc,char * argv[])
{
	Argc_Count = argc -1;
	PKEY = (KEY *)malloc(Argc_Count * sizeof(KEY)); /* dynamic memory creation for structure */ 
	if(PKEY ==NULL)
	{
		printf("Error in Memory Creation\n");
		return 0;
	}
	if (init_table(Argc_Count,argv) ==0)
		return 0;
	file_read();
	for(iloop=0;iloop<Argc_Count;iloop++)
		printf("%s\t%d\n",PKEY[iloop].key,PKEY[iloop].key_count);
	return 0;


}
/* copying the command line arguments to local structure */
char init_table(short int count,char **pointer)
{
	if(count ==0)
		return 0;
	for(iloop=1;iloop<=count;iloop++)
		PKEY[iloop-1].key = pointer[iloop];
	return 1;
}
char file_read()
{
	FILE *fp;
//	fp = fopen("file.txt","r");
	char *line;
	size_t len=0;
#if 0
	if(fp == NULL)
	{
		printf("Error in file open :\n"); return 0;}
#endif
	/* read the line by line from stdin */
	while(!(getline(&line,&len,stdin)<0) )
	{
		str_to_word(line);
	}
	//fclose(fp);
}
int str_to_word(char *str)
{
	//char ss[500] ={0};
	//strcpy(ss,str);
	char *ss = str;
	char *ptr ;
	ptr = strtok(ss," ,.\n"); /* collect the word from the string line */
#if 1
	while(ptr != NULL)
	{
#if 1
		for(iloop=0; iloop<Argc_Count;iloop++)
		{
			if(Argc_Count ==0)
				break;
			if(!strcmp(PKEY[iloop].key,ptr))
			{
				PKEY[iloop].key_count +=1;
			}
		}
#endif
		ptr =  strtok(NULL,"  ,.\n");
	}
#endif
}
