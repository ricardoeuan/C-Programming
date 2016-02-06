//
//  selection_sort.c
//
//  Created by Ricardo Euán Romo on 20/09/13.
//  Copyright (c) 2013 Ricardo. All rights reserved.
//
#include <stdio.h>

#define N 10

void selection_sort(int a[], int size);

int main(void)
{
	int array[N];
	int i;

	printf("Enter %d numbers to be sorted: ", N);
	for(i=0; i<N; i++)
		scanf("%d", &array[i]);

	printf("\nOriginal array:\n");
	for(i=0; i<10; i++)
	{
		printf("%d ", array[i]);
	}	
	selection_sort(array, 10);
	printf("\nSorted array:\n");
	for(i=0; i<10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}

void selection_sort(int a[], int size)
{
	int i;
	int counter;
	int high_index = 0;
	int b;
	for(counter = size; counter > 1; counter--)	
	{
		for(i = 0; i< counter; i++)
		high_index = a[i] > a[high_index] ? i : high_index;
		b = a[high_index];
		a[high_index] = a[counter - 1];
		a[counter - 1] = b;
	}
}