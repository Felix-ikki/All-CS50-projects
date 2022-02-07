#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float letters;
float words;
float sentences;

int main(void)
{
    //ask the user for input
    string text = get_string("Input text: ");

    //check for the amount of letters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    //check for the amount of words
    for (int x = 0, n = strlen(text); x < n; x++)
    {
        if (isspace(text[x]))
        {
            words++;
        }
    }
    words++;

    //check for the amount of sentences
    for (int j = 0, n = strlen(text); j < n; j++)
    {
        if (text[j] == '.' || text[j] == '!' || text[j] == '?')
        {
            sentences++;
        }
    }

    //Calculate Coleman-Liau index
    float L = (100 * letters) / words;
    float S = (100 * sentences) / words;

    int INDEX = round(0.0588 * L - 0.296 * S - 15.8);

    //Give user grade of difficulty of text
    if (INDEX < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (INDEX >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (INDEX > 1 && INDEX < 16)
    {
        printf("Grade %i\n", INDEX);
    }
}