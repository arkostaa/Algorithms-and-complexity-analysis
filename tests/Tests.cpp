#include "Tests.h"

template<typename T>
void printVector(const std::vector<T>& elems)
{
	for (const auto& elem : elems)
	{
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
}



//AVL SORT

int64_t generateRandomNumbers(int64_t min, int64_t max) { 
 
   	// Генерация случайного числа в заданном диапазоне 
    int64_t randomNumber = min + (std::rand() % (max - min + 1)); 
 
    return randomNumber; 
}


void testAVLSort()
{

	std::cout << std::endl;

	std::vector<int64_t> elems{ 1,5,-2,11,5,6,57,38,9,0,1,22,3,4,INT16_MIN};
	printVector(elems);

	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandomAVLSort() {
	std::cout << std::endl;

	std::vector<int64_t> elems(15);
	for (auto& elem: elems)
	{
		elem = generateRandomNumbers(-1000,1000);
	}
	
	printVector(elems);

	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandAVLIncSort() {
	std::cout << std::endl;

	std::vector<int64_t> elems(15);
	for (auto& elem: elems)
	{
		elem = generateRandomNumbers(-1000,1000);
	}
	printVector(elems);

	std::sort(elems.begin(), elems.end());

	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandAVLDicSort() {
	std::cout << std::endl;

	std::vector<int64_t> elems(15);
	for (auto& elem: elems)
	{
		elem = generateRandomNumbers(-1000,1000);
	}
	printVector(elems);

	std::sort(elems.rbegin(), elems.rend());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

// AVL CHANGE SIZE

int64_t testChangeSizeAVLSort(int64_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	
	AVLsort(elems);	
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeSizeAVLSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeSizeAVLSortNoSort.txt"), std::fstream::out);

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSort(size, 0, 1'000'000'000);
		file << size << ' ' << result << '\n';
		std::cout << size << ' ' << result << '\n';
	}
	file.close();
}

int64_t testChangeSizeAVLSortIncSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::sort(elems.begin(), elems.end());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();
	return duration;
}

void autoTestChangeSizeAVLSortIncSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeSizeAVLSortIncSort.txt"), std::fstream::out);

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSortIncSort(size, 0, 1'000'000'000);
		file << size << ' ' << result << '\n';
		std::cout << size << ' ' << result << '\n';
	}
	file.close();
}

int64_t testChangeSizeAVLSortDicSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::sort(elems.begin(), elems.end());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();


	return duration;
}

void autoTestChangeSizeAVLSortDicSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeSizeAVLSortDicSort.txt"), std::fstream::out);

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSortDicSort(size, 0, 1'000'000'000);
		file << size << ' ' << result << '\n';
		std::cout << size << ' ' << result << '\n';
	}
	file.close();
}

// // AVL CHANGE VALUE

int64_t testChangeValueAVLSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::sort(elems.begin(), elems.end());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeValueAVLSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeValueAVLSortNoSort.txt"), std::fstream::out);

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueAVLSort(1'000'000, 1, value);
		file << value << ' ' << result << '\n';
		std::cout << value << ' ' << result << '\n';
	}
	file.close();
}

int64_t testChangeValueAVLSortIncSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);
	
	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	std::sort(elems.begin(), elems.end());

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeValueAVLSortIncSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeValueAVLSortIncSort.txt"), std::fstream::out);

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueAVLSortIncSort(1'000'000, 1, value);
		file << value << ' ' << result << '\n';
		std::cout << value << ' ' << result << '\n';
	}
	file.close();
}

int64_t testChangeValueAVLSortDicSort(size_t size, int64_t min, int64_t max) {

	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	std::sort(elems.begin(), elems.end());

	AVLsort(elems);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();


	return duration;
}

void autoTestChangeValueAVLSortDicSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeValueAVLSortDicSort.txt"), std::fstream::out);

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueAVLSortDicSort(1'000'000, 1, value);
		file << value << ' ' << result << '\n';
		std::cout << value << ' ' << result << '\n';
	}
	file.close();
}

