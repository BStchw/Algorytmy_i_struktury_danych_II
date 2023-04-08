#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// node w liscie sasiedztwa
struct AdjListNode
{
    int dest;                       //numer wierzchołka
    int weight;                     //waga krawędzi
    struct AdjListNode* next;       //następny element listy

    AdjListNode(int dest, int weight)   // konstruktor do wezla listy sasiedztwa
    {
        this->dest = dest;
        this->weight = weight;
        this->next = nullptr;
    }
};

// lista sasiedztwa
struct AdjList
{
    struct AdjListNode* head;
};


// graf jako tablica list sasiedztwa
class Graph
{
    public:
    int V;
    struct AdjList* array;
    
    Graph(int V)   // konstruktor do grafu
    {
        this->V = V;

        // tworzenie tablicy list sasiedztwa o rozmiarze v
        this->array = new struct AdjList[V];

        for (int i = 0; i < V; ++i)
            this->array[i].head = nullptr;
    }
    void addEdge(int src, int dest, int weight);
    void floydWarshall(int src, int dest);



};

void Graph::addEdge(int src, int dest, int weight)
{
    // dodaje krawedz od src do dest, dodaje na poczatek listy sasiedztwa
    struct AdjListNode* newNode = new AdjListNode(dest, weight);
    newNode->next = array[src].head;
    array[src].head = newNode;

}

void Graph::floydWarshall(int src, int dest)
{
    int dist[V][V];
    int i, j, k;
    struct AdjListNode* pCrawl;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    for (i=0; i<V; i++)
    {
        pCrawl = array[i].head;
        while (pCrawl != NULL)
        {
            dist[i][pCrawl->dest] = pCrawl->weight;
            pCrawl = pCrawl->next;
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    if(dist[src][dest]==INT_MAX)
    {
        std::cout<<"INF ";
    }
    else
        std::cout<<dist[src][dest]<<" ";


}

#endif