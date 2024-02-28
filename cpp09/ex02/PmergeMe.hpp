#pragma once

#include <vector> 
#include <iostream>
#include <deque>

void PmergeImpl(std::vector<int>& source);

template <typename T>
void Pmerge(T src)
{	
	std::cerr << "Error: Wrong container. support only vector, dequeue. " << std::endl;
}

//template <>
void Pmerge(std::vector<int>& vec)
{
	PmergeImpl(vec);
}

// template <>
void Pmerge(std::deque<int>& dq)
{
	//PmergeImpl<std::deque, int>(dq);
}

void PmergeImpl(std::vector<int>& source)
{
	struct Node
	{
	public:
		Node*   left;
		Node*   right;
		int     value;
	};

	std::vector<Node*> nodeArr;
	nodeArr.resize(source.size());

std::cout << "source size: " << source.size() << std::endl;
	// Initialize leaf nodes by source elements
	// 소스의 int들을 다 노드로 바꿈.
	for (size_t i = 0; i < source.size(); i++)
	{
		Node* newNode = new Node;
		newNode->value = source[i];
		newNode->left = NULL;
		newNode->right = NULL;
		
		nodeArr[i] = newNode;
	}
	
for (size_t i = 0; i < nodeArr.size(); i++)
{
	std::cout << nodeArr[i]->value << " ";
}
std::cout << std::endl;

	for (; nodeArr.size() != 1; nodeArr.resize(nodeArr.size() / 2))
	{
		if (nodeArr.size() % 2 == 1)
			nodeArr.push_back(NULL);
		
		// Merge nodes by 2
		for (size_t i = 0; i < nodeArr.size(); i += 2)
		{
			Node* newNode = new Node;
			Node* nodeA = nodeArr[i];
			Node* nodeB = nodeArr[i + 1];
			if (nodeB == NULL)
			{
				newNode->left = NULL;
				newNode->right = nodeA;
				newNode->value = nodeA->value;
			}
			else if (nodeA->value < nodeB->value)
			{
				newNode->left = nodeA;
				newNode->right = nodeB;
				newNode->value = nodeB->value;
			}
			else // nodeA >= nodeB
			{
				newNode->left = nodeB;
				newNode->right = nodeA;
				newNode->value = nodeA->value;
			}
			std::cout << nodeArr[i]->value << " ";

			nodeArr[i / 2] = newNode;
		}
		std::cout << std::endl;

		// print nodes
		for (size_t i = 0; i < nodeArr.size() /2; i++)
		{
			std::cout << "GG" << i << "  " <<nodeArr[i]->value << " ";
		}
		std::cout << std::endl;
	}

	// Insertion phase
	//while (nodeArr.size() != source.size())
	{
		for (size_t i = 0; i < nodeArr.size(); i++) //< 얘 순서대로 하는게 아니라 나중에 야콥스탙 순서로 바뀌어야됨.
		{
			Node* curr = nodeArr[i];
			Node* left = curr->left;
			Node* right = curr->right;

			nodeArr[i] = right;

			// Find position to insert the left node.
			{
				// ~이분탐색~ 넣을 곳 찾기~
				// 탐색 범위 [0 ~ i]
				{
				}
				size_t insertPosition;

				// 넣은 공간 만들기~
				// TODO:
				{
				}

				// 넣기
				nodeArr[insertPosition] = left;
			}
		}
	}

	// // shift for insert
	// const int insertIdx = 2; ///숫자를 넣고자하는 위치
	// for (int i = size; i > insertIdx; i--)
	// {
	// 	source[i] = source[i - 1];
	// }
	// source[insertIdx] = .left
}
