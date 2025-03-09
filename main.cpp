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

    add_node_to_list(head1, 22); //(0,1)
    add_node_to_list(head1, 6.6); //(0,2)
    add_node_to_list(head1, 36.2); //(0,3)

    listArray[1] = new Node{1, nullptr};
    NodePtr head2 = listArray[1];

    add_node_to_list(head2, 22); //(1, 0)
    add_node_to_list(head2, 30.2); //(1,2)
    add_node_to_list(head2, 10.4); //(1,3)
    add_node_to_list(head2, 14); //(1,4)
    add_node_to_list(head2, 51.3); //(1,5)


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
