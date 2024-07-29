#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Tree.h"
int const BUFFER_SIZE1 = 1023 + 1;

Tree* dataBase()
{
	Tree* tree = new Tree();
	char str[BUFFER_SIZE1] = "Turning from the wrong lane";
	char str1[BUFFER_SIZE1] = "Crossing a solid";
	char str2[BUFFER_SIZE1] = "Hitting a pedestrian";
	char str3[BUFFER_SIZE1] = "Stop in the wrong place";
	char str4[BUFFER_SIZE1] = "Speeding";
	tree->addReceipt(456, str);
	tree->addReceipt(456, str1);
	tree->addReceipt(215, str2);
	tree->addReceipt(674, str4);
	tree->addReceipt(111, str4);
	tree->addReceipt(111, str2);

	return tree;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "���� ������ ���\n";
	std::cout << "M���:\n";
	std::cout << "1 - ������ ���������� ���� ������;\n"
		"2 - ���������� �� ��������� ������;\n"
		"3 - ���������� ������ �� ��������� �������.\n";

	Tree* tree = dataBase();
	int menuItem;
	std::cout << "������� ����� ����:\n";
	std::cin >> menuItem;
	
	if (menuItem == 1)
	{
		std::cout << "������ ���������� ���� ������:\n";
		tree->printTree();
	}
	else if (menuItem == 2) {
		std::cout << "���������� �� ��������� ������\n";
		int number;
		do
		{
			std::cout << "������� ����������� �����:\n";
			std::cin >> number;
			if (number < 100 || number > 999) {
				std::cout << "������� ������ ����� ����������:\n";
			}
		}
		while (number < 100 || number > 999);

		tree->find(number);
	}
	else if (menuItem == 3) {
		std::cout << "������� �������� �������:\n";
		int left, right;
		std::cin >> left >> right;
		tree->printRangeTree(left, right);
	}
	else
		std::cout << "������� ��������� ����� ����!\n";

	return 0;
}

