#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long pick_max_12(char *line) {
  int len = strlen(line);
  if (line[len - 1] == '\n')
    line[--len] = '\0';
  if (len < 12)
    return 0; // not enough digits

  char result[13]; // 12 digits + null
  int pos = 0;     // where to place next digit
  int start = 0;
  int to_pick = 12;

  while (to_pick > 0) {
    // search for max digit in range [start, len - to_pick]
    int max_digit = -1;
    int max_index = -1;
    for (int i = start; i <= len - to_pick; i++) {
      if (line[i] - '0' > max_digit) {
        max_digit = line[i] - '0';
        max_index = i;
      }
    }
    result[pos++] = line[max_index];
    start = max_index + 1;
    to_pick--;
  }
  result[12] = '\0';

  // convert to long long
  return strtoll(result, NULL, 10);
}

int main(void) {
  FILE *file = fopen("puzzle_input_1.txt", "r");
  if (!file)
    return 1;

  long long total = 0;
  char line[10000];

  while (fgets(line, sizeof(line), file)) {
    total += pick_max_12(line);
  }

  fclose(file);
  printf("Total output joltage: %lld\n", total);
  return 0;
}
