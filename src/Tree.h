
#pragma once
#include<string>
#include<iostream>
#include <string>
#include <vector>
#include <list>

int const BUFFER_SIZE = 1023 + 1;
int const LIST_SIZE = 100;

class TreeNode
{
public:
	TreeNode* lchild_ = nullptr;
	TreeNode* rchild_ = nullptr;
	int value_;
	char** list_;
	void printNode();
	void addViolation(char* str);
	TreeNode(int value);
	~TreeNode();
};

void TreeNode::addViolation(char* str)
{
	char* string = new char[BUFFER_SIZE];
	strcpy(string, str);

	for (int ii = 0; ii < LIST_SIZE; ii++)
	{
		if (list_[ii] == nullptr) {
			list_[ii] = string;
			break;
		}
	}
}

TreeNode::TreeNode(int value)
{
	value_ = value;

	list_ = new char* [LIST_SIZE];

	for (int ii = 0; ii < LIST_SIZE; ii++)
	{
		list_[ii] = nullptr;
	}
}

TreeNode::~TreeNode()
{
	if (lchild_) delete lchild_;
	if (rchild_) delete rchild_;
}

void TreeNode::printNode()
{
	std::cout << "\nНомер автомобиля: " << value_;
	std::cout << "\nНарушения:\n";

	for (int ii = 0; ii < LIST_SIZE; ii++)
	{
		if(list_[ii] != nullptr)
			std::cout << ii + 1 << ") " << list_[ii] << '\n';
	}
}

class Tree
{
public:
	Tree() {};
	~Tree();
	void find(int value);
	void addReceipt(int value, char* str);
	void printTree();
	void printRangeTree(int left, int right);

private:
	TreeNode* root_ = nullptr;
	void print(TreeNode* curr);
	void printRange(TreeNode* curr, int left, int right);
};

Tree::~Tree()
{
	delete root_;
}

void Tree::print(TreeNode* curr)
{
	if (curr)
	{
		print(curr->lchild_);
		curr->printNode();
		print(curr->rchild_);
	}
}

void Tree::printTree()
{
	print(root_);
	std::cout << std::endl;
}

void Tree::find(int value)
{
	TreeNode* curr = root_;

	while (curr && curr->value_ != value)
	{
		if (curr->value_ > value)
			curr = curr->lchild_;
		else
			curr = curr->rchild_;
	}
	if (curr != nullptr)
		curr->printNode();
	else
		std::cout << "Number not found!\n";
}

void Tree::addReceipt(int value, char* str)
{
	if (root_ == nullptr) {
		root_ = new TreeNode(value);
		root_->addViolation(str);
		return;
	}

	TreeNode* curr = root_;

	while (curr && curr->value_ != value)
	{
		if (curr->value_ > value && curr->lchild_ == nullptr)
		{
			curr->lchild_ = new TreeNode(value);
			curr->lchild_->addViolation(str);
			return;
		}
		if (curr->value_ < value && curr->rchild_ == nullptr)
		{
			curr->rchild_ = new TreeNode(value);
			curr->rchild_->addViolation(str);
			return;
		}
		if (curr->value_ > value)
			curr = curr->lchild_;
		else
			curr = curr->rchild_;
	}

	if (curr->value_ == value) {
		curr->addViolation(str);
		return;
	}
}

void Tree::printRange(TreeNode* curr, int left, int right)
{
	if (curr)
	{
		printRange(curr->lchild_, left, right);
		if(curr->value_ >= left && curr->value_ <= right)
			curr->printNode();
		printRange(curr->rchild_, left, right);
	}
}

void Tree::printRangeTree(int left, int right)
{
	printRange(root_, left, right);
	std::cout << std::endl;
}
