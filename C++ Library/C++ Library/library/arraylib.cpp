#include "arraylib.h"
#include <windows.h>

void helloWorld(){
	std::cout<<"Hello World Template"<<std::endl;
}

//function of Array::Searching

//constructor of Searching Class
template <class A>
Array::Searching<A>::Searching(A arr[], int s){
	arrPtr = new A[s];
	size = s;
	for (int i=0; i<size; i++){
		arrPtr[i] = arr[i];
	}
}

//linear Search function in Searching Class of Array Namespace
template <class A>
A Array::Searching<A>::linear_search(A item){
	//loop over each element of array
	for (int i = 0; i< size; i++){
		if(arrPtr[i] == item)
			return i;
	}
	//if item is not present in the array
	return -1;
}

//binary_search function in Searching class of Array Namespace
template <class A>
int Array::Searching<A>::binary_search(int left, int right, A item){
	if (right >= left) {
        int middle = left + (right - left) / 2;

        if (arrPtr[middle] == item)
            return middle;

        //right sub array
        if (arrPtr[middle] < item)
            return binary_search(middle + 1, right, item);

        //left sub array
        return binary_search(left, middle - 1, item);
    }
    //if item is not persent
    return -1;
}

//jump_search function in Searching class of Array Namespace
template <class A>
A Array::Searching<A>::jump_search(A item){
	//jumping block size
    int jumpStep = sqrt(size);

    int prev = 0;
    while (arrPtr[min(jumpStep, size)-1] < item)
    {
        prev = jumpStep;
        jumpStep += sqrt(size);
        if (prev >= size)
            return -1;
    }

    while (arrPtr[prev] < item)
    {
        prev++;

        if (prev == min(jumpStep,size))
            return -1;
    }
    // If element found
    if (arrPtr[prev] == item)
        return prev;

 	//if item is not persent
    return -1;
}

//jump_search function in Searching class of Array Namespace
template <class A>
A Array::Searching<A>::interpolation_search(int lower, int upper, A item){

	int position;
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lower <= upper && item >= arrPtr[lower] && item <= arrPtr[upper]) {

        // Probing the position with keeping
        // uniform distribution in mind.
        position = lower
              + (((double)(upper - lower) / (arrPtr[upper] - arrPtr[lower]))
                 * (item - arrPtr[lower]));

        if (arrPtr[position] == item)
            return position;

        //search in left sub array
        if (arrPtr[position] > item)
            return interpolation_search(lower, position - 1, item);

        //search in right sub array
        if (arrPtr[position] < item)
            return interpolation_search(position + 1, upper, item);
    }
    //if element is not present
    return -1;
}


//additional function used in array sorting
template <class A>
void Array::swap(A *xp, A *yp)
{
    A temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Sorting of array starts here
template <class A>
Array::Sorting<A>::Sorting(A arr[], int s){
	arrPtr = new A[s];
	size = s;
	for(int i = 0; i < size; i++){
        arrPtr[i] = arr[i];
    }
}

//1. Bubble sorting
template <class A>
A * Array::Sorting<A>::bubble_sort(){
	int i, j;
    for (i = 0; i < size-1; i++)
    // Last i elements are already in place
    for (j = 0; j < size-i-1; j++)
        if (arrPtr[j] > arrPtr[j+1])
        	swap<A>(&arrPtr[j], &arrPtr[j+1]);
    return arrPtr;
}


//2. Insertion Sorting
template <class A>
A * Array::Sorting<A>::insertion_sort(){
	int i, j;
	A key;
    for (i = 1; i < size; i++)
    {
        key = arrPtr[i];
        j = i - 1;
        while (j >= 0 && arrPtr[j] > key)
        {
            arrPtr[j + 1] = arrPtr[j];
            j = j - 1;
        }
        arrPtr[j + 1] = key;
    }
    return arrPtr;
}


//3. Selection Sorting
template <class A>
A * Array::Sorting<A>::selection_sort(){

	int i, j, lowest_index;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        lowest_index = i;
        for (j = i+1; j < size; j++)
        if (arrPtr[j] < arrPtr[lowest_index])
            lowest_index = j;

        // Swap the found minimum element with the first element
        swap<A>(&arrPtr[lowest_index], &arrPtr[i]);
    }
    return arrPtr;
}



//merge function for merge sorting
template <typename A>
void Array::merge(A arr[], int beg, int mid, int end)
{
    int i=beg,j=mid+1,k,index = beg;
    A temp[end+1];
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[index] = arr[i];
            i = i+1;
        }
        else
        {
            temp[index] = arr[j];
            j = j+1;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index] = arr[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = arr[i];
            index++;
            i++;
        }
    }
    k = beg;
    while(k<index)
    {
        arr[k]=temp[k];
        k++;
    }
}

//4. merge sorting
template <class A>
A * Array::Sorting<A>::merge_sort(int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid = (beg+end)/2;
        merge_sort(beg,mid);
        merge_sort(mid+1,end);
        merge<A>(arrPtr,beg,mid,end);
    }
	return arrPtr;
}



//partition function for quick sort
template <class A>
int Array::partition (A arr[], int low, int high)
{
    A pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap<A>(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//5. Quick Sorting
template <class A>
A * Array::Sorting<A>::quick_sort(int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition<A>(arrPtr, low, high);

        //sorting element before and after partition
        quick_sort(low, partitionIndex - 1);
        quick_sort(partitionIndex + 1, high);
    }
    return arrPtr;
}

//heapify function for heap sort
template <typename A>
void Array::heapify(A arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap<A>(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify<A>(arr, n, largest);
    }
}


//6. Heap Sorting
template <class A>
A * Array::Sorting<A>::heap_sort(){
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify<A>(arrPtr, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap<A>(&arrPtr[0], &arrPtr[i]);

        // call max heapify on the reduced heap
        heapify<A>(arrPtr, i, 0);
    }
    return arrPtr;
}



BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}

	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
