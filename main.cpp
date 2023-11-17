#include <iostream>
#include <string>
#include "Tests.h"
using namespace std;



int main() {
	// testAVLSort();
	// testRandomAVLSort();
	// testRandAVLIncSort();
	// testRandAVLDicSort();
	autoTestChangeSizeAVLSort();
	autoTestChangeSizeAVLSortIncSort();
	autoTestChangeSizeAVLSortDicSort();
	autoTestChangeValueAVLSort();
	autoTestChangeValueAVLSortIncSort();
	autoTestChangeValueAVLSortDicSort();
	// testQuickSort();
	// testRandomQuickSort();
	// testRandQuickSortIncSort();
	// testRandQuickSortDicSort();
	autoTestChangeSizeQuickSort();
	autoTestChangeSizeQuickSortIncSort();
	autoTestChangeSizeQuickSortDicSort();
	autoTestChangeValueQuickSort();
	autoTestChangeValueQuickSortIncSort();
	autoTestChangeValueQuickSortDicSort();
	return 0;
}
