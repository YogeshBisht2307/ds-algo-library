#include "stacklib.h"
#include<windows.h>


template <class S>
LinkedListStack::Stack<S>::Stack(){
	top = nullptr;
}

template<class S>
typename LinkedListStack::Stack<S>::Node *
LinkedListStack::Stack<S>::get_stack(){
	Node *temp = top;
	return temp;
}

template<class S>
bool LinkedListStack::Stack<S>::push(S value){
	Node * ptr = new Node();

	if(!ptr){
		return false;
	}

	ptr->data = value;
	ptr->link = top;
	top = ptr;

	return true;
}



template<class S>
void LinkedListStack::Stack<S>::traversing(){
	Node *ptr;
	if(top == nullptr)
		exit(1);
	else{
		ptr = top;
		while(ptr != nullptr){
			cout<<ptr->data <<endl;
			ptr = ptr->link;
		}
	}
}



template <class S>
S LinkedListStack::Stack<S>::peek(){
	if (top!= nullptr){
		return top->data;
	}
	else
		exit(1);
}



template<class S>
S LinkedListStack::Stack<S>::pop(){
	Node *ptr;
	if(top == nullptr){
		exit(1);
	}
	else{
		S data = top->data;
		ptr = top;
		top = top->link;
		ptr->link = nullptr;
		return data;
	}
}



template<class S>
int LinkedListStack::Stack<S>::linear_search(S item){
	Node *ptr;
	int count = 0;
	if(top == nullptr){
		return -2;
	}
	else{
		ptr = top;
		while(ptr != nullptr && ptr->data!=item){
			count++;
			ptr = ptr->link;
		}
		if(ptr->data == item){
			return count;
		}

		if(ptr == nullptr){
			return -1;
		}
	}
}



template <class S>
void LinkedListStack::Stack<S>::bubble_sort() {
	Node *ptr,*ptr1;
	ptr1=nullptr;
	int swap;
	if(top==nullptr)
		cout<<"Stack is empty"<<endl;
	else {
		do {
			ptr=top;
			swap=0;
			while(ptr->link!=ptr1) {
				if(ptr->data > ptr->link->data) {
					S temp;
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
