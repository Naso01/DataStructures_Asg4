#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
#endif // !SORTINGALGORITHMS_H

#include <iostream>
#include <vector>
#include "Student.h"

class SortingAlgorithms {
public:
    // Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order.
    static void bubbleSort(std::vector<Student>& arr) {
        int n = arr.size();

        bool swapped;
        // Outer loop to go through all elements
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            // Inner loop to compare adjacent elements
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j].GetGPA() > arr[j + 1].GetGPA()) {
                    std::swap(arr[j], arr[j + 1]);  // Swap if the element is greater
                    swapped = true;
                }
            }
            // If no elements were swapped in the inner loop, the array is already sorted
            if (!swapped) break;
        }
    }

    // Insertion Sort: Builds the sorted array one item at a time by moving elements to the right.
    static void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        // Loop over all elements starting from the second
        for (int i = 1; i < n; ++i) {
            int key = arr[i]; // The element to be inserted
            int j = i - 1;
            // Move elements of arr[0..i-1] that are greater than key to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;  // Insert the key in its correct position
        }
    }

    // Selection Sort: Selects the smallest element and swaps it with the first unsorted element.
    static void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        // Outer loop to select the minimum element from unsorted part
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            // Inner loop to find the smallest element in the unsorted part
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;  // Update the minimum element index
                }
            }
            std::swap(arr[i], arr[minIdx]);  // Swap with the first unsorted element
        }
    }

    // Merge Sort: Divide and conquer algorithm that divides the array into halves and merges them back.
    static void mergeSort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;
        std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
        std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());

        // Recursively sort both halves
        mergeSort(left);
        mergeSort(right);

        // Merge the sorted halves back into the original array
        merge(arr, left, right);
    }

    // Helper function to merge two sorted halves
    static void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;
        // Merge the two sorted halves into arr
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        // Copy any remaining elements from left
        while (i < left.size()) {
            arr[k++] = left[i++];
        }
        // Copy any remaining elements from right
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }

    // Quick Sort: Divide and conquer algorithm that selects a pivot and partitions the array.
    static void quickSort(std::vector<int>& arr) {
        quickSortHelper(arr, 0, arr.size() - 1);
    }

    // Helper function for quick sort
    static void quickSortHelper(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pi = partition(arr, low, high);
            // Recursively sort the two halves
            quickSortHelper(arr, low, pi - 1);
            quickSortHelper(arr, pi + 1, high);
        }
    }

    // Partition function for quick sort with lats element as pivot selection
    /*
    static int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];  // Choose the last element as pivot
        int i = low - 1;  // Pointer for the smaller element
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;  // Return the partition index
    }
    */
    // Partition function for quick sort with Median of Three pivot selection with different paradaign of partitioning
    /*
    static int partition(std::vector<int>& arr, int low, int high) {
        // Find the first, middle, and last elements
        int mid = low + (high - low) / 2;

        // Find the median of the three (first, middle, last)
        int pivotIndex;
        if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) {
            pivotIndex = mid;  // Middle is the median
        }
        else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) {
            pivotIndex = low;  // First is the median
        }
        else {
            pivotIndex = high;  // Last is the median
        }

        // Swap the pivot element with the last element
        std::swap(arr[pivotIndex], arr[high]);

        int pivot = arr[high];  // Choose the pivot as the last element (after swapping)
        int i = low - 1;  // Pointer for the smaller element

        // Partition the array
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }

        // Place the pivot in its correct position
        std::swap(arr[i + 1], arr[high]);

        return i + 1;  // Return the partition index
    }
     */

     // Partition function for quick sort with Median of Three pivot selection
     // the partitioning paradigm is similar to what we discussed in the classroom 
    static int partition(std::vector<int>& arr, int low, int high) {
        // Find the first, middle, and last elements
        int mid = low + (high - low) / 2;

        // Find the median of the three (first, middle, last)
        int pivotIndex;
        if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) {
            pivotIndex = mid;  // Middle is the median
        }
        else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) {
            pivotIndex = low;  // First is the median
        }
        else {
            pivotIndex = high;  // Last is the median
        }

        // Swap the pivot element with the last element
        std::swap(arr[pivotIndex], arr[high]);

        int pivot = arr[high];  // Pivot is the element at the last position (after swap)
        int i = low;  // Pointer for the smaller element
        int j = high - 1;  // Pointer for the larger element

        // Partition the array with two pointers
        while (i <= j) {
            // Move i to the right while arr[i] < pivot
            while (arr[i] < pivot) {
                ++i;
            }

            // Move j to the left while arr[j] > pivot
            while (arr[j] > pivot) {
                --j;
            }

            // If i and j haven't crossed, swap arr[i] and arr[j]
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }

        // Finally, place the pivot in its correct position (swap arr[i] and arr[high])
        std::swap(arr[i], arr[high]);

        return i;  // Return the partition index
    }


    // Utility function to print the array
    static void printArray(const std::vector<Student>& arr) {
        for (Student student : arr) {
            student.Display();
        }
    }
};