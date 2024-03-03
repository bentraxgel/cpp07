#include <iostream>
#include <set>
#include <map>
using namespace std;

int	main() {
	std::set<int> st;

	st.insert(1);
	
	std::set<int>::iterator iter;

	iter = st.find(1);

	int idx = 0;
	for (iter = st.begin(); iter != st.end(); ++iter){
		idx++;

		// if (idx == 3)
		// 	std:: cout << *iter << '\n';
	}

	map<char, int> mp;
	map<char, int>::iterator it;

    mp['c'] = 1;

	cout << mp.size() << '\n'; // 1
	it = mp.find('d');
	if(it == mp.end())
		cout << "wtf" << '\n';
	cout << mp.size() << '\n'; // 1

	if(mp['d'])
		cout << "wtf" << '\n';
	cout << mp.size() << '\n'; // 2

	it = mp.find('d');
	if(it != mp.end())
		cout << "i found you" << '\n';
	// map<char, int> m;

    // m['c'] = 1;        
    // map<char, int> m2(m), m3;

    // m3 = m;
    
    // cout << m['c'] << " " << m2['c'] << endl;
    //output : 1 1
    //output : 1 1
}


// set insert로 데이터 넣는다
// find로 찾는다. 못찾으면 iter == st.end()
// set은 정렬된 상태로 데이터가 저장된다.
// set은 레드블랙트리로 만들어져 있다. 그래서 빠르다.
// set은 사실상 집합이다.


// vector는 동적 배열이다.