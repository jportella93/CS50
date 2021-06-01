#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long full_num = get_long("Number: ");
    long two_digit_num = full_num;
    int number_lenght = 0;
    while (two_digit_num > 99)
    {
        number_lenght += 1;
        two_digit_num /= 10;
    }
    number_lenght += 2;

    string brand = "";
    if (number_lenght == 15 && (two_digit_num == 34 || two_digit_num == 37))
    {
        brand = "AMEX";
    }
    else if (two_digit_num >= 51 && two_digit_num <= 55 && number_lenght == 16)
    {
        brand = "MASTERCARD";
    }
    else if (two_digit_num / 10 == 4 && (number_lenght == 16 || number_lenght == 13))
    {
        brand = "VISA";
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    int pair_addition = 0;
    int odd_addition = 0;
    long full_num_copy = full_num;
    for (int i = 0; full_num_copy > 0; i++)
    {
        int current = full_num_copy % 10;
        if (i % 2 != 0)
        {
            int product = current * 2;
            while (product > 0)
            {
                pair_addition += product % 10;
                product = product / 10;
            }
        }
        else
        {
            odd_addition += current;
        }
        full_num_copy = full_num_copy / 10;
    }

    if ((pair_addition + odd_addition) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s\n", brand);
    }
}
