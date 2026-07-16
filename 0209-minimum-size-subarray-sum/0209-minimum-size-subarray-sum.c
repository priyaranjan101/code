int minSubArrayLen(int target, int* nums, int numsSize) {
    int l = 0, h = 0, res = INT_MAX, len, sum = 0;

    while (h < numsSize) {
        sum = sum + nums[h];
        while (sum >= target) {
            int len = h - l + 1;
            if (res > len) {
                res = len;
            }
            sum = sum - nums[l];
            l++;
        }
        h++;
    }
    if (res ==INT_MAX)
        return 0; else return res;
}