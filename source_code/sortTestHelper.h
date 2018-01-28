//
// Created by hua on 18-1-27.
//

#ifndef ALGORITHMS_SORTTESTHELPER_H
#define ALGORITHMS_SORTTESTHELPER_H


#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace sortHelp {
    template<typename T>
    T *generateRandomArray(T n, T rangeL, T rangeR) {
        assert(rangeL < rangeR);
        int *arr = new int[n];

        srand(unsigned(time(NULL)));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

        return arr;
    }


    template<typename T>
    T *generateOrderedArray(T n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        for (int j = 0; j < swapTimes; j++) {
            int x = rand() % n;
            int y = rand() % n;
            swap(arr[x], arr[y]);
        }

        return arr;
    }

    template<typename T>
    void printArray(T a[], T n) {
        for (int i = 0; i < n; i++) {
            cout << " " << a[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    int *copyArray(T a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }


    bool is_sorted(int a[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }


    template<typename T>
    double testSort(void(*sort)(T[], int), T a[], int n) {

        T *a_copy = sortHelp::copyArray(a, n);

        clock_t startTime = clock();
        sort(a_copy, n);
        clock_t endTime = clock();

        assert(is_sorted(a_copy, n));

        delete[] a_copy;
        double run_time = double(endTime - startTime) / CLOCKS_PER_SEC;
        return run_time;
    }


}

#endif //ALGORITHMS_SORTTESTHELPER_H
