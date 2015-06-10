#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd[2];
	__pid_t pid;
	const void* message = "Hello Child!";

	pipe(fd); // Create two tunnels for message sending.

	if ((pid = fork()) > 0)
	{
		close(fd[0]); // close unused tunnel
		write(fd[1], message, 12); // Send message to second tunnel
	}
	else
	{
		sleep(1);

		void* buf;
		close(fd[1]);

		while (read(fd[0], &buf, 1) > 0)
		{
			write(STDOUT_FILENO, &buf, 1);
		}
	}

	return 1;
}
