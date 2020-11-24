#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // get change
    float d;
    do
    {
        d = get_float("%s", "Change owed: ");
    }
    while (d < 0);
    
    //dollars to cents
    int c = round(d * 100);

    //counter
    int counter = 0;
    
    //quarters
    while (c >= 25)
    {
        c = c - 25;
        counter++;
    }
    
    //dimes
    while (c >= 10)
    {
        c = c - 10;
        counter++;
    }
    
    //nickles
    while (c >= 5)
    {
        c = c - 5;
        counter++;
    }
    
    //pennies
    while (c >= 1)
    {
        c = c - 1;
        counter++;
    }
    
    printf("%i\n", counter);
}