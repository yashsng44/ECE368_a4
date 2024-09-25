#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

int main(void) {

    char window_spec[15];
    struct Node * head = NULL;
    struct Header * header = malloc(sizeof(struct Header));
    header->head = head;
    
    while(header != NULL) {
            fgets(window_spec, sizeof(window_spec), stdin);
            window_spec[strcspn(window_spec, "\n")] = 0;
            if (!(output_window(window_spec, &header))) {
                printf("\n");
                break;
            }
            printf("%d\n", header->head->data);
    }

    free_list(&header);
    free(header);
    return EXIT_SUCCESS;
}