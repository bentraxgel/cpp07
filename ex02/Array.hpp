#ifndef ARRAY_HPP
#define ARRAY_HPP
#define MAX_VAL 750

template <typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array() : _array(NULL), _size(0) {};
	Array(unsigned int n) : _array(new T[n]), _size(n) {};

	Array(Array<T>& copy)
		: _array(new T[copy._size]), _size(copy._size) {
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy[i];
	};
	Array& operator=(const Array& copy) {
		if (this != &copy) {
			_size = copy._size;
			delete[] _array;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy[i];
		}
		return *this;
	};
	~Array() { delete[] _array; };

	unsigned int size() const { return _size; };
	
	T&	operator [] (int idx) const {
		if (idx < 0 || idx >= MAX_VAL)
			throw InvalidIdex();
		return _array[idx];
	};
	class InvalidIdex : public std::exception {
		public:
			const char* what() const throw();
	};
};

template <typename T>
const char* Array<T>::InvalidIdex::what() const throw() {
	return "Error: Invalid number of index.";
}

#endif