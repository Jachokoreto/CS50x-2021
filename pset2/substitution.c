#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//VCHPRZGJNTLSKFBDQWAXEUYMOI
const string ERROR = "Usage : ./caesar key";

int check_duplicate(int i, char c, char array[]);

int main(int argc, string argv[])
{
    string text;
    string key;
    char used_key[26];

    //check if key available and key is 26 char
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("%s", ERROR);
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            //check if key's char is alphabeltical
            if (isalpha(argv[1][i]) == 0)
            {
                printf("%s", ERROR);
                return 1;
            }
            
            //check for duplicates key
            char n = tolower(argv[1][i]);
            used_key[i] = n;

            if (check_duplicate(i, n, used_key) == 1)
            {
                printf("%s", ERROR);
                return 1;
            }
        }
    }

    //prepare text and key for substitution
    text = get_string("plaintext: ");
    key = argv[1];
    string d_text = text;

    //SUBSTITUTE!!!
    //only alpabets, keep lower and uppercase of original message
    for (int i = 0; i < strlen(text); i++)
    {
        char current = (text[i]);
        //if character is alphabet,
        //convert to lowercase and get its placement,
        //then convert back to original case
        //if character is not alphabet, keep it as it is
        if (isalpha(current))
        {
            int map = tolower(current) - 'a';
            d_text[i] = key[map];
            if (isupper(current))
            {
                d_text[i] = toupper(d_text[i]);
            }
            else
            {
                d_text[i] = tolower(d_text[i]);
            }
        }
        else
        {
            d_text[i] = current;
        }
    }
    
    // print encryted message and exit program
    printf("ciphertext: %s", d_text);
    printf("\n");
    return 0;
}

int check_duplicate(int i, char c, char array[])
{
    int n = 0;
    for (int j = 0; j < i ; j++)
    {
        if (c == array[j])
        {
            n = 1;
        }
    }
    return n;
}