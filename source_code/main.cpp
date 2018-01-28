#include "sortTestHelper.h"
#include "allAlgorithms.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ofstream fcout("./sort-result.csv");
    fcout << "排序算法,无序数组,近乎有序的数组" << endl;

    int n = 30000;
    int *arr_disorderly = sortHelp::generateRandomArray(n, 1, n);
    int *arr_ordered = sortHelp::generateOrderedArray(n, n / 100);

    double insert_time_d = sortHelp::testSort(insertSort, arr_disorderly, n);
    double insert_time_o = sortHelp::testSort(insertSort, arr_ordered, n);
    fcout << "插入排序," << insert_time_d << "s," << insert_time_o << "s" << endl;


    double select_time_d = sortHelp::testSort(selectionSort, arr_disorderly, n);
    double select_time_o = sortHelp::testSort(selectionSort, arr_ordered, n);
    fcout << "简单选择排序," << select_time_d << "s," << select_time_o << "s" << endl;


    double bubble_time_d = sortHelp::testSort(bubbleSort, arr_disorderly, n);
    double bubble_time_o = sortHelp::testSort(bubbleSort, arr_ordered, n);
    fcout << "冒泡排序," << bubble_time_d << "s," << bubble_time_o << "s" << endl;


    double shell_time_d = sortHelp::testSort(shellSort, arr_disorderly, n);
    double shell_time_o = sortHelp::testSort(shellSort, arr_ordered, n);
    fcout << "希尔排序," << shell_time_d << "s," << shell_time_o << "s" << endl;

    double quick_time_d = sortHelp::testSort(quickSort, arr_disorderly, n);
    double quick_time_o = sortHelp::testSort(quickSort, arr_ordered, n);
    fcout << "快速排序," << quick_time_d << "s," << quick_time_o << "s" << endl;

    double merge_time_d = sortHelp::testSort(mergeSort, arr_disorderly, n);
    double merge_time_o = sortHelp::testSort(mergeSort, arr_ordered, n);
    fcout << "归并排序," << merge_time_d << "s," << merge_time_o << "s" << endl;

    delete[] arr_disorderly;
    delete[] arr_ordered;

    fcout.close();
    cout << "所有数据已经写入文件，请到桌面查看" << endl;
}