#include <stdio.h>

int binary_search(int a[], int lower_bound, int upper_bound, int val) {
    int beg = lower_bound, end = upper_bound, pos = -1;
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (a[mid] == val) {
            pos = mid;
            printf("%d", pos);
            break;
        }
        else if (a[mid] > val) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
    }
    if (pos == -1) {
        printf("Value is not present in the array");
    }
    return pos;
}

int main() {
    int n, val;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &val);
    binary_search(a, 0, n-1, val);
    return 0;
}

