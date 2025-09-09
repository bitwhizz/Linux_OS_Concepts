#include<stdio.h>

int main()
{

fork();
while(1)
{
sleep(1);
printf("the process id is %d",(int)getpid());
fflush(stdout);	
}
return 0;
}
