/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    int* a = (int*)malloc(numsSize * sizeof(int));
    int* b = (int*)malloc(numsSize * sizeof(int));
    int p = 0, q = 0, i=0, temp;
    while (i < numsSize) {
        if (nums[i] < 0){
            a[p] = nums[i]; i++;
        p++;}
        else {
            b[q] = nums[i]; i++;
            q++;
        }
    }
    for (int i = 0; i < q; i++) {
        b[i] = b[i] * b[i];
    }
    for (int i = 0; i < p; i++) {
        a[i] = a[i] * a[i];
    }
    for (int i = 0; i < p - 1; i++) {

        for (int j = 0; j < p - i - 1; j++) {

            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    

    int* c = (int*)malloc((p + q) * sizeof(int));
    int x = 0, y = 0, k = 0;
    while (x < p && y < q) {
        if (a[x] < b[y])
            c[k++] = a[x++];

        else
            c[k++] = b[y++];
    }
    while (x< p) {
        c[k++] = a[x++];
    }
    while (y< q) {
        c[k++] = b[y++];
    }

* returnSize = numsSize;
free(a);
free(b);
return c;
}