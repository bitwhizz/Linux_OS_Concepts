#include<stdio.h>

/*the environ variable contains the environment */
extern char** environ;

int main()
{
char** var;
for(var=environ; *var!=NULL;++var)
printf("%s\n",*var);
return 0;
}

/*the variable of type char** ,is a NULL-terminated array of pointer 
to character strings */
