#include <pthread.h>
#include <stdio.h>

/* Prints x’s to stderr.The parameter is unused.Does not return.*/

void* print_xs (void* unused)		//void* (*start_routine) (void*)
{
	while (1)
{
	fputc ('x', stderr);
	sleep(1);
}
	return NULL;
}



/* The main program.*/

int main ()
{
	pthread_t thread_id;
	/* Create a new thread. The new thread will run the print_xs function. */


/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);*/
	pthread_create(&thread_id,NULL,&print_xs,NULL);
	
/* Print o’s continuously to stderr. */

	while (1)
	{
	fputc ('o', stderr);
	sleep(1);
	}
	return 0;
}
/*Linux schedules both threads asynchronously */
/*creates a thread that prints x’s continuously to standard error. After calling pthread_create ,
 the main thread prints o’s continuously to standard error.*/

/*cmd: gcc -o threads_create threads_create.c -lpthread and execute file ./threads_create  */
