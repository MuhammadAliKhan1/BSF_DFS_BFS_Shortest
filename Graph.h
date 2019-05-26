#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <queue>
#include <stack>
#include <vector>
class Graph
{
private:
    int vertices;
    Node *head;
    Node *last;
    std::stack<Node *> stack;
    std::vector<Node *> origin;
    std::vector<Node *> neighbour;

public:
    Graph();
    void printGraph();
    void addNode(char u);
    void addEdge(char u, char v);
    void BFSImpl(std::queue<Node *>);
    void BFS(Node *);
    void shortBFSImpl(std::queue<Node *>, Node *, Node *);
    void shortBFS(Node *, Node *);
    void DFS(Node *);
    void DFSImpl(Node *);
    bool clearVisit();
    bool checkDup(std::vector<Node *>, Node *);
    bool checkIfVisited(AdjNode *);
    bool findNode(char u);
    int getInd(std::vector<Node *>, int);
    Node *getOrigin(Node *);
    Node *getHeadVal();
    Node *getNode(AdjNode *);
    Node *getNode(char);
};
#endif /*GRAPH_H*/