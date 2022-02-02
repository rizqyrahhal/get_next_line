#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

int main()
{
	char *buffer;
	// int byt_read;
	int fd = open("Myfile.txt", O_RDONLY);

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	// byt_read = 1;
	// while(byt_read > 0)
	// {
	// 	byt_read = read(fd, buffer, BUFFER_SIZE);
	// 	if(byt_read == -1)
	// 		free(buffer);
	// }
	read(fd, buffer, BUFFER_SIZE);
	printf("|%s|\n", buffer);
	read(fd, buffer, BUFFER_SIZE);
	printf("|%s|\n", buffer);
	read(fd, buffer, BUFFER_SIZE);
	printf("|%s|\n", buffer);
	close(fd);
	return(0);
}