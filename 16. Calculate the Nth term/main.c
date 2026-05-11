// https://www.hackerrank.com/challenges/recursion-in-c/problem

#include <stdio.h>

// Complete the following function.

int find_nth_term(int n, int a, int b, int c) {

  // Base cases
  if (n == 1)
    return a;
  if (n == 2)
    return b;
  if (n == 3)
    return c;

  int next;

  // Generate terms from 4 to n
  for (int i = 4; i <= n; i++) {
    next = a + b + c;

    // Shift values forward
    a = b;
    b = c;
    c = next;
  }

  return c;
}

int main() {
  int n, a, b, c;

  scanf("%d %d %d %d", &n, &a, &b, &c);
  int ans = find_nth_term(n, a, b, c);

  printf("%d", ans);
  return 0;
}
