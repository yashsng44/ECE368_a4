#ifndef a2_h
#define a2_h 
#include <stdio.h>
#include <stdbool.h>

typedef int Info_t;

typedef struct Node
{ Info_t data;
struct Node *next;
} Node;

typedef struct Header
{ Node *head;
Node *tail;
} Header;

int output_window(char * window_spec, Header ** header);
void free_list(Header ** header);
#endif