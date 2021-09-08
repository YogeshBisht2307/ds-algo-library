#include "linkedlistlib.h"
#include <windows.h>

void helloWorldLinkedList(){
	std::cout<<"Hello World Linked list Template"<<std::endl;
}


//constructor of List class
template<class L>
LinkedList::List<L>::List(){
	header=nullptr; 
}

//get list function for List class
template<class L>
typename LinkedList::List<L>::node *
LinkedList::List<L>::get_list(){
	node *temp = header;
	return temp;
}


//insertion at beginning of List
template<class L>
bool LinkedList::List<L>::insertion_at_beginning(L value) { 
	node *new_node=new node; 
	if(new_node==nullptr) 
		return false; 
	else{ 
		if(header==nullptr) {
			header=new_node; 
			new_node->link=nullptr; 
			new_node->data=value;
			return true; 
		} 
		else{
			node *ptr; 
			ptr=header; 
			header=new_node; 
			new_node->link=ptr; 
			new_node->data=value;
			return true; 
		}
		
	} 
}  


//Insertion at the end of a singly linked List
template <class L>  
bool LinkedList::List<L>::insertion_at_end(L value) {  
	node *new_node=new node;  
	if(new_node==nullptr)  
		return false;
	else { 
		node *ptr; ptr=header; 
		while(ptr->link!=nullptr) { 
			ptr=ptr->link; 
		} 
		ptr->link=new_node; 
		new_node->link=nullptr; 
		new_node->data=value;
		return true; 
	} 
}   

//insertion after a given node 
template <class L>  
bool LinkedList::List<L>::insertion_after_node(L key_value, L value) { 
  
	node * new_node=new node;  
	if(new_node==nullptr) 
		return false; 
	else { 
		node *ptr; 
		ptr=header; 
		while(ptr->link!=nullptr && ptr->data!=key_value){
		    ptr=ptr->link;
		}
		if(ptr->data!=key_value) 
			return false;
		else if(ptr->data==key_value && ptr->link==nullptr) { 
			ptr->link=new_node; 
			new_node->link=nullptr; 
			new_node->data=value;
			return true; 
		} 
		else { 
			new_node->link=ptr->link; 
			ptr->link=new_node; 
			new_node->data=value;
			return true; 
		}
		
	} 
}  


//deletion operation at the beginning;
template <class L>  
bool LinkedList::List<L>::deletion_from_beginning() { 
	if(header==nullptr) 
		return false; 
	else{ 
		node *ptr; 
		ptr=header; 
		header=ptr->link; 
		return true;
	} 
} 

 
//deletion from the end;
template <class L>  
bool LinkedList::List<L>::deletion_from_end(){ 
	if(header==nullptr) 
		return false; 
	else { 
		node *ptr=header; 
		node *ptr1; 
		while(ptr->link!=nullptr) { 
			ptr1=ptr; 
			ptr=ptr->link; 
		} 
		ptr1->link=nullptr; 
		return true;
	} 
} 

   
//deleting a given node 
template <class L>     
bool LinkedList::List<L>::deletion_specific_element(L key_value){  
	if(header==nullptr)  
		return false;  
	else {  
		node *ptr,*ptr1;  
		ptr=header;  
		while(ptr->data!=key_value && ptr->link!=nullptr)  {  
			ptr1=ptr;  
			ptr=ptr->link; 
		} 
		if(ptr->data==key_value) { 
			ptr1->link=ptr->link; 
			return true;
		} 
		else { 
			return false;
		} 
	} 
}  

//traversing in singly linked List
template <class L>  
bool LinkedList::List<L>::traversing() {
	if (header == nullptr)
		return false;
	else{
		node *ptr; 
		ptr=header; 
		cout<<"node in List are:-"<<endl; 
		while(ptr!=nullptr) { 
			cout<<ptr->data<<endl; 
			ptr=ptr->link; 
		}
		return true;
 	}  
}
 
//Linear Search in Singly Linked List 
template <class L> 
LinkedList::List<L>::linear_search(L item) {
	int count =0;
	if(header==nullptr) 
		return -2; 
	else{ 
		node *ptr=header; 
		while(ptr->data!=item && ptr->link!=nullptr){ 
			count++;
			ptr=ptr->link; 
		}        
		if(ptr->data!=item) 
			return -1;
		else { 
			return count;
		}
	}
}
    
//bubble sorting in singly linked List
template <class L>  
bool LinkedList::List<L>::bubble_sort() { 
	node *ptr,*ptr1; 
	ptr1=nullptr; 
	int swap; 
	if(header==nullptr) 
		return false; 
	else { 
		do { 
			ptr=header; 
			swap=0; 
			while(ptr->link!=ptr1) { 
				if(ptr->data>ptr->link->data) { 
					L temp; 
					temp=ptr->data; 
					ptr->data=ptr->link->data; 
					ptr->link->data=temp;  
					swap=1; 
				} 
				ptr=ptr->link; 
			} 
			ptr1=ptr; 
		}
		while(swap);
		return true; 
	} 
}

