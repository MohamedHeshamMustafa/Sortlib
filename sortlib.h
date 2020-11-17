#pragma once

#include<algorithm>
#include<functional>

namespace sortlib {

enum Sorting_Type{

		bubble_sort,
		selection_sort,
		merge_sort,
		quick_sort
	};

/*swap two variables without using a temp variable*/
template <typename T>
inline void swap(T& First_Var, T& Sec_Var){

	First_Var = First_Var ^ Sec_Var;
	Sec_Var = First_Var ^ Sec_Var;
	First_Var = First_Var ^ Sec_Var;
}


/*Bubble Sort Algorithm : works by repeatedly swapping
the adjacent elements if they are in wrong order.*/
template <typename Itr>
void Bubble_Sort(Itr begin, Itr end) {
	for (auto Itr1 = begin; Itr1 != end; ++Itr1)
		for (auto Itr2 = begin; Itr2 != (end - (Itr1 - begin) - 1); ++Itr2)
			if (*Itr2 > *(Itr2 + 1))
				swap(*Itr2, *(Itr2 + 1));

}

/*Selection Sort by repeatedly finding the minimum element 
from unsorted partand putting it at the beginning.*/
template <typename Itr>
void Selection_Sort(Itr begin, Itr end){

	Itr Current_Min;
	for (auto Itr1 = begin; Itr1 != end; ++Itr1){
		Current_Min = Itr1;

		for (auto Itr2 = (Itr1 + 1); Itr2 != end; ++Itr2)
			if (*Itr2 < *Current_Min)
				Current_Min = Itr2;

		if (Current_Min != Itr1)
			swap(*Current_Min, *Itr1);

	}
		

}

/*Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves,
calls itself for the two halves and then merges the two sorted halves*/
template <typename Itr>
void Merge_Sort(Itr begin, Itr end) {

	auto size = std::distance(begin, end);
	if (size < 2)
		return;
	//getting an itterator pointing to the middle element
	auto middle = std::next(begin, size/2);
	Merge_Sort(begin, middle);
	Merge_Sort(middle, end);

	std::inplace_merge(begin, middle, end);
}

/*Quick sort is a divide and conquer algorithm 
It picks an element as pivot and partitions the given array around the picked pivot*/
template <typename Itr, class Compare = std::less<>>
void Quick_Sort(Itr begin, Itr end, Compare cmp = Compare{}) {

	auto const N = std::distance(begin, end);
	if (N <= 1) return;
	auto const pivot = std::next(begin, N / 2);
	std::nth_element(begin, pivot, end, cmp);
	Quick_Sort(begin, pivot, cmp);
	Quick_Sort(pivot, end, cmp);
}

template<typename Container>
void Sort(Container & C, Sorting_Type t){
	auto Begin_Itr =std::begin(C);
	auto End_Itr = std::end(C);
	
	if (t == 0)
		Bubble_Sort(Begin_Itr, End_Itr);


	else if (t == 1)
		Selection_Sort(Begin_Itr, End_Itr);
	
	else if(t == 2)
		Merge_Sort(Begin_Itr, End_Itr);


	else if (t == 3)
		Quick_Sort(Begin_Itr, End_Itr);
}




}
