#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    int line_length = height * 2 + 2;
    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i <= line_length; col_i++)
        {
            if (col_i == height || col_i == height + 1)
            {
                printf(" ");
            }
            else if (row_i == height - 1 && col_i == line_length)
            {
                printf("");
            }
            else if (col_i == line_length)
            {
                printf("\n");
            }
            else if (col_i < height && col_i > height - row_i - 2)
            {
                printf("#");
            }
            else if (col_i > height && col_i < height + row_i + 3)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
    }
}
