#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char **test;
    int fd = open("alphabet", O_RDONLY);
    test = (char**)malloc(sizeof(char*) * 1);

    int i;
    i =  get_next_line(fd, test);
    printf("get renvoi : ""%d\n", i);
    printf("line = ""%s\n", *test);
    free(*test);

    i =  get_next_line(fd, test);
    printf("get renvoi : ""%d\n", i);
    printf("line = ""%s\n", *test);

    i =  get_next_line(fd, test);
    printf("get renvoi : ""%d\n", i);
    printf("line = ""%s\n", *test);

    i =  get_next_line(fd, test);
    printf("get renvoi : ""%d\n", i);
    printf("line = ""%s\n", *test);
    close(fd);

	while (i)
    {
        i = get_next_line(fd, test);
        printf("get renvoi : ""%d\n", i);
        printf("line = ""%s\n", *test);
        free(*test);
    }
}
