**
 * Created CS50.
 * User: Evgeniy Ryzhyk
 * Date: 01.10.2016
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // get user name
    string name = GetString();
    
    // print the first initial
    if(name[0] != ' ')
        {
			//toupper - conversion of lowercase to uppercase
            printf("%c", toupper(name[0]));
        }
    
    /*Selection first letter*/
	//length of string
    int n = strlen(name);
    for(int i = 0; i <= n; i++)
    {
        if(name[i] == ' ' && name[i + 1] != ' ' && i + 1 < n)
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}   
 