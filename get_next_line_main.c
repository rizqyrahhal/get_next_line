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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	lentgh = ft_strlen(s1) + ft_strlen(s2);
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

/*
void	ft_bzero(void	*s, size_t	n)
{
	unsigned char	*str;
	size_t			i;

	if (n != 0)
	{
		i = 0;
		str = s;
		while (i < n)
		{
			str[i] = 0;
			i++;
		}
	}
	return ;
}


char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{	
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}



char	*read_file(int fd)
{
	char	*res = NULL;
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}*/

char	*read_all(int	fd)
{
	char	*buf;
	static char	*save = NULL;
	int		nbr_read;
	int		i;
	int		j;

	nbr_read = 1;
	i = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	// while ((nbr_read = read(fd, buf, BUFFER_SIZE)) > 0) 
	while (fd > 0 && nbr_read >= 0)
	{
		j = 0;
		nbr_read = read(fd, buf, BUFFER_SIZE);
		if (nbr_read < 0)
			return (NULL);
		save[i] = buf[j];
		i++;
		j++;
		// save = ft_strjoin(save, buf);
		free(buf);
	}
	return (save);
}

int	main()
{
	int fd = open("Myfile.txt", O_RDONLY);
	printf("READ_ALL :: %s", read_all(fd));
	// printf("READ_ALL :: %s", read_file(fd));
	// printf("READ_ALL :: %s", read_file(fd));

	// printf("LINE: %s", My_get_next_line(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	// printf("LINE: %s", My_get_next_line(fd));
	close(fd);
	return (0);
}