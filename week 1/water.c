/**
 * Created CS50.
 * User: Evgeniy Ryzhyk
 * Date: 20.09.2016
 */

#include <cs50.h>
#include <stdio.h>

void water (int min);

int main (void) 
{
    int minutes;
    do {
		//ask user
        printf ("minutes: ");
        minutes = GetInt();
    }
    while (minutes <= 0); 
    water (minutes);
}

void water (int minutes) 
{
    int bottles = minutes * (12);
    printf ("bottles: %i\n", bottles);
}