/**
 * Created CS50 Week1.
 * Problem Set 3
 * User: Evgeniy Ryzhyk
 * Date: 07.09.2016
 */
#include <cs50.h>
#include "helpers.h"

void bubblesort(int* , int );

bool search(int value, int* values, int n) {
    
    int leftedge, rightedge, middle;
    leftedge = 0;
    rightedge = n - 1;
    while (rightedge >= leftedge) {
		// always find the middle of the array
        middle =leftedge + (rightedge - leftedge)/2;   
        if (n < 2)             
            return false;
        if (values[middle] == value)        
            return true;
		// if middle value greater than value ==> ignore right side of array
        if (values[middle] > value)
            rightedge = middle  - 1;
        else      
            leftedge = middle + 1;
    }   
   return false;
}
//sort array
void sort(int values[], int n)
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (values[j] > values[j+1]) {
                int tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }

}
