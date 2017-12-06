/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
// binary search (tested and works)
    
bool search(int value, int values[], int n)
{
    // define start and end of (sub)array
    int start = 0;
    int end = n - 1;

    // halve (sub)array until value is found or (sub)array is size 0
    while (start <= end)
    {
        // calculate the midpoint of (sub)array
        int midpoint = (start + end) / 2;

        // if value is at midpoint
        if (value == values[midpoint])
        {
            // return true
            return true;
        }

        // if value is left of midpoint
        else if (value < values[midpoint])
        {
            // reset end point
            end = midpoint - 1;
        }

        // if value is right of midpoint
        else if (value > values[midpoint])
        {
            // reset start point
            start = midpoint + 1;
        }
    }
    // value is not in array of values
    return false;
}
/**
 * Sorts array of n values.
 */
 // bubble sort (tested and works)
 
void sort(int values[], int n) 
{
    // set swap counter to non-zero value
    int counter = 1;
    
    do 
    {
        // reset swap counter to zero
        counter = 0;
        
        // iterate through entire array
        for (int i = 0; i < n; i++)
        {
            // check if each adjacent pair are in order
            if (values[i] > values[i + 1])
            {
                // if not, swap them
                int tmp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = tmp;
                
                // increment counter
                counter++;
            }
        }
    }
    while (counter > 0);
}

