#ifndef _arraylib_H_
#define _arraylib_H_

//predefined header files
#include<bits/stdc++.h>
using namespace std;


#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

void helloWorld();
//Array Namespace

namespace Array{
	//Searching class
	template<class A> 
	class Searching{
		private:
			A *arrPtr;
			int size;
		public:
			Searching(A arr[], int s);
			A linear_search(A item);
	        int binary_search(int left, int right, A item);
	        A jump_search(A item);
	        A interpolation_search(int lower, int upper, A item);
	};
	
	
	// function used in Sorting class
	template <typename A>
	void swap(A *xp, A *yp);
	
	//merge function for merge sort
	
	template <typename A>
	void merge(A arr[], int beg, int mid, int end);
	
	//partition function for quick sort
	template <class A>
	int partition (A arr[], int low, int high);
	
	//Heafify function for heap sort
	template <typename A>
	void heapify(A arr[], int n, int i);
	
	
	//Sorting Class
	template <class A>
	class Sorting{
		private:
			A *arrPtr;
	        int size;
	    public:
	    	Sorting( A arr[], int s);
	    	A * bubble_sort();
	    	A * insertion_sort();
	    	A * selection_sort();
	    	A * merge_sort(int begin, int end);
	    	A * quick_sort(int low, int hight);
	    	A * heap_sort();
	    	void display_array();
	};
}

#endif
