#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

//declarations
int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

float coleman_liau_index(float l, float s);

//main   
int main(void)
{
    //get text from user
    string text = get_string("Text: ");
    
    //count letters
    float letters = count_letters(text);

    //count words
    float words = count_words(text);
    
    //count sentences
    float sentences = count_sentences(text);

    //find index
    float l = 100 * letters / words;
    float s = 100 * sentences / words;
    float index = coleman_liau_index(l, s);
    
    //round answer to nearest int
    int answer = round(index);
    
    //what grade?
    if (answer < 1)
    {
        printf("Before Grade 1\n");
    }
    if (answer >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (answer > 0 && answer < 16)
    {
        printf("Grade %i\n", answer);
    }
}



//count letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            letters++;
        }
    }
    return letters;
}


//count words
int count_words(string text)
{
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}


//count sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}


//run coleman_liau_index
float coleman_liau_index(float l, float s)
{
    float index = 0.0588 * l - 0.296 * s - 15.8;
    return index;
}