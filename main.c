/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:27:22 by rarahhal          #+#    #+#             */
/*   Updated: 2022/02/12 23:05:41 by rarahhal         ###   ########.fr       */
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
	line1 = get_next_line(fd);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd);
	printf("%s", line1);
	free(line1);
	line1 = get_next_line(fd);
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

// cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line.h get_next_line_utils.c -D BUFFER_SIZE=10 && ./a.out
