#ifndef TESTS_H
#define TESTS_H

#include "Algorithms.h"
#include <iostream>
#include <fstream>
#include <chrono>

template<typename T>
void printVector(const std::vector<T>& elems);

int64_t generateRandomNumbers(int64_t min, int64_t max);

//----------------------------AVL SORT------------------------//
void testAVLSort();

void testRandomAVLSort();

void testRandAVLIncSort();

void testRandAVLDicSort();

//--------------------------AVL CHANGE SIZE-------------------//

int64_t testChangeSizeAVLSort(int64_t size, int64_t min, int64_t max);
void autoTestChangeSizeAVLSort();


int64_t testChangeSizeAVLSortIncSort(size_t size, int64_t min, int64_t max);
void autoTestChangeSizeAVLSortIncSort();


int64_t testChangeSizeAVLSortDicSort(size_t size, int64_t min, int64_t max);
void autoTestChangeSizeAVLSortDicSort();

// //--------------------------AVL CHANGE VALUE-------------------------//

int64_t testChangeValueAVLSort(size_t size, int64_t min, int64_t max);
void autoTestChangeValueAVLSort();


int64_t testChangeValueAVLSortIncSort(size_t size, int64_t min, int64_t max);
void autoTestChangeValueAVLSortIncSort();


int64_t testChangeValueAVLSortDicSort(size_t size, int64_t min, int64_t max);
void autoTestChangeValueAVLSortDicSort();

// //---------------------------QUICK SORT----------------------//
void testQuickSort();

void testRandomQuickSort();

void testRandQuickSortIncSort();

void testRandQuickSortDicSort();

// //---------------------------QUICK CHANGE SIZE--------------------//

int64_t testChangeSizeQuickSort(size_t size, int64_t min, int64_t max);
void autoTestChangeSizeQuickSort();


int64_t testChangeSizeQuickSortIncSort(size_t size, int64_t min, int64_t max);
void autoTestChangeSizeQuickSortIncSort();


int64_t testChangeSizeQuickSortDicSort(size_t size, int64_t min, int64_t max);
void autoTestChangeSizeQuickSortDicSort();

// //--------------------------QUICK CHANGE VALUE-------------------------//
int64_t testChangeValueQuickSort(size_t size, int64_t min, int64_t max);
void autoTestChangeValueQuickSort();


int64_t testChangeValueQuickSortIncSort(size_t size, int64_t min, int64_t max);
void autoTestChangeValueQuickSortIncSort();


int64_t testChangeValueQuickSortDicSort(size_t size, int64_t min, int64_t max);
void autoTestChangeValueQuickSortDicSort();



#endif // TESTS_H