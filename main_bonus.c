/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:27:09 by rarahhal          #+#    #+#             */
/*   Updated: 2022/02/12 18:30:16 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

void checkLeaks(void)
{
	system("leaks a.out");
	// system("leaks teat_fg");
}
// void check_leaks();
int	main()
{
	int fd = open("get_next_line.h", O_RDONLY);
	char *line1;
	// char *line2;
	// char *line3;
	// char *line4;
	// char *line5;


	int fd1 = open("Myfile.txt", O_RDONLY);
	int fd2 = open("get_next_line.c", O_RDONLY);
	line1 = get_next_line(fd);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd2);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd1);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd);
	printf("%s", line1);
	free(line1);


	// free(line2);
	// free(line3);
	// free(line4);
	// free(line5);


	// printf("%s", get_next_line(fd2));
	
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));


	close(fd);

	atexit(checkLeaks);
	// check_leaks();
	return (0);
}

//OPEN_MAX :     Maximum number of files that one process can have open at anyone time.

//OPEN_MAX : 	(65534) Maximum number of files that one process can have open at any given time

/*Macro: int OPEN_MAX
If defined, the unvarying maximum number of files that a single process can have open simultaneously.
*/


/*
    {OPEN_MAX}
        Maximum number of files that one process can have open at any one time.
        Minimum Acceptable Value: {_POSIX_OPEN_MAX}
*/







// cc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c -D BUFFER_SIZE=10 && ./a.out
// https://linoxide.com/install-debian-11-on-virtualbox/
// https://velog.io/@yamkim/42-Seoul-Get-Next-Line2-Overview