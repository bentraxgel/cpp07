#include <iostream>
#include <algorithm>
#include <vector>

int	main() {
	std::vector<int> v(6);
	std::vector<int> aaaa;
	aaaa.push_back(100);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector size: " << aaaa.size() << "\n";
}

///////////////////////////////////////////////

int	main() {
	vector<int> vec;

	int sz = vec.size();
	int cp = vec.capacity();
	for(int i = 0; i < 100; ++i){
		vec.push_back(i);
		cout << "current size: " << vec.size() <<  " current capacity: " << vec.capacity() << '\n';
	}

}
/*
해당 결과물을 통해 2배씩 capacity가 들어난다는것을 볼 수 있다.
current size: 1 current capacity: 1
current size: 2 current capacity: 2
current size: 3 current capacity: 4
current size: 4 current capacity: 4
current size: 5 current capacity: 8
current size: 6 current capacity: 8
current size: 7 current capacity: 8
current size: 8 current capacity: 8
current size: 9 current capacity: 16
current size: 10 current capacity: 16
current size: 11 current capacity: 16
current size: 12 current capacity: 16
current size: 13 current capacity: 16
current size: 14 current capacity: 16
current size: 15 current capacity: 16
current size: 16 current capacity: 16
current size: 17 current capacity: 32
current size: 18 current capacity: 32
current size: 19 current capacity: 32
current size: 20 current capacity: 32
current size: 21 current capacity: 32
current size: 22 current capacity: 32
current size: 23 current capacity: 32
current size: 24 current capacity: 32
current size: 25 current capacity: 32
current size: 26 current capacity: 32
current size: 27 current capacity: 32
current size: 28 current capacity: 32
current size: 29 current capacity: 32
current size: 30 current capacity: 32
current size: 31 current capacity: 32
current size: 32 current capacity: 32
current size: 33 current capacity: 64
current size: 34 current capacity: 64
current size: 35 current capacity: 64
current size: 36 current capacity: 64
current size: 37 current capacity: 64
current size: 38 current capacity: 64
current size: 39 current capacity: 64
current size: 40 current capacity: 64
current size: 41 current capacity: 64
current size: 42 current capacity: 64
current size: 43 current capacity: 64
current size: 44 current capacity: 64
current size: 45 current capacity: 64
current size: 46 current capacity: 64
current size: 47 current capacity: 64
current size: 48 current capacity: 64
current size: 49 current capacity: 64
current size: 50 current capacity: 64
current size: 51 current capacity: 64
current size: 52 current capacity: 64
current size: 53 current capacity: 64
current size: 54 current capacity: 64
current size: 55 current capacity: 64
current size: 56 current capacity: 64
current size: 57 current capacity: 64
current size: 58 current capacity: 64
current size: 59 current capacity: 64
current size: 60 current capacity: 64
current size: 61 current capacity: 64
current size: 62 current capacity: 64
current size: 63 current capacity: 64
current size: 64 current capacity: 64
current size: 65 current capacity: 128
current size: 66 current capacity: 128
current size: 67 current capacity: 128
current size: 68 current capacity: 128
current size: 69 current capacity: 128
current size: 70 current capacity: 128
current size: 71 current capacity: 128
current size: 72 current capacity: 128
current size: 73 current capacity: 128
current size: 74 current capacity: 128
current size: 75 current capacity: 128
current size: 76 current capacity: 128
current size: 77 current capacity: 128
current size: 78 current capacity: 128
current size: 79 current capacity: 128
current size: 80 current capacity: 128
current size: 81 current capacity: 128
current size: 82 current capacity: 128
current size: 83 current capacity: 128
current size: 84 current capacity: 128
current size: 85 current capacity: 128
current size: 86 current capacity: 128
current size: 87 current capacity: 128
current size: 88 current capacity: 128
current size: 89 current capacity: 128
current size: 90 current capacity: 128
current size: 91 current capacity: 128
current size: 92 current capacity: 128
current size: 93 current capacity: 128
current size: 94 current capacity: 128
current size: 95 current capacity: 128
current size: 96 current capacity: 128
current size: 97 current capacity: 128
current size: 98 current capacity: 128
current size: 99 current capacity: 128
current size: 100 current capacity: 128
*/