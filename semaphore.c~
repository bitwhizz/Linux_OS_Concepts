#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <stdlib.h>

int main()
{
  int semid;
  struct semid_ds status;

  semid = semget(( key_t )0x20,10,IPC_CREAT|0666);
  if(semid == -1)
    {
      perror("sem creation failed:Reason");
      exit(0);
    }
  //get the permission details
  semctl(semid,0,IPC_STAT,&status);
  printf("owners uid is %u\n",status.sem_perm.uid);
  printf("group uid is %u\n",status.sem_perm.gid);
  printf("Access mode is %c\n",status.sem_perm.mode);

  //set the permissions details 
  status.sem_perm.uid = 102;
  status.sem_perm.gid = 102;
  status.sem_perm.mode = 0444;
  semctl(semid,0,IPC_SET,&status);

  return 1;
}
