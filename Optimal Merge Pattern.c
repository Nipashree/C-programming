#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Min Heap operations
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}

void insertHeap(int arr[], int *n, int key) {
    int i = (*n)++;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int optimalMergePattern(int files[], int n) {
    int totalCost = 0;

    buildMinHeap(files, n);

    while (n > 1) {
        int first = extractMin(files, &n);
        int second = extractMin(files, &n);
        int cost = first + second;

        totalCost += cost;
        insertHeap(files, &n, cost);
    }

    return totalCost;
}

int main() {
    int n, files[MAX];

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter sizes of files:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int minCost = optimalMergePattern(files, n);
    printf("Minimum total computation cost: %d\n", minCost);

    return 0;
}
