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

int search_max(char *line, int lowerb, int upperb,
               int *position) // sizes from 0 to n
{
  int max = 0;
  for (int i = lowerb; i <= upperb; ++i) {
    if (*(line + i) <= '9' && *(line + i) >= '0') {
      if (max < *(line + i)) {
        max = *(line + i);
        *position = i;
      }
    }
  }
  return max;
}

long long get_max(char *line) {
  int len = strlen(line);
  int first_pos = 0;
  int last_pos = len;
  int max_1 = 0, max_2 = 0;
  int max = 0;
  int position = 0;
  int pos[12] = {0};
  int pos_count = 0;
  if (len > 0 && line[len - 1] == '\n') {
    line[--len] = '\0';
  }

  if (len < 12)
    return 0;

  for (int i = 0; i < 12; ++i) {
    max = search_max(line, first_pos, last_pos, &position);
    if (position == len - 13 - i) {
      long long out = 0;
      for (int i = 0; i < 12 - count; ++i) {
        pos[i + first_pos] = *(line + first_pos + i + 48);
      }
      return out;
    }
    first_pos++;

    pos_count++
  }

  for (int i = first_pos; i < len; ++i) {
  }
  return (max_2 - 48 + 10 * (max_1 - 48));
}
