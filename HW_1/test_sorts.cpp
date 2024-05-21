#include "sorts.h"
#include "test_sorts.h"
#include <iostream>


int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
size_t size = sizeof(arr) / sizeof(arr[0]);

bool compareAscending(int a, int b) {
    return a < b;
}
// убывание
bool compareDescending(int a, int b) {
    return a > b;
}

void test_BubbleSort(){
    std::cout << "Test BubbleSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    BubbleSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_InsertionSort(){
    std::cout << "Test InsertionSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    InsertionSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_SelectionSort(){
    std::cout << "Test SelectionSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    SelectionSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_ShellSort(){
    std::cout << "Test ShellSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    ShellSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_CountSort(){
    std::cout << "Test CountSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    CountSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_QuickSort(){
    std::cout << "Test QuickSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    QuickSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_QuickSortMod(){
    std::cout << "Test QuickSortMod: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    QuickSortMod(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_MergeSort(){
    std::cout << "Test MergeSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    MergeSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_HeapSort(){
    std::cout << "Test HeapSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    HeapSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

void test_RadixSort(){
    std::cout << "Test RadixSort: ";

    int arr_copy[size];
    std::copy(arr, arr + size, arr_copy);

    RadixSort(arr_copy, size, compareAscending);

    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr_copy[i] > arr_copy[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR!!!" << std::endl;
    }
}

