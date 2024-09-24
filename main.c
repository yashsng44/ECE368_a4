#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

int main(void) {

    char window_spec[1000];
    struct Node * head = NULL;
    struct Header * header = malloc(sizeof(struct Header));
    header->head = head;
    int leftovers;
    
    while(fgets(window_spec, sizeof(window_spec), stdin)) {
            window_spec[strcspn(window_spec, "\n")] = 0;
            leftovers = output_window(window_spec, &header);
            if (!leftovers) {
                break;
            }
    }

    free(head);
    free(header);


    return EXIT_SUCCESS;
}