#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
// this function will take char* point to line from file input
// e.g : R384 , and return if it has R or L and number of steps in rotation
int extract_signed_steps(char *line);
int main(void) {

  FILE *file = fopen("puzzle_input_1.txt", "r");
  if (!file) {
    fprintf(stderr, "ERROR: Opening file failed!\n");
    return 1;
  }

  int password_count = 0;
  int dial_point_to = 50;
  char line[32];
  int steps = 0;
  while (fgets(line, 32, file)) {

    steps = extract_signed_steps(line);

    if (steps > 0) {
      for (int i = 1; i <= steps; i++) {
        dial_point_to += 1;
        if (dial_point_to > 99) {
          password_count++;
          dial_point_to = 0;
        }
      }
    } else if (steps < 0) {
      for (int i = 1; i <= -steps; i++) {
        dial_point_to -= 1;
        if (dial_point_to < 0) {
          dial_point_to = 99;
        }
        if (dial_point_to == 0)
          password_count++;
      }
    }
  }
  fclose(file);
  printf("The Secret Password is => %d\n", password_count);
  return 0;
}

int extract_signed_steps(char *line) {
  bool is_right;
  int steps = 0;
  if (*line == 'R')
    is_right = true;
  else if (*line == 'L')
    is_right = false;

  line++;

  while (*line >= '0' && *line <= '9') {
    steps = (steps * 10) + (*line - 48);
    line++;
  }
  if (!is_right)
    return -steps;
  return steps;
}
