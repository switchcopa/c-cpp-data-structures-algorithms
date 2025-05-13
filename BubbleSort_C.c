#include <stdio.h>

int* swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return a, b;
}

/*
So here's what we're going to do in this bubble sort algorithm: 
we're going to iterate from the range 0 to n (the length of the array)
Let's take int i to be that index
** this is going to be our outer loop 
And for our inner loop, we're going to iterate from i+1 to n, so this is going to be n - i + 1 times
then we're going to compare 
*/

int* bubble_sort(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }

    return arr;
}

int main() {
    int arr[7] = {2,7,3,1,9,4,8};
    printf("Unsorted array:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, 7);

    printf("Sorted array:\n");
    for (int i = 0; i < 7; i++){ 
        printf("%d ", arr[i]);
    }

    return 0;
}   
