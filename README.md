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

### Execution

Run the compiled program using:

./gauteng_graph

## Usage

The program initializes a graph representation of Gauteng with predefined distances.

The user is prompted to enter a start and destination location (from 0 to 32).

The program calculates the shortest distance and displays the optimal path.

The output includes the shortest distance and a step-by-step route.

## Data Representation

Each location is indexed from 0 to 32, corresponding to:

0 - Temba
1 - Soshanguve
2 - Hammanskraal
3 - Winterveld
4 - Klipgat
...
32 - Vanderbijlpark

## Functions

void create_gauteng_graph(Node** listArray): Initializes the graph with locations and distances.

void dijkstra(Node** listArray, int start, int end): Computes the shortest path using Dijkstra's algorithm.

void print_path(const std::vector& parent, int end): Recursively prints the shortest path from start to end.

void add_node_to_list(NodePtr &currentNode, int destination, double distance): Adds a node to the adjacency list.

void print_data(Node** listArray): Displays the stored graph data.

## Future Enhancements

Extend the graph to include additional locations in Gauteng.

Improve the accuracy of the distance computation over longer distances

Implement a graphical interface for visualization.

Add real-time traffic data for dynamic shortest path computation.

## Author

Mabo Giqwa

