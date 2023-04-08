#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "graph.hpp"
#include "set.hpp"



using namespace std;
 
int main(int argc, char *argv[])
{
  int V = 10001;
  int E = 10001;
  struct Graph graph = Graph(V, E);

  ifstream ip(argv[1]);

  if(!ip.is_open())
  {
    std::cout << "ERROR: File Open" << '\n';
  }

  string src;
  string dest;
  string weight;


  int src1 = 0;

  while(ip.good()){    
    src.clear();
    dest.clear();
    weight.clear();
    getline(ip, src,',');
    getline(ip,dest,',');
    getline(ip,weight,'\n');

    if(src.empty() || weight.empty() || weight.empty())
    {
      break;
    }

    src1 = stoi(src);
    int dest1 = stoi(dest);
    int weight1 = stoi(weight);

    graph.addEdge(src1, dest1, weight1);
  }
  
  ip.close();

  graph.kruskal_Forest();
  graph.kruskal();


	return 0;
}