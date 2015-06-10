#include <sys/sem.h>
#include <stdio.h>

int main()
{
	int semid;

	union semun
	{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
		struct seminfo *__buf;
	} arg;

	struct sembuf sb = {0, -1, 0};

	semid = semget(0, 1024, 0666 | IPC_CREAT);
	arg.val = 1;

	semctl(semid, 0, SETVAL, arg);

	semop(semid, &sb, 1);

	printf("Enter critical area!");

	sb.sem_op = 1;
	semop(semid, &sb, 1);


	return 1;
}
