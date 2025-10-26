#include <pthread.h>
#include <stdio.h>

/*
*****Passing Data to Threads*********
use the thread argument to pass a pointer to some structure or array of data. 

One commonly used technique is to define a structure for each thread function, 
which contains the “parameters” that the thread function expects.*/

//#define condition1
#define condition2
/*warning:choose any one condition at a time */

/*condition1 returns nothing condition2 returns value of controlled thread */

/* Parameters to print_function.*/

struct char_print_parms
{
	/* The character to print. */
	char character;
	/* The number of times to print it.*/
	int count;
};


/* Prints a number of characters to stderr, as given by PARAMETERS,
which is a pointer to a struct char_print_parms. */

void* char_print(void* parameters)
{
	/* Cast the cookie pointer to the right type. */
	struct char_print_parms* p=(struct char_print_parms*) parameters;
	
	int i;
	for(i=0;i<p->count;i++)
	{
		fputc(p->character, stderr);
		//printf("%c",p->character);
	}
	
	return NULL;
}	

#ifdef condition1

/*what is wrong with this condition?

The memory containing the thread parameter structures will be deallocated
 while the other two threads are still accessing it. */

int main ()
{
	pthread_t thread1_id;
	pthread_t thread2_id;

	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;

	/* Create a new thread to print 30,000 'x's. */
	thread1_args.character='x';
	thread1_args.count=300;
	pthread_create(&thread1_id, NULL, &char_print, &thread1_args);
	

	/* Create a new thread to print 20,000 'o's. */
	thread2_args.character='o';
	thread2_args.count=200;
	pthread_create(&thread2_id,NULL,&char_print,&thread2_args);
	
	return 0;
}
#endif

#ifdef condition2
int main ()
{
pthread_t thread1_id;
pthread_t thread2_id;

struct char_print_parms thread1_args;
struct char_print_parms thread2_args;

/* Create a new thread to print 30,000 x’s. */
thread1_args.character='x';
thread1_args.count=300;
pthread_create (&thread1_id,NULL,&char_print,&thread1_args);

/* Create a new thread to print 20,000 o’s. */
thread2_args.character = 'o';
thread2_args.count=200;
pthread_create (&thread2_id,NULL,&char_print,&thread2_args);

/* Make sure the first thread has finished. */
pthread_join (thread1_id, NULL);

/* Make sure the second thread has finished. */
pthread_join (thread2_id, NULL);

//pthread_equal(thread1_id,thread2_id);

/* Now we can safely return.*/
return 0;
}
#endif

/*warning---->"program returns nothing!" because the memory containing the 
thread parameter structures will be deallocated while the other two threads are still accessing it.*/

/*gcc -o threads_create_control threads_create_control.c -lpthread and executable file ./threads_create_control */

/*to avoid this we need to join the threads */

/*Using the thread argument, it’s easy to reuse the same thread function for many
threads. All these threads execute the same code, but on different data.*/
