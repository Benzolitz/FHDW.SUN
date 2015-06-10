#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int file;
	char buf[] = "Hallo Welt! Hallo FileHandling!"; // String (char-Array) which will be written into the file
	char filePath[] = "./06_FileHandling"; // relative-filepath
	struct stat fileMetaData;

	file = open(filePath, O_CREAT || O_RDWR);

	if (file == -1)
		printf("ERROR! No File found!");

	write(file, buf, sizeof(buf) - 1);
	read(file, buf, sizeof(buf) - 1);
	close(file);


	stat(filePath, &fileMetaData);
	printf("Dateigröße: %d Bytes\n", fileMetaData.st_size);

	return 1;
}
