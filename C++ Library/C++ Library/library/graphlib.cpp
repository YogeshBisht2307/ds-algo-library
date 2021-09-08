#include "graphlib.h"

#include <windows.h>

template<class G>
void WeightedGraph::Graph<G>::add_edge(int v1,int v2, int wt){
    adjancy_list[v1].push_back(make_pair(v2,wt));
	adjancy_list[v2].push_back(make_pair(v1,wt));
}
template<class G>
void WeightedGraph::Graph<G>::display_graph()
{
  int a,b;
  //first loop to traverse across vertices
  for(int i=0;i<vertices;i++)
  {
      cout<<"Adjacency list of vertex "<<i<<endl;
    //second loop to traverse across the adjacency list of some vertex i
    for(auto it=adjancy_list[i].begin();it!=adjancy_list[i].end();it++)
    {
      //set a as the vertex number and b as the weight
      a=it->first;
      b=it->second;
      cout<<"Vertex : "<<a<<" Weight : "<<b<<endl;
    }
    cout<<endl;
  }
}
