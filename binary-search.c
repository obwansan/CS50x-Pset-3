#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int size)
{
    // define upper and lower bounds
    int upper = size - 1;
    int lower = 0;

    // halve array until bounds overlap
    while(lower <= upper)
    {
        // define middle
        int middle = (upper + lower) / 2;

        // if needle is at middle
        if(needle == haystack[middle])
        {
            // return true
            return true;
        }

        // if needle is left of middle
        else if(needle < haystack[middle])
        {
            // reset upper bound
            upper = middle - 1;
        }

        // if needle is right of middle
        else if(needle > haystack[middle])
        {
            // reset lower bound
            lower = middle + 1;
        }
    }
    // needle is not in haystack
    return false;
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = get_int();
    if (search(n, numbers, SIZE))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}