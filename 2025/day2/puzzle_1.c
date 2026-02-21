#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_invalide(long long number);

int main(void) {
  FILE *file = fopen("puzzle_input_1.txt", "r");
  if (!file) {
    fprintf(stderr, "ERROR: Failed to open file!\n");
  }

  long long first_id = 0;
  long long last_id = 0;
  long long sum = 0;
  char c;
  while (fscanf(file, "%lld-%lld%c", &first_id, &last_id, &c) == 3) {
    for (long long i = first_id; i <= last_id; ++i) {
      if (is_invalide(i)) {
        sum += i;
      }
    }
  }
  fclose(file);
  printf("the result is -> %lld\n", sum);
  return 0;
}

bool is_invalide(long long number) {
  char str[20];
  sprintf(str, "%lld", number);
  int len = strlen(str);
  if (len % 2 != 0)
    return false;
  int half = len / 2;
  return strncmp(str, str + half, half) == 0;
}
