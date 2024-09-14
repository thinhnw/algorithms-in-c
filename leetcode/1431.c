#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies,
                      int *returnSize) {
    *returnSize = candiesSize;
    bool *output = (bool *)malloc(*returnSize * sizeof(bool));

    int max = 0;
    for (int i = 0; i < candiesSize; ++i)
        max = candies[i] > max ? candies[i] : max;

    for (int i = 0; i < candiesSize; ++i)
        output[i] = candies[i] + extraCandies >= max;
    return output;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int extraCandies = 3;
    int returnSize;

    bool *result =
        kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    printf("Result:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("candies[%d] + extraCandies >= max: %s\n", i,
               result[i] ? "true" : "false");
    }

    // Free allocated memory
    free(result);

    return 0;
}