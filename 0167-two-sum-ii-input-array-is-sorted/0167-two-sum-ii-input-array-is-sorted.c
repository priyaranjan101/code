/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0, j = numbersSize - 1,sum;
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    while (i < j) {
        sum = numbers[i] + numbers[j];
        if (sum == target) {
            result[0] = i+1;
            result[1] = j+1;
            return result;
        }
        if (sum < target) {
            i++;
        } 
        else {
            j--;
        }
    }
    return NULL;
    
}