#ifndef _LINKEDLISTLIB_H_
#define _LINKEDLISTLIB_H_

//predefined header files
#include<bits/stdc++.h>
using namespace std;


#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

void helloWorldLinkedList();
namespace LinkedList{
	//defining class for performing all operation on singly linked list
	template <class L>  
	class List{
		public:
			struct node{ 
				L data; 
				struct node *link; 
			};
			List();
			
			//get list function for returning node;
			typename List<L>::node *
			get_list();
			
			bool insertion_at_beginning(L value);  
			bool traversing();
			bool insertion_at_end(L value);
			bool insertion_after_node(L key_value, L value);
			bool deletion_from_end();
			bool deletion_from_beginning();
			bool deletion_specific_element(L Key_value);
			int linear_search(L value);
			bool bubble_sort();
			
		private: 
			node * header;		  		
	};
}

#endif
