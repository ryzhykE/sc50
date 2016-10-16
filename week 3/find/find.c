/**
 * Created CS50 Week1.
 * Problem Set 3
 * User: Evgeniy Ryzhyk
 * Date: 07.09.2016
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount 
const int MAX = 65536;

int main(int argc, string argv[])
{
   
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%i] = ", size);
        int straw = get_int();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);

    // try to find needle in haystack
    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
}
