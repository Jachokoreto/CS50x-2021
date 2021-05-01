#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long("Number: ");

    int result = 0;
    int digit_length = 0;
    long first_digit = 0;
    string answer;


    //1st validation...
    for (long n = 10; n < credit; n *= 100)
    {
        int temp1 = (((credit / n) % 10) * 2) % 10;
        int temp2 = (((credit / n) % 10) * 2) / 10;
        result += temp1 + temp2;
        digit_length++;
    }

    //2nd validation...
    for (long n = 1; n < credit; n *= 100)
    {
        result += (credit / n) % 10;
        digit_length++;
    }
    //printf("%i\n", digit_length);

    //get first digit
    first_digit = credit;

    for (int n = 0; n < digit_length - 2; n++)
    {
        first_digit /= 10;
    }
    //printf("%li\n", first_digit);

    //Final validation
    if (result % 10 == 0)
    {
        if (digit_length == 16 && first_digit >= 51 && first_digit <= 55)
        {
            answer = "MASTERCARD";
        }
        else if (digit_length == 15 && first_digit >= 34 && first_digit <= 37)
        {
            if (first_digit == 34 || first_digit == 37)
            {
                answer = "AMEX";
            }
            else
            {
                answer = "INVALID";
            }
        }
        else if (digit_length >= 13 && digit_length <= 16 && first_digit >=40 && first_digit <= 49)
        {
            answer = "VISA";
        }
        else
        {
            answer = "INVALID";
        }
    }
    else
    {
        answer = "INVALID";
    }
    printf("%s\n", answer);
}

