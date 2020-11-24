#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    // get size from user
    int n = get_positive_int();
    
    // height
    for (int i = 0; i < n; i++)
    {
        // number of spaces before pyramid
        for (int j = 0; j < (n - i) - 1; j++)
        {
            printf(" ");
        }
        
        // number of #s on left of pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        
        // space between pyramids
        printf("  ");
        
        // number of #s on right of pyramid
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }
        
        // print new line before repeating int i
        printf("\n");
    }
}

// Prompt user for positive integer between 1-8
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("%s", "Size (1-8): ");
    }
    while (n < 1 || n > 8);
    return n;
}