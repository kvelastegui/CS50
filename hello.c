#include <cs50.h>
#include <stdio.h>

//get name from user and say hello
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}