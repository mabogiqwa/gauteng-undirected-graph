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

    //Temba
    listArray[0] = new Node{0, nullptr};
    NodePtr head1 = listArray[0];

    add_node_to_list(head1, 22); //(0,1)
    add_node_to_list(head1, 6.6); //(0,2)
    add_node_to_list(head1, 36.2); //(0,3)

    //Soshanguve
    listArray[1] = new Node{1, nullptr};
    NodePtr head2 = listArray[1];

    add_node_to_list(head2, 22); //(1, 0)
    add_node_to_list(head2, 30.2); //(1,2)
    add_node_to_list(head2, 10.4); //(1,3)
    add_node_to_list(head2, 14); //(1,4)
    add_node_to_list(head2, 51.3); //(1,5)

    //Hammanskraal
    listArray[2] = new Node{2, nullptr};
    NodePtr head3 = listArray[2];

    add_node_to_list(head3, 6.6); //(2,0)
    add_node_to_list(head3, 20.2); //(2,1)
    add_node_to_list(head3, 43); //(2,5)
    add_node_to_list(head3, 49.1); //(2,6)

    //Winterveld
    listArray[3] = new Node{3, nullptr};
    NodePtr head4 = listArray[3];

    add_node_to_list(head4, 36.2); //(3,0)
    add_node_to_list(head4, 10.4); //(3,1)
    add_node_to_list(head4, 11.8); //(3,4)

    //Klipgat
    listArray[4] = new Node{4, nullptr};
    NodePtr head5 = listArray[4];

    add_node_to_list(head5, 14); //(4,1)
    add_node_to_list(head5, 11.8); //(4,3)
    add_node_to_list(head5, 56.3); //(4,5)
    add_node_to_list(head5, 7.8); //(4,7)

    //Roodeplaat
    listArray[5] = new Node{5, nullptr};
    NodePtr head6 = listArray[5];

    add_node_to_list(head6, 51.3); //(5,1)
    add_node_to_list(head6, 43); //(5,2)
    add_node_to_list(head6, 56.3); //(5,4)
    add_node_to_list(head6, 27.8); //(5,6)
    add_node_to_list(head6, 49.7); //(5,7)
    add_node_to_list(head6, 49.7); //(5,8)
    add_node_to_list(head6, 60.1); //(5,9)
    add_node_to_list(head6, 21.6); //(5,10)

    //Refilwe
    listArray[6] = new Node{6, nullptr};
    NodePtr head7 = listArray[6];

    add_node_to_list(head7, 49.1); //(6,2)
    add_node_to_list(head7, 27.8); //(6,5)
    add_node_to_list(head7, 5.5); //(6,11)
    add_node_to_list(head7, 29.9); //(6,13)

    //Mabopane
    listArray[7]  = new Node{7, nullptr};
    NodePtr head8 = listArray[7];

    add_node_to_list(head8, 7.8); //(7,4)
    add_node_to_list(head8, 49.7); //(7,5)
    add_node_to_list(head8, 9.9); //(7,8)

    //Ga-Rankuwa
    listArray[8] = new Node{8, nullptr};
    NodePtr head9 = listArray[8];

    add_node_to_list(head9, 49.7); //(8,5)
    add_node_to_list(head9, 9.9); //(8,7)
    add_node_to_list(head9, 24.2); //(8,9)

    //Hartbeespoort
    listArray[9] = new Node{9, nullptr};
    NodePtr head10 = listArray[9];

    add_node_to_list(head10, 60.1); //(9,4)
    add_node_to_list(head10, 24.2); //(9,8)
    add_node_to_list(head10, 33.9); //(9,10)
    add_node_to_list(head10, 34); //(9,13)
    add_node_to_list(head10, 82.6); //(9,14)

    //Pretoria
    listArray[10] = new Node{10, nullptr};
    NodePtr head11 = listArray[10];

    add_node_to_list(head11, 21.6); //(10,5)
    add_node_to_list(head11, 33.9); //(10,9)
    add_node_to_list(head11, 41.9); //(10,12)
    add_node_to_list(head11, 15.1); //(10,13)

    //Cullinan
    listArray[11] = new Node{11, nullptr};
    NodePtr head12 = listArray[11];

    add_node_to_list(head12, 5.5); //(11,8)
    add_node_to_list(head12, 9.1); //(11,12)

    //Rayton
    listArray[12] = new Node{12, nullptr};
    NodePtr head13 = listArray[12];

    add_node_to_list(head13, 41.9); //(12,10)
    add_node_to_list(head13, 9.1); //(12,11)
    add_node_to_list(head13, 33.5); //(12,13)
    add_node_to_list(head13, 60.2); //(12,14)
    add_node_to_list(head13, 31.4); //(12,15)
    add_node_to_list(head13, 57.7); //(12,17)
    add_node_to_list(head13, 60); //(12,18)
    add_node_to_list(head13, 53.9); //(12,22)
    add_node_to_list(head13, 69.2); //(12,23)

    //Ekangala
    listArray[13] = new Node{13, nullptr};
    NodePtr head14 = listArray[13];

    add_node_to_list(head14, 29.9); //(13,6)
    add_node_to_list(head14, 33.5); //(13,12)
    add_node_to_list(head14, 19.6); //(13,15)

    //Centurion
    listArray[14] = new Node{14, nullptr};
    NodePtr head15 = listArray[14];

    add_node_to_list(head15, 34); //(14,9)
    add_node_to_list(head15, 15.1); //(14,10)
    add_node_to_list(head15, 60.2); //(14,12)
    add_node_to_list(head15, 26.2); //(14,16)
    add_node_to_list(head15, 40.5); //(14,17)
    add_node_to_list(head15, 52.5); //(14, 19)
    add_node_to_list(head15, 48.3); //(14, 21)

    //Bronkhorstspruit
    listArray[15] = new Node{15, nullptr};
    NodePtr head16 = listArray[15];

    add_node_to_list(head16, 31.4); //(15,12)
    add_node_to_list(head16, 19.6); //(15,13)
    add_node_to_list(head16, 68.2); //(15,18)
    add_node_to_list(head16, 70.4); //(15,22)
    add_node_to_list(head16, 68.7); //(15,23)

    //Midrand
    listArray[16] = new Node{16, nullptr};
    NodePtr head17 = listArray[16];

    add_node_to_list(head17, 26.2); //(16,14)
    add_node_to_list(head17, 21.5); //(16,17)
    add_node_to_list(head17, 15.6); //(16,20)

    //Tembisa
    listArray[17] = new Node{17, nullptr};
    NodePtr head18 = listArray[17];

    add_node_to_list(head18, 57.7); //(17,12)
    add_node_to_list(head18, 40.5); //(17,14)
    add_node_to_list(head18, 21.5); //(17,16)
    add_node_to_list(head18, 12.4); //(17,18)
    add_node_to_list(head18, 25.4); //(17,20)

    //Kempton Park
    listArray[18] = new Node{18, nullptr};
    NodePtr head19 = listArray[18];

    add_node_to_list(head19, 60); //(18,12)
    add_node_to_list(head19, 68.2); //(18,15)
    add_node_to_list(head19, 12.4); //(18,17)
    add_node_to_list(head19, 19.3); //(18,20)
    add_node_to_list(head19, 29); //(18,22)
    add_node_to_list(head19, 39.2); //(18,25)


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
