#pragma once
#include <iostream>
#include <stdexcept> // 引入 std::bad_alloc 異常

// 創建動態陣列，加入錯誤處理
int* createArray(int size) {
	int* arr = nullptr;//初始化為空指標
	try {
		arr = new int[size];
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		// 在這裡可以選擇做其他錯誤處理，例如回傳 null 或拋出自己的異常
		}
	return arr;
}

// 填充陣列
void fillArray(int* arr, int size) {
	if (arr) {
		std::cout << "請輸入 " << size << " 個整數 (以空格分隔): " << std::endl;
		for (int i = 0; i < size; ++i) {
			std::cin >> arr[i];//從使用者輸入讀取數值並存儲到陣列中
			//不需要 arr[i] = i 是因為我們想要讓使用者提供陣列的內容，而不是用迴圈的索引值來填充陣列。
		}
	}
	else {
		std::cerr << "無法填充陣列，因為指標無效。" << std::endl;
	}
}

//列印陣列
void printArray(int* arr, int size) {
	if (arr) {
		std::cout << "Array: ";
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cerr << "無法列印陣列，因為指標無效。" << std::endl;
		//輸出錯誤和診斷訊息，與正常的程式輸出分開，並且通常具有非緩衝的特性
	}
}

// 釋放陣列記憶體
void freeArray(int* arr) {
	if (arr) {
		delete[] arr; // 先釋放記憶體
		arr = nullptr;// 再將指標設為空指標
		// 釋放後將指標設為空指標，防止懸浮指標
		//nullptr 是一個類型安全的空指標，用於表示指標不指向任何有效的記憶體位置

		std::cout << "陣列記憶體已釋放。" << std::endl;
	}
	else {
		std::cerr << "無法釋放陣列記憶體，因為指標無效。" << std::endl;
	}
}

int main() {
	int size;
	std::cout << "請輸入陣列大小: ";
	std::cin >> size;

	int* arr = createArray(size);

	if (arr) {
		fillArray(arr, size);
		printArray(arr, size);
		freeArray(arr);
	}
	else {
		std::cerr << "程式終止，因為無法分配記憶體。" << std::endl;
	}
	
	return 0;
}