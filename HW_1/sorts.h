#ifndef SORTS_H
#define SORTS_H

#include <functional>

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int));
void InsertionSort(int* ar, size_t size, bool (*comp)(int, int));
void SelectionSort(int* ar, size_t size, bool (*comp)(int, int));
void ShellSort(int* ar, size_t size, bool (*comp)(int, int));
void CountSort(int* ar, size_t size, bool (*comp)(int, int));
void QuickSort(int* ar, size_t size, bool (*comp)(int, int));
void QuickSortMod(int* ar, size_t size, bool (*comp)(int, int));
void MergeSort(int* ar, size_t size, bool (*comp)(int, int));
void HeapSort(int* ar, size_t size, bool (*comp)(int, int));
void RadixSort(int* ar, size_t size, bool (*comp)(int, int));

#endif // SORTS_HH
