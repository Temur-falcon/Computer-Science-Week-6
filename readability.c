#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Averages per 100 words
    double L = (double) letters * 100.0 / words;
    double S = (double) sentences * 100.0 / words;

    // Coleman–Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha((unsigned char) text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    // By spec: words are sequences separated by a single space, no leading/trailing/multiple spaces.
    // So words = spaces + 1 (if non-empty). We'll also handle multiple spaces robustly.
    int count = 0;
    bool in_word = false;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isspace((unsigned char) text[i]))
        {
            if (!in_word)
            {
                in_word = true;
                count++;
            }
        }
        else
        {
            in_word = false;
        }
    }

    return count > 0 ? count : 0;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?')
        {
            count++;
        }
    }
    return count;
}
