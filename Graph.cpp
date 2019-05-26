#include "Graph.h"
Graph::Graph()
{
    //default construct for Graph
    vertices = 0;
    head = NULL;
    last = NULL;
}
Node *Graph::getHeadVal()
{
    //returns and mark head pointer as visited
    head->is_visited = true;
    return head;
}
void Graph::addNode(char u)
{
    //Add nodes to the graph and increment vertices
    if (head == NULL)
    {
        head = new Node(u);
        last = head;
    }
    else
    {
        last->next = new Node(u);
        last = last->next;
    }
    ++vertices;
}
bool Graph::findNode(char u)
{
    //Finds node and returns bool
    for (Node *curr = head; curr != NULL; curr = curr->next)
        if (curr->data == u)
            return 1;
    return 0;
}
void Graph::addEdge(char u, char v)
{
    //Adds a edge to the graph using add node function
    //Function is dynamic and would add as many nodes as you like to graph
    if (!findNode(u))
        addNode(u);
    if (!findNode(v))
        addNode(v);
    Node *curr = head;
    AdjNode *c = NULL;

    while (curr != NULL)
    {
        if (curr->data == u)
            break;
        curr = curr->next;
    }
    if (curr->n == NULL)
        curr->n = new AdjNode(v);
    else
    {
        for (c = curr->n; c != NULL; c = c->next)
        {
            if (c->next == NULL)
            {
                c->next = new AdjNode(v);
                break;
            }
        }
    }
}
void Graph::printGraph()
{
    //prints graph
    for (Node *curr_1 = head; curr_1 != NULL; curr_1 = curr_1->next)
    {
        std::cout << curr_1->data << "->";
        for (AdjNode *curr_2 = curr_1->n; curr_2 != NULL; curr_2 = curr_2->next)
        {
            std::cout << curr_2->data << "-";
        }
        std::cout << "*" << std::endl;
    }
}
void Graph::BFSImpl(std::queue<Node *> q)
{
    //BFS recursive algo
    if (q.empty())
        return;
    Node *curr = q.front();
    AdjNode *c = curr->n;
    q.pop();
    std::cout << curr->data << "-";
    while (c != NULL)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == c->data)
                break;
            temp = temp->next; //Finds the Node* for AdjNode*
        }
        if (temp->is_visited != true)
        {
            //pushes to queue and marks it visited
            q.push(temp);
            temp->is_visited = true;
        }
        c = c->next;
    }
    BFSImpl(q);
}

void Graph::BFS(Node *curr)
{
    //Wrapper for BFS traversal implementation
    clearVisit();
    std::queue<Node *> queue;
    queue.push(getHeadVal());
    BFSImpl(queue);
    std::cout << '*' << std::endl;
    clearVisit();
}
bool Graph::checkDup(std::vector<Node *> arr, Node *node)
{
    //Checks for duplicate node inserted in an array
    for (std::vector<Node *>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it == node)
            return 1;
    }
    return 0;
}
Node *Graph::getOrigin(Node *val)
{
    //gets parent of the given Node
    for (Node *curr_1 = head; curr_1 != NULL; curr_1 = curr_1->next)
    {
        for (AdjNode *curr_2 = curr_1->n; curr_2 != NULL; curr_2 = curr_2->next)
        {
            if (curr_2->data == val->data)
                return curr_1;
        }
    }
    return NULL;
}
void Graph::shortBFSImpl(std::queue<Node *> q, Node *src, Node *dest)
{
    //BFS shortest path algo
    if (checkDup(neighbour, dest))
        return;
    Node *curr = q.back();
    AdjNode *c = curr->n;
    q.pop();
    while (c != NULL)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == c->data)
                break;
            temp = temp->next;
        }
        if (temp->is_visited != true)
        {
            q.push(temp);
            if (!checkDup(neighbour, temp))
            {
                neighbour.push_back(temp);
                origin.push_back(getOrigin(temp));
            }
            temp->is_visited = true;
        }
        c = c->next;
    }
    shortBFSImpl(q, src, dest);
}
int Graph::getInd(std::vector<Node *> arr, int val)
{
    for (int i = arr.size() - 1; i > -1; --i)
        if (arr[i]->data == val)
            return i;
}
void Graph::shortBFS(Node *src, Node *dest)
{
    //Wrapper for BFS traversal implementation
    clearVisit();
    std::queue<Node *> queue;
    queue.push(getHeadVal());
    neighbour.push_back(queue.front());
    origin.push_back(NULL);
    shortBFSImpl(queue, src, dest);
    while (!stack.empty())
    {
        stack.pop();
    }

    for (int i = neighbour.size() - 1;;)
    {
        if (src->data == neighbour[i]->data)
        {
            stack.push(src);
            break;
        }
        stack.push(neighbour[i]);
        i = getInd(neighbour, origin[i]->data);
    }
    while (!stack.empty())
    {
        std::cout << stack.top()->data << "-";
        stack.pop();
    }
    std::cout << "*" << std::endl;
    clearVisit();
}
bool Graph::checkIfVisited(AdjNode *curr_1)
{
    //checks a node if visited or not and returns a bool
    for (Node *curr_2 = head; curr_2 != NULL; curr_2 = curr_2->next)
    {
        if (curr_2->data == curr_1->data)
            return curr_2->is_visited;
    }
}
Node *Graph::getNode(AdjNode *curr_1)
{
    //Gets a Node type based on Adjacent Node
    for (Node *curr_2 = head; curr_2 != NULL; curr_2 = curr_2->next)
    {
        if (curr_2->data == curr_1->data)
            return curr_2;
    }
    return NULL;
}
Node *Graph::getNode(char data)
{
    //Gets a node type based on data
    for (Node *curr_1 = head; curr_1 != NULL; curr_1 = curr_1->next)
    {
        if (curr_1->data == data)
            return curr_1;
    }
    return NULL;
}
void Graph::DFSImpl(Node *curr_1)
{
    //Recursive DFS Algo
    curr_1->is_visited = true;
    stack.push(curr_1);
    for (AdjNode *curr_2 = curr_1->n; curr_2 != NULL; curr_2 = curr_2->next)
    {
        Node *neighbour = getNode(curr_2);
        if (neighbour->is_visited == false)
            DFSImpl(neighbour);
    }
}
void Graph::DFS(Node *curr)
{
    //Wrapper for DFS algo
    clearVisit();
    DFSImpl(curr);
    while (!stack.empty())
    {
        std::cout << (stack.top())->data << "-";
        stack.pop();
    }
    std::cout << '*' << std::endl;
    clearVisit();
}
bool Graph::clearVisit()
{
    //Clears visit of the whole graph
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->is_visited = false;
    }
}
