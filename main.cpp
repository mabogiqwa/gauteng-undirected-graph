//Source code for the graph that will contain
//data related to the distances between locations in
//Gauteng map
//Gonna rename the Node struct into Edge
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

void create_gauteng_graph(Node** listArray);

void print_data(Node** listArray);

int main()
{
    Node* listArray[SIZE] = {nullptr};

    create_gauteng_graph(listArray);

    print_data(listArray);

    return 0;
}

void print_data(Node** listArray)
{
    NodePtr tempPtr;
    int index;

    std::string provinceNames[SIZE+1] = {"Temba","Soshanguve","Hammanskraal","Winterveld","Klipgat","Roodeplaat","Refilwe","Mabopane","Ga-Rankuwa","Hartbeespoort","Pretoria",
                                 "Cullinan","Rayton","Ekangala","Centurion","Bronkhorspruit","Midrand","Tembisa","Kempton Park","Randburg","Sandton","Roodepoort","Krugersdorp",
                                 "Benoni","Springs","Boksburg","Alberton","Soweto","Randfontein","Carltonville","Fochville","Vereeniging","Vanderbijlpark"};


    index = 0;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << provinceNames[index] << ": ";
        for (tempPtr = listArray[i]; tempPtr != nullptr; tempPtr=tempPtr->link)
        {
            std::cout << tempPtr->distance << " ";
        }
        index = index + 1;
        std::cout << std::endl;
    }
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

void create_gauteng_graph(Node** listArray)
{
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

    //Randburg
    listArray[19] = new Node{19, nullptr};
    NodePtr head20 = listArray[19];

    add_node_to_list(head20, 52.5); //(19,14)
    add_node_to_list(head20, 15.7); //(19,20)
    add_node_to_list(head20, 12.6); //(19,21)

    //Sandton
    listArray[20] = new Node{20, nullptr};
    NodePtr head21 = listArray[20];

    add_node_to_list(head21, 15.6); //(20,16)
    add_node_to_list(head21, 25.4); //(20,17)
    add_node_to_list(head21, 19.3); //(20,18)
    add_node_to_list(head21, 15.7); //(20,19)
    add_node_to_list(head21, 36.8); //(20,25)

    //Roodepoort
    listArray[21] = new Node{21, nullptr};
    NodePtr head22 = listArray[21];

    add_node_to_list(head22, 12.6); //(21,19)
    add_node_to_list(head22, 16.2); //(21,22)
    add_node_to_list(head22, 38.2); //(21,26)
    add_node_to_list(head22, 15.9); //(21,27)

    //Krugersdorp
    listArray[22] = new Node{22, nullptr};
    NodePtr head23 = listArray[22];

    add_node_to_list(head23, 62.6); //(22,9)
    add_node_to_list(head23, 48.3); //(22,14)
    add_node_to_list(head23, 16.2); //(22,21)
    add_node_to_list(head23, 14.5); //(22,28)

    //Benoni
    listArray[23] = new Node{23, nullptr};
    NodePtr head24 = listArray[23];

    add_node_to_list(head24, 53.9); //(23,12)
    add_node_to_list(head24, 70.4); //(23,15)
    add_node_to_list(head24, 29); //(23,18)
    add_node_to_list(head24, 19.7); //(23,24)
    add_node_to_list(head24, 24.8); //(23,25)

    //Springs
    listArray[24] = new Node{24, nullptr};
    NodePtr head25 = listArray[24];

    add_node_to_list(head25, 69.2); //(24,12)
    add_node_to_list(head25, 68.7); //(24,15)
    add_node_to_list(head25, 19.7); //(24,23)
    add_node_to_list(head25, 21.2); //(24,25)
    add_node_to_list(head25, 90.7); //(24,31)

    //Boksburg
    listArray[25] = new Node{25, nullptr};
    NodePtr head26 = listArray[25];

    add_node_to_list(head26, 24.8); //(25,23)
    add_node_to_list(head26, 21.2); //(25,24)
    add_node_to_list(head26, 22.6); //(25,26)

    //Alberton
    listArray[26] = new Node{26, nullptr};
    NodePtr head27 = listArray[26];

    add_node_to_list(head27, 39.2); //(26,18)
    add_node_to_list(head27, 36.8); //(26,20)
    add_node_to_list(head27, 38.2); //(26,21)
    add_node_to_list(head27, 22.6); //(26,25)
    add_node_to_list(head27, 81.9); //(26,30)
    add_node_to_list(head27, 45.4); //(26,31)

    //Soweto
    listArray[27] = new Node{27, nullptr};
    NodePtr head28 = listArray[27];

    add_node_to_list(head28, 15.9); //(27,21)
    add_node_to_list(head28, 38.6); //(27,26)
    add_node_to_list(head28, 24.2); //(27,28)
    add_node_to_list(head28, 53.1); //(27,29)
    add_node_to_list(head28, 53.7); //(27,30)

    //Randfontein
    listArray[28] = new Node{28, nullptr};
    NodePtr head29 = listArray[28];

    add_node_to_list(head29, 14.5); //(28,22)
    add_node_to_list(head29, 24.2); //(28,27)
    add_node_to_list(head29, 39.6); //(28,29)

    //Carltonville
    listArray[29] = new Node{29, nullptr};
    NodePtr head30 = listArray[29];

    add_node_to_list(head30, 53.1); //(29,27)
    add_node_to_list(head30, 39.6); //(29,28)
    add_node_to_list(head30, 17.7); //(29,30)

    //Fochville
    listArray[30] = new Node{30, nullptr};
    NodePtr head31 = listArray[30];

    add_node_to_list(head31, 81.9); //(30,26)
    add_node_to_list(head31, 53.7); //(30,27)
    add_node_to_list(head31, 17.7); //(30,29)
    add_node_to_list(head31, 63.4); //(30,31)
    add_node_to_list(head31, 53.4); //(30,32)

    //Vereeniging
    listArray[31] = new Node{31, nullptr};
    NodePtr head32 = listArray[31];

    add_node_to_list(head32, 90.7); //(31,24)
    add_node_to_list(head32, 45.4); //(31,26)
    add_node_to_list(head32, 63.4); //(31,30)
    add_node_to_list(head32, 23); //(31,32)

    //Vanderbijlpark
    listArray[32] = new Node{32, nullptr};
    NodePtr head33 = listArray[32];

    add_node_to_list(head33, 53.4); //(32,30)
    add_node_to_list(head33, 23); //(32,31)

}
