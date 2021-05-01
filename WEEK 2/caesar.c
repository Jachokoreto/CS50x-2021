#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const string ERROR = "Usage : ./caesar key";

int main(int argc, string argv[])
{
    string text;
    int key;
    
    if (argc != 2)
    {
        printf("%s", ERROR);
        return 1;
    }
    else 
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("%s", ERROR);
                return 1;
            }
        }
    }
    
    text = get_string("plaintext: ");
    key = atoi(argv[1]);
    string d_text = text;
    
    //(p + k) % 26 
    for (int i = 0; i < strlen(text); i++)
    {
        char c_dec = text[i];
        
        if (isalpha(c_dec))
        {
            if(islower(c_dec))
            {
                d_text[i] = (((c_dec -'a') + key) % 26) + 'a';
            }
            else
            {
                d_text[i] = (((c_dec -'A') + key) % 26) + 'A';
            }
        }
        else 
        {
            d_text[i] = text[i];
        }
    }
    
    printf("ciphertext: %s\n", d_text);
    return 0;
}
