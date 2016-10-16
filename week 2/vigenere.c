/*
 * Created CS50.
 * User: Evgeniy Ryzhyk
 * evgenii_r84@mail.ru
 * Date: 02.10.2016
 */
 
 int main (int argc, string argv [])
{
    string k = argv[1];
   
    // check if arguments more than 2 or 0
    if (argv[2] != NULL || k == NULL)
    {
        printf ("More than 2 or 0!\n");
        return 1;
    }
     // transform argument int
    int z = strlen (k);
    int code [z];
     for (int i = 0; i < z; i++)
    {
        code [i] = toupper(k [i]) - 65;
        if (isdigit(k[i]))
        {
            printf ("More than 2 or 0!\n");
            return 1;
        }
    } 
    // get string
    char x;
    string text = GetString();
    
    int t = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // check if character is letter
        if (isalpha(text[i]))
        {
            if (t >= z)
                 t = t % z;
                           
            x = text[i] + code[t];
            
            if (isalpha(x) && isupper(x) == isupper(text[i]))
                printf ("%c",x);
            else 
            {   
                x = x - 26;
                printf ("%c",x);
            }
            t = t + 1; 
        }
        // if non letters
        if (isalpha(text[i]) == false)
        {
            printf ("%c",text[i]);
        }    
    }
   printf ("\n");
   return 0;
}