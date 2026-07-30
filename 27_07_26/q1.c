// Q1)WACP to find kth maximum in array (can't return duplicate number)

#include <stdio.h>
# define max 30
int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[max];
    printf("Enter array elements:\n ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);
   // Sort in descending 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int count = 1;
    int ans = a[0];

    if (k == 1) {
        printf("%d", a[0]);
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {   // Ignore duplicates
            count++;
            if (count == k) {
                ans = a[i];
                printf("%d", ans);
                return 0;
            }
        }
    }

    printf("Kth distinct maximum does not exist.");

    return 0;
}