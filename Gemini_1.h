#pragma once
#include <iostream>
#include <stdexcept> // �ޤJ std::bad_alloc ���`

// �ЫذʺA�}�C�A�[�J���~�B�z
int* createArray(int size) {
	int* arr = nullptr;//��l�Ƭ��ū���
	try {
		arr = new int[size];
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		// �b�o�̥i�H��ܰ���L���~�B�z�A�Ҧp�^�� null �ΩߥX�ۤv�����`
		}
	return arr;
}

// ��R�}�C
void fillArray(int* arr, int size) {
	if (arr) {
		std::cout << "�п�J " << size << " �Ӿ�� (�H�Ů���j): " << std::endl;
		for (int i = 0; i < size; ++i) {
			std::cin >> arr[i];//�q�ϥΪ̿�JŪ���ƭȨæs�x��}�C��
			//���ݭn arr[i] = i �O�]���ڭ̷Q�n���ϥΪ̴��Ѱ}�C�����e�A�Ӥ��O�ΰj�骺���ޭȨӶ�R�}�C�C
		}
	}
	else {
		std::cerr << "�L�k��R�}�C�A�]�����еL�ġC" << std::endl;
	}
}

//�C�L�}�C
void printArray(int* arr, int size) {
	if (arr) {
		std::cout << "Array: ";
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cerr << "�L�k�C�L�}�C�A�]�����еL�ġC" << std::endl;
		//��X���~�M�E�_�T���A�P���`���{����X���}�A�åB�q�`�㦳�D�w�Ī��S��
	}
}

// ����}�C�O����
void freeArray(int* arr) {
	if (arr) {
		delete[] arr; // ������O����
		arr = nullptr;// �A�N���г]���ū���
		// �����N���г]���ū��СA�����a�B����
		//nullptr �O�@�������w�����ū��СA�Ω��ܫ��Ф����V���󦳮Ī��O�����m

		std::cout << "�}�C�O����w����C" << std::endl;
	}
	else {
		std::cerr << "�L�k����}�C�O����A�]�����еL�ġC" << std::endl;
	}
}

int main() {
	int size;
	std::cout << "�п�J�}�C�j�p: ";
	std::cin >> size;

	int* arr = createArray(size);

	if (arr) {
		fillArray(arr, size);
		printArray(arr, size);
		freeArray(arr);
	}
	else {
		std::cerr << "�{���פ�A�]���L�k���t�O����C" << std::endl;
	}
	
	return 0;
}