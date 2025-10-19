#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid_key(string key);
char substitute(char letter, string key);

int main(int argc, string argv[])
{
    // Check number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate key
    if (!valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Encrypt each character
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Validate key correctness
bool valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    bool used[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (used[index])
        {
            // duplicate letter found
            return false;
        }
        used[index] = true;
    }

    return true;
}

// Substitute one letter according to the key
char substitute(char letter, string key)
{
    if (isupper(letter))
    {
        int index = letter - 'A';
        return toupper(key[index]);
    }
    else if (islower(letter))
    {
        int index = letter - 'a';
        return tolower(key[index]);
    }
    else
    {
        return letter; // Non-alphabetic: unchanged
    }
}
//In order to correctly execute the code , when typing ./substitution in the terminal,
//add ZYXWVUTSRQPONMLKJIHGFEDCBA as the key
