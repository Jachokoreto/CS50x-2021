#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get positive interger
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    int hash = 1;
    
    for (int i = 0; i < height; i++)
    {
        //spaces for left stairs
        for (int j = 0; j < height - hash; j++)
        {
            printf(" ");
        }
        //build left step
        for (int k = 0; k < hash; k++)
        {
            printf("#");
        }
        printf("  ");
        //build right steps
        for (int l = 0; l < hash; l++)
        {
            printf("#");
        }
        hash++;
        printf("\n");
    }
}