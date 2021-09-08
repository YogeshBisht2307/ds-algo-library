#include "treelib.h"

#include <windows.h>

//insert functional add element in the binary tree;
template<class T> 
void BinaryTree::Tree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode){
	if (nodePtr == nullptr){
		// Insert the node.
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value){
		// Search the left branch
		insert(nodePtr->left, newNode);
	}
	else{
		// Search the right branch
		insert(nodePtr->right, newNode);
	}
}

//insertNode creates a new node to hold data and its value and pass it to insert function;
template<class T> 
void BinaryTree::Tree<T>::insert_node(T value){
	TreeNode *newNode = nullptr; // Pointer to a new node.
	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = value;
	newNode->left = newNode->right = nullptr;
	// Insert the node.
	insert(root, newNode);
}

//destroySubTree is called by destructor , it will deleteds all the nodes in the tree.
template<class T> 
void BinaryTree::Tree<T>::destroy_sub_tree(TreeNode *nodePtr){
	if (nodePtr->left){
		destroy_sub_tree(nodePtr->left);
	}
	if(nodePtr->right){
		destroy_sub_tree(nodePtr->right);
	}
	delete nodePtr;
}

//searchNode function check wheather a value is present in the tree or not;
template<class T> 
bool BinaryTree::Tree<T>::search_node(T item){
	bool status = false;
	TreeNode *nodePtr = root;
	while (nodePtr){
		if (nodePtr->value == item){
			status = true;
		}
		else if (item < nodePtr->value){
			nodePtr = nodePtr->left;
		}
		else{
			nodePtr = nodePtr->right;
		}
	}
	return status;
}

//remove node call delete_node function to delete the node.
template<class T> 
void BinaryTree::Tree<T>::remove(T value){
	delete_node(value, root);
}


//delete_node delete the given item from tree, if it is present;
template<class T> 
void BinaryTree::Tree<T>::delete_node(T value, TreeNode *&nodePtr){
	if (value < nodePtr->value){
		delete_node(value, nodePtr->left);
	}
	else if (value > nodePtr->value){
		delete_node(value, nodePtr->right);
	}
	else{
		make_deletion(nodePtr);
	}
}

//make_deletion takes a reference to a pointer to the node that is to be deleted and node is removed and branches of the tree below the node are rconfigure.
template<class T> 
void BinaryTree::Tree<T>::make_deletion(TreeNode *&nodePtr){
// Temporary pointer, used in reattaching the left subtree.
	TreeNode *tempNodePtr = nullptr;
	if (nodePtr == nullptr){
		cout << "Cannot delete empty node.\n";
	}
	else if (nodePtr->right == nullptr){
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr){
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else{
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left){
			tempNodePtr = tempNodePtr->left;
		}
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	
	cout<<"\n\nNow deleting "<<nodePtr->value<<" from the tree...."<<endl;
}

//tree traversing in inorder.
template <class T>
void BinaryTree::Tree<T>::display_inorder(TreeNode *nodePtr){
	if (nodePtr){
		display_inorder(nodePtr->left);
		cout << nodePtr->value <<" ";
		display_inorder(nodePtr->right);
	}
}


//tree traversing in postorder;
template <class T>
void BinaryTree::Tree<T>::display_preorder(TreeNode *nodePtr){
	if (nodePtr){
		cout << nodePtr->value <<" ";
		display_preorder(nodePtr->left);
		display_preorder(nodePtr->right);
	}
}

//tree traversing in post doctor;
template <class T>
void BinaryTree::Tree<T>::display_postorder(TreeNode *nodePtr){
	if (nodePtr){
		display_postorder(nodePtr->left);
		display_postorder(nodePtr->right);
		cout <<nodePtr->value<<" ";
	}
}

// calling the countNodes function to return the no of node;
template<class T> 
int BinaryTree::Tree<T>::num_nodes(){
	return count_nodes(root);
}

//countNodes function to count the no of element int the tree;
template<class T>
int BinaryTree::Tree<T>::count_nodes(TreeNode *&nodePtr){
	int count;
	if (nodePtr == nullptr){
		count = 0;
	}
	else{
		count = 1 + count_nodes(nodePtr->left) + count_nodes(nodePtr->right);
	}
	return count;
}


