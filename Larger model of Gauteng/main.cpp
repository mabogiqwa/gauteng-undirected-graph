#include <iostream>
#include <iomanip>

const int SIZE = 33;

struct Node
{
    int destination;
    double distance;
    Node *link;
};
typedef Node* NodePtr;

oid add_node_to_list(NodePtr &currentNode, int destination, double distance);

void create_gauteng_graph(Node** listArray);

int main()
{

    return 0;
}

void create_gauteng_graph(Node** listArray)
{
    Node* listArray[SIZE] = {nullptr};

    //Winterveld
    listArray[0] = new Node{1, 24, nullptr}; //Winterveld->Reefentse
    NodePtr head = listArray[0];

    add_node_to_list(head, 7, 16); //Winterveld->Mabopane

    //Reefentse
    listArray[1] = new Node{0, 24, nullptr}; //Reefentse->Winterveld
    NodePtr head1 = listArray[1];

    add_node_to_list(head1, 2, 12); //Reefentse->Temba
    add_node_to_list(head1, 5, 9.4); //Reefentse->Soshanguve
    add_node_to_list(head1, 6, 12); //Reefentse->Hammanskraal

    //Temba
    listArray[2] = new Node{1, 12, nullptr};
    NodePtr head2 = listArray[2];

    add_node_to_list(head2, 1, 12); //Temba->Reefentse
    add_node_to_list(head2, 3, 16); //Temba->Klipdrift
    add_node_to_list(head2, 4, 7.3); //Temba->Marokoleng
    add_node_to_list(head2, 6, 6.8); //Temba->Hammanskraal

    //Klipdrift
    listArray[3] = new Node{2, 16, nullptr};
    NodePtr head3 = listArray[3];

    add_node_to_list(head3, 4, 11);
    add_node_to_list(head3, 10, 16);

    //Marokoleng
    listArray[4] = new Node{2, 7.3, nullptr};
    NodePtr head4 = listArray[4];

    add_node_to_list(head4, 3, 11);
    add_node_to_list(head4, 6, 6.6)
    add_node_to_list(head4, 10, 13);

    //Soshanguve
    listArray[5] = new Node{1, 9.4, nullptr};
    NodePtr head5 = listArray[5];

    add_node_to_list(head5, 6, 12);
    add_node_to_list(head5, 7, 11);

    //Hammanskraal
    listArray[6] = new Node{1, 12, nullptr};
    NodePtr head6 = listArray[6];

    add_node_to_list(head6, 2, 6.8);
    add_node_to_list(head6, 4, 6.6);
    add_node_to_list(head6, 5, 20);
    add_node_to_list(head6, 7, 31);
    add_node_to_list(head6, 8, 49);
    add_node_to_list(head6, 10, 13);
    add_node_to_list(head6, 11, 44);

    //Mabopane
    listArray[7] = new Node{0, 16, nullptr};
    NodePtr head7 = listArray[7];

    add_node_to_list(head7, 5, 11);
    add_node_to_list(head7, 6, 31);
    add_node_to_list(head7, 8, 18);
    add_node_to_list(head7, 9, 10);

    //Rosslyn
    listArray[8] = new Node{6, 49, nullptr};
    NodePtr head8 = listArray[8];

    add_node_to_list(head8, 7, 18);
    add_node_to_list(head8, 9, 14);
    add_node_to_list(head8, 11, 6.8);
    add_node_to_list(head8, 12, 8.6);

    //Ga-Rankuwa
    listArray[9] = new Node{7, 10, nullptr};
    NodePtr head9 = listArray[9];

    add_node_to_list(head9, 8, 14);
    add_node_to_list(head9, 12, 6);

    //Komdraai
    listArray[10] = new Node{3, 16, nullptr};
    NodePtr head10 = listArray[10];

    add_node_to_list(head10, 4, 13);
    add_node_to_list(head10, 6, 13);
    add_node_to_list(head10, 11, 32);
    add_node_to_list(head10, 13, 16);

    //Akasia
    listArray[11] = new Node{6, 44, nullptr};
    NodePtr head11 = listArray[11];

    add_node_to_list(head11, 8, 6.8);
    add_node_to_list(head11, 12, 11);
    add_node_to_list(head11, 13, 29);
    add_node_to_list(head11, 14, 25);
    add_node_to_list(head11, 15, 21);

    //Sefako-Makgathu University
    listArray[12] = new Node{8, 8.6, nullptr};
    NodePtr head12 = listArray[12];

    add_node_to_list(head12, 9, 6);
    add_node_to_list(head12, 11, 11);
    add_node_to_list(head12, 14, 33);

    //Wallmannsthal
    listArray[13] = new Node{10, 16, nullptr};
    NodePtr head13= listArray[13];

    add_node_to_list(head13 11, 29);
    add_node_to_list(head13, 15, 29);
    add_node_to_list(head13, 16, 28);
    add_node_to_list(head13, 20, 21);

    //Atteridgeville
    listArray[14] = new Node{11, 25, nullptr};
    NodePtr head14 = listArray[14];

    add_node_to_list(head14, 12, 33);
    add_node_to_list(head14, 15, 13);
    add_node_to_list(head14, 17, 7);

    //National Zoological Gardens
    listArray[15] = new Node{11, 21, nullptr};
    NodePtr head15= listArray[15];

    add_node_to_list(head15 13, 29);
    add_node_to_list(head15, 14, 13);
    add_node_to_list(head15, 16, 2.4);
    add_node_to_list(head15, 17, 13);
    add_node_to_list(head15, 18, 1.9);

    //Union Buildings
    listArray[16] = new Node{13, 29, nullptr};
    NodePtr head16 = listArray[16];

    add_node_to_list(head16, 15, 2.4);
    add_node_to_list(head16, 18, 1.9);
    add_node_to_list(head16, 19, 15);

    //Laudium
    listArray[17] = new Node{14, 7, nullptr};
    NodePtr head17 = listArray[17];

    add_node_to_list(head17, 15, 13);
    add_node_to_list(head17, 18, 28);
    add_node_to_list(head17, 28, 16);
    add_node_to_list(head17, 29, 7.7);

    //Pretoria Central
    listArray[18] = new Node{15, 1.9, nullptr};
    NodePtr head18 = listArray[18];

    add_node_to_list(head18, 16, 3.3);
    add_node_to_list(head18, 17, 12);
    add_node_to_list(head18, 19, 16);
    add_node_to_list(head18, 28, 2.7);

    //Montana Park
    listArray[19] = new Node{16, 15, nullptr};
    NodePtr head19 = listArray[19];

    add_node_to_list(head19, 18, 16);
    add_node_to_list(head19, 24, 7.5);
    add_node_to_list(head19, 26, 14);

    //Pebble Rock Village
    listArray[20] = new Node{13, 21, nullptr};
    NodePtr head20 = listArray[20];

    add_node_to_list(head20, 21, 8.8);
    add_node_to_list(head20, 22, 27);

    //Baviaanspoort
    listArray[21] = new Node{20, 8.8, nullptr};
    NodePtr head21 = listArray[21];

    add_node_to_list(head21, 24, 4.5);
    add_node_to_list(head21, 30, 21);

    //Refilwe
    listArray[22] = new Node{20, 27, nullptr};
    NodePtr head22 = listArray[10];

    add_node_to_list(head22, 23, 30);
    add_node_to_list(head22, 30, 5.5);

    //Ekangala
    listArray[23] = new Node{22, 30, nullptr};
    NodePtr head23 = listArray[23];

    add_node_to_list(head23, 31, 8.5);

    //Roodeplaat
    listArray[24] = new Node{19, 7.5, nullptr};
    NodePtr head24 = listArray[24];

    add_node_to_list(head24, 21, 4.5);
    add_node_to_list(head24, 25, 18);
    add_node_to_list(head24, 32, 22);

    //University of Pretoria
    listArray[25] = new Node{24, 18, nullptr};
    NodePtr head25 = listArray[25];

    add_node_to_list(head25, 26, 2.4);
    add_node_to_list(head25, 27, 30);

    //Sunnyside
    listArray[26] = new Node{19, 14, nullptr};
    NodePtr head26 = listArray[26];

    add_node_to_list(head26, 25, 2.4);
    add_node_to_list(head26, 28, 2.1);

    //Pyramid
    listArray[27] = new Node{25, 30, nullptr};
    NodePtr head27 = listArray[27];

    add_node_to_list(head27, 28, 25);
    add_node_to_list(head27, 32, 12);
    add_node_to_list(head27, 33, 50);

    //University of South Africa
    listArray[28] = new Node{17, 16, nullptr};
    NodePtr head28 = listArray[28];

    add_node_to_list(head28, 18, 2.7);
    add_node_to_list(head28, 26, 2.1);
    add_node_to_list(head28, 27, 25);
    add_node_to_list(head28, 29, 16);
    add_node_to_list(head28, 33, 13);

    //Centurion
    listArray[29] = new Node{17, 7.7, nullptr};
    NodePtr head29 = listArray[29];

    add_node_to_list(head29, 28, 16);
    add_node_to_list(head29, 35, 5.3);

    //Cullinan
    listArray[30] = new Node{21, 21, nullptr};
    NodePtr head30 = listArray[30];

    add_node_to_list(head30, 22, 5.5);
    add_node_to_list(head30, 31, 22);

    //Rethabiseng
    listArray[31] = new Node{23, 8.5, nullptr};
    NodePtr head31 = listArray[31];

    add_node_to_list(head31, 30, 22);
    add_node_to_list(head31, 34, 13);

    //Wonderboom National Airport
    listArray[32] = new Node{24, 22, nullptr};
    NodePtr head32 = listArray[32];

    add_node_to_list(head32, 27, 12);
    add_node_to_list(head32, 30, 41);
    add_node_to_list(head32, 33, 30);
    add_node_to_list(head32, 34, 74);
    add_node_to_list(head32, 36, 45);
    add_node_to_list(head32, 44, 74);

    //Eldoraigne
    listArray[33] = new Node{27, 50, nullptr};
    NodePtr head33 = listArray[33];

    add_node_to_list(head33, 28, 13);
    add_node_to_list(head33, 32, 30);
    add_node_to_list(head33, 35, 2.6);

    //Zithobeni
    listArray[34] = new Node{31, 13, nullptr};
    NodePtr head34 = listArray[34];

    add_node_to_list(head34, 32, 74);
    add_node_to_list(head34, 43, 6.4);

    //Wierdapark
    listArray[35] = new Node{29, 5.3, nullptr};
    NodePtr head35 = listArray[35];

    add_node_to_list(head35, 33, 2.6);
    add_node_to_list(head35, 36, 2.9);
    add_node_to_list(head35, 38, 9.9);
    add_node_to_list(head35, 45, 77);

    //Hennopsdark
    listArray[36] = new Node{32, 45, nullptr};
    NodePtr head36 = listArray[36];

    add_node_to_list(head36, 35, 2.9);
    add_node_to_list(head36, 37, 4.1);

    //Rooihuiskraal
    listArray[37] = new Node{36, 4.1, nullptr};
    NodePtr head37 = listArray[37];

    add_node_to_list(head37, 38, 7.7);

    //Olievenhoutbosch
    listArray[38] = new Node{35, 9.9, nullptr};
    NodePtr head38 = listArray[38];

    add_node_to_list(head38, 37, 7.7);
    add_node_to_list(head38, 39, 8.4);

    //Noordwyk
    listArray[39] = new Node{40, 8, nullptr};
    NodePtr head39 = listArray[39];

    add_node_to_list(head39, 41, 6.4);

    //Kyalami Grand Prix
    listArray[40] = new Node{39, 8, nullptr};
    NodePtr head40 = listArray[40];

    add_node_to_list(head32, 42, 4);
    add_node_to_list(head32, 47, 5.2);

    //Glen Austion
    listArray[41] = new Node{39, 6.4, nullptr};
    NodePtr head41 = listArray[41];

    add_node_to_list(head41, 42, 9.1);
    add_node_to_list(head41, 44, 87);

    //Vorna Valley
    listArray[42] = new Node{40, 4, nullptr};
    NodePtr head42 = listArray[42];

    add_node_to_list(head42, 41, 9.1);
    //Bronkhorstspruit
    listArray[43] = new Node{34, 6.4, nullptr};
    NodePtr head43 = listArray[43];

    add_node_to_list(head43, 44, 2.2);

    //Erasmus
    listArray[44] = new Node{32, 74, nullptr};
    NodePtr head44 = listArray[44];

    add_node_to_list(head44, 34, 8.5);
    add_node_to_list(head44, 41, 87);
    add_node_to_list(head44, 43, 2.2);
    add_node_to_list(head44, 55, 71);
    add_node_to_list(head44, 56, 60);
    add_node_to_list(head44, 74, 70);

    //Magaliesig
    listArray[45] = new Node{35, 77, nullptr};
    NodePtr head45 = listArray[45];

    add_node_to_list(head45, 35, 77);
    add_node_to_list(head45, 46, 65);
    add_node_to_list(head45, 49, 65);

    //Paulshof
    listArray[46] = new Node{45, 65, nullptr};
    NodePtr head46 = listArray[46];

    add_node_to_list(head46, 47, 5.2);
    add_node_to_list(head46, 48, 4.7);

    //Sunninghill
    listArray[47] = new Node{40, 5.2, nullptr};
    NodePtr head47 = listArray[47];

    add_node_to_list(head47, 46, 5.2);
    add_node_to_list(head47, 48, 5.1);
    add_node_to_list(head47, 55, 22);

    //Woodmead
    listArray[48] = new Node{46, 4.7, nullptr};
    NodePtr head48 = listArray[48];

    add_node_to_list(head48, 47, 5.1);
    add_node_to_list(head48, 49, 9.4);
    add_node_to_list(head48, 50, 6.1);

    //Bryanston
    listArray[49] = new Node{45, 65, nullptr};
    NodePtr head49 = listArray[49];

    add_node_to_list(head49, 48, 9.4);
    add_node_to_list(head49, 60, 22);
    add_node_to_list(head49, 62, 63);

    //Morningside
    listArray[50] = new Node{48, 6.1, nullptr};
    NodePtr head48 = listArray[50];

    add_node_to_list(head50, 51, 16);
    add_node_to_list(head50, 58, 9.3);
    add_node_to_list(head50, 60, 27);

    //Lethabong
    listArray[51] = new Node{50, 16, nullptr};
    NodePtr head48 = listArray[51];

    add_node_to_list(head51, 52, 5.1);
    add_node_to_list(head51, 49, 9.4);
    add_node_to_list(head51, 50, 6.1);
    add_node_to_list(head51, 52, 9.8);

    //Kempton Park
    listArray[52] = new Node{55, 5.9, nullptr};
    NodePtr head48 = listArray[52];

    add_node_to_list(head52, 51, 9.8);

    //Sandton
    listArray[53] = new Node{54, 15, nullptr};
    NodePtr head53 = listArray[53];

    add_node_to_list(head53, 58, 5.2);

    //Edenvale
    listArray[54] = new Node{53, 15, nullptr};
    NodePtr head54 = listArray[54];

    add_node_to_list(head54, 55, 6.2);
    add_node_to_list(head54, 58, 15);
    add_node_to_list(head54, 65, 15);

    //OR Tambo
    listArray[55] = new Node{44, 71, nullptr};
    NodePtr head55 = listArray[55];

    add_node_to_list(head55, 47, 22);
    add_node_to_list(head55, 52, 5.9);
    add_node_to_list(head55, 54, 6.2);
    add_node_to_list(head55, 56, 28);
    add_node_to_list(head55, 57, 22);
    add_node_to_list(head55, 69, 17);
    add_node_to_list(head55, 70, 13);
    add_node_to_list(head55, 71, 37);

    //Daveyton
    listArray[56] = new Node{44, 60, nullptr};
    NodePtr head56 = listArray[56];

    add_node_to_list(head56, 55, 28);
    add_node_to_list(head56, 57, 7.4);
    add_node_to_list(head56, 71, 19);
    add_node_to_list(head56, 74, 63);

    //Benoni
    listArray[57] = new Node{55, 22, nullptr};
    NodePtr head57 = listArray[57];

    add_node_to_list(head57, 56, 7.4);
    add_node_to_list(head57, 71, 22);

    //Melrose Arch
    listArray[58] = new Node{50, 9.8, nullptr};
    NodePtr head58 = listArray[58];

    add_node_to_list(head58, 53, 5.2);
    add_node_to_list(head58, 54, 15);
    add_node_to_list(head58, 59, 2.4);
    add_node_to_list(head58, 64, 8.2);

    //Parkton
    listArray[59] = new Node{58, 7.7, nullptr};
    NodePtr head59 = listArray[59];

    add_node_to_list(head59, 60, 16);
    add_node_to_list(head59, 64, 2.4);

    //Roodeport
    listArray[60] = new Node{49, 22, nullptr};
    NodePtr head60 = listArray[60];

    add_node_to_list(head60, 50, 27);
    add_node_to_list(head60, 59, 16);
    add_node_to_list(head60, 61, 16);
    add_node_to_list(head60, 67, 16);

    //Krugersdorp
    listArray[61] = new Node{60, 16, nullptr};
    NodePtr head61 = listArray[61];

    add_node_to_list(head61, 62, 31);
    add_node_to_list(head61, 63, 15);

    //Magaliesburg
    listArray[62] = new Node{49, 63, nullptr};
    NodePtr head48 = listArray[62];

    add_node_to_list(head62, 61, 31);

    //Randfontein
    listArray[63] = new Node{61, 15, nullptr};
    NodePtr head63 = listArray[48];

    add_node_to_list(head63, 66, 40);
    add_node_to_list(head63, 67, 36);
    add_node_to_list(head63, 50, 6.1);


    //Hillbrow

    //Kensington

    //Carletonville

    //Johannesburg

    //Wits

    //Germiston

    //Boksburg

    //Springs

    //Rosettenville

    //Fochville

    //Devon

    //Brakpan

    //Johannesburg

    //Meadowlands

    //Dobsonville

    //Zola

    //Jabulani

    //Zondi

    //Lenasia

    //Alberton

    //Vosloorus

    //Nigel

    //Katlehong

    //Eikenhof

    //Thokoza

    //Vlakfontein

    //Lawley

    //Protea

    //Vlakfontein

    //Orange Farm

    //Three Rivers



}

void add_node_to_list(NodePtr &currentNode, int destination, double distance)
{
    //This creates a FIFO data structure
    NodePtr tempPtr = new Node;
    tempPtr->destination = destination;
    tempPtr->distance = distance;
    currentNode->link = tempPtr;
    currentNode = tempPtr;
    tempPtr->link = nullptr;
}
