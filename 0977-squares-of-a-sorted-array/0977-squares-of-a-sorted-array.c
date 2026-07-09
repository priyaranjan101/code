/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* n = (int*)malloc(numsSize * sizeof(int));
    int* m = (int*)malloc(numsSize * sizeof(int));
    int p = 0, q = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            n[p] = nums[i];
            p++;

        } else {
            m[q] = nums[i];
            q++;
        }
    }
    for (int i = 0; i < p; i++) {
        n[i] = n[i] * n[i];
    }
        for (int i = 0; i < p - 1; i++) {
            for (int j = i + 1; j < p; j++) {
                if (n[i] > n[j]) {
                    int temp = n[i];
                    n[i] = n[j];
                    n[j] = temp;
                }
            }
        }
    
    for (int i = 0; i < q; i++) {
        m[i] = m[i] * m[i];
    }
    int* d = (int*)malloc((p + q) * sizeof(int));
    int x = 0, y = 0, k = 0;

    while (x < p && y < q) {
        if (n[x] < m[y])
            d[k++] = n[x++];
        else
            d[k++] = m[y++];
    }

    while (x < p)
        d[k++] = n[x++];

    while (y < q)
        d[k++] = m[y++];

    free(n);
    free(m);
    *returnSize = numsSize;
    return d;
}