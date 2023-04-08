#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <iterator>
#include "set.hpp"
#include <string>
#include <time.h>

class Graph
{
    public:
    friend class Set<int>;
    int V, E;
    typedef std::pair<int, int> iPair;
    std::vector< std::pair<int, iPair> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    void kruskal_Forest();
    void create_sets(Set<int> set[]);
    int FIND_SET(int i, Set<int> set[]);
    void LINK(int x, int y, Set<int> set[]);
    int find_set(int i, Set<int> set[]);
    void kruskal();


};

void Graph::create_sets(Set<int> set[]) 
{
    for (int i=0; i<V; i++)
    {
            set[i].insert(i);
            set[i].head = i;
            set[i].rank = 0;
    }
}

int Graph::FIND_SET(int x, Set<int> set[]) 
{
    if(x != set[x].head)
    {
        set[x].head = (FIND_SET(set[x].head, set));
    }

    return set[x].head;
}

void Graph::LINK(int x, int y, Set<int> set[]) 
{
    if(set[x].rank > set[y].rank)
    {
        set[y].head = x;
    }
    else
    {
        set[x].head = y;
    }
    if(set[x].rank == set[y].rank)
    {
        set[y].rank++;
    }

}

void Graph::kruskal_Forest()
{
    clock_t start = clock();
    int mst_wt = 0;
    Set<std::pair<int, int>> A;
    Set<int> set[V];
    
  
    create_sets(set);

    sort(edges.begin(), edges.end());
    
    int u;
    int v;
    int w;
    int set_u;
    int set_v;

    
    std::vector< std::pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        u = it->second.first;
        v = it->second.second;
        w = it->first;
        set_u = FIND_SET(u, set);
        set_v = FIND_SET(v, set);

            if((set_u != set_v))
            {
                mst_wt = mst_wt + w;
                LINK(set_u, set_v, set);
            }
    }
    clock_t end = clock();

    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    std::cout<< "FOREST:  " << elapsed << " s, " <<"WEIGHT: " << mst_wt << std::endl;

}


int Graph::find_set(int i, Set<int> set[]) 
{
    int result;

    for(int j = 0; j<V; j++)
    {
        if(set[j].isMember(i))
        {
            result = j;
            break;
        }
    }

    return result;
}

void Graph::kruskal()
{
    clock_t start = clock();
    int mst_wt = 0;
    Set<int> set[V];
    
  
    create_sets(set);

    sort(edges.begin(), edges.end());

    int u;
    int v;
    int w;

    int set_u;
    int set_v;
    std::vector< std::pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        u = it->second.first;
        v = it->second.second;
        w = it->first;

        set_u = find_set(u, set);
        set_v = find_set(v, set);

            if((set_u != set_v))
            {
                mst_wt = mst_wt + w;
                set[set_u].unionn(set[set_v]);
                set[set_v].popAll(set[set_v]);
            }

    }
    clock_t end = clock();

    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    std::cout<< "ORGINAL: " << elapsed << " s, " <<"WEIGHT: " << mst_wt << std::endl;
}

#endif