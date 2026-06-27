#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to manually sort the array in ascending order
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to find the length of the longest contiguous subsequence
int findLongestConseqSubseq(int arr[], int n) {
    int ans = 0, count = 0;

    // Sort the array
    bubbleSort(arr, n);

    // Array to store unique elements
    int temp[1000]; 
    int size = 0;

    // Insert only unique elements into temp[]
    temp[size++] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            temp[size++] = arr[i];
        }
    }

    // Find the maximum length of contiguous subsequence
    for (int i = 0; i < size; i++) {
        if (i > 0 && temp[i] == temp[i - 1] + 1) {
            count++; // Increment count if consecutive
        } else {
            count = 1; // Reset count if not consecutive
        }
        if (count > ans) {
            ans = count; // Update maximum length
        }
    }
    return ans;
}

// Driver code
int main() {
    int arr[] = {1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findLongestConseqSubseq(arr, n);
    printf("Length of the Longest contiguous subsequence is %d\n", result);

    return 0;
}
