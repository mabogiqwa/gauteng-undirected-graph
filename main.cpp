//Source code for the graph that will contain 
//data related to the distances between locations in
//Gauteng map
#include <iostream>

struct Node
{
    double distance;
    Node *link;
};
typedef Node* NodePtr;

void add_node_to_list(NodePtr &currentNode, double distance);

int main()
{
    NodePtr list = new Node[32];

    add_node_to_list(list[0], distance)

    delete[] list;

    return 0;
}

void add_node_to_list(NodePtr &currentNode, double distance)
{
    //This creates a FIFO data structure
    NodePtr tempPtr = new Node;
    tempPtr->coefficient = c;
    tempPtr->exponent = exp;
    currentNode->link = tempPtr;
    currentNode = tempPtr;
    tempPtr->link = nullptr;
}