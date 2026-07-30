// Q2) Check if array is palindrome using recursion
#include <stdio.h>
# define max 30

int isPalindrome(int a[], int start, int end)
{
    if (start >= end)
        return 1;

    if (a[start] != a[end])
        return 0;

    return isPalindrome(a, start + 1, end - 1);
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[max];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (isPalindrome(a, 0, n - 1))
        printf("Array is Palindrome");
    else
        printf("Array is Not Palindrome");

    return 0;
}