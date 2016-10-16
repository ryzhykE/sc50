/**
 * Created CS50.
 * User: Evgeniy Ryzhyk
 * Date: 01.10.2016
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv [])
{
    // check if arguments more than 2 
     if (argc != 2)
    {
        printf("Enter your key\n");
        return 1;
    }
    // get int
    int k = atoi(argv[1]);
    k = k % 26;
    // get string to code  
    char x;
    string text = GetString();
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // check if character is letter
        if (isalpha(text[i]))
        {
            x = text[i] + k;
            if (isalpha(x) && isupper(x) == isupper(text[i]))
                printf ("%c",x);
            else 
            {   
                x = x - 26;
                printf ("%c",x);
            } 
        }
        
        if (isalpha(text[i]) == false)
        {
            printf ("%c",text[i]);
        }    
    }
   printf ("\n");
}
 