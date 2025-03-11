#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

const int SIZE = 103;

struct Node {
    int destination;
    double distance;
    Node* link;
};

typedef Node* NodePtr;

void add_node_to_list(NodePtr& currentNode, int destination, double distance);
void create_gauteng_graph(Node** listArray);
std::vector<int> reconstruct_path(const std::vector<int>& previous, int start, int end);
void print_shortest_path(int start, int end, const std::vector<double>& distances, const std::vector<int>& previous);
std::pair<std::vector<double>, std::vector<int>> dijkstra(Node** listArray, int numVertices, int start);

int main() {
    const int NUM_VERTICES = SIZE;

    // Initialize adjacency list
    Node** listArray = new Node*[NUM_VERTICES];
    for (int i = 0; i < NUM_VERTICES; i++) {
        listArray[i] = nullptr;
    }

    int startVertex, endVertex;
    create_gauteng_graph(listArray);

    std::cout << "Enter the start location from 0-102: ";
    std::cin >> startVertex;
    std::cout << "Enter the destination location from 0-102: ";
    std::cin >> endVertex;

    std::string locations[SIZE] = {"Winterveld","Reefentse","Temba","Klipdrift","Marokoleng","Soshanguve","Hammanskraal","Mabopane","Rosslyn","Ga-Rankuwa",
                             "Komdraai","Akasia","SMHSU","Wallmannsthal","Atteridgeville","National Zoological Gardens", "Union Buildings","Laudium",
                             "Pretoria Central","Montana Park","Pebble Rock Village","Baviaanspoort","Refilwe","Ekangala","Roodeplaat","University of Pretoria",
                             "Sunnyside","Pyramind","University of South Africa","Centurion","Cullinan","Rethabiseng","Wonderboom National Airport","Eldoraigne",
                             "Zithobeni","Wierdapark","Hennopsdark","Rooihuiskraal","Olievenhourbosch","Noordwyk","Kyalami Grand Prix","Glen Austin","Vorna Valley",
                             "Bronkhorstspruit","Erasmus","Magaliesig","Paulshof","Sunninghill","Woodmead","Bryanston","Morningside","Lethabong","Kempton Park",
                             "Sandton","Edenvale","OR Tambo International Airport","Daveyton","Benoni","Melrose Arch","Parktown","Roodepoort","Krugersdorp","Magaliesburg",
                             "Randfontein","Hillbrow","Kensington","Carletonville","Johannesburg","Witwatersrand University","Germiston","Boksburg","Springs","Rosettenville",
                             "Fochville","Devon","Brakpan","Johannesburg South","Meadowlands","Dobsonville","Zola","Jabulani","Zondi","Lenasia","Alberton","Vosloorus","Nigel",
                             "Katlehong","Eikenhof","Thokoza","Vlakfontein","Lawley","Protea Glen","Ennerdale","Orange Farm","Evaton","Three Rivers","Sebokeng","Duncanville",
                             "Mamelo","Vaal University of Technology","Vaal Marina","North-West University Vaal Campus","Vanderbijlpark"};

    // Call Dijkstra with correct parameters
    auto result = dijkstra(listArray, NUM_VERTICES, startVertex);
    std::vector<double> distances = result.first;
    std::vector<int> previous = result.second;

    // Print the shortest path and distance
    print_shortest_path(startVertex, endVertex, distances, previous);

    // Print with location names
    std::vector<int> path = reconstruct_path(previous, startVertex, endVertex);
    if (!path.empty()) {
        std::cout << "\nPath with location names:" << std::endl;
        for (size_t i = 0; i < path.size(); i++) {
            int locationIndex = path[i];
            std::cout << locations[locationIndex];
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < NUM_VERTICES; i++) {
        NodePtr current = listArray[i];
        while (current != nullptr) {
            NodePtr temp = current;
            current = current->link;  // Fixed: changed "next" to "link"
            delete temp;
        }
    }
    delete[] listArray;

    return 0;
}

// Implementation of Dijkstra's algorithm
std::pair<std::vector<double>, std::vector<int>> dijkstra(Node** listArray, int numVertices, int start) {
    // Vector to store the shortest distance from start to i
    std::vector<double> dist(numVertices, std::numeric_limits<double>::infinity());

    // Vector to store the previous vertex in the shortest path
    std::vector<int> previous(numVertices, -1);

    // Priority queue to get the vertex with minimum distance
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;

    // Distance from start to itself is 0
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        double dist_u = pq.top().first;
        pq.pop();

        // Skip if this is not the latest distance
        if (dist_u > dist[u]) continue;

        // Visit all the adjacent vertices
        NodePtr temp = listArray[u];
        while (temp != nullptr) {
            int v = temp->destination;
            double weight = temp->distance;

            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                previous[v] = u;
                pq.push({dist[v], v});
            }
            temp = temp->link;
        }
    }

    return {dist, previous};
}

// Function to reconstruct the path from start to end
std::vector<int> reconstruct_path(const std::vector<int>& previous, int start, int end) {
    std::vector<int> path;
    for (int at = end; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    // Check if there's a path
    if (path.size() <= 1 || path[0] != start) {
        return {}; // No path exists
    }

    return path;
}

// Print the shortest path and distance
void print_shortest_path(int start, int end, const std::vector<double>& distances, const std::vector<int>& previous) {
    if (distances[end] == std::numeric_limits<double>::infinity()) {
        std::cout << "No path exists from " << start << " to " << end << std::endl;
        return;
    }

    std::cout << "Shortest distance from " << start << " to " << end << ": " << distances[end] << " km" << std::endl;

    std::cout << "Path: ";
    std::vector<int> path = reconstruct_path(previous, start, end);
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

void create_gauteng_graph(Node** listArray)
{
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
    add_node_to_list(head4, 6, 6.6);
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

    add_node_to_list(head13, 11, 29);
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

    add_node_to_list(head15, 13, 29);
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
    NodePtr head50 = listArray[50];

    add_node_to_list(head50, 51, 16);
    add_node_to_list(head50, 58, 9.3);
    add_node_to_list(head50, 60, 27);

    //Lethabong
    listArray[51] = new Node{50, 16, nullptr};
    NodePtr head51 = listArray[51];

    add_node_to_list(head51, 52, 5.1);
    add_node_to_list(head51, 49, 9.4);
    add_node_to_list(head51, 50, 6.1);
    add_node_to_list(head51, 52, 9.8);

    //Kempton Park
    listArray[52] = new Node{55, 5.9, nullptr};
    NodePtr head52 = listArray[52];

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
    NodePtr head62 = listArray[62];

    add_node_to_list(head62, 61, 31);

    //Randfontein
    listArray[63] = new Node{61, 15, nullptr};
    NodePtr head63 = listArray[63];

    add_node_to_list(head63, 66, 40);
    add_node_to_list(head63, 67, 36);
    add_node_to_list(head63, 73, 73);

    //Hillbrow
    listArray[64] = new Node{58, 8.2, nullptr};
    NodePtr head64 = listArray[64];

    add_node_to_list(head64, 59, 2.4);
    add_node_to_list(head64, 65, 5.6);
    add_node_to_list(head64, 67, 3.1);
    add_node_to_list(head64, 68, 3.7);

    //Kensington
    listArray[65] = new Node{54, 15, nullptr};
    NodePtr head65 = listArray[65];

    add_node_to_list(head65, 64, 5.6);
    add_node_to_list(head65, 69, 8.4);
    add_node_to_list(head65, 72, 11);

    //Carletonville
    listArray[66] = new Node{63, 40, nullptr};
    NodePtr head66 = listArray[66];

    add_node_to_list(head66, 73, 18);

    //Johannesburg
    listArray[67] = new Node{60, 16, nullptr};
    NodePtr head67 = listArray[67];

    add_node_to_list(head67, 63, 36);
    add_node_to_list(head67, 64, 3.1);
    add_node_to_list(head67, 73, 73);
    add_node_to_list(head67, 76, 14);
    add_node_to_list(head67, 77, 19);
    add_node_to_list(head67, 78, 22);

    //Wits
    listArray[68] = new Node{64, 3.7, nullptr};
    NodePtr head68 = listArray[68];

    add_node_to_list(head68, 72, 11);
    add_node_to_list(head68, 76, 17);

    //Germiston
    listArray[69] = new Node{55, 17, nullptr};
    NodePtr head69 = listArray[69];

    add_node_to_list(head69, 65, 8.4);
    add_node_to_list(head69, 70, 12);
    add_node_to_list(head69, 72, 18);
    add_node_to_list(head69, 83, 21);

    //Boksburg
    listArray[70] = new Node{55, 13, nullptr};
    NodePtr head70 = listArray[70];

    add_node_to_list(head70, 69, 12);
    add_node_to_list(head70, 71, 23);
    add_node_to_list(head70, 83, 23);

    //Springs
    listArray[71] = new Node{55, 37, nullptr};
    NodePtr head71 = listArray[71];

    add_node_to_list(head71, 56, 19);
    add_node_to_list(head71, 57, 22);
    add_node_to_list(head71, 70, 23);
    add_node_to_list(head71, 74, 43);
    add_node_to_list(head71, 75, 14);
    add_node_to_list(head71, 85, 21);

    //Rosettenville
    listArray[72] = new Node{65, 11, nullptr};
    NodePtr head72 = listArray[72];

    add_node_to_list(head72, 68, 11);
    add_node_to_list(head72, 69, 18);
    add_node_to_list(head72, 76, 7.5);
    add_node_to_list(head72, 87, 12);
    add_node_to_list(head72, 89, 31);

    //Fochville
    listArray[73] = new Node{63, 48, nullptr};
    NodePtr head73 = listArray[73];

    add_node_to_list(head73, 66, 18);
    add_node_to_list(head73, 67, 73);
    add_node_to_list(head73, 79, 53);
    add_node_to_list(head71, 80, 54);

    //Devon
    listArray[74] = new Node{44, 70, nullptr};
    NodePtr head74 = listArray[74];

    add_node_to_list(head74, 56, 40);
    add_node_to_list(head74, 71, 36);
    add_node_to_list(head74, 85, 73);
    add_node_to_list(head74, 95, 67); //inaccurate distance

    //Brakpan
    listArray[75] = new Node{71, 14, nullptr};
    NodePtr head75 = listArray[75];

    add_node_to_list(head75, 83, 35);
    add_node_to_list(head75, 84, 23);

    //Johannesburg South
    listArray[76] = new Node{67, 15, nullptr};
    NodePtr head76 = listArray[76];

    add_node_to_list(head76, 68, 17);
    add_node_to_list(head76, 72, 7.5);
    add_node_to_list(head76, 77, 19);
    add_node_to_list(head76, 89, 18);

    //Meadowlands
    listArray[77] = new Node{67, 14, nullptr};
    NodePtr head77 = listArray[77];

    add_node_to_list(head77, 68, 17);
    add_node_to_list(head77, 72, 7.5);
    add_node_to_list(head77, 77, 19);
    add_node_to_list(head77, 89, 18);

    //Dobsonville
    listArray[78] = new Node{67, 22, nullptr};
    NodePtr head78 = listArray[78];

    add_node_to_list(head78, 79, 22);
    add_node_to_list(head78, 82, 17);

    //Zola
    listArray[79] = new Node{73, 53, nullptr};
    NodePtr head79 = listArray[79];

    add_node_to_list(head79, 78, 2.7);
    add_node_to_list(head79, 80, 2.9);
    add_node_to_list(head79, 81, 4.2);

    //Jabulani
    listArray[80] = new Node{73, 54, nullptr};
    NodePtr head80 = listArray[80];

    add_node_to_list(head80, 79, 2.9);
    add_node_to_list(head80, 81, 3.1);
    add_node_to_list(head80, 91, 7.8);

    //Zondi
    listArray[81] = new Node{79, 4.2, nullptr};
    NodePtr head81 = listArray[81];

    add_node_to_list(head81, 80, 3.1);
    add_node_to_list(head81, 90, 23);

    //Lenasia
    listArray[82] = new Node{81, 23, nullptr};
    NodePtr head82 = listArray[82];

    add_node_to_list(head82, 82, 9.9);
    add_node_to_list(head82, 91, 20);
    add_node_to_list(head82, 92, 5.2);

    //Alberton
    listArray[83] = new Node{69, 21, nullptr};
    NodePtr head83 = listArray[83];

    add_node_to_list(head83, 70, 23);
    add_node_to_list(head83, 75, 35);
    add_node_to_list(head83, 86, 10);
    add_node_to_list(head83, 87, 25);
    add_node_to_list(head83, 88, 7.5);

    //Vosloorus
    listArray[84] = new Node{75, 23, nullptr};
    NodePtr head84 = listArray[84];

    add_node_to_list(head84, 85, 32);
    add_node_to_list(head84, 86, 8.9);

    //Nigel
    listArray[85] = new Node{71, 21, nullptr};
    NodePtr head85 = listArray[85];

    add_node_to_list(head85, 74, 44);
    add_node_to_list(head85, 84, 8.9);

    //Katlehong
    listArray[86] = new Node{83, 10, nullptr};
    NodePtr head86 = listArray[86];

    add_node_to_list(head86, 84, 8.9);
    add_node_to_list(head86, 88, 2.5);

    //Eikenhof
    listArray[87] = new Node{72, 12, nullptr};
    NodePtr head87 = listArray[87];

    add_node_to_list(head87, 83, 25);
    add_node_to_list(head87, 88, 27);
    add_node_to_list(head87, 89, 16);
    add_node_to_list(head87, 93, 29);

    //Thokoza
    listArray[88] = new Node{83, 7.5, nullptr};
    NodePtr head88 = listArray[88];

    add_node_to_list(head88, 86, 2.5);
    add_node_to_list(head88, 87, 27);
    add_node_to_list(head88, 94, 49);

    //Vlakfontein
    listArray[89] = new Node{72, 31, nullptr};
    NodePtr head89 = listArray[89];

    add_node_to_list(head89, 76, 18);
    add_node_to_list(head89, 87, 16);
    add_node_to_list(head89, 92, 7.7);

    //Lawley
    listArray[90] = new Node{81, 23, nullptr};
    NodePtr head90 = listArray[90];

    add_node_to_list(head90, 82, 9.9);
    add_node_to_list(head90, 91, 20);
    add_node_to_list(head90, 92, 5.2);

    //Protea
    listArray[91] = new Node{80, 7.8, nullptr};
    NodePtr head91 = listArray[91];

    add_node_to_list(head91, 90, 20);
    add_node_to_list(head91, 94, 48);

    //Vlakfontein
    listArray[92] = new Node{89, 7.7, nullptr};
    NodePtr head92 = listArray[92];

    add_node_to_list(head92, 90, 5.2);
    add_node_to_list(head92, 93, 10);

    //Orange Farm
    listArray[93] = new Node{87, 29, nullptr};
    NodePtr head93 = listArray[93];

    add_node_to_list(head93, 92, 13);
    add_node_to_list(head93, 94, 10);

    //Evaton
    listArray[94] = new Node{88, 49, nullptr};
    NodePtr head94 = listArray[94];

    add_node_to_list(head94, 91, 48);
    add_node_to_list(head94, 93, 10);
    add_node_to_list(head94, 96, 3.3);

    //Three Rivers
    listArray[95] = new Node{88, 47, nullptr};
    NodePtr head95 = listArray[95];

    add_node_to_list(head95, 97, 5.1);
    add_node_to_list(head95, 100, 39);

    //Sebokeng
    listArray[96] = new Node{94, 3.3, nullptr};
    NodePtr head96 = listArray[96];

    add_node_to_list(head96, 99, 13);
    add_node_to_list(head96, 102, 18);

    //Duncanville
    listArray[97] = new Node{95, 5.1, nullptr};
    NodePtr head97 = listArray[97];

    add_node_to_list(head97, 101, 14);

    //Mamelo
    listArray[98] = new Node{74, 67, nullptr}; //Not an accurate distance
    NodePtr head98 = listArray[98];

    add_node_to_list(head98, 85, 70);
    add_node_to_list(head98, 100, 10); //Not an accurate distance

    //VUT
    listArray[99] = new Node{96, 13, nullptr};
    NodePtr head99 = listArray[99];

    add_node_to_list(head99, 102, 14);

    //Vaal Marina
    listArray[100] = new Node{95, 39, nullptr};
    NodePtr head100 = listArray[100];

    add_node_to_list(head100, 98, 10);

    //NWU Vaal
    listArray[101] = new Node{97, 14, nullptr};
    NodePtr head101 = listArray[101];

    add_node_to_list(head101, 102, 9);

    //Vanderbijlpark
    listArray[102] = new Node{96, 18, nullptr};
    NodePtr head102 = listArray[102];

    add_node_to_list(head102, 99, 14);
    add_node_to_list(head102, 101, 9);

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
