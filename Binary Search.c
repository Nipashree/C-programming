#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoids overflow

        if (arr[mid] == target)
            return mid;  // Target found, return index
        else if (arr[mid] < target)
            low = mid + 1;  // Search right half
        else
            high = mid - 1;  // Search left half
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
