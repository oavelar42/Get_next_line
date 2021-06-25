#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	int fd2;
	char *line;

	fd = open("texto.txt", O_RDONLY);
	fd2 = open("texto3.txt", O_RDONLY);

	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
	printf("%d-->", get_next_line(fd2, &line));
	printf("%s\n", line);
	free(line);
}