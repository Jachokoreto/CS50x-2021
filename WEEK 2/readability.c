#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void)
{
    string text = get_string("Text: ");
    
    int letter = 0;
    double word = 1;
    int sentence = 0;
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        char current = text[i];
        
        if (isalpha(current))
        {
            letter++;
        }
        else if (isspace(current))
        {
            word++;
        }
        else if (current == '.' || current == '!' || current == '?')
        {
            sentence++;
        }
    }
    
    double L = letter / word * 100;
    double S = sentence / word * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int result = (int) round(index);
    
    if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}