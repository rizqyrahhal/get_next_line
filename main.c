#include "get_next_line.h"
#include <sys/types.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

char *get_line(char *str)
{
	char *line;
	int	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] !='\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
char *My_get_next_line(int fd)
{
	static char *buf;
	char *line;
	int rd_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!strchr(buf, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
	}
	line = get_line(buf);
	free(buf);
	return (line);
}

int	main()
{
	char *line;
	int fd = open("Myfile.txt", O_RDONLY);

	line = My_get_next_line(fd);
	printf("LINE: %s", line);
	return (0);
}

// int	main()
// {
// 	char	*buf;
// 	ssize_t	byte;
// 	int		fd;
	
// 	fd = open("Myfile.txt", O_RDONLY);
// 	// buf[13] = '\0';
// 	byte = read(fd, buf, 13);
// 	printf("buf: %s", buf);
// 	printf("read_bytes == %zd\n", byte);
// 	close(fd);
	
// 	return (0);
// }