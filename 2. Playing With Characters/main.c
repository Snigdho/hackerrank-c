// https://www.hackerrank.com/challenges/playing-with-characters/problem

#include <stdio.h>

int main()
{
    char s[100];

    scanf("%c", &s[0]); // s[0] = getchar(); // also works
    printf("%c\n", s[0]);

    scanf("%s", s);
    getchar();
    printf("%s\n", s);

    scanf("%[^\n]%*c", s);
    printf("%s", s);

    return 0;
}
