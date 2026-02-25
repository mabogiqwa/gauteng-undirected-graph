# Gauteng Map Graph Project

## Overview

This project implements a graph data structure to represent distances between various locations in Gauteng, South Africa. The graph is represented as an adjacency list using an array of linked lists. The project includes an implementation of Dijkstra's algorithm to find the shortest path between two locations.

## Features

Representation of Gauteng locations as a graph using an adjacency list

Implementation of Dijkstra's algorithm to find the shortest path between two locations

Interactive console input for selecting start and end locations

Distance data representation in kilometers

Path tracing to display the shortest route between selected locations

## Dependencies

C++ Standard Library

## Compilation and Execution

### Compilation

To compile the program, use the following command in a terminal:

g++ -o gauteng_graph main.cpp

## Usage

The program initializes a graph representation of Gauteng with predefined distances.

The user is prompted to enter a start and destination location (from 0 to 32).

The program calculates the shortest distance and displays the optimal path.

The output includes the shortest distance and a step-by-step route.

## Things to note
The graph at the moment can be used for education purposes and the error rate of the larger graph ~32% is much higher than the error rate for the smaller graph ~19%.

## Data Representation for smaller graph

Each location is indexed from 0 to 32, corresponding to: 

0  - Temba  
1  - Soshanguve  
2  - Hammanskraal  
3  - Winterveld  
4  - Klipgat  
5  - Roodeplaat  
6  - Refilwe  
7  - Mabopane  
8  - Ga-Rankuwa  
9  - Hartbeespoort  
10 - Pretoria  
11 - Cullinan  
12 - Rayton  
13 - Ekangala  
14 - Centurion  
15 - Bronkhorstspruit  
16 - Midrand  
17 - Tembisa  
18 - Kempton Park  
19 - Randburg  
20 - Sandton  
21 - Roodepoort  
22 - Krugersdorp  
23 - Benoni  
24 - Springs  
25 - Boksburg  
26 - Alberton  
27 - Soweto  
28 - Randfontein  
29 - Carltonville  
30 - Fochville  
31 - Vereeniging  
32 - Vanderbijlpark  

## Data Representation for larger graph

Each location is indexed from 0 to 102, corresponding to:

0  - Winterveld  
1  - Reefentse  
2  - Temba  
3  - Klipdrift  
4  - Marokoleng  
5  - Soshanguve  
6  - Hammanskraal  
7  - Mabopane  
8  - Rosslyn  
9  - Ga-Rankuwa  
10 - Komdraai  
11 - Akasia  
12 - Sefako-Makgathu University  
13 - Wallmannsthal  
14 - Atteridgeville  
15 - National Zoological Gardens  
16 - Union Buildings  
17 - Laudium  
18 - Pretoria Central  
19 - Montana Park  
20 - Pebble Rock Village  
21 - Baviaanspoort  
22 - Refilwe  
23 - Ekangala  
24 - Roodeplaat  
25 - University of Pretoria  
26 - Sunnyside  
27 - Pyramid  
28 - University of South Africa  
29 - Centurion  
30 - Cullinan  
31 - Rethabiseng  
32 - Wonderboom National Airport  
33 - Eldoraigne  
34 - Zithobeni  
35 - Wierdapark  
36 - Hennopsdark  
37 - Rooihuiskraal  
38 - Olievenhoutbosch  
39 - Noordwyk  
40 - Kyalami Grand Prix  
41 - Glen Austion  
42 - Vorna Valley  
43 - Bronkhorstspruit  
44 - Erasmus  
45 - Magaliesig  
46 - Paulshof  
47 - Sunninghill  
48 - Woodmead  
49 - Bryanston  
50 - Morningside  
51 - Lethabong  
52 - Kempton Park  
53 - Sandton  
54 - Edenvale  
55 - OR Tambo  
56 - Daveyton  
57 - Benoni  
58 - Melrose Arch  
59 - Parkton  
60 - Roodeport  
61 - Krugersdorp  
62 - Magaliesburg  
63 - Randfontein  
64 - Hillbrow  
65 - Kensington  
66 - Carletonville  
67 - Johannesburg  
68 - Wits  
69 - Germiston  
70 - Boksburg  
71 - Springs  
72 - Rosettenville  
73 - Fochville  
74 - Devon  
75 - Brakpan  
76 - Johannesburg South  
77 - Meadowlands  
78 - Dobsonville  
79 - Zola  
80 - Jabulani  
81 - Zondi  
82 - Lenasia  
83 - Alberton  
84 - Vosloorus  
85 - Nigel  
86 - Katlehong  
87 - Eikenhof  
88 - Thokoza  
89 - Vlakfontein  
90 - Lawley  
91 - Protea  
92 - Vlakfontein  
93 - Orange Farm  
94 - Evaton  
95 - Three Rivers  
96 - Sebokeng  
97 - Duncanville  
98 - Mamelo  
99 - VUT  
100 - Vaal Marina  
101 - NWU Vaal  
102 - Vanderbijlpark  

## Future Enhancements

Extend the graph to include additional locations in Gauteng.

Improve the accuracy of the distance computation over longer distances

Implement a graphical interface for visualization.

Add real-time traffic data for dynamic shortest path computation.

## Author

Mabo Giqwa

