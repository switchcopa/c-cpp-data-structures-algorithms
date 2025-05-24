
#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[i + 1], &arr[right]);

    return i + 1;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

bool linear_scan(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }

    return true;
}

int binary_search(int arr[], int target, int left, int right)
{

    if (arr[left] == target)
        return left;
    if (arr[right] == target)
        return right;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {2,11,7,3,5,9,17,23,69,404,1,0,-11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    print(arr, n);
    printf("Sorting the array\n");
    quickSort(arr, 0, n - 1);
    printf("Sorted!\n");
    printf("Target element: %d\n", target);
    print(arr, n);

    int index = binary_search(arr, target, 0, n - 1);

    if (index != -1)
    {
        printf("Index found: %d\n", index);
    }
    else
    {
        printf("target element not found\n");
    }

    return 0;
}
