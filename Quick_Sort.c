#include <stdio.h>

/* Simple Swap function */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
The partition sets the pivot element in its correct position, and all the elements on the right are greater
than all the elements on the left
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose the pivot element to be the last element
    int i = low - 1; // pointer 

    for (int j = low; j < high; j++) { // simple swap operations
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[i+1], &arr[high]); // swap the last element with the pivot (the element at i + 1)

    return i + 1; // return the index of the pivot
}

/*
Of course, quick sort uses recursion to sort an array, so in each step, we partition the array and 
split it into two subarrays (not including the pivot element). 
We keep repeating the same process until high <= low (the base case)
*/

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }   
}

// print the array
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[5] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The size of the array: %d\n", n);
    print(arr, n);

    printf("The partition of the array:\n");
    int pi = partition(arr, 0, n-1);

    print(arr, n);
    printf("And the pivot index is: %d\n", pi);
    QuickSort(arr, 0, n - 1);


    printf("Array after sorting:\n");
    print(arr, n);

    return 0;
}
