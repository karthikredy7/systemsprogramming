#include<stdio.h> 
#include<stdlib.h>
int main()
{    
int given_number,x=2,y=0,prime=0;    
printf("enter number to know if it's prime:");   
scanf("%d",&given_number);  

do {
       
if(given_number%x==0)    
        {    
printf("The %d is not  prime",given_number);    
prime=1;    
break;    
        }    
    x++;
}
while(x<=given_number/2);
    
if(prime==0)    
printf("The %d is prime",given_number);     
return 0;  
}