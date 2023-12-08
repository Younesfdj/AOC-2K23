#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int part1(FILE *fp)
{
    char str[1000];
    int sum = 0;

    int counter = 0;
    while (fgets(str, 1000, fp) != NULL)
    {
        counter++;
        char first[2], last[2];
        bool firstTaken = false;
        for (int i = 0; i < strlen(str); i++)
        {
            if (isdigit(str[i]))
            {
                if (!firstTaken)
                {
                    first[0] = str[i];
                    first[1] = '\0';
                    firstTaken = true;
                }
                last[0] = str[i];
                last[1] = '\0';
            }
        }
        strcat(first, last);
        sum += atoi(first);
    }
    fclose(fp);
    return sum;
}

int part2()
{
    char *values[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char test[] = "4nineeightseven2";

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
    {
        char *result = strstr(test, values[i]);

        if (result != NULL)
        {
            printf("Substring found : %s\n", result);
        }
    }
    return 1;
}

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    printf("part1 value is %d\n", part1(fp));
    int res = part2();
    return 0;
}