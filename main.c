#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

int main(void) {


    char window_spec[1000];
    struct Node * head = malloc(sizeof(Node));
    struct Header * header = malloc(sizeof(Header));
    header->head = head;
    
    while(header->head != NULL) {
        if(fgets(window_spec, sizeof(window_spec), stdin)){
            window_spec[strcspn(window_spec, "\n")] = 0;
            output_window(window_spec, header);
        } else {
            return EXIT_FAILURE;
        }
    }

     while(header->head != NULL) {
        printf("%d\n", header->head->data);
        header->head = header->head->next;
    }


    return EXIT_SUCCESS;
}