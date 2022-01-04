#include "get_next_line.h"
#include <stdio.h>
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

// void checkLeaks(void)
// {
// 	system("leaks a.out");
// }

int	main()
{
	// char *line;
	// char *line1;
	// char *line2;
	// int fd = open("Myfile.txt", O_RDONLY);
	int fd = open("get_next_line.h", O_RDONLY);

	// line = get_next_line(fd);
	// line1 = get_next_line(fd);
	// line2 = get_next_line(fd);
	
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	// printf("%s\n", line);
	// printf("%s\n", line1);
	// printf("%s\n", line2);

	// atexit(checkLeaks);
	return (0);
}

// https://linoxide.com/install-debian-11-on-virtualbox/
https://velog.io/@yamkim/42-Seoul-Get-Next-Line2-Overview