#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int exit_with_message(string msg);
bool is_non_alfa(string key);
bool is_short_key(string key);
bool has_repeated_letters(string key);
void print_ciphertext(string key, string plain);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (!key)
    {
        return exit_with_message("Usage: ./substitution key");
    }
    if (is_non_alfa(key))
    {
        return exit_with_message("Key can only contain letters.");
    }
    if (is_short_key(key))
    {
        return exit_with_message("Key must contain 26 characters.");
    }
    if (has_repeated_letters(key))
    {
        return exit_with_message("Key must not contain repeated characters.");
    }

    string plaintext = get_string("plaintext:");
    print_ciphertext(key, plaintext);
    printf("\n");
}

int exit_with_message(string msg)
{
    printf("%s", msg);
    printf("\n");
    return 1;
}

bool is_short_key(string key)
{
    return strlen(key) < 26;
}

bool is_non_alfa(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
    }
    return false;
}

bool has_repeated_letters(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (key[i] == key[j])
            {
                return true;
            }
        }
    }
    return false;
}

void print_ciphertext(string key, string plain)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        char plain_c = plain[i];
        char cipher_c = plain_c;
        if (isalpha(plain_c))
        {
            cipher_c = key[(int)tolower(plain_c) - 97];
            cipher_c = islower(plain_c) ? tolower(cipher_c) : toupper(cipher_c);
        }
        printf("%c", cipher_c);
    }
}
