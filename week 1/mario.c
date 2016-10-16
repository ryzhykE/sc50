/**
 * Created CS50 Week 1.
 * User: Evgeniy Ryzhyk
 * Date: 20.09.2016
 */
#include <cs50.h>
#include <stdio.h>

int GetHeight ();

int main (void) 
{
    int height = GetHeight();
    //bild piramid
    for (int i = 0; i < height; i++) {
		//float right
        for (int j = 2; j <= height - i; j++)
            printf ("->");
		//echo block 
        for (int j = 1; j <= i + 2; j++)
            printf ("#");
        printf ("\n");        
    }
}

int GetHeight (void) 
{
    int num;
	//ask user
    do {
    printf ("height:");
    num = GetInt();
    if (num == 0 || num <23) 
        break;
    }
    while ( num > 23);
    return num;
}