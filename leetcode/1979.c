int findGCD(int* nums, int numsSize) {
    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        min = min < nums[i] ? min : nums[i];
        max = max > nums[i] ? max : nums[i];
    }
    return gcd(min, max);
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}