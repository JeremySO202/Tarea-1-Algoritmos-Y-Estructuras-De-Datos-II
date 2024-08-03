#include <iostream>
#include <vector>
#include <algorithm> // para std::random_shuffle
#include <chrono>
#include <cstdlib>
#include <iterator>
#include <random>
#include "PagedArray.h"

using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int start, int end)
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

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main() {
    int n = 134217728;
    vector<int> arr(n);


    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }


    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);


    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    return 0;
}
