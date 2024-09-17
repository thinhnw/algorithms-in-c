**Problem**: Find the Greatest Common Divisor (GCD) of 2 non-negative number `a` and `b`, denoted as:

`GCD(a, b) = d`

d is the largest number such that both `a mod d = 0` and `b mod d = 0`

**Observation:** if `u` is greater than `v` then the greatest common divisor of `u` and `v` is the same as the greatest common divisor of `v` and `u-v`

**Implementation:**
```c
#include <stdio.h>
int gcd(int u, int v) {
    int t;
    while (u > 0) {
        if (u < v) {
            t = u;
            u = v;
            v = t;
        }
        u = u - v;
    }
    return v;
}
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > 0 && y > 0)
        printf("%d\n", gcd(x, y));
    return 0;
}
```

Because `a` remains to be greater than `b` until `a` becomes `a mod b`. Therefore we have better implementation
```c
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
```


**Time complexity:**

By observation, `a mod b` for `a >= b` is at least 2 times smaller than `a`, so the larger number is reduced at least in half for each iteration.

We can estimate the algorithm works in `O(log min(a,b))`