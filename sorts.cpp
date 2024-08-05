#include <iostream>
#include "PagedArray.h"

using namespace std;

int partition(PagedArray &arr, int start, int end)
{
    int pivot = arr[start];
    int low = start + 1;
    int high = end;

    while (true) {
        while (low <= high && arr[low] <= pivot) {
            low++;
        }
        while (low <= high && arr[high] > pivot) {
            high--;
        }
        if (low > high) {
            break;
        }
        swap(arr[low], arr[high]);
    }
    swap(arr[start], arr[high]);
    return high;
}

void quickSort(PagedArray &arr, int start, int end)
{
    if (start >= end) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void insertionSort(PagedArray &arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(PagedArray &arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}