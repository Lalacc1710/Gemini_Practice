#include <iostream>
#include <string>
#include <algorithm>// �ݭn�Ψ� std::reverse

// ����r��
void reverseString(std::string& str) {
	std::reverse(str.begin(), str.end());
}

// �P�_�O�_���^��
bool isPalindrome(const std::string& str) {
	std::string reversedStr = str;
	reverseString(reversedStr);
	return str == reversedStr;
}

int main() {
	std::string inputStr;
	std::cout << "�п�J�@�Ӧr�� : ";
	std::cin >> inputStr;

	if (isPalindrome(inputStr)) {
		std::cout << "�o�O�@�Ӧ^��" << std::endl;
	}
	else {
		std::cout << "�o���O�@�Ӧ^��" << std::endl;
	}
	return 0;
}