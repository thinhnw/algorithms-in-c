**Problem**: Find the Greatest Common Divisor (GCD) of 2 non-negative number `a` and `b`, denoted as:

`GCD(a, b) = d`

d is the largest number such that both `a mod d = 0` and `b mod d = 0`

**Observation:** if `u` is greater than `v` then the greatest common divisor of `u` and `v` is the same as the greatest common divisor of `v` and `u-v`

**Solution:**
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