int removeDuplicates(int* nums, int numsSize) {
    int k = 1, i = 0, j = 1;
    {
        while (j < numsSize) {
            if (nums[j] == nums[i]) {
                j++;
            } else {
                nums[i + 1] = nums[j];
                k++;
                i++;
                j++;
            }
        }
        return k;
    }
}