/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0, j = numbersSize - 1, m;
    int* ans = malloc(2 * sizeof(int));
    *returnSize=2;
    
    while (i <= j) {
        m = numbers[i] + numbers[j];
        if (m == target){
        ans[0]=i+1;
        ans[1]=j+1;
            return ans;
    }
        if (m > target)
            j--;
        else
            i++;
    }
    return NULL;
}