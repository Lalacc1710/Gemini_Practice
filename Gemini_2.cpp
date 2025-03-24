#include <iostream>
#include <string>
#include <algorithm>// 需要用到 std::reverse

// 反轉字串
void reverseString(std::string& str) {
	std::reverse(str.begin(), str.end());
}

// 判斷是否為回文
bool isPalindrome(const std::string& str) {
	std::string reversedStr = str;
	reverseString(reversedStr);
	return str == reversedStr;
}

int main() {
	std::string inputStr;
	std::cout << "請輸入一個字串 : ";
	std::cin >> inputStr;

	if (isPalindrome(inputStr)) {
		std::cout << "這是一個回文" << std::endl;
	}
	else {
		std::cout << "這不是一個回文" << std::endl;
	}
	return 0;
}