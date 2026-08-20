int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 2, k = 2;
    if(numsSize<=2)
    return numsSize;

    while (j < numsSize) {
        if (nums[j] == nums[i])
            j++;
        else {
            nums[k++] = nums[j];
           
            i++;
            j++;
        }
    }
    return k;
}