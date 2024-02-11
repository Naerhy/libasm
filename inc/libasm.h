#ifndef LIBASM_H
#define LIBASM_H

typedef struct s_list
{
	void* data;
	struct s_list* next;
} t_list;

ssize_t ft_read(int fd, void* buf, size_t count);
int ft_strcmp(char const* s1, char const* s2);
char* ft_strcpy(char* dest, char const* src);
char* ft_strdup(char const* s);
size_t ft_strlen(char const* s);
ssize_t ft_write(int fd, void const* buf, size_t count);

void ft_list_push_front(t_list** begin_list, void* data);
int ft_list_size(t_list* begin_list);
void ft_list_sort(t_list** begin_list, int (*cmp)());
void ft_list_remove_if(t_list** begin_list, void* data, int (*cmp)(), void (*free_fct)(void*));

#endif
