#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "so_long.h"

int main()
{
  char **map;
  int i;
  int fd;

  map = malloc(sizeof(char*) * 10);
  fd = open("maps/42.ber", O_RDONLY);
	i = 0;
  while (i < 6)
  {
    map[i] = get_next_line(fd);
    printf("%s", map[i]);
    i++;
  }
}