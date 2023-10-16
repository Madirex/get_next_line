#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> // Para la función close
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("prueba.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
     while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
