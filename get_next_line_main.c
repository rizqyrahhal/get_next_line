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

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		lentgh;
	char	*newstring;

	i = -1;
	j = -1;
	k = 0;
	lentgh = strlen(s1) + strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (lentgh + 1));
	if (!newstring)
		return (NULL);
	while (s1[++i])
	{
		newstring[k] = s1[i];
		k++;
	}
	while (s2[++j])
	{
		newstring[k] = s2[j];
		k++;
	}	
	newstring[k] = 0;
	return (newstring);
}

char	*read_all(int	fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*save;
	int		nbr_read;
	// int		i;

	nbr_read = 1;
	*buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (nbr_read >= 0)
	{
		nbr_read = read(fd, buf, BUFFER_SIZE);
		ft_strjon(save, buf);
		free(buf);
	}
	return (save);
}

int	main()
{
	int fd = open("Myfile.txt", O_RDONLY);
	printf("READ_ALL :: %s\n", read_all(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	close(fd);
	return (0);
}