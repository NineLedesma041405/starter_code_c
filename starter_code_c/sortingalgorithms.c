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

// for merge sort
void merge(Record *arr, int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    Record L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i].idNumber <= R[j].idNumber)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(Record *arr, int p, int r)
{
    // TODO: Implement this sorting algorithm here.

    if (p < r)
        {
            int q = (p + r) / 2;
            mergeSort(arr, p, q);
            mergeSort(arr, q + 1, r);
            merge(arr, p, q, r);
        }
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
