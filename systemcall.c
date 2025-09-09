#include <stdlib.h>
#include<stdio.h>
int main ()
{
	int return_value;
	return_value = system ("ls -l /");	//system() is a function to execute a shell command
	return_value = system ("ps -o pid,ppid,cmd");
	printf("return_value=%d\n",return_value);
	//return return_value;
}