// // QSORT

void testQuickSort()
{
	std::cout << std::endl;

	std::vector<int64_t> elems{ 1,5,-2,11,5,6,57,38,9,0,1,22,3,4,INT_MIN };
	printVector(elems);

	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandomQuickSort() {
	std::cout << std::endl;
	
	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generateRandomNumbers(-1000, 1000);
	printVector(elems);

	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;
	std::cout << std::endl;
}

void testRandQuickSortIncSort() {
	std::cout << std::endl;

	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generateRandomNumbers(-1000, 1000);
	printVector(elems);
	
	printVector(elems);

	std::sort(elems.begin(), elems.end());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandQuickSortDicSort() {
	std::cout << std::endl;

	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generateRandomNumbers(-1000, 1000);
	printVector(elems);

	std::sort(elems.rbegin(), elems.rend());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();
 

	printVector(elems);
	std::cout << "Result: " << duration << "ns" << std::endl;

	std::cout << std::endl;
}

// //---------------------------QUICK CHANGE SIZE--------------------//

int64_t testChangeSizeQuickSort(size_t size, int64_t min, int64_t max) {

	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();

	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeSizeQuickSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeSizeQuickSortNoSort.txt"), std::fstream::out);


	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeQuickSort(size, 0, 1'000'000'000);
		file << size << ' ' << result << '\n';
		std::cout << size << ' ' << result << '\n';
	}
	file.close();
}


int64_t testChangeSizeQuickSortIncSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }

	std::sort(elems.begin(), elems.end());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeSizeQuickSortIncSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeSizeQuickSortIncSort.txt"), std::fstream::out);

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeQuickSortIncSort(size, 0, 1'000'000'000);
		file << size << ' ' << result << '\n';
		std::cout << size << ' ' << result << '\n';
	}
	file.close();
}


int64_t testChangeSizeQuickSortDicSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }

	std::sort(elems.rbegin(), elems.rend());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeSizeQuickSortDicSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeSizeQuickSortDicSort.txt"), std::fstream::out);


	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeQuickSortDicSort(size, 0, 1'000'000'000);
		file << size << ' ' << result << '\n';
		std::cout << size << ' ' << result << '\n';
	}
	file.close();
}

// //--------------------------QUICK CHANGE VALUE-------------------------//

int64_t testChangeValueQuickSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }

	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeValueQuickSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeValueQuickSortNoSort.txt"), std::fstream::out);

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueQuickSort(1'000'000, 1, value);
		file << value << ' ' << result << '\n';
		std::cout << value << ' ' << result << '\n';
	}
	file.close();
}


int64_t testChangeValueQuickSortIncSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }


	std::sort(elems.begin(), elems.end());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
}

void autoTestChangeValueQuickSortIncSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeValueQuickSortIncSort.txt"), std::fstream::out);

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueQuickSortIncSort(1'000'000, 1, value);
		file << value << ' ' << result << '\n';
		std::cout << value << ' ' << result << '\n';
	}
	file.close();
}


int64_t testChangeValueQuickSortDicSort(size_t size, int64_t min, int64_t max) {
	std::vector<int64_t> elems(size);

	for (auto& elem: elems){ elem = generateRandomNumbers(min, max); }


	std::sort(elems.rbegin(), elems.rend());
	std::chrono::high_resolution_clock::time_point timer;
	timer = std::chrono::high_resolution_clock::now();
	quickSort(elems, 0, elems.size() - 1);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();

	return duration;
};


void autoTestChangeValueQuickSortDicSort() {
	int64_t result = 0;

	std::fstream file(std::string(".\\TestChangeValueQuickSortDicSort.txt"), std::fstream::out);

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueQuickSortDicSort(1'000'000, 1, value);
		file << value << ' ' << result << '\n';
		std::cout << value << ' ' << result << '\n';
	}
	file.close();
}