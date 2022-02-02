#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*read_file(int fd, char *save)
{
	char	*buffer;
	int		byt_read;

	// malloc if res dont exist
	if (!save)
		save = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byt_read = 1;
	// buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while(byt_read > 0)
	{
		byt_read = read(fd, buffer, BUFFER_SIZE);
		if (byt_read == -1)
		{
			free(buffer);
			return(NULL);
		}
		buffer[byt_read] = 0;
		save = ft_free(save, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	// printf("|%d|", byt_read);
	return(save);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	// char		*line;

	// error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	// line = ft_line(buffer);
	// buffer = ft_next(buffer);
	// return (line);
	return(buffer);
}





// int main()
// {
// 	int fd = open("Myfile.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));

// 	close(fd);
// 	return(0);
// }