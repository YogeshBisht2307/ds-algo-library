#ifndef _GRAPHLIB_H_
#define _GRAPHLIB_H_

//predefined header files
#include<bits/stdc++.h>
using namespace std;


#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

namespace WeightedGraph{
	template<class G>
	class Graph{
    private:
        vector<pair<int,int> > * adjancy_list;
        int vertices;

    public:
        Graph(int V){
            vertices = V;
            adjancy_list = new vector< pair<int,int> >[vertices];
        }
        void add_edge(int v1,int v2, int wt);
        void display_graph();
};	
}
#endif
