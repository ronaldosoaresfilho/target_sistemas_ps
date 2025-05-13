#include <stdio.h>

int isFib(int n)
{
    int a = 0, b = 1;
    int temp;

    while (b < n) {
        temp = b;
        b = a + b;
        a = temp;
    }
    return (b == n || n == 0);
}

int main(void)
{
    int n = 34;

    if (isFib(n)) {
        printf("Is Fibonacci.\n");
    }else {
        printf("Not a Fibonacci.\n");
    }
    return 0;
}
