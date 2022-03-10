#include"include.h"

/* This file is used to copy the  userinput into gloabal variables */

int copy_args(int argc,char **argv)
{
int opt;
	while((opt = getopt(argc,argv,":Ss:f:t:e:E:")) != -1)  
	{
		 if(opt == 'S')
			 S_OP = 1;
		 else if(opt == 's')
		 { s_OP = 1;
		   s_OP_size = atoi(optarg);
		 }
		 else if(opt == 'f')
		 {
		    f_OP =1;
		    f_OP_str = optarg;
		 }
		 else if(opt == 'e')
		 {
		    e_OP =1;
		    e_OP_str = optarg;
		 }
		 else if(opt == 'E')
		 {
		    E_OP =1;
		    E_OP_str = optarg;
		    char *ptr ;
		    ptr = strtok(E_OP_str," \n");
		    while(ptr !=NULL)
		    {
		       Ename[FileCount] = malloc(strlen(ptr)+1);
		       strcpy(Ename[FileCount],ptr);
		       ptr = strtok(NULL," \n");
		       FileCount +=1;
		    }
		    for(int i =0; i < FileCount ; i++)
			    printf("%s\n",Ename[i]);
		 }
		 else if(opt == 't')
		 {
		    t_OP =1;
		    t_OP_CH = optarg[0];
		 }
		 else if(opt ==  ':'){
			 printf("%c this required a value\n",optopt);
		         return -1;}
		 else if(opt ==  '?'){
			 printf("unrecognised option:%c\n",optopt);
			 return -1;
		 }
		 
	}
		while(optind < argc)	 
		{
		   //printf("dir =%s\n",argv[optind]);
		    OP_PATH = argv[optind];
		    optind++;
		}


}
