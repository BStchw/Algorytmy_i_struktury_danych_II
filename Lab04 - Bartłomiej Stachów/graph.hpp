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
    void bfs(struct Graph tree, int src);
    std::list<int> get_path(int root, int end);
    int get_hops(int root, int end);




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

void Graph::bfs(struct Graph tree, int src)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }   

    std::list<int> queue;

    visited[src] = true;

    queue.push_back(src);
 

    while(!queue.empty())
    {
        src = queue.front();
        queue.pop_front();
 

        struct AdjListNode* temp = array[src].head;
        while (temp != NULL)
        {
            int v = temp->dest;



            if (!visited[v])
            {
                visited[v] = true;
                tree.addoneEdge(src, v, temp->weight);
                queue.push_back(v);
            }
            
            temp = temp->next;


        }
    }
}

std::list<int> Graph::get_path(int root, int end)
{
    //root = 1;
    std::list<int> path;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }   

    std::list<int> queue;

    visited[root] = true;
    path.push_back(root);


    queue.push_back(root);
    int v;

    while(!queue.empty())
    {
        root = queue.front();
        queue.pop_front();
        

        if(v==end)
        {
            break;
        }

     

        struct AdjListNode* temp = array[root].head;
        while (temp != NULL)
        {
            v = temp->dest;
            
            if (!visited[v])
            {
                visited[v] = true;
                queue.push_back(v);
                path.push_back(v);
            }
      
            
            temp = temp->next;

            if(v==end)
            {
                break;
            }


        }
    }
    if(v!=end)
    {
        path.clear();
    }
    return path;
}

int Graph::get_hops(int root, int end)
{
    //root = 1;
    int path = 0;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }   

    std::list<int> queue;

    int v;

    visited[root] = true;


    queue.push_back(root);
 

    while(!queue.empty())
    {
        root = queue.front();
        queue.pop_front();

        if(v==end)
        {
            break;
        }

     

        struct AdjListNode* temp = array[root].head;
        while (temp != NULL)
        {
            v = temp->dest;
            int p = temp->weight;
            
            if (!visited[v])
            {
                visited[v] = true;
                queue.push_back(v);
                path = path + p;
            }
      
            
            temp = temp->next;

            if(v==end)
            {
                break;
            }


        }
    }
    if(v!=end)
    {
        return -1;
    }
    return path;
}


#endif