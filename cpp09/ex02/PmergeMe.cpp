#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char**argv)
{
	makeVector(argv);
	makeDeque();
}
PmergeMe::~PmergeMe() {}

std::vector<int>& PmergeMe::getVector()
{
	return _vec;
}
std::deque<int>& PmergeMe::getDeque()
{
	return _dq;
}

void	PmergeMe::printToVector(std::string str)
{
	std::cout << str << ":\t";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::makeVector(char** argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream iss(argv[i]);
		int num;
		// iss에 남은 버퍼가 있는지 remain으로 확인
		std::string remain;
		if (!(iss >> num) || num <= 0 || (iss >> remain))
		{
			throw InvalidInput();
		}
		// check to duplicates
		std::vector<int>::iterator iter;
		for (iter = _vec.begin(); iter != _vec.end(); iter++)
		{
			if (*iter == num)
			{
				std::cout << "duplicates num: " << num << " ";
				throw InvalidInput();
			}
		}
		_vec.push_back(num);
	}
}
void	PmergeMe::makeDeque()
{
	_dq.resize(_vec.size());
	for (size_t i = 0; i < _vec.size(); i++)
	{
		_dq[i] = _vec[i];
	}
}


template <typename T>
void PmergeMe::Pmerge(T src)
{
	static_cast<void>(src);
	std::cout << "Error: Wrong container. support only vector, dequeue. " << std::endl;
}
void PmergeMe::Pmerge(std::vector<int>& vec)
{
	PmergeImpl(vec);
}
void PmergeMe::Pmerge(std::deque<int>& dq)
{
	PmergeImpl(dq);
}


void PmergeMe::PmergeImpl(std::vector<int>& source)
{
	std::vector<Node*> nodeArr;
	nodeArr.resize(source.size());

	// 짝이 되지 않는 홀수개의 노드를 저장하는 배열
	std::vector<Node*> oddNodeArr;

	// Initialize leaf nodes by source elements
	// 소스의 int들을 다 노드로 바꿈.
	for (size_t i = 0; i < source.size(); i++)
	{
		Node* newNode = new Node;
		newNode->value = source[i];
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->level = 1;

		nodeArr[i] = newNode;
	}

	for (; nodeArr.size() != 1; nodeArr.resize(nodeArr.size() / 2))
	{
		// Merge nodes by 2
		for (size_t i = 0; i < nodeArr.size(); i += 2)
		{
			Node* newNode = new Node;
			Node* nodeA = nodeArr[i];
			if (i + 1 >= nodeArr.size())
			{
				delete newNode;
				oddNodeArr.push_back(nodeA);
				break;
			}
			Node* nodeB = nodeArr[i + 1];
			
			newNode->level = nodeA->level + 1;
			
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
	}

	// Insertion phase
	while (nodeArr.size() != source.size())
	{
		// // Print nodes < DEBUG
		// std::cout << "-------------------round start------------------" << std::endl;
		// for (size_t i = 0; i < nodeArr.size(); i++)
		// {
		// 	std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		// }
		// std::cout << std::endl << std::endl;

		size_t roundLevel = nodeArr[0]->level;

		if (oddNodeArr.size() != 0)
		{
			if (static_cast<int>(roundLevel - 1) == oddNodeArr.back()->level)
			{
				Node* newNode = new Node;
				newNode->left = oddNodeArr.back();
				newNode->right = NULL;
				newNode->level = oddNodeArr.back()->level + 1;
				newNode->value = oddNodeArr.back()->value; 
				oddNodeArr.pop_back();

				nodeArr.push_back(newNode);
			}
		}

		size_t globalShiftCount = 0;
		size_t lastJacobsNum = 1;
		size_t jacobsNum;
		for (size_t jacobsIdx = 1; lastJacobsNum <= nodeArr.size(); jacobsIdx++, lastJacobsNum = jacobsNum)
		{
			jacobsNum = std::pow(2, jacobsIdx) - lastJacobsNum;

			size_t localShiftCount = globalShiftCount;
			for (size_t i = jacobsNum; i > lastJacobsNum || (jacobsNum == 1 && i == 1); i--)
			{
				size_t currIdx = i + localShiftCount - 1;
				if (currIdx >= nodeArr.size())
				{
					continue;
				}

				// // Debug print nodes and disassemble index < DEBUG
				// for (size_t j = 0; j < nodeArr.size(); j++)
				// {
				// 	std::cout << std::setw(4) << nodeArr[j]->value << '[' << nodeArr[j]->level << "] ";
				// }
				// std::cout << std::endl;
				// for (size_t j = 0; j < currIdx; j++)
				// {
				// 	std::cout << "        ";
				// }
				// std::cout << "   ^";
				// std::cout << std::endl << std::endl;

				Node* curr = nodeArr[currIdx];
				if (curr->level < static_cast<int>(roundLevel))
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
				if (right != NULL)
					nodeArr[currIdx] = right;
				if (right == NULL)
					nodeArr.pop_back();

				// Find position to insert the left node.
				if (left == NULL)
				{
					continue;
				}
				{
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

					nodeArr.insert(nodeArr.begin() + insertPosition, left);
					localShiftCount += 1;
					globalShiftCount += 1;
				}
			}
		}

		// // print to result of nodeArr < DEBUG
		// std::cout << "-------------------RESULT------------------" << std::endl;
		// for (size_t i = 0; i < nodeArr.size(); i++)
		// {
		// 	std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		// }
		// std::cout << std::endl << std::endl;
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
}

// DEQUE
void PmergeMe::PmergeImpl(std::deque<int>& source)
{
	std::deque<Node*> nodeArr;
	nodeArr.resize(source.size());

	// 짝이 되지 않는 홀수개의 노드를 저장하는 배열
	std::deque<Node*> oddNodeArr;

	// Initialize leaf nodes by source elements
	// 소스의 int들을 다 노드로 바꿈.
	for (size_t i = 0; i < source.size(); i++)
	{
		Node* newNode = new Node;
		newNode->value = source[i];
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->level = 1;

		nodeArr[i] = newNode;
	}

	for (; nodeArr.size() != 1; nodeArr.resize(nodeArr.size() / 2))
	{
		// Merge nodes by 2
		for (size_t i = 0; i < nodeArr.size(); i += 2)
		{
			Node* newNode = new Node;
			Node* nodeA = nodeArr[i];
			if (i + 1 >= nodeArr.size())
			{
				delete newNode;
				oddNodeArr.push_back(nodeA);
				break;
			}
			Node* nodeB = nodeArr[i + 1];
			
			newNode->level = nodeA->level + 1;
			
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
	}

	// Insertion phase
	while (nodeArr.size() != source.size())
	{
		size_t roundLevel = nodeArr[0]->level;
		// // Print nodes < DEBUG
		// std::cout << "-------------------round start------------------" << std::endl;
		// for (size_t i = 0; i < nodeArr.size(); i++)
		// {
		// 	std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		// }
		// std::cout << std::endl << std::endl;

		if (oddNodeArr.size() != 0)
		{
			if (static_cast<int>(roundLevel - 1) == oddNodeArr.back()->level)
			{
				Node* newNode = new Node;
				newNode->left = oddNodeArr.back();
				newNode->right = NULL;
				newNode->level = oddNodeArr.back()->level + 1;
				newNode->value = oddNodeArr.back()->value; 
				oddNodeArr.pop_back();

				nodeArr.push_back(newNode);
			}
		}

		size_t globalShiftCount = 0;
		size_t lastJacobsNum = 1;
		size_t jacobsNum;
		for (size_t jacobsIdx = 1; lastJacobsNum <= nodeArr.size(); jacobsIdx++, lastJacobsNum = jacobsNum)
		{
			jacobsNum = std::pow(2, jacobsIdx) - lastJacobsNum;

			size_t localShiftCount = globalShiftCount;
			for (size_t i = jacobsNum; i > lastJacobsNum || (jacobsNum == 1 && i == 1); i--)
			{
				size_t currIdx = i + localShiftCount - 1;
				if (currIdx >= nodeArr.size())
				{
					continue;
				}

				// // Debug print nodes and disassemble index < DEBUG
				// for (size_t j = 0; j < nodeArr.size(); j++)
				// {
				// 	std::cout << std::setw(4) << nodeArr[j]->value << '[' << nodeArr[j]->level << "] ";
				// }
				// std::cout << std::endl;
				// for (size_t j = 0; j < currIdx; j++)
				// {
				// 	std::cout << "        ";
				// }
				// std::cout << "   ^";
				// std::cout << std::endl << std::endl;

				Node* curr = nodeArr[currIdx];
				if (curr->level < static_cast<int>(roundLevel))
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
				if (right != NULL)
					nodeArr[currIdx] = right;
				if (right == NULL)
					nodeArr.pop_back();
				
				// Find position to insert the left node.
				if (left == NULL)
				{
					continue;
				}
				{
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

					nodeArr.insert(nodeArr.begin() + insertPosition, left);
					localShiftCount += 1;
					globalShiftCount += 1;
				}
			}
		}

		// // print to result of nodeArr < DEBUG
		// std::cout << "-------------------RESULT------------------" << std::endl;
		// for (size_t i = 0; i < nodeArr.size(); i++)
		// {
		// 	std::cout << std::setw(4) << nodeArr[i]->value << '[' << nodeArr[i]->level << "] ";
		// }
		// std::cout << std::endl << std::endl;
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

}
