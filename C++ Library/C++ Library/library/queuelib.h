#ifndef _TREELIB_H_
#define _TREEELIB_H_

//predefined header files
#include<bits/stdc++.h>
using namespace std;


#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif


namespace LinkedListQueue{
	template <class Q>
	class Queue{
		public:
			struct node{ 
				Q data; 
				struct node *link; 
			};
			Queue();
			
			//get list function for returning node;
			typename Queue<Q>::node *
			get_queue();
			
			
			void insertion(Q value);  
			void traversing();
			Q deletion();
			int linear_search(Q item);
			void bubble_sort();
			
		private: 
			node * front;
			node * rear;
				  		
	};	
}

#endif
