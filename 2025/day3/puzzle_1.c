#include <stdio.h>
#include <string.h>

long long get_max(char *line);

int main(void) {
  FILE *file = fopen("puzzle_input_1.txt", "r");
  if (!file)
    return 1;
  long long sum = 0;
  char line[10000];
  while (fgets(line, sizeof(line), file)) {
    sum += get_max(line);
  }

  printf("the result is ~> %lld\n", sum);
  return 0;
}

long long get_max(char *line) {
  int len = strlen(line);
  int first_pos = 0;
  int last_pos = 0;
  int max_1 = 0, max_2 = 0;
  if (len > 0 && line[len - 1] == '\n') {
    line[--len] = '\0';
  }
  if (len < 2)
    return 0;
  for (int i = 0; i < len - 1; i++) {
    if (*(line + i) <= '9' && *(line + i) >= '0') {
      if (max_1 < *(line + i)) {
        max_1 = *(line + i);
        first_pos = i;
      }
    }
  }

  for (int i = len - 1; i > first_pos; --i) {
    if (*(line + i) <= '9' && *(line + i) >= '0') {
      if (max_2 < *(line + i)) {
        max_2 = *(line + i);
      }
    }
  }
  return (max_2 - 48 + 10 * (max_1 - 48));
}
