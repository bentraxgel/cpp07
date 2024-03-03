#pragma once

#include <iostream>
#include <vector> 
#include <deque>
#include <iomanip>
#include <cmath>

void PmergeImpl(std::vector<int>& source);
void PmergeImpl(std::deque<int>& source);

template <typename T>
void	validateForPrint(std::string str, T container)
{
	std::cout << str << ":\t";
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void Pmerge(T src)
{
	(void)src;
	std::cerr << "Error: Wrong container. support only vector, dequeue. " << std::endl;
}

void Pmerge(std::vector<int>& vec)
{
	validateForPrint("Before", vec);
	PmergeImpl(vec);
	validateForPrint("After", vec);
}

void Pmerge(std::deque<int>& dq)
{
	validateForPrint("Before", dq);
	PmergeImpl(dq);
	validateForPrint("After", dq);
}

struct Node
{
public:
	Node*	left;
	Node*	right;
	int		value;
	
	// DEBUG
	int		level;
};

void PmergeImpl(std::vector<int>& source)
{

	std::vector<Node*> nodeArr;
	nodeArr.resize(source.size());

	std::vector<Node*> oddNodeArr;

std::cout << "source size: " << source.size() << std::endl;
	// Initialize leaf nodes by source elements
	// 소스의 int들을 다 노드로 바꿈.
	for (size_t i = 0; i < source.size(); i++)
	{
		Node* newNode = new Node;
		newNode->value = source[i];
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->level = 1; //< DEBUG

		nodeArr[i] = newNode;
	}
	std::cout << "Before:\t";
	for (size_t i = 0; i < nodeArr.size(); i++)
	{
		std::cout << nodeArr[i]->value << " ";
	}

	std::cout << std::endl;

	for (; nodeArr.size() != 1; nodeArr.resize(nodeArr.size() / 2))
	{		
		// Merge nodes by 2
		for (size_t i = 0; i < nodeArr.size(); i += 2)
		{
			Node* newNode = new Node;
			Node* nodeA = nodeArr[i];
			if (i + 1 >= nodeArr.size())
			{
				oddNodeArr.push_back(nodeA);
				break;
			}
			Node* nodeB = nodeArr[i + 1];
			
			newNode->level = nodeA->level + 1; //< DEBUG
			
			if (nodeA->value < nodeB->value)
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

			nodeArr[i / 2] = newNode;
		}
		std::cout << std::endl;

		// print nodes
		for (size_t i = 0; i < nodeArr.size() /2; i++)
		{
			std::cout << nodeArr[i]->value << " ";
		}
		std::cout << std::endl;
	}

	// Insertion phase
	while (nodeArr.size() != source.size())
	{
		// Print nodes 
		std::cout << "-------------------round start------------------" << std::endl;
		for (size_t i = 0; i < nodeArr.size(); i++)
		{
			std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		}
		std::cout << std::endl << std::endl;

		size_t roundLevel = nodeArr[0]->level;
		size_t globalShiftCount = 0;
		size_t lastJacobsNum = 1;
		size_t jacobsNum;
		for (size_t jacobsIdx = 1; lastJacobsNum <= nodeArr.size(); jacobsIdx++, lastJacobsNum = jacobsNum)
		{
			jacobsNum = std::pow(2, jacobsIdx) - lastJacobsNum;
			std::cout << "jacobsNum = " << jacobsNum << std::endl << std::endl;

			size_t localShiftCount = globalShiftCount;
			for (size_t i = jacobsNum; i > lastJacobsNum || (jacobsNum == 1 && i == 1); i--) //< 얘 순서대로 하는게 아니라 나중에 야콥스탙 순서로 바뀌어야됨.
			{
				std::cout << "i = " << i << std::endl;

				size_t currIdx = i + localShiftCount - 1;
				if (currIdx >= nodeArr.size())
				{
					continue;
				}

				// Debug print nodes and disassemble index
				for (size_t j = 0; j < nodeArr.size(); j++)
				{
					std::cout << std::setw(4) << nodeArr[j]->value << '[' << nodeArr[j]->level << "] ";
				}
				std::cout << std::endl;
				for (size_t j = 0; j < currIdx; j++)
				{
					std::cout << "        ";
				}
				std::cout << "   ^";
				std::cout << std::endl << std::endl;

				Node* curr = nodeArr[currIdx];
				if (curr->level < int(roundLevel))
				{
					localShiftCount -= 1;
					i++;
					continue;
				}

				Node* left = curr->left;
				Node* right = curr->right;

				// release the memory of the parent node.
				delete curr;

				// Insert right
				nodeArr[currIdx] = right;

				// Find position to insert the left node.
				if (left == NULL)
				{
					continue;
				}
				{
					// ~이분탐색~ 넣을 곳 찾기~
					// 탐색 범위 [0 ~ i]
					size_t l = 0;
					size_t r = currIdx;
					while (l < r)
					{
						const int mid = (l + r) / 2;
						
						if (nodeArr[mid]->value < left->value)
						{
							l = mid + 1;
						}
						else
						{
							r = mid;
						}
					}
					size_t insertPosition = l;

					// 넣은 공간 만들기~ <- .inser()
					// TODO:

					// 넣기
					nodeArr.insert(nodeArr.begin() + insertPosition, left);
					localShiftCount += 1;
					globalShiftCount += 1;
				}
			}
		}

		if (oddNodeArr.size() != 0)
		{
			if (int(roundLevel - 1) == oddNodeArr.back()->level)
			{
				size_t l = 0;
				size_t r = nodeArr.size();
				while (l < r)
				{
					const int mid = (l + r) / 2;
					
					if (nodeArr[mid]->value < oddNodeArr.back()->value)
					{
						l = mid + 1;
					}
					else
					{
						r = mid;
					}
				}
				size_t insertPosition = l;

				// 넣은 공간 만들기~ <- .inser()
				// TODO:

				// 넣기
				nodeArr.insert(nodeArr.begin() + insertPosition, oddNodeArr.back());
				oddNodeArr.pop_back();
			}
		}

		std::cout << "-------------------RESULT------------------" << std::endl;
		for (size_t i = 0; i < nodeArr.size(); i++)
		{
			std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		}
		std::cout << std::endl << std::endl;
	}

	// 정렬 결과 적용
	{
	}

	// 메모리 해제
	for (size_t i = 0; i < nodeArr.size(); i++)
	{
		 delete nodeArr[i];
	}

	// // shift for insert
	// const int insertIdx = 2; ///숫자를 넣고자하는 위치
	// for (int i = size; i > insertIdx; i--)
	// {
	// 	source[i] = source[i - 1];
	// }
	// source[insertIdx] = .left
}


void PmergeImpl(std::deque<int>& source)
{

	std::deque<Node*> nodeArr;
	nodeArr.resize(source.size());

	std::deque<Node*> oddNodeArr;

std::cout << "source size: " << source.size() << std::endl;
	// Initialize leaf nodes by source elements
	// 소스의 int들을 다 노드로 바꿈.
	for (size_t i = 0; i < source.size(); i++)
	{
		Node* newNode = new Node;
		newNode->value = source[i];
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->level = 1; //< DEBUG

		nodeArr[i] = newNode;
	}
	std::cout << "Before:\t";
	for (size_t i = 0; i < nodeArr.size(); i++)
	{
		std::cout << nodeArr[i]->value << " ";
	}

	std::cout << std::endl;

	for (; nodeArr.size() != 1; nodeArr.resize(nodeArr.size() / 2))
	{		
		// Merge nodes by 2
		for (size_t i = 0; i < nodeArr.size(); i += 2)
		{
			Node* newNode = new Node;
			Node* nodeA = nodeArr[i];
			if (i + 1 >= nodeArr.size())
			{
				oddNodeArr.push_back(nodeA);
				break;
			}
			Node* nodeB = nodeArr[i + 1];
			
			newNode->level = nodeA->level + 1; //< DEBUG
			
			if (nodeA->value < nodeB->value)
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

			nodeArr[i / 2] = newNode;
		}
		std::cout << std::endl;

		// print nodes
		for (size_t i = 0; i < nodeArr.size() /2; i++)
		{
			std::cout << nodeArr[i]->value << " ";
		}
		std::cout << std::endl;
	}

	// Insertion phase
	while (nodeArr.size() != source.size())
	{
		// Print nodes 
		std::cout << "-------------------round start------------------" << std::endl;
		for (size_t i = 0; i < nodeArr.size(); i++)
		{
			std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		}
		std::cout << std::endl << std::endl;

		size_t roundLevel = nodeArr[0]->level;
		size_t globalShiftCount = 0;
		size_t lastJacobsNum = 1;
		size_t jacobsNum;
		for (size_t jacobsIdx = 1; lastJacobsNum <= nodeArr.size(); jacobsIdx++, lastJacobsNum = jacobsNum)
		{
			jacobsNum = std::pow(2, jacobsIdx) - lastJacobsNum;
			std::cout << "jacobsNum = " << jacobsNum << std::endl << std::endl;

			size_t localShiftCount = globalShiftCount;
			for (size_t i = jacobsNum; i > lastJacobsNum || (jacobsNum == 1 && i == 1); i--) //< 얘 순서대로 하는게 아니라 나중에 야콥스탙 순서로 바뀌어야됨.
			{
				std::cout << "i = " << i << std::endl;

				size_t currIdx = i + localShiftCount - 1;
				if (currIdx >= nodeArr.size())
				{
					continue;
				}

				// Debug print nodes and disassemble index
				for (size_t j = 0; j < nodeArr.size(); j++)
				{
					std::cout << std::setw(4) << nodeArr[j]->value << '[' << nodeArr[j]->level << "] ";
				}
				std::cout << std::endl;
				for (size_t j = 0; j < currIdx; j++)
				{
					std::cout << "        ";
				}
				std::cout << "   ^";
				std::cout << std::endl << std::endl;

				Node* curr = nodeArr[currIdx];
				if (curr->level < int(roundLevel))
				{
					localShiftCount -= 1;
					i++;
					continue;
				}

				Node* left = curr->left;
				Node* right = curr->right;

				// release the memory of the parent node.
				delete curr;

				// Insert right
				nodeArr[currIdx] = right;

				// Find position to insert the left node.
				if (left == NULL)
				{
					continue;
				}
				{
					// ~이분탐색~ 넣을 곳 찾기~
					// 탐색 범위 [0 ~ i]
					size_t l = 0;
					size_t r = currIdx;
					while (l < r)
					{
						const int mid = (l + r) / 2;
						
						if (nodeArr[mid]->value < left->value)
						{
							l = mid + 1;
						}
						else
						{
							r = mid;
						}
					}
					size_t insertPosition = l;

					// 넣은 공간 만들기~ <- .inser()
					// TODO:

					// 넣기
					nodeArr.insert(nodeArr.begin() + insertPosition, left);
					localShiftCount += 1;
					globalShiftCount += 1;
				}
			}
		}

		if (oddNodeArr.size() != 0)
		{
			if (int(roundLevel - 1) == oddNodeArr.back()->level)
			{
				size_t l = 0;
				size_t r = nodeArr.size();
				while (l < r)
				{
					const int mid = (l + r) / 2;
					
					if (nodeArr[mid]->value < oddNodeArr.back()->value)
					{
						l = mid + 1;
					}
					else
					{
						r = mid;
					}
				}
				size_t insertPosition = l;

				// 넣은 공간 만들기~ <- .inser()
				// TODO:

				// 넣기
				nodeArr.insert(nodeArr.begin() + insertPosition, oddNodeArr.back());
				oddNodeArr.pop_back();
			}
		}

		std::cout << "-------------------RESULT------------------" << std::endl;
		for (size_t i = 0; i < nodeArr.size(); i++)
		{
			std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		}
		std::cout << std::endl << std::endl;
	}

	// 정렬 결과 적용
	for (size_t i = 0; i < nodeArr.size(); i++)
	{
		source[i] = nodeArr[i]->value;
	}

	// 메모리 해제
	for (size_t i = 0; i < nodeArr.size(); i++)
	{
		 delete nodeArr[i];
	}

	// // shift for insert
	// const int insertIdx = 2; ///숫자를 넣고자하는 위치
	// for (int i = size; i > insertIdx; i--)
	// {
	// 	source[i] = source[i - 1];
	// }
	// source[insertIdx] = .left
}
