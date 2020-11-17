# Sortlib Library
sortlib is a library implemented in modern C++. It’s used for sorting any type of containers having
Random Access Iterators. sortlib sorts the elements inside the container in ascending order. The elements
are compared using operator< and operator>.
The Following four sorting algorithms are implemented:
- Bubble Sort
- Selection Sort
- Merge Sort
- Quick Sort


## Interface
```cpp
TEMPLATE<TYPENAME CONTAINER>
VOID SORT(CONTAINER & C, SORTING_TYPE T)
```
Sorts the elements inside the container based on the requested sorting type. There are four available
**sorting algorithms**, **bubble_sort**, **selection_sort**, **merge_sort**, and **quick_sort**.

## Function Parameters
c: type of the container.
t: sorting algorithm. Can either be bubble_sort, selection_sort, merge_sort, or quick_sort.

```cpp
TEMPLATE <TYPENAME ITR>
VOID BUBBLE_SORT(ITR BEGIN, ITR END)
```
Sorts the elements in the range [BEGIN, END) into ascending order using **Bubble Sort** Algorithm.

## Function Parameters
BEGIN, END: Random-access iterators to the initial and final positions of the sequence to be sorted. The
range used is [BEGIN ,END), which contains all the elements between BEGIN and END, including the
element pointed by BEGIN but not the element pointed by END.

```cpp
TEMPLATE <TYPENAME ITR>
VOID BUBBLE_SORT(ITR BEGIN, ITR END)
```
Sorts the elements in the range [BEGIN, END) into ascending order using **Selection Sort** Algorithm

```cpp
TEMPLATE <TYPENAME ITR>
VOID MERGE_SORT(ITR BEGIN, ITR END)
```
Sorts the elements in the range [BEGIN, END) into ascending order using **Merge Sort** Algorithm.

```cpp
TEMPLATE <TYPENAME ITR>
VOID QUICK_SORT(ITR BEGIN, ITR END)
```
Sorts the elements in the range [BEGIN, END) into ascending order using **Quick Sort** Algorithm.

## Example
```cpp
#include<iostream>
#include<vector>
#include"sortlib.h"
int main()
{
//Merge sort
int myints[] = {32,71,12,45,26,80,53,33};
std::vector<int> vec(myints, myints+8);
// Before sort algorithm: 32 71 12 45 26 80 53 33
sortlib::Sort(vec, sortlib::Sorting_Type::merge_sort);
//After sort algorithm: 12 26 32 33 45 53 71 80
}
```