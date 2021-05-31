#include <cs50.h>
#include <stdio.h>

int main(void)
{
     int start_size;
      do
      {
          start_size = get_int("Start size: ");
      }
      while (start_size < 9);
      
      int end_size;
      do
      {
          end_size = get_int("End size: ");
      }
      while (end_size < start_size);
      
    int years = 0;
    int current_size = start_size;
    while (current_size < end_size)
    {
        int born = current_size / 3;
        int dead = current_size / 4;
        current_size += born;
        current_size -= dead;
        years++;
    }

    printf("Years: %d", years);
}