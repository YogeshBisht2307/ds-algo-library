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


namespace LinkedListStack{
	template<class S>
	class Stack{
		public:
			struct Node{
				S data;
				struct Node *link;
			};
			Stack();
			typename Stack<S>::Node *
			get_stack();
			
			bool push(S value);  
			void traversing();
			S pop();
			S peek();
			int linear_search(S item);
			void bubble_sort();
		
		private:
			Node * top;
	};	
}

#endif
