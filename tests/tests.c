#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "libasm.h"

int main(void)
{
	printf("ft_strlen:\n");
	printf("length = %zu\n", ft_strlen("test"));
	printf("length = %zu\n", ft_strlen(""));
	printf("length = %zu\n", ft_strlen("0"));
	// printf("length = %zu\n", ft_strlen(NULL)); // ERROR

	printf("\n\n");

	printf("ft_write:\n");
	printf("errno = %d\n", errno);
	printf("%ld\n", ft_write(1, "test\n", 5));
	printf("errno = %d\n", errno);

	printf("\n\n");

	printf("ft_strcpy:\n");
	char* s1;
	char* s2;
	s1 = malloc(120);
	s2 = ft_strcpy(s1, "I am a string!");
	printf("%s - %s\n", s1, s2);
	s2 = ft_strcpy(s1, "test");
	printf("%s - %s\n", s1, s2);
	free(s1);

	printf("\n\n");

	printf("ft_strcmp:\n");
	printf("%d\n", ft_strcmp("test", "test"));
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", ft_strcmp("abc", "def"));
	printf("%d\n", ft_strcmp("", "def"));
	printf("%d\n", ft_strcmp("abc", ""));
	printf("%d\n", ft_strcmp("def", "abc"));
	printf("%d\n", ft_strcmp("random", "randomly"));

	printf("\n\n");

	printf("ft_strdup:\n");
	char* s3;
	s3 = ft_strdup("");
	printf("%s\n", s3);
	s3 = ft_strdup("this is a test");
	printf("%s\n", s3);

	printf("\n\n");

	printf("ft_read:\n");
	int fd = open("Makefile", O_RDONLY);
	void* buf = malloc(120);
	if (fd == -1)
		printf("ERROR\n");
	ssize_t x = ft_read(fd, buf, 10);
	printf("x = %ld\n", x);
	close(fd);
	return 0;
}
