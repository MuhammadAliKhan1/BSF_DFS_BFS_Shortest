#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Adj_Node.h"
class Node
{
public:
    char data;
    Node *next;
    AdjNode *n;
    bool is_visited;
    Node(char data);
};
#endif //NODE_H