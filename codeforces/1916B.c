#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        if (b % a == 0) {
            printf("%d\n", b * (int)(b / a));
        } else {
            printf("%d\n", lcm(a, b));
        }
    }
    return 0;
}