# DsAlgo Library

DsAlgo Library is a Data Structure and Algorithm Dynamic Link Library that is build on top of C++ language. The data structure &algorithm library  DSALGO Library provides a carefully
integrated use of general data structures and their implementation using easy class, object and their respective
function. In doing so, the developer will be able to get to know the functionality of each namespace, class,
function and template using the documentation of the library which is well written on the website.
Website for downloading the library files and user guidance is developed using one of the trending frameworks
Django(python).

## Installation

Use the github respository [dsalgolib](https://github.com/YogeshBisht2307/DsAlgo-Library) to download the dsalgo library.

Use the C++ library folder present in the repository and setup the folder on your Code Block IDE as per your project requirement.


## Usage

```c
include "dsalgolib.h"

# use the namespace
using namespace LinkedList;

# create object of list class present in LinkedList namespace
List<int> listObj;

#  call the any algorithm function that you want to use
listObj.insertion_at_beginning(12); //insert element at beginning of list
listObj.insertion_at_end(30); //insert element at end of list
listObj.bubble_sort(); //sort the array in assending order
listObj.linear_search(30); //search the element 30 in the array sequentially

```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
