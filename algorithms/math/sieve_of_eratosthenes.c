#include <stdio.h>
#define N 1000
int main() {
    int is_prime[N + 1];
    is_prime[1] = 0;
    for (int i = 2; i < N; ++i)
        is_prime[i] = 1;

    for (int i = 2; i <= N / 2; ++i)
        for (int j = 2; j <= N / i; ++j)
            is_prime[i * j] = 0;

    for (int i = 1; i < N; ++i)
        if (is_prime[i])
            printf("%4d", i);
    printf("\n");

    return 0;
}