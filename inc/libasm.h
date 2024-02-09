#ifndef LIBASM_H
#define LIBASM_H

ssize_t ft_read(int fd, void* buf, size_t count);
int ft_strcmp(char const* s1, char const* s2);
char* ft_strcpy(char* dest, char const* src);
char* ft_strdup(char const* s);
size_t ft_strlen(char const* s);
ssize_t ft_write(int fd, void const* buf, size_t count);

#endif
