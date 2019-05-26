#include "Node.h"
Node::Node(char data)
{
    this->data = data;
    next = NULL;
    n = NULL;
    is_visited = false;
}