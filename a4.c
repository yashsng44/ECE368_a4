#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include "a4.h"

Node * search_for_node (Header ** header, int target) {
    Node * search_node = (*header)->head;
    while(search_node != NULL && search_node->data != target) {
        search_node = search_node->next;
    }
    return search_node;
}

void free_list(Header **header) {
    Node *current = (*header)->head;
    Node *next;

    while (current != NULL) {
        next = current->next;  // Store the next node
        free(current);         // Free the current node
        current = next;        // Move to the next node
    }
    (*header)->head = NULL;
}

void open_window (Header ** header, int target) {

    //Node * searched = search_for_node(header, target);
    //if (searched == NULL) {
        Node * newNode = malloc(sizeof(Node));
        newNode->data = target;
        newNode->next = (*header)->head;
        (*header)->head = newNode;
    //} 
    return;
}

void switch_window (Header ** header, int target) {
     if (search_for_node(header, target)) {
        close_window(header, target);
        open_window(header, target);
     }
     
    return;
}

int close_window (Header ** header, int target) {
    Node * search_node = (*header)->head; // creates a copy of the header head..
    Node * prev = NULL;

    if (search_node == NULL) {
        return 1;
    } 

    if (search_node->next == NULL) {
        return 0;
    }
    
    while(search_node != NULL && search_node->data != target) {
        prev = search_node;
        search_node = search_node->next;
    }

    if (search_node) {
        if (prev == NULL && search_node == (*header)->head) {
        (*header)->head = (*header)->head->next; // shift the header to the next node; closing the top node.
    } else {
        prev->next = search_node->next;
        }
    }

    free(search_node);
    search_node = NULL;
    return 1;
}

int output_window (char * window_spec, Header ** header) {
    int number;
    int leftovers = 1;

    if (sscanf(window_spec, "%*[^0-9]%d", &number)) {
        if ( !(strcmp(window_spec, "open")) || !(strcmp(window_spec, "switch")) || !(strcmp(window_spec, "close"))) {
            return 1;
        }
        if(strstr(window_spec, "open") == window_spec) {
            open_window(header, number);
        } else if (strstr(window_spec, "switch") == window_spec)   {
            switch_window(header, number);
        } else if (strstr(window_spec, "close") == window_spec) {
            leftovers = close_window(header, number);
        }
    }
    return leftovers;
}
