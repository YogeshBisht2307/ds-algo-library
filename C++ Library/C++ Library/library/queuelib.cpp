#include "queuelib.h"
#include<windows.h>

//constructor of List class
template<class Q>
LinkedListQueue::Queue<Q>::Queue(){
	front= rear = nullptr; 
}

//get list function for List class
template<class Q>
typename LinkedListQueue::Queue<Q>::node *
LinkedListQueue::Queue<Q>::get_queue(){
	node *temp = front;
	return temp;
}

template <class Q>  
void LinkedListQueue::Queue<Q>::insertion(Q value) {  
	node *new_node=new node;  
	if(new_node==nullptr)  
		cout<<"overflow,insertion not possible"<<endl; 
	else { 
		new_node->data = value;
		new_node->link = nullptr;
		
		if(front == nullptr){
			front = rear = new_node;
		}
		else{
			rear->link = new_node;
			rear = new_node;
		}
		
		cout<<"Inserted Successfully"<<endl; 
	} 
}


template <class Q>  
Q LinkedListQueue::Queue<Q>::deletion() { 
	if(front==nullptr) 
		exit(1);
		
	node *ptr = front;
	front = front->link;
	
	if(front==nullptr)
		rear = nullptr;
	
	cout<<"The data is deleted from beginning"<<endl; 
	cout<<"Deleted item is :- "<<ptr->data<<endl;
	return ptr->data; 
} 


template<class Q>
void LinkedListQueue::Queue<Q>::traversing(){
	if (front == nullptr){
		return exit(1);
	}
	node *ptr = front;
	
	while(ptr->link!=nullptr){
		cout<<ptr->data<<" -> ";
		ptr = ptr->link;
	}
	cout<<ptr->data<<endl;
} 

template <class Q>
int LinkedListQueue::Queue<Q>::linear_search(Q item){
	if(front == nullptr){
		return -2;
	}
	node *ptr = front;
	int count = 0;
	while(ptr->link != nullptr){
		count++;
		if(ptr->data==item){
			return count;
		}
		ptr = ptr->link;
	}
	if(ptr->data == item){
		return count;
	}
	return -1;
} 

template <class Q>
void LinkedListQueue::Queue<Q>::bubble_sort(){
	node *ptr,*ptr1; 
	ptr1=nullptr; 
	int swap; 
	if(front==nullptr) 
		cout<<"Queue is empty"<<endl; 
	else { 
		do { 
			ptr=front; 
			swap=0; 
			while(ptr->link!=ptr1) { 
				if(ptr->data>ptr->link->data) { 
					Q temp; 
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
	} 
}
