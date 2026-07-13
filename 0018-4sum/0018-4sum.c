/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize,
              int** returnColumnSizes) {

    int i,j;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = 0; j < numsSize - i - 1; j++) {
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
    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int L = j + 1;
            int R = numsSize - 1;
            

            while (L < R) {
                long long sum = (long long)nums[i] +
                nums[j] +
                nums[L] +
                nums[R];

                if (sum == target) {
                      result[*returnSize] = (int*)malloc(4 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[L];
                result[*returnSize][3] = nums[R];

                (*returnColumnSizes)[*returnSize] = 4;
                (*returnSize)++;

                    L++;
                    R--;

                    while (L < R && nums[L] == nums[L - 1])
                        L++;

                    while (L < R && nums[R] == nums[R + 1])
                        R--;
                } else if (sum < target) {
                    L++;
                } else {
                    R--;
                }
            }
        }
    }
    return result;
}