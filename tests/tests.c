#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "libasm.h"

static int cmp_nb(void* n1, void* n2)
{
	int nb1;
	int nb2;

	nb1 = *((int*)n1);
	nb2 = *((int*)n2);
	if (nb1 < nb2)
		return -1;
	else if (nb1 == nb2)
		return 0;
	else
		return 1;
}

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

	t_list* list = NULL;
	int nb1 = 123;
	int nb2 = 222;
	printf("list size = %d\n", ft_list_size(list));
	printf("nb = %d\n", nb1);
	printf("nb address = %p\n", &nb1);
	printf("list = %p\n", list);
	ft_list_push_front(&list, (void*)(&nb1));
	printf("list size = %d\n", ft_list_size(list));
	printf("list after func = %p\n", list);
	printf("list->next = %p\n", list->next);
	void* data = list->data;
	printf("list->data = %p\n", data);
	printf("nb1 = %d\n", *((int*)data));

	// pushing second node
	ft_list_push_front(&list, (void*)(&nb2));
	printf("list size = %d\n", ft_list_size(list));
	printf("list->next = %p\n", list->next);
	printf("second number = %d\n", *((int*)(list->data)));

	printf("sort:\n");
	printf("first number = %d\n", *((int*)(list->data)));
	printf("second number = %d\n", *((int*)(list->next->data)));
	ft_list_sort(&list, cmp_nb);
	printf("first number = %d\n", *((int*)(list->data)));
	printf("second number = %d\n", *((int*)(list->next->data)));

	return 0;
}
