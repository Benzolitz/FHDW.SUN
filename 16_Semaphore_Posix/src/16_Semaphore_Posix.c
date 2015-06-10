#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	sem_t *posixlock;
	char semaphoreFile[] ="/16_Semaphore_Posix";

	posixlock = sem_open(semaphoreFile, O_CREAT, 0644, 1);
	sem_wait(posixlock);

	printf("Critical area!");

	sem_post(posixlock);
	sem_close(posixlock);
	sem_unlink(semaphoreFile);


	return 1;
}
