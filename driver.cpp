#include "Graph.h"
int main()
{
    Graph *obj = new Graph();
    obj->addEdge('Z', 'X');
    obj->addEdge('Z', 'C');
    obj->addEdge('X', 'V');
    obj->addEdge('X', 'C');
    obj->addEdge('C', 'V');
    obj->addEdge('V', 'B');
    obj->addEdge('V', 'R');
    obj->addEdge('B', 'R');
    obj->addEdge('B', 'C');
    obj->addEdge('R', 'O');
    obj->addEdge('O', 'B');
    std::cout << "DFS: ";
    obj->DFS(obj->getHeadVal());
    std::cout << "BFS: ";
    obj->BFS(obj->getHeadVal());
    std::cout << "Shortest path(Z-O): ";
    obj->shortBFS(obj->getNode('Z'), obj->getNode('O'));
}