#include <stdio.h>
#include <stdlib.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

void print_number(char *num)
{
    while (*num == '0' && *(num + 1) != '\0')
        num++;
    while (*num)
        _putchar(*(num++));
}

void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, len_res;
    int i, j, carry, digit;
    char *result;

    while (num1[len1] != '\0')
        len1++;
    while (num2[len2] != '\0')
        len2++;

    len_res = len1 + len2;
    result = malloc(sizeof(char) * (len_res + 1));

    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = 0; i < len_res; i++)
        result[i] = '0';

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            digit = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = digit / 10;
            result[i + j + 1] = (digit % 10) + '0';
        }

        result[i + j + 1] = (carry % 10) + '0';
    }

    print_number(result);
    _putchar('\n');
    free(result);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    for (int i = 1; i <= 2; i++)
    {
        char *num = argv[i];

        while (*num)
        {
            if (*num < '0' || *num > '9')
            {
                printf("Error\n");
                return 98;
            }
            num++;
        }
    }

    multiply(argv[1], argv[2]);

    return 0;
}

