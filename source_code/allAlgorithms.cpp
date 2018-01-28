//
// Created by hua on 18-1-27.
//

#include "allAlgorithms.h"


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) swap(arr[i], arr[min]);
    }
}


// ============================================================


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = true;
            }
        }
        if (flag == false) {
            return;
        }
    }
}


// ============================================================


void insertSort(int a[], int n) {
    int i, j = 0;
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            int cc = a[i];
            for (j = i - 1; cc < a[j]; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = cc;
        }
    }
}

// ============================================================



void shellSort(int a[], int n) {
    int i, j = 0;
    for (int dk = n / 2; dk >= 1; dk = dk / 2) {
        for (i = dk; i <= n; i++) {
            if (a[i] < a[i - dk]) {
                int cc = a[i];
                for (j = i - dk; j >= 0 && cc < a[j]; j -= dk)
                    a[j + dk] = a[j];
                a[j + dk] = cc;
            }
        }
    }
}

// ============================================================

int partition(int a[], int low, int high)
{
    // low是序列第一个元素的下标号，high是最后一个元素的下标号。
    // 比如数组a = {1,2,3} 那么 low==0  high==2
    // 取序列中间的元素作为基准元素，可以提高对有序序列的排序速度，
    // 原理是尽量选中间值作为递归树的根节点，可以使得递归树的高度尽量降低
    int pivot = a[(low+high)/2];
    while (low < high) {
        while (low<high && a[high] >= pivot) { high--; }
        a[low] = a[high];
        while (low<high && a[low] <= pivot) { low++; }
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void _quickSort(int a[], int low, int high)
{
    if (low<high)
    {
        int pivotpos = partition(a, low, high);
        _quickSort(a, low, pivotpos - 1);
        _quickSort(a, pivotpos + 1, high);
    }
}

void quickSort(int a[], int n)
{
    _quickSort(a, 0, n - 1);
}

// ============================================================

//把无序的数组归并为有序数组
//需要一个辅助数组。
int* b = new int[100001];
void merge(int a[], int low, int mid, int high)
{
    for (int t = low; t <= high; t++)
    {
        b[t] = a[t];
    }

    int i, j, k = 0;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (b[i]<b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }

    while (i <= mid) a[k++] = b[i++];
    while (j <= high) a[k++] = b[j++];
}

//递归分割数组之后，再调用merge函数进行排序并且合并。
void _mergeSort(int a[], int low, int high)
{
    if (low<high)
    {
        int mid = (low + high) / 2;
        _mergeSort(a, low, mid);
        _mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

//这函数仅仅是为了封装一个统一的接口。
//以便调用sort_test_help.h中的测试函数。
void mergeSort(int a[], int n)
{
    _mergeSort(a, 0, n - 1);
}