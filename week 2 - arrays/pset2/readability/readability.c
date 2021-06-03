#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float get_avg_100(int occurences, int sample_size);

int get_grade(float letters_avg, float sentence_avg);

int main(void)
{
    string s = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0, s_length = strlen(s); i < s_length; i++)
    {
        char c = s[i];
        if (isalnum(c))
        {
            letters++;
        }
        else if (isspace(c))
        {
            words++;
        }
        else if (c == '!' || c == '?' || c == '.')
        {
            sentences++;
        }
    }
    words++;

    float letters_avg = get_avg_100(letters, words);
    float sentences_avg = get_avg_100(sentences, words);
    int grade = get_grade(letters_avg, sentences_avg);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

float get_avg_100(int occurences, int sample_size)
{
    return occurences * 100.00 / sample_size;
}

int get_grade(float letters_avg, float sentence_avg)
{
    return (int)round(0.0588 * letters_avg - 0.296 * sentence_avg - 15.8);
}
