#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int start_size);

int main(void)
{
    // TODO: Prompt for start size
    // TODO: Prompt for end size
    int year = 0;
    int start_size = get_start_size();
    int end_size = get_end_size(start_size);
    int n = start_size;
    
    // TODO: Calculate number of years until we reach threshold
    if (start_size != end_size)
    {
        do
        {
            n = n + n / 3 - n / 4;
            year++;
        }
        while (n < end_size);
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", year);
}

int get_start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

int get_end_size(int start_size)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < start_size);
    return n;
}