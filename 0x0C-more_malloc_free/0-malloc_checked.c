#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: Number of bytes to allocate.
 *
 * Return: A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
    void *ptr;

    ptr = malloc(b);

    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(98);
    }

    return ptr;
}

