#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

// for quick sort
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// for quick sort
int partition(Record *arr, int low, int high) {

    int pivot = arr[high].idNumber; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].idNumber < pivot) {
            i++;

            Record temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Record temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
        
    return (i + 1);
}


void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
    
    Record key;

    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].idNumber > key.idNumber) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.


    for (int i = 0; i < n - 1; i++) {

        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].idNumber < arr[min_idx].idNumber) {
                min_idx = j;
            }
        }    

        Record temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

    }
}

void mergeSort(Record *arr, int p, int r)
{
    // TODO: Implement this sorting algorithm here.






}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/

void quickSort (Record *arr, int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}


#endif