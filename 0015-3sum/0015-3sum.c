/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int capacity = numsSize * numsSize;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;
        int r = numsSize - 1;
        int target = -nums[i];

        while (l < r) {

            int sum = nums[l] + nums[r];

            if (sum == target) {

                result[*returnSize] = (int*)malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[l];
                result[*returnSize][2] = nums[r];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                l++;
                r--;

                while (l < r && nums[l] == nums[l - 1])
                    l++;

                while (l < r && nums[r] == nums[r + 1])
                    r--;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    return result;
}