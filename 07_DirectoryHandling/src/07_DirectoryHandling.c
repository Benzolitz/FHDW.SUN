#include <dirent.h>

int main()
{
	DIR *directoryPointer;
	struct dirent *directoryEntPointer;
	directoryPointer = opendir("./");
	while ((directoryEntPointer = readdir(directoryPointer)) != 0)
	{
		printf("Datei: %s\n", directoryEntPointer->d_name);
	}

	closedir(directoryPointer);

	return 1;
}
