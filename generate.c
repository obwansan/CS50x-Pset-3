/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Print usage example if user inputs less than two or more than three arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // convert number of pseudorandom numbers the user wants to generate from a string to an integer
    int n = atoi(argv[1]);

    // if the user provides a third arg, convert it to a long integer and make it the 'seed' for the pseudorandom number.
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    // if they don't, create a 'seed' long integer value using the current time.
    else
    {
        srand48((long) time(NULL));
    }

    // generate a random number using drand48(), multiply it by LIMIT (a constant defined within the file),
    // and convert it from long to int. Repeat for length of n, and print each number
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
