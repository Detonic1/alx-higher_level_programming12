i#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: Size of the allocated space for ptr.
 * @new_size: New size for the reallocated memory block.
 *
 * Return: A pointer to the reallocated memory block, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;

    /* If new_size is zero, treat it as a call to free */
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    /* If ptr is NULL, treat it as a call to malloc */
    if (ptr == NULL)
        return malloc(new_size);

    /* Allocate new memory block */
    new_ptr = malloc(new_size);

    if (new_ptr == NULL)
        return NULL;

    /* Copy data from old block to new block */
    if (new_size > old_size)
        new_size = old_size;

    for (unsigned int i = 0; i < new_size; i++)
        *((char *)new_ptr + i) = *((char *)ptr + i);

    /* Free the old memory block */
    free(ptr);

    return new_ptr;
}

