#ifndef SLIDE_LINE
#define SLIDE_LINE
#include <stdio.h>
#include <stddef.h>

int slide_line(int *line, size_t size, int direction);
void move_it(int *line, size_t size, int direction);

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#endif /* SLIDE_LINE */
