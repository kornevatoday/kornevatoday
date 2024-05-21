#include "sorts.h"
#include <algorithm>

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int)) {
    bool swapped;
    for (size_t i = 0; i < size - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (comp(ar[j], ar[j + 1])) {
                std::swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void InsertionSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t i = 1; i < size; i++) {
        int key = ar[i];
        size_t j = i;
        while (j > 0 && comp(ar[j - 1], key)) {
            ar[j] = ar[j - 1];
            j--;
        }
        ar[j] = key;
    }
}

void SelectionSort(int* ar, size_t size, bool (*comp)(int, int)) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t max_idx = i;
        for (size_t j = i + 1; j < size; j++) {
            if (!comp(ar[max_idx], ar[j])) {
                max_idx = j;
            }
        }
        std::swap(ar[i], ar[max_idx]);
    }
}

void ShellSort(int* ar, size_t size, bool (*comp)(int, int)) {
    std::vector<size_t> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
    for (size_t gap : gaps) {
        for (size_t i = gap; i < size; i++) {
            int temp = ar[i];
            size_t j = i;
            while (j >= gap && comp(ar[j - gap], temp)) {
                ar[j] = ar[j - gap];
                j -= gap;
            }
            ar[j] = temp;
        }
    }
}
void CountSort(int* ar, size_t size, bool (*comp)(int, int)) {
    // This implementation uses a vector of pairs to store the count and the original value
    // It's useful when the input array is large and the range of integers is small
    std::vector<std::pair<int, int>> count(100, {0, 0});
    for (size_t i = 0; i < size; i++) {
        count[ar[i]].first++;
        count[ar[i]].second = ar[i];
    }
    for (size_t i = 1; i < 100; i++) {
        count[i].first += count[i - 1].first;
    }
    std::vector<int> output(size);
    for (size_t i = 0; i < size; i++) {
        output[count[ar[i]].first - 1] = count[ar[i]].second;
        count[ar[i]].first--;
    }
    for (size_t i = 0; i < size; i++) {
        ar[i] = output[i];
    }
}

// QuickSort
void QuickSort(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size <= 1)
        return;

    size_t pivotIndex = size / 2;
    int pivotValue = ar[pivotIndex];

    size_t leftSize = 0;
    for (size_t i = 0; i < size; ++i) {
        if (i == pivotIndex) {
            continue;
        }
        if (comp(ar[i], pivotValue)) {
            std::swap(ar[i], ar[leftSize]);
            ++leftSize;
        }
    }

    std::swap(ar[pivotIndex], ar[leftSize]);
    QuickSort(ar, leftSize, comp);
    QuickSort(ar + leftSize + 1, size - leftSize - 1, comp);
}

// QuickSortMod
void QuickSortMod(int* ar, size_t size, bool (*comp)(int, int)) {
    // This function is not well-defined.
    // QuickSortMod could mean a modified QuickSort with a different pivot selection strategy,
    // in which case, the implementation would depend on the specific strategy.
    // Please provide more details.
}

// MergeSort
void Merge(int* ar, size_t left, size_t mid, size_t right, bool (*comp)(int, int)) {
    int* temp = new int[right - left + 1];
    size_t i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (comp(ar[i], ar[j])) {
            temp[k++] = ar[i++];
        } else {
            temp[k++] = ar[j++];
        }
    }

    while (i <= mid)
        temp[k++] = ar[i++];

    while (j <= right)
        temp[k++] = ar[j++];

    for (i = left; i <= right; ++i)
        ar[i] = temp[i - left];

    delete[] temp;
}

void MergeSort(int* ar, size_t size, bool (*comp)(int, int)) {
    if (size <= 1)
        return;

    size_t mid = size / 2;
    MergeSort(ar, mid, comp);
    MergeSort(ar + mid, size - mid, comp);
    Merge(ar, 0, mid, size - 1, comp);
}

// HeapSort
void HeapSort(int* ar, size_t size, bool (*comp)(int, int)) {
    // Build a max heap
    for (size_t i = size / 2; i > 0; --i) {
        size_t index = i;
        size_t largest = index;
        size_t left = 2 * index;
        size_t right = 2 * index + 1;

        if (left <= size && !comp(ar[largest], ar[left])) {
            largest = left;
        }

        if (right <= size && !comp(ar[largest], ar[right])) {
            largest = right;
        }

        if (largest != index) {
            std::swap(ar[index], ar[largest]);

            index = largest;
            left = 2 * index;
            right = 2 * index + 1;

            while (left <= size) {
                largest = index;

                if (left <= size && !comp(ar[largest], ar[left])) {
                    largest = left;
                }

                if (right <= size && !comp(ar[largest], ar[right])) {
                    largest = right;
                }

                if (largest == index) {
                    break;
                }

                std::swap(ar[index], ar[largest]);

                index = largest;
                left = 2 * index;
                right = 2 * index + 1;
            }
        }
    }
    for (size_t i = size; i > 1; --i) {
        std::swap(ar[1], ar[i]);

        size_t index = 1;
        size_t largest = index;
        size_t left = 2 * index;
        size_t right = 2 * index + 1;

        if (left <= i - 1 && !comp(ar[largest], ar[left])) {
            largest = left;
        }

        if (right <= i - 1 && !comp(ar[largest], ar[right])) {
            largest = right;
        }

        if (largest != index) {
            std::swap(ar[index], ar[largest]);

            index = largest;
            left = 2 * index;
            right = 2 * index + 1;

            while (left <= i - 1) {
                largest = index;

                if (left <= i - 1 && !comp(ar[largest], ar[left])) {
                    largest = left;
                }

                if (right <= i - 1 && !comp(ar[largest], ar[right])) {
                    largest = right;
                }

                if (largest == index) {
                    break;
                }

                std::swap(ar[index], ar[largest]);

                index = largest;
                left = 2 * index;
                right = 2 * index + 1;
            }
        }
    }
}


void RadixSort(int* ar, size_t size, bool (*comp)(int, int)) {
    // Find the maximum element in the array
    int maxElement = ar[0];
    for (size_t i = 1; i < size; ++i) {
        if (comp(ar[i], maxElement)) {
            maxElement = ar[i];
        }
    }

    // Sort the elements by each digit, starting from the least significant digit
    for (int exp = 1; maxElement/exp > 0; exp *= 10) {
        int* count = new int[10]();
        int* output = new int[size];

        for (size_t i = 0; i < size; ++i) {
            int digit = (ar[i]/exp)%10;
            if (comp(digit, 0)) {
                count[0]++;
            } else {
                count[digit]++;
            }
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i-1];
        }

        for (int i = size-1; i >= 0; --i) {
            int digit = (ar[i]/exp)%10;
            if (comp(digit, 0)) {
                output[count[0]-1] = ar[i];
                count[0]--;
            } else {
                output[count[digit]-1] = ar[i];
                count[digit]--;
            }
        }

        std::copy(output, output + size, ar);

        delete[] count;
        delete[] output;
    }
}

