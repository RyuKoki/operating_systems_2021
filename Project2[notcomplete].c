#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void swap(int *high, int *low) {
	// BUFFER is for saving high value
	int buffer = *high;
	// get swap high to low
	*high = *low;
	// get swap low to high[buffer array]
	*low = buffer;
} 

void arr_sort(int arr[], int ele) {
	//////////// BUBBLE SORT /////////////
	int i, j;
	for ( i=0; i < ele-1; i++ ) {
		for ( j=0; j < ele-i-1; j++ ) {
			// check if next value is lower than provious
			if ( arr[j] > arr[j+1] ) {
				// swap them
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void print_arr(int arr[], int arr_size) {
	int i;
	for ( i = 0; i < arr_size; i++ ) {
		printf("%d, ", arr[i]);
	}
}

int main() {
	// define example array
	int arr[] = {5, 3, 2, 1, 9, 8};
	// arr_sort(arr, n);
	// print_arr(arr, n);
	// get numbers of all elements in array
	int len_arr = sizeof(arr)/sizeof(arr[0]);
	// get index of middle array
	int middle_arr = len_arr / 2;
	// set number of first array
	int arr1[middle_arr];
	int len_arr1 = sizeof(arr1)/sizeof(arr1[0]);
	// set number of second array
	int arr2[len_arr - middle_arr];
	int len_arr2 = sizeof(arr2)/sizeof(arr2[0]);
	// separate all of array to first and second empty
	int i;
	for ( i=0; i<len_arr1; i++ ) {
		arr1[i] = arr[i];
	} 
	for ( i=0; i<len_arr2; i++ ) {
		arr2[i] = arr[i+middle_arr];
	}
	// sorting part
	arr_sort(arr1, len_arr1);
	arr_sort(arr2, len_arr2);
	print_arr(arr1, len_arr1);
	print_arr(arr2, len_arr2);
}

