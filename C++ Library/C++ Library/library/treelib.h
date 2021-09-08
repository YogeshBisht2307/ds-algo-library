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


namespace BinaryTree{
	template<class T> 
	class Tree{
		private:
			struct TreeNode{
				T value;
				TreeNode *left;
				TreeNode *right;
			};
			TreeNode *root;
			void insert(TreeNode *&, TreeNode *&);
			void destroy_sub_tree(TreeNode *);
			void delete_node(T, TreeNode *&);
			void make_deletion(TreeNode *&);
			void display_inorder(TreeNode *);
			void display_preorder(TreeNode *);
			void display_postorder(TreeNode *);
			int count_nodes(TreeNode *&);
		public:
			Tree(){ 
				root = NULL; 
			}
			~Tree(){ 
				destroy_sub_tree(root); 
			}
			void insert_node(T);
			bool search_node(T);
			void remove(T);
			void display_inorder(){
				display_inorder(root); 
			}
			void display_preorder(){ 
				display_preorder(root); 
			}
			void display_postorder(){ 
				display_postorder(root); 
			}
			int num_nodes();
	};	
}

#endif
