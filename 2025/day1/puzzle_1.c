#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
// this function will take char* point to line from file input
// e.g : R384 , and return if it has R or L and number of steps in rotation
void extract_from_line(char *line, bool *is_right, int *steps);

int main(void) {

  FILE *file = fopen("puzzle_input_1.txt", "r");
  if (!file) {
    fprintf(stderr, "ERROR: Opening file failed!\n");
    return 1;
  }

  int password_count = 0;
  int dial_point_to = 50;
  bool is_right;
  int steps;
  char line[32];

  while (fgets(line, 32, file)) {

    extract_from_line(line, &is_right, &steps);

    if (is_right)
      dial_point_to = (dial_point_to + steps) % 100;
    else
      dial_point_to = (dial_point_to - steps) % 100;
    if (dial_point_to < 0)
      dial_point_to += 100;
    if (dial_point_to == 0)
      password_count++;
  }
  fclose(file);
  printf("The Secret Password is => %d\n", password_count);
  return 0;
}

void extract_from_line(char *line, bool *is_right, int *steps) {
  *steps = 0;
  if (*line == 'R')
    *is_right = true;
  else if (*line == 'L')
    *is_right = false;
  line++;

  while (*line >= '0' && *line <= '9') {
    *steps = (*steps * 10) + (*line - 48);
    line++;
  }
}
