#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <regex.h>
#include "a4.h"
// //regex_t regex;
Node * search_for_node (Header * header, int target) {
    Node * search_node = header->head;

    while(search_node != NULL && search_node->data != target) {
        search_node = search_node->next;
    }

    return search_node;
}
void open_window (Header * header, Node * newNode) {
    Node * dummy_node = malloc(sizeof(Node));
    int target = newNode->data;
    Node * searched = search_for_node(header, target);
    if (searched == NULL) {
    dummy_node = header->head;
    header->head = newNode;
    newNode->next = dummy_node;
    } 
    return;
}

void switch_window (Header * header, int target) {
    Node * search_node = header->head;
    Node * prev = NULL;

    while(search_node != NULL && search_node->data != target) {
        prev = search_node;
        search_node = search_node->next;
    }

    if (search_node) {
        if (prev !=NULL) {
        prev->next = search_node->next;
        open_window(header, search_node);
        } 
    }
    return;
}

void close_window (Header * header, int target) {
    Node * search_node = header->head; // creates a copy of the header head..
    Node * prev = NULL;

    if (search_node == NULL) {
        header->head = NULL;
        return;
    }

    while(search_node != NULL && search_node->data != target) {
        prev = search_node;
        search_node = search_node->next;
    }

    if (search_node) {
        if (prev == NULL && search_node == header->head) {
        header->head = header->head->next; // shift the header to the next node; closing the top node.
    } else {
        prev->next = search_node->next;
        }
    }
    return;
}

void output_window (char * window_spec, Header * header) {
    int number;

    if (sscanf(window_spec, "%*[^0-9]%d", &number)) {
        
    if(strstr(window_spec, "open") == window_spec) {
        Node * newNode = malloc(sizeof(Node));
        newNode->data = number;
        newNode->next = NULL;
        open_window(header, newNode);
    } else if (strstr(window_spec, "switch") == window_spec)   {
        switch_window(header, number);
    } else if (strstr(window_spec, "close") == window_spec) {
        close_window(header, number);
    } else {
    }
    } else {
        printf("No valid number input \n");
        return;
    }

    printf("%d\n", header->head->data);
    return;
}
