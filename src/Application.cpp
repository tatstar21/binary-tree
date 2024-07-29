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
	std::cout << "БАЗА ДАННЫХ ГАИ\n";
	std::cout << "Mеню:\n";
	std::cout << "1 - полная распечатка базы данных;\n"
		"2 - распечатка по заданному номеру;\n"
		"3 - распечатка данных по диапазону номеров.\n";

	Tree* tree = dataBase();
	int menuItem;
	std::cout << "Введите пункт меню:\n";
	std::cin >> menuItem;
	
	if (menuItem == 1)
	{
		std::cout << "Полная распечатка базы данных:\n";
		tree->printTree();
	}
	else if (menuItem == 2) {
		std::cout << "Распечатка по заданному номеру\n";
		int number;
		do
		{
			std::cout << "Введите трехзначный номер:\n";
			std::cin >> number;
			if (number < 100 || number > 999) {
				std::cout << "Неверно введен номер автомобиля:\n";
			}
		}
		while (number < 100 || number > 999);

		tree->find(number);
	}
	else if (menuItem == 3) {
		std::cout << "Введите диапазон номеров:\n";
		int left, right;
		std::cin >> left >> right;
		tree->printRangeTree(left, right);
	}
	else
		std::cout << "Неверно введенный пункт меню!\n";

	return 0;
}

