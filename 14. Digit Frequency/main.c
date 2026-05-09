// https://www.hackerrank.com/challenges/frequency-of-digits-1/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *s;
  s = malloc(1001 * sizeof(char));
  scanf("%[^\n]", s);
  s = realloc(s, strlen(s) + 1);

  int arr[10] = {0};

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      arr[s[i] - '0']++;
    }
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
