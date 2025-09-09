#include<stdio.h>
#include<stdlib.h>

int main()
{
char* server_name=getenv("SERVER_NAME");
printf("accessing server: %s\n",server_name);


if(server_name == NULL)
/*the SERVER_NAME environment variable was not set.use the default. */
server_name="server.sonictech.com";

printf("accessing server: %s\n",server_name);
/*access the server here... */

return 0;
}

/* to set SERVER_NAME variable from cmd line
export SERVER_NAME= <NAME>   */
/* To set and clear environment variabe ,use the setenv and unsetenv */
