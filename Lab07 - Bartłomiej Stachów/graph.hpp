#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int src;                        //numer poczatkowego wierzcholka
    int dest;                       //numer koncowego wierzchołka
    int weight;                     //waga krawędzi
};

// graf jako tablica list sasiedztwa
class Graph
{
    public:
    int V;
    int E;
    int licznik = 0;
    struct Node* edges;
    
    Graph(int V, int E)   // konstruktor do grafu
    {
        this->V = V;
        this->E = E;
        this->edges = new struct Node[E];
    }
    void addEdge(int src, int dest, int weight);
    void BellmanFord(int src);
    void initialize(int dist[], int prev[], int src);

};

// dodaje krawedz(graf skierowany)
void Graph::addEdge(int src1, int dest1, int weight1)
{
    edges[licznik].src = src1;
    edges[licznik].dest = dest1;
    edges[licznik].weight = weight1;

    licznik++;

}

void Graph::initialize(int dist[], int prev[], int src)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = {NULL};
    }
    dist[src] = 0;
}

void Graph::BellmanFord(int src)
{
    int dist[V];
    int prev[V];
    bool s;

    initialize(dist, prev, src);

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            
            //Relax
            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
        }
    }
 
    for (int i = 0; i < E; i++) 
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
        {
            s = false;
            break;
        }
        else
            s = true;
    }

    if(s==false)
    {
        std::cout << "FALSE" <<std::endl;
    }
    else
    {
        std::cout << "TRUE" <<std::endl;
    }

    for (int i = 1; i < V; i++)
    {
        if(dist[i]==INT_MAX)
        {
            std::cout << "(" << i << ", " << "inf" << ") ";
        }
        else
        {
            std::cout << "(" << i << ", " << dist[i] << ") ";
        }
    }

    std::cout << std::endl << std::endl;
    
    for (int i = 1; i < V; i++)
    {
        if(prev[i] == 0)
        {
            std::cout << "(" << i << ", " << "NULL" << ") ";
        }
        else
        {
            std::cout << "(" << i << ", " << prev[i] << ") ";
        }
    }
    std::cout << std::endl;
}

#endif