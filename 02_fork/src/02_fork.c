#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	__pid_t childPid;

	if ((childPid = fork()) == 0)
	{
		printf("This-ID: %d (Child) \n", getpid());
		printf("Parent-ID: %d \n", getppid());
		sleep(2);
	}
	else
	{
		int rc;
		waitpid(childPid, &rc, 0);
		printf("\n --- Waiting for Child %d --- \n\n", childPid);
		printf("rc: %d \n", rc);
		printf("Child-ID: %d \n", childPid);
		printf("This-ID: %d (Parent) \n", getpid());
	}

	return 1;
}
