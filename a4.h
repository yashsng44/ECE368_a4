#ifndef a4_h
#define a4_h 
#include <stdio.h>
#include <stdbool.h>

typedef int Info_t;

typedef struct Node
{ Info_t data;
struct Node *next;
} Node;

typedef struct Header
{ Node *head;
} Header;

void free_list(Header ** header);
Node * search_for_node (Header ** heaer, int target);
void open_window(Header ** header, int target);
void switch_window (Header ** header, int target);
int close_window (Header ** header, int target);
int output_window (char * window_spec, Header ** header);

#endif