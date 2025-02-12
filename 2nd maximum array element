#include <stdio.h>
#include <limits.h>

void findSecondMax(int arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements.\n");
        return;
    }

    int max1 = INT_MIN, max2 = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max1) {  
            max2 = max1;  
            max1 = arr[i];  
        } else if (arr[i] > max2 && arr[i] < max1) {  
            max2 = arr[i];  
        }
    }

    if (max2 == INT_MIN)  
        printf("No second maximum found (all elements may be the same).\n");
    else  
        printf("The second maximum element is: %d\n", max2);
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    findSecondMax(arr, size);

    return 0;
}
