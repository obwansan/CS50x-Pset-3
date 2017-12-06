#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    // iterate through unsorted part of array from l->r
    for (int i = 1; i < size; i++) 
    {
        // define the start of the sorted array
        int j = i - 1;
        
        // specify the next element to sort
        int to_sort = array[i];
        
        // iterate through sorted part of array from r->l
        // figure out where in sorted portion element should go
        while (j >= 0 && to_sort < array[j]) // if right num less than left num (e.g. 50 less than 108)
        {
            // shift sorted elements rightward
            array[j + 1] = array[j];  // element 108 moved right by one index position
            j--;
        }
        // insert element into sorted portion of array
        array[j + 1] = to_sort;  // 
    }
}

int main(void)
{
    int numbers[SIZE] = { 108, 50, 42, 23, 16, 15, 8, 4 };
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}