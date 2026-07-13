int threeSumClosest(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize - 1; i++)
        for (int j = 0; j < numsSize - i - 1; j++)
            if (nums[j] > nums[j + 1]) {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
    int sum = 0, rs, l, r, dif, maxd = INT_MAX;
    for (int i = 0; i < numsSize - 2; i++) {
        l = i + 1;
        r = numsSize - 1;
        while (l < r) {
            sum = nums[i] + nums[l] + nums[r];

            dif = abs(sum - target);
            if (maxd > dif) {
                maxd = dif;
                rs = sum;
            }
            if (sum == target) {
                return sum;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    return rs;
}
