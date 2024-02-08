#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array() : _array(NULL), _size(0);
	Array(unsigned int n) : _size(n) {
		_array = new T[n];
	};
	~Array();
	unsigned int size() const;
	T&	operator [] (int idx) : public std::exception {
		if (idx < 0 || idx > MAX_VAL)
			throw "Error: Invalid number of index.";
		_array[idx] = 
	}
};



#endif