**Problem:** Find all prime numbers in range `[1;n]`

**Aproach:**

For each number `i`, mark its multiples as non prime

**Complexity:** 
- Time complexity: `O(n * log log n)`
- Space complexity: `O(n)`

**Implementation:**
```c
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
```

**Sieving till root:** 

Only perform sifting on prime number `i` where `i < sqrt(n)`, since if `i` is not prime, the array elements corresponding
to all of its multiples must already have been marked.

Such optimization doesn't affect complexity, but does reduce the number of operations noticeably

```c
for (int i = 0; i <= N; ++i)
    is_prime[i] = 1;

is_prime[1] = 0;

for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
        for (int j = i * i; j <= N; j += i) 
            is_prime[j] = 0;
    }
}
```