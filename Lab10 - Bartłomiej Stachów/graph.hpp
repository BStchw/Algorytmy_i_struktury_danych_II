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


struct Graph
{
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

    int kruskalMST();
    void create_sets(Set<int> set[]);
    int find_set(int i, Set<int> set[]);
};

void Graph::create_sets(Set<int> set[]) 
{
    Set<int> setp;
    std::vector< std::pair<int, iPair> >::iterator it;
    int index = 0;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        if(!setp.isMember(it->second.first))
        {
            setp.insert(it->second.first);
            set[index].insert(it->second.first);
            index++;
        }
        
        if(!setp.isMember(it->second.second))
        {
            setp.insert(it->second.second);
            set[index].insert(it->second.second);
            index++;
        }
        
    }
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

int Graph::kruskalMST()
{
    int mst_wt = 0;
    Set<std::pair<int, int>> A;
    Set<int> set[V];
    
  
    create_sets(set);

    sort(edges.begin(), edges.end());

    std::string const fileName("output_file.csv");
    std::ofstream mystream(fileName.c_str());
    std::vector< std::pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;

        int set_u = find_set(u, set);
        int set_v = find_set(v, set);

            if((set_u != set_v))
            {
                mst_wt = mst_wt + (it->first);
                set[set_u].unionn(set[set_v]);
                set[set_v].popAll(set[set_v]);
                if(mystream)    
                {
                    mystream << u << ","<< v << "," << w << "\n";
                }
                else
                {
                    std::cout << "ERROR. Cannot open a file" << std::endl;
                }

            }

    }


    return mst_wt;
}

#endif