#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }

    //request the text to cipher
    string plain = get_string("plaintext: ");

    //start printing the ciphered text
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(plain), m = strlen(argv[1]); i < n; i++)
    {
        int key = shift(argv[1][j]);

        //if plaintext char is lower case
        if (islower(plain[i]))
        {
            printf("%c", ((((plain[i] - 'a') + key) % 26) + 'a'));
            j++;
        }
        //if plaintext char is upper case
        else if (isupper(plain[i]))
        {
            printf("%c", ((((plain[i] - 'A') + key) % 26) + 'A'));
            j++;
        }
        //if non alpha character, do not change it
        else
        {
            printf("%c", plain[i]);
        }
        
        //if the counter for the key is shorter than the string to cipher, reuse key from start
        if (j >= m)
        {
            j = 0;
        }
    }

    printf("\n");
    //exit without error
    return 0;
}

//function to properly convert key
int shift(char c)
{
    int key;
    //case if key char is lower case
    if (islower(c))
    {
        key = (c - 'a');
    }
    //otherwise char is upper case
    else
    {
        key = (c - 'A');
    }

    //return the key as an int
    return key;
}
