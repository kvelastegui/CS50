#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char caesar(char c, int a, int k);

int main(int argc, string argv[])
{
    //checking number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check for digits and end if not digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]))
        {
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    //make key
    int k = atoi(argv[1]) % 26;
    
    //prompt user for string
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        //uppercase letters
        if (text[i] >= 65 && text[i] <= 90)
        {
            printf("%c", caesar(text[i], 65, k));
        }
        //lowercase letters
        else if (text[i] >= 97 && text[i] <= 122)
        {
            printf("%c", caesar(text[i], 97, k));
        }
        //other characters
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

//wrap letters
char caesar(char c, int a, int k)
{
    char d = ((c - a + k) % 26) + a;
    return d;
}