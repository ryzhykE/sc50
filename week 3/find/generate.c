/**
 * Created CS50 Week1.
 * Problem Set 3
 * User: Evgeniy Ryzhyk
 * Date: 07.09.2016
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define LIMIT 65536

int main(int argc, string argv[])
{
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // if we have entered 3rd argument == [s], we have a seed for srand function. This seed is stored in argv[2]
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }
    // Printing n times pseudorandom numbers calling a  function drand48, that transformed to int and have a LIMIN for itself
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }
    return 0;
}
