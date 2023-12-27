#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void compute(string text);
void printing(float index);

int main(void)
{
    string text = get_string("Text: ");
    // printf("%s\n", text);
    // printf("%d letters\n%d words\n%d sentences\n", count_letters(text), count_words(text),  count_sentences(text));
    compute(text);
    return (0);
}

int count_letters(string text)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (text[i])
    {
        if (isalpha(text[i]) != 0)
            res++;
        i++;
    }
    return (res);
}

int count_words(string text)
{
    int i;
    int res;

    i = 0;
    res = 1;
    while (text[i])
    {
        if (text[i] == 32)
            res++;
        i++;
    }
    return (res);
}

int count_sentences(string text)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (text[i])
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            res++;
        i++;
    }
    return (res);
}

void compute(string text)
{
    float L;
    float S;
    float num_letters;
    float num_words;
    float num_sentences;
    float index;

    num_letters = count_letters(text);
    num_words = count_words(text);
    num_sentences = count_sentences(text);

    L = (num_letters / num_words) * 100;
    // printf("L = %.2f\n", L);
    S = (num_sentences / num_words) * 100;
    // printf("S = %.2f\n", S);
    index = round((0.0588 * L) - (0.296 * S) - 15.8);
    printing(index);
    return;
}

void printing(float index)
{
    int res;

    res = (int) index;
    if (res >= 16)
        printf("Grade 16+\n");
    else if (res < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", res);
}
