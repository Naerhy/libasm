#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libasm.h"

static void test_ft_read(void)
{
	int fd;
	char buf[128];
	ssize_t ret;

	fd = open("Makefile", O_RDONLY);
	if (fd == -1)
		return ;

	ret = ft_read(fd, buf, 10);
	assert(ret == 10);

	ret = ft_read(fd, buf, 0);
	assert(ret == 0);

	ret = ft_read(fd, buf, 56);
	assert(ret == 56);

	ret = ft_read(-12, buf, 56);
	assert(ret == -1 && errno == 9);

	close(fd);
}

static void test_ft_strcmp(void)
{
	assert(ft_strcmp("test", "test") == 0);
	assert(ft_strcmp("", "") == 0);
	assert(ft_strcmp("abc", "def") == -3);
	assert(ft_strcmp("", "def") == -100);
	assert(ft_strcmp("abc", "") == 97);
	assert(ft_strcmp("def", "abc") == 3);
	assert(ft_strcmp("random", "randomly") == -108);
}

static void test_ft_strcpy(void)
{
	char buf[128];

	ft_strcpy(buf, "I am a string");
	assert(ft_strcmp(buf, "I am a string") == 0);

	ft_strcpy(buf, "");
	assert(ft_strcmp(buf, "") == 0);

	ft_strcpy(buf, "this is a very long string\nwhich never ends\n\nbut I don't care...\t\n");
	assert(ft_strcmp(buf, "this is a very long string\nwhich never ends\n\nbut I don't care...\t\n") == 0);
}

static void test_ft_strdup(void)
{
	char* s1;
	char* s2;
	char* s3;

	s1 = ft_strdup("hahaha");
	s2 = ft_strdup("");
	s3 = ft_strdup("this is just a string made of words...");
	assert(ft_strcmp(s1, "hahaha") == 0);
	assert(ft_strcmp(s2, "") == 0);
	assert(ft_strcmp(s3, "this is just a string made of words...") == 0);

	free(s1);
	free(s2);
	free(s3);
}

static void test_ft_strlen(void)
{
	assert(ft_strlen("test") == 4);
	assert(ft_strlen("") == 0);
	assert(ft_strlen("0") == 1);
	assert(ft_strlen("a string full of 0\n\0is still a string\0") == 19);
}

static void test_ft_write(void)
{
	ssize_t ret;
	int fd;

	ret = ft_write(1, "why end might ask civil again spoil\n", 36);
	assert(ret == 36);

	ret = ft_write(1, "", 0);
	assert(ret == 0);

	ret = ft_write(456, "test\n", 5);
	assert(ret == -1 && errno == 9);

	fd = open("Makefile", O_RDONLY);
	if (fd == -1)
		return ;
	ret = ft_write(fd, "random word", 11);
	assert(ret == -1 && errno == 9);
	close(fd);
}

static void print_list(t_list* list)
{
	int nb;

	printf("printing list:\n");
	while (list)
	{
		nb = *((int*)list->data);
		printf("nb = %d\n", nb);
		list = list->next;
	}
}

static int cmp_list(void* a, void* b)
{
	int nb1;
	int nb2;

	nb1 = *((int*)a);
	nb2 = *((int*)b);
	if (nb1 < nb2)
		return -1;
	else if (nb2 < nb1)
		return 1;
	else
		return 0;
}

static void free_list(void* data)
{
	free(data);
}

static void test_ft_bonus(void)
{
	int** nbs;
	int nbs_arr[6] = {27, 3, 44, 1, -1, 30};
	size_t max;
	t_list* list;

	max = 6;
	nbs = malloc(sizeof(int*) * max);
	if (!nbs)
		return ;
	for (size_t i = 0; i < max; i++)
	{
		nbs[i] = malloc(sizeof(int));
		if (!nbs[i])
			return ;
		nbs[i][0] = nbs_arr[i];
	}
	list = NULL;
	for (size_t i = 0; i < max; i++)
	{
		ft_list_push_front(&list, (void*)nbs[i]);
		if (i == 2)
			assert(ft_list_size(list) == 3);
	}
	assert(ft_list_size(list) == 6);
	print_list(list);
	ft_list_sort(&list, cmp_list);
	print_list(list);
	ft_list_remove_if(&list, nbs_arr, cmp_list, free_list);
	ft_list_remove_if(&list, nbs_arr + 4, cmp_list, free_list);
	assert(ft_list_size(list) == 4);
	ft_list_remove_if(&list, nbs_arr + 5, cmp_list, free_list);
	ft_list_remove_if(&list, nbs_arr + 3, cmp_list, free_list);
	ft_list_remove_if(&list, nbs_arr + 1, cmp_list, free_list);
	ft_list_remove_if(&list, nbs_arr + 2, cmp_list, free_list);
	assert(ft_list_size(list) == 0);
	free(nbs);
}

int main(void)
{
	test_ft_read();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_strdup();
	test_ft_strlen();
	test_ft_write();
	test_ft_bonus();
	return 0;
}
