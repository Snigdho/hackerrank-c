// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b) { return strcmp(a, b); }

int lexicographic_sort_reverse(const char *a, const char *b) {
  return strcmp(b, a);
}

int count_distinct_chars(const char *s) {
  int freq[256] = {0};
  int count = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    unsigned char ch = s[i];
    if (freq[ch] == 0) {
      freq[ch] = 1;
      count++;
    }
  }

  return count;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
  int countA = count_distinct_chars(a);
  int countB = count_distinct_chars(b);

  if (countA != countB)
    return countA - countB;

  // tie-breaker: lexicographical order
  return strcmp(a, b);
}

int sort_by_length(const char *a, const char *b) {
  int lenA = strlen(a);
  int lenB = strlen(b);

  if (lenA != lenB)
    return lenA - lenB;

  // tie-breaker: lexicographical order
  return strcmp(a, b);
}

void string_sort(char **arr, const int len,
                 int (*cmp_func)(const char *a, const char *b)) {

  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {

      if (cmp_func(arr[i], arr[j]) > 0) {
        char *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  char **arr;
  arr = (char **)malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_length);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_number_of_distinct_characters);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");
}
