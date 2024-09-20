#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <regex.h>
#include "a4.h"
// //regex_t regex;

void open_window (Header * header, Node * newNode) {
    Node * dummy_node = malloc(sizeof(Node));
    dummy_node = header->head;
    header->head = newNode;
    newNode->next = dummy_node;
    return;
}

void switch_window (Header * header, int target) {
    Node * search_node = header->head;
    Node * dummy = NULL;
    Node * prev = NULL;

    while(search_node != NULL && search_node->data != target) {
        prev = search_node;
        search_node = search_node->next;
    }
    // found the node!
    // not deleting/rerouting properly...
    if (search_node) {
        if (prev == NULL) {
        return; // make no switches if the tab you want to switch to is the same one..
        header->head = search_node->next;
        } else {
        prev->next = search_node->next;
        dummy = search_node;
        free(search_node);
        }
    }
    open_window(header, dummy);
    return;
}

void close_window (Header * header, int target) {
    Node * search_node = header->head;
    Node * dummy = header -> head;
    Node * prev = NULL;

    while(search_node != NULL && search_node->data != target) {
        prev = search_node;
        search_node = search_node->next;
    }
    header->head = search_node;
    

}
void output_window (char * window_spec, Header * header) {
    int number;

    if (sscanf(window_spec, "%*[^0-9]%d", &number)) {

    if(strcmp(window_spec, "open")) {
        // the only case where its necessary to create a new node...
        Node * newNode = malloc(sizeof(Node));
        newNode->data = number;
        newNode->next = NULL;
        open_window(header, newNode);
        printf("%d\n", header->head->data);
    } else if (strcmp(window_spec, "switch"))   {
        switch_window(header, number);
        printf("%d\n", header->head->data);
    } else if (strcmp(window_spec, "close")) {
    }
    } else {
        printf("No valid number input \n");
        return;
    }

    return;
}
