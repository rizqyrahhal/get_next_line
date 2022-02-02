#include "get_next_line.h"

int	main()
{
	// int fd = open("get_next_line.h", O_RDONLY);
	int fd = open("Myfile.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}



// cc -Wall -Wextra -Werror test.c get_next_line.c get_next_line.h get_next_line_utils.c -D BUFFER_SIZE=10 && ./a.out
// https://linoxide.com/install-debian-11-on-virtualbox/
// https://velog.io/@yamkim/42-Seoul-Get-Next-Line2-Overview