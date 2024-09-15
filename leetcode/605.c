#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize && n > 0; ++i) {
        if (flowerbed[i])
            continue;
        if (i > 0 && flowerbed[i - 1])
            continue;
        if (i < flowerbedSize - 1 && flowerbed[i + 1])
            continue;
        flowerbed[i] = 1;
        n--;
    }
    return n == 0;
}

int main() {
    int flowerbed[] = {1, 0, 0, 0, 0, 1};
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    int n = 2;
    printf("%s\n", canPlaceFlowers(&flowerbed, flowerbedSize, n) ? "true" : "false");
    return 0;
}