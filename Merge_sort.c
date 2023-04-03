#include <stdio.h>

void merge(int arr[], int beg, int mid, int end) {
    int left[100], right[100];
    int n1 = mid - beg + 1;
	int n2 = end - mid;
    int i, j, k;

    for (i = 0; i < n1; i++)
        left[i] = arr[beg + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    i = j = 0;
    k = beg;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void merge_sort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    int n, i;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    printf("Sorted array is \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]); 

    return 0;
}


/*
The program contains two functions: merge_sort and merge.

The merge_sort function is a recursive function that divides the input array into two halves,
sorts each half recursively using the same function, and finally merges the two sorted halves.
The base case of the recursion is when the subarray has only one element, which is considered to be already sorted.

The merge function is used to merge the two sorted subarrays into a single sorted array. 
The function takes three parameters: the array, the start index, and the end index of the subarray to be merged.
The function first creates two arrays left and right to store the elements of the two subarrays.
the left array stores the elements from the start to the mid index, and the right array stores the elements from the mid + 1 to the end index.
The function then merges the elements of the left and right arrays into the original array in a sorted manner.

Finally, the main function takes the input from the user, calls the merge_sort function to sort the input array,
and prints the sorted array.



*/
