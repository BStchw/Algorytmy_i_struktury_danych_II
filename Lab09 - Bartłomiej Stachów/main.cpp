#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "graph.hpp"


using namespace std;
 
int main(int argc, char *argv[])
{

  int V = 1001;
  struct Graph graph = Graph(V);
  
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

  int start;
  int end; 

  for(int i=2; i<argc; i++)
  {
    string s;
    string d;
    string data = argv[i];
    size_t pos = data.find(",");

    s = data.substr(0, pos);
    d = data.substr(pos+1);
    
    start = stoi(s);
    end = stoi(d);
    graph.floydWarshall(start, end);
  }
  cout<<endl;

	return 0;
}