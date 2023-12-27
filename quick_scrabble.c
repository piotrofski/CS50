#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 == score2)
        printf("Tie!\n");
    else if (score1 > score2)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");
}

int compute_score(string word)
{
    int i;
    int j;
    int res;
    int index;
    char *temp;

    i = 0;
    j = 0;
    index = 0;
    res = 0;
    temp = (char *) malloc(sizeof(char) * (strlen(word)));
    if (!temp)
        return (0);

    // CONVERT INTO MAJ AND GETTING RID OF NON-ALPHA CHAR
    while (word[i])
    {
        if (isalpha(word[i]) != 0)
        {
            if (islower(word[i]) != 0)
                temp[j] = word[i] - 32;
            else
                temp[j] = word[i];
            j++;
        }
        i++;
    }
    temp[j] = '\0';

    // CONVERT INTO POINTS
    i = 0;
    while (temp[i])
    {
        index = temp[i] - 65;
        res += POINTS[index];
        // printf("Char :\t%c\t\tIndex :\t%d\t\tValue : \t%d\n", temp[i] ,index, POINTS[index]);
        i++;
    }
    // printf("\nRES FINAL\t%d\n", res);

    free(temp);
    return (res);
}
