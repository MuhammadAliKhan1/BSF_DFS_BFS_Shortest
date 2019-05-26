#ifndef ADJ_NODE_H
#define ADJ_NODE_H
#include <iostream>
class AdjNode
{
public:
    char data;
    AdjNode *next;
    AdjNode(char data);
};
#endif //ADJ_NODE_H