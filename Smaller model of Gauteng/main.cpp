//Source code for the graph that will contain
//data related to the distances between locations in
//Gauteng map
//Gonna rename the Node struct into Edge
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <iomanip>

const int SIZE = 33;
struct Node
{
    int destination;
    double distance;
    Node *link;
};
typedef Node* NodePtr;

void add_node_to_list(NodePtr &currentNode, int destination, double distance);
//Postcondition: Adds a new node to a FIFO data structure

void create_gauteng_graph(Node** listArray);
//Postcondition: Stores data related to the Gauteng province into a graph. A graph
//in this instance is represented as an array of linked lists. Each index being a location

void dijkstra(Node** listArray, int start, int end);

void print_path(const std::vector<int>& parent, int end);

void print_data(Node** listArray);
//Postcondition: Prints the data stores in the graph. The data is the distances between
//locations

int main()
{
    Node* listArray[SIZE] = {nullptr};
    int start, end;

    create_gauteng_graph(listArray);

    std::cout << "Enter the start location from 0-32: ";
    std::cin >> start;
    std::cout << "Enter the destination location from 0-32: ";
    std::cin >> end;

    std::string provinceNames[SIZE+1] = {"Temba","Soshanguve","Hammanskraal","Winterveld","Klipgat","Roodeplaat","Refilwe","Mabopane","Ga-Rankuwa","Hartbeespoort","Pretoria",
                                 "Cullinan","Rayton","Ekangala","Centurion","Bronkhorspruit","Midrand","Tembisa","Kempton Park","Randburg","Sandton","Roodepoort","Krugersdorp",
                                 "Benoni","Springs","Boksburg","Alberton","Soweto","Randfontein","Carltonville","Fochville","Vereeniging","Vanderbijlpark"};
    dijkstra(listArray, start, end);


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

void dijkstra(Node** listArray, int start, int end)
{
    const double INF = std::numeric_limits<double>::infinity(); //defines infinity

    std::vector<double> distance(SIZE, INF);

    std::vector<int> parent(SIZE, -1);

    std::vector<bool> visited(SIZE, false);

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> priorityQueue;

    distance[start] = 0;

    priorityQueue.push(std::make_pair(0.0, start));

    while (!priorityQueue.empty())
    {
        int u = priorityQueue.top().second;
        priorityQueue.pop();

        if (u == end)
            break;

        if (visited[u])
            continue;

        visited[u] = true;

        for (NodePtr temp = listArray[u]; temp != nullptr; temp = temp->link)
        {
            int v = temp->destination;
            double weight = temp->distance;

            if (!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                priorityQueue.push(std::make_pair(distance[v], v));
            }
        }
    }

    std::string provinceNames[SIZE+1] = {"Temba","Soshanguve","Hammanskraal","Winterveld","Klipgat","Roodeplaat","Refilwe","Mabopane","Ga-Rankuwa","Hartbeespoort","Pretoria",
                                 "Cullinan","Rayton","Ekangala","Centurion","Bronkhorspruit","Midrand","Tembisa","Kempton Park","Randburg","Sandton","Roodepoort","Krugersdorp",
                                 "Benoni","Springs","Boksburg","Alberton","Soweto","Randfontein","Carltonville","Fochville","Vereeniging","Vanderbijlpark"};

    if (distance[end] == INF)
    {
        std::cout << "No path exists from " << provinceNames[start] << " to " << provinceNames[end] << std::endl;
    } else {
        std::cout << "Shortest distance from " << provinceNames[start] << " to " << provinceNames[end] << " is " << std::fixed << std::setprecision(1) << distance[end] << " km "  << std::endl;

        std::cout << "Path: ";
        print_path(parent, end);
        std::cout << std::endl;
    }
}

void print_path(const std::vector<int>& parent, int end)
{
    std::string provinceNames[SIZE+1] = {"Temba","Soshanguve","Hammanskraal","Winterveld","Klipgat","Roodeplaat","Refilwe","Mabopane","Ga-Rankuwa","Hartbeespoort","Pretoria",
                                 "Cullinan","Rayton","Ekangala","Centurion","Bronkhorspruit","Midrand","Tembisa","Kempton Park","Randburg","Sandton","Roodepoort","Krugersdorp",
                                 "Benoni","Springs","Boksburg","Alberton","Soweto","Randfontein","Carltonville","Fochville","Vereeniging","Vanderbijlpark"};

    if (parent[end] == -1)
    {
        std::cout << provinceNames[end];
        return;
    }

    print_path(parent, parent[end]);

    std::cout << " -> " << provinceNames[end];
}

void create_gauteng_graph(Node** listArray)
{
    //Temba
    listArray[0] = new Node{1, 22, nullptr}; //(0,1) Temba->Sosha
    NodePtr head1 = listArray[0];

    add_node_to_list(head1, 2, 6.6); //(0,2) Temba->Hammanskraal
    add_node_to_list(head1, 3, 36.2); //(0,3) Temba->Winterveld

    //Soshanguve
    listArray[1] = new Node{0, 22, nullptr}; //(1,0) Sosha->Temba
    NodePtr head2 = listArray[1];

    add_node_to_list(head2, 2, 20.2); //(1,2) Sosha->Hammanskraal
    add_node_to_list(head2, 3, 10.4); //(1,3) Sosha->Winterveld
    add_node_to_list(head2, 4, 14); //(1,4) Sosha->Klipgat
    add_node_to_list(head2, 5, 51.3); //(1,5) Sosha->Roodeplaat

    //Hammanskraal
    listArray[2] = new Node{0, 6.6, nullptr}; //(2,0) Hammanskraal->Temba
    NodePtr head3 = listArray[2];

    add_node_to_list(head3, 1, 20.2); //(2,1) Hammanskraal->Temba
    add_node_to_list(head3, 5, 43); //(2,5) Hammanskraal->Roodeplaat
    add_node_to_list(head3, 6, 49.1); //(2,6) Hammanskraal->Refilwe

    //Winterveld
    listArray[3] = new Node{0, 36.2, nullptr}; //(3,0) Winterveld->Temba
    NodePtr head4 = listArray[3];

    add_node_to_list(head4, 1, 10.4); //(3,1) Winterveld->Sosha
    add_node_to_list(head4, 4, 11.8); //(3,4) Winterveld->Klipgat

    //Klipgat
    listArray[4] = new Node{1, 14, nullptr}; //(4,1) Klipgat->Sosha
    NodePtr head5 = listArray[4];

    add_node_to_list(head5, 3, 11.8); //(4,3) Klipgat->Winterveld
    add_node_to_list(head5, 5, 56.3); //(4,5) Klipgat->Roodeplaat
    add_node_to_list(head5, 7, 7.8); //(4,7) Klipgat->Mabopane

    //Roodeplaat
    listArray[5] = new Node{1, 51.3, nullptr}; //(5,1)
    NodePtr head6 = listArray[5];

    add_node_to_list(head6, 2, 43); //(5,2) Roodeplaat->Hammanskraal
    add_node_to_list(head6, 4, 56.3); //(5,4) Roodeplaat->Klipgat
    add_node_to_list(head6, 6, 27.8); //(5,6) Roodeplaat->Refilwe
    add_node_to_list(head6, 7, 49.7); //(5,7) Roodeplaat->Mabopane
    add_node_to_list(head6, 8, 49.7); //(5,8) Roodeplaat->Ga-Rankuwa
    add_node_to_list(head6, 9, 60.1); //(5,9) Roodeplaat->Hartbeespoort
    add_node_to_list(head6, 10, 21.6); //(5,10) Roodeplaat->Pretoria

    //Refilwe
    listArray[6] = new Node{2, 49.1, nullptr}; //(6,2) Refilwe->Hammanskraal
    NodePtr head7 = listArray[6];

    add_node_to_list(head7, 5, 27.8); //(6,5) Refilwe->Roodeplaat
    add_node_to_list(head7, 11, 5.5); //(6,11) Refilwe->Cullinan
    add_node_to_list(head7, 13, 29.9); //(6,13) Refilwe->Ekangala

    //Mabopane
    listArray[7]  = new Node{4, 7.8, nullptr}; //(7,4)
    NodePtr head8 = listArray[7];

    add_node_to_list(head8, 5, 49.7); //(7,5)
    add_node_to_list(head8, 8, 9.9); //(7,8)

    //Ga-Rankuwa
    listArray[8] = new Node{5, 49.7, nullptr}; //(8,5)
    NodePtr head9 = listArray[8];

    add_node_to_list(head9, 7, 9.9); //(8,7)
    add_node_to_list(head9, 9, 24.2); //(8,9)

    //Hartbeespoort
    listArray[9] = new Node{4, 60.1, nullptr}; //(9,4)
    NodePtr head10 = listArray[9];

    add_node_to_list(head10, 8, 24.2); //(9,8)
    add_node_to_list(head10, 10, 33.9); //(9,10)
    add_node_to_list(head10, 13, 34); //(9,13)
    add_node_to_list(head10, 14, 82.6); //(9,14)

    //Pretoria
    listArray[10] = new Node{5, 21.6, nullptr}; //(10,5)
    NodePtr head11 = listArray[10];

    add_node_to_list(head11, 9, 33.9); //(10,9)
    add_node_to_list(head11, 12, 41.9); //(10,12)
    add_node_to_list(head11, 13, 15.1); //(10,13)

    //Cullinan
    listArray[11] = new Node{8, 5.5, nullptr};//(11,8)
    NodePtr head12 = listArray[11];

    add_node_to_list(head12, 12, 9.1); //(11,12)

    //Rayton
    listArray[12] = new Node{10, 41.9, nullptr}; //(12,10)
    NodePtr head13 = listArray[12];

    add_node_to_list(head13, 11, 9.1); //(12,11)
    add_node_to_list(head13, 13, 33.5); //(12,13)
    add_node_to_list(head13, 14, 60.2); //(12,14)
    add_node_to_list(head13, 15, 31.4); //(12,15)
    add_node_to_list(head13, 17, 57.7); //(12,17)
    add_node_to_list(head13, 18, 60); //(12,18)
    add_node_to_list(head13, 23, 53.9); //(12,22)
    add_node_to_list(head13, 24, 69.2); //(12,23)

    //Ekangala
    listArray[13] = new Node{6, 29.9, nullptr}; //(13,6)
    NodePtr head14 = listArray[13];

    add_node_to_list(head14, 12, 33.5); //(13,12)
    add_node_to_list(head14, 15, 19.6); //(13,15)

    //Centurion
    listArray[14] = new Node{9, 34, nullptr}; //(14,9)
    NodePtr head15 = listArray[14];

    add_node_to_list(head15, 10, 15.1); //(14,10)
    add_node_to_list(head15, 12, 60.2); //(14,12)
    add_node_to_list(head15, 16, 26.2); //(14,16)
    add_node_to_list(head15, 17, 40.5); //(14,17)
    add_node_to_list(head15, 19, 52.5); //(14, 19)
    add_node_to_list(head15, 22, 48.3); //(14, 21)

    //Bronkhorstspruit
    listArray[15] = new Node{12, 31.4, nullptr}; //(15,12)
    NodePtr head16 = listArray[15];

    add_node_to_list(head16, 13, 19.6); //(15,13)
    add_node_to_list(head16, 18, 68.2); //(15,18)
    add_node_to_list(head16, 23, 70.4); //(15,22)
    add_node_to_list(head16, 24, 68.7); //(15,23)

    //Midrand
    listArray[16] = new Node{14, 26.2, nullptr}; //(16,14)
    NodePtr head17 = listArray[16];

    add_node_to_list(head17, 17, 21.5); //(16,17)
    add_node_to_list(head17, 20, 15.6); //(16,20)

    //Tembisa
    listArray[17] = new Node{12, 57.7, nullptr}; //(17,12)
    NodePtr head18 = listArray[17];

    add_node_to_list(head18, 14, 40.5); //(17,14)
    add_node_to_list(head18, 16, 21.5); //(17,16)
    add_node_to_list(head18, 18, 12.4); //(17,18)
    add_node_to_list(head18, 20, 25.4); //(17,20)

    //Kempton Park
    listArray[18] = new Node{12, 60, nullptr}; //(18,12)
    NodePtr head19 = listArray[18];

    add_node_to_list(head19, 15, 68.2); //(18,15)
    add_node_to_list(head19, 17, 12.4); //(18,17)
    add_node_to_list(head19, 20, 19.3); //(18,20)
    add_node_to_list(head19, 23, 29); //(18,22)
    add_node_to_list(head19, 26, 39.2); //(18,25)

    //Randburg
    listArray[19] = new Node{14, 52.5, nullptr}; //(19,14)
    NodePtr head20 = listArray[19];

    add_node_to_list(head20, 20, 15.7); //(19,20)
    add_node_to_list(head20, 21, 12.6); //(19,21)

    //Sandton
    listArray[20] = new Node{16, 15.6, nullptr}; //(20,16)
    NodePtr head21 = listArray[20];

    add_node_to_list(head21, 17, 25.4); //(20,17)
    add_node_to_list(head21, 18, 19.3); //(20,18)
    add_node_to_list(head21, 19, 15.7); //(20,19)
    add_node_to_list(head21, 26, 36.8); //(20,25)

    //Roodepoort
    listArray[21] = new Node{19, 12.6, nullptr}; //(21,19)
    NodePtr head22 = listArray[21];

    add_node_to_list(head22, 22, 16.2); //(21,22)
    add_node_to_list(head22, 26, 38.2); //(21,26)
    add_node_to_list(head22, 27, 15.9); //(21,27)

    //Krugersdorp
    listArray[22] = new Node{9, 62.6, nullptr}; //(22,9)
    NodePtr head23 = listArray[22];

    add_node_to_list(head23, 14, 48.3); //(22,14)
    add_node_to_list(head23, 21, 16.2); //(22,21)
    add_node_to_list(head23, 28, 14.5); //(22,28)

    //Benoni
    listArray[23] = new Node{12, 53.9, nullptr}; //(23,12)
    NodePtr head24 = listArray[23];

    add_node_to_list(head24, 15, 70.4); //(23,15)
    add_node_to_list(head24, 18, 29); //(23,18)
    add_node_to_list(head24, 24, 19.7); //(23,24)
    add_node_to_list(head24, 25, 24.8); //(23,25)

    //Springs
    listArray[24] = new Node{12, 69.2, nullptr}; //(24,12)
    NodePtr head25 = listArray[24];

    add_node_to_list(head25, 15, 68.7); //(24,15)
    add_node_to_list(head25, 23, 19.7); //(24,23)
    add_node_to_list(head25, 25, 21.2); //(24,25)
    add_node_to_list(head25, 31, 90.7); //(24,31)

    //Boksburg
    listArray[25] = new Node{23, 24.8, nullptr}; //(25,23)
    NodePtr head26 = listArray[25];

    add_node_to_list(head26, 24, 21.2); //(25,24)
    add_node_to_list(head26, 26, 22.6); //(25,26)

    //Alberton
    listArray[26] = new Node{18, 39.2, nullptr}; //(26,18)
    NodePtr head27 = listArray[26];

    add_node_to_list(head27, 20, 36.8); //(26,20)
    add_node_to_list(head27, 21, 38.2); //(26,21)
    add_node_to_list(head27, 25, 22.6); //(26,25)
    add_node_to_list(head27, 26, 81.9); //(26,30)
    add_node_to_list(head27, 31, 45.4); //(26,31)

    //Soweto
    listArray[27] = new Node{21, 15.9, nullptr}; //(27,21)
    NodePtr head28 = listArray[27];

    add_node_to_list(head28, 26, 38.6); //(27,26)
    add_node_to_list(head28, 28, 24.2); //(27,28)
    add_node_to_list(head28, 29, 53.1); //(27,29)
    add_node_to_list(head28, 30, 53.7); //(27,30)

    //Randfontein
    listArray[28] = new Node{22, 14.5, nullptr}; //(28,22)
    NodePtr head29 = listArray[28];

    add_node_to_list(head29, 27, 24.2); //(28,27)
    add_node_to_list(head29, 29, 39.6); //(28,29)

    //Carltonville
    listArray[29] = new Node{27, 53.1, nullptr}; //(29,27)
    NodePtr head30 = listArray[29];

    add_node_to_list(head30, 28, 39.6); //(29,28)
    add_node_to_list(head30, 30, 17.7); //(29,30)

    //Fochville
    listArray[30] = new Node{26, 81.9, nullptr}; //(30,26)
    NodePtr head31 = listArray[30];

    add_node_to_list(head31, 27, 53.7); //(30,27)
    add_node_to_list(head31, 29, 17.7); //(30,29)
    add_node_to_list(head31, 31, 63.4); //(30,31)
    add_node_to_list(head31, 32, 53.4); //(30,32)

    //Vereeniging
    listArray[31] = new Node{24, 90.7, nullptr}; //(31,24)
    NodePtr head32 = listArray[31];

    add_node_to_list(head32, 26, 45.4); //(31,26)
    add_node_to_list(head32, 30, 63.4); //(31,30)
    add_node_to_list(head32, 32, 23); //(31,32)

    //Vanderbijlpark
    listArray[32] = new Node{30, 53.4, nullptr}; //(32,30)
    NodePtr head33 = listArray[32];

    add_node_to_list(head33, 31, 23); //(32,31)

}
