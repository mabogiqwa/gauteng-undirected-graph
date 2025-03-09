//Source code for the graph that will contain
//data related to the distances between locations in
//Gauteng map
#include <iostream>

const int SIZE = 32;
struct Node
{
    double distance;
    Node *link;
};
typedef Node* NodePtr;

void add_node_to_list(NodePtr &currentNode, double distance);
//Postcondition: Adds a new node to a FIFO data structure
int main()
{
    Node* listArray[SIZE] = {nullptr};

    listArray[0] = new Node{0, nullptr};
    NodePtr head1 = listArray[0];

    add_node_to_list(head1, 22);
    add_node_to_list(head1, 6.6);
    add_node_to_list(head1, 36.2);

    for (NodePtr tempPtr = listArray[0]->link; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        std::cout << tempPtr->distance << " ";
    }

    return 0;
}

void add_node_to_list(NodePtr &currentNode, double distance)
{
    //This creates a FIFO data structure
    NodePtr tempPtr = new Node;
    tempPtr->distance = distance;
    currentNode->link = tempPtr;
    currentNode = tempPtr;
    tempPtr->link = nullptr;
}
