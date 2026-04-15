#include <stdio.h>

int main() {
    int a, b;
    float c, d;

    // Input
    scanf("%d %d", &a, &b);
    scanf("%f %f", &c, &d);

    // Integer results
    printf("%d %d\n", a + b, a - b);

    // Float results (1 decimal place)
    printf("%.1f %.1f\n", c + d, c - d);

    return 0;
}
