#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i;
int n;
int arg;
int j;
int key;
int x;
char ciphertext[256];
string plaintext;
char scale[256];
int l;
char finaltext[256];

int main(int argc, string argv[])
{
    //check if the argc is higher than 1
    if (argc != 2)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }

    //check for argv digits
    for (i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]))
        {
            j++;
        }
    }

    //convert key to integer or tell error
    if (j == n)
    {
        key = atoi(argv[1]);
        printf("Success\n");
        printf("%s\n", argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //prompt the user to type the Plaintext
    plaintext = get_string("Type in plaintext: ");
    
    //start printing final text
    printf("ciphertext: ");

    //convert to 0-25 index, then apply the key, then convert to ASCII value
    for (x = 0, l = strlen(plaintext); x < l; x++)
    {
        //if is upper
        if (isupper(plaintext[x]))
        {
            ciphertext[x] = (plaintext[x] - 65 + key) % 26;
            finaltext[x] = ciphertext[x] + 65;
            printf("%c", finaltext[x]);
        }
        
        //if is lower
        else if (islower(plaintext[x]))
        {
            ciphertext[x] = (plaintext[x] - 97 + key) % 26;
            finaltext[x] = ciphertext[x] + 97;
            printf("%c", finaltext[x]);
        }
        else
        {
            printf("%c", plaintext[x]);
        }
    }
    printf("\n");
}