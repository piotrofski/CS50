#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recognizeCard(int size, int *list)
{
    if (size == 14)
    {
        if (list[0] == 3 && (list[1] == 4 || list[1] == 7))
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else if (size == 15 && list[0] == 5)
    {
        if (list[1] == 1 || list[1] == 2 || list[1] == 3 || list[1] == 4 || list[1] == 5)
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
    else if ((list[0] == 4) && (size == 15 || size == 12))
    {
        if (list[0] == 4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
    return;
}

int getSize(long int number)
{
    int size;

    size = 0;
    while (number > 10)
    {
        number = number / 10;
        size++;
    }
    return (size);
}

int compute(int size, int *list)
{
    int i;
    int j;
    int res;
    int *newList;
    newList = (int *) malloc(sizeof(int) * (size + 1) / 2);
    if (!newList)
        return (0);

    res = 0;
    if ((size + 1) % 2 == 0)
    {
        i = 0;
        j = 0;
        while (i < size + 1)
        {
            newList[j] = list[i] * 2;
            list[i] = 0;
            i += 2;
            j++;
        }
        j = -1;
        while (j++ < size / 2)
        {
            if (newList[j] >= 10)
                newList[j] = (newList[j] % 10) + 1;
            res = res + newList[j];
        }
        i = 0;
        while (i < size + 1)
        {
            res = res + list[i];
            i++;
        }
        if (res % 10 == 0)
            return (1);
    }
    else if ((size + 1) % 2 == 1)
    {
        i = 1;
        j = 0;
        while (i < size + 1)
        {
            newList[j] = list[i] * 2;
            list[i] = 0;
            i += 2;
            j++;
        }
        j = -1;
        while (j++ < size / 2)
        {
            if (newList[j] >= 10)
                newList[j] = (newList[j] % 10) + 1;
            res = res + newList[j];
        }
        i = 0;
        while (i < size + 1)
        {
            res = res + list[i];
            i++;
        }
        if (res % 10 == 0)
            return (1);
    }
    free(newList);
    return (0);
}

int valid_input(char *str)
{
    int i;
    int length;

    length = strlen(str);
    i = 0;
    while (i < length)
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    long int number;
    int *list;
    int i;
    int size;
    char *str;
    int cpy[50];
    bool ok;

    // PROMPT
    ok = 0;
    printf("Number: ");
    number = 0;
    str = (char *) malloc(sizeof(char) * 20);
    while (ok != 1)
    {
        if (scanf("%s", str) == 1)
        {
            if (valid_input(str) == 1)
            {
                number = strtol(str, NULL, 10);
                ok = 1;
                break;
            }
            else
            {
                printf("Number: ");
                ok = 0;
            }
        }
    }
    // MALLOC
    size = getSize(number);
    list = (int *) malloc(sizeof(int) * (size + 1));
    if (!list)
        return (0);

    // CONVERT TO ARRAY
    i = size;
    while (i >= 0)
    {
        list[i] = number % 10;
        number = number / 10;
        i--;
    }
    list[i] = number % 10;

    // COPY ARRAY
    i = -1;
    while (i++ < size + 1)
        cpy[i] = list[i];

    // DISPATCH
    if (compute(size, list) == 1)
        recognizeCard(size, cpy);
    else
        printf("INVALID\n");

    free(list);
    free(str);

    return 0;
}
