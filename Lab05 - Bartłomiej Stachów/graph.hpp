#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <list>


// node w liscie sasiedztwa
struct AdjListNode
{
    int dest;                       //numer wierzchołka
    int weight;                      //waga krawędzi
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
    std::list<int> listaw;


    
    Graph(int V)   // konstruktor do grafu
    {
        this->V = V;
        // tworzenie tablicy list sasiedztwa o rozmiarze v
        this->array = new struct AdjList[V];

        for (int i = 0; i < V; ++i)
            this->array[i].head = nullptr;
    }
    void addEdge(int src, int dest, int weight);
    void addoneEdge(int src, int dest, int weight);
    std::list<int> DFS();
    void DFS_visit(int v, bool visited[]);




};

// dodaje krawedz(graf nieskierowany)
void Graph::addEdge(int src, int dest, int weight)
{
    // dodaje krawedz od src do dest, dodaje na poczatek listy sasiedztwa
    struct AdjListNode* newNode = new AdjListNode(dest, weight);
    newNode->next = array[src].head;
    array[src].head = newNode;

    // jako ze graf jest nieskierowany to dodaje tez druga krawedz
    newNode = new AdjListNode(src, weight);
    newNode->next = array[dest].head;
    array[dest].head = newNode;
    std::cout<< src << " - " << dest << " (" << weight << ")\n";
}

void Graph::addoneEdge(int src, int dest, int weight)
{
    // dodaje krawedz od src do dest, dodaje na poczatek listy sasiedztwa
    struct AdjListNode* newNode = new AdjListNode(dest, weight);
    newNode->next = array[src].head;
    array[src].head = newNode;

    std::cout<< src << " -> " << dest << " (" << weight << ")\n";
}

void Graph::DFS_visit(int v, bool visited[])
{

    visited[v] = true;

    struct AdjListNode* temp = array[v].head;    
    while (temp != NULL)
    {
        int i = temp->dest;
        if(!visited[i])
        { 
            DFS_visit(i, visited);

        }
        temp = temp->next;
    }
    listaw.push_front(v);

    
} 
   
std::list<int> Graph::DFS() 
{ 
    bool *visited = new bool[V];


    struct AdjListNode* temp = array[0].head;    
    for (int i = 0; i < V; i++)
    { 
        while (temp != NULL)
        {
            if(i == temp->dest)
            {
                visited[i] = false;
            }
            temp = temp->next;
        }
    }  
    temp = array[0].head;
    while (temp != NULL)
    {
        int i = temp->dest;
        if (visited[i] == false)
        {
            DFS_visit(i, visited);

        }
        temp = temp->next;
    }
    return listaw;
}

#endif