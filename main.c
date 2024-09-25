#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

int main(void)
{
    char window_spec[15];
    struct Header *header = malloc(sizeof(struct Header));
    header->head = NULL;

    do
    {
        fgets(window_spec, sizeof(window_spec), stdin);
        output_window(window_spec, &header);
        if (header->head)
        {
            printf("%d\n", header->head->data);
        }
    } while (header->head != NULL);

    free(header);
    return 0;
}