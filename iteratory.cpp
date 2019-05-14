#include<iostream>

using namespace std

class IterableIterator{

	public:
		virtual pair<int, string> Dereference() = 0;
		virtual IterableIterator &Next() = 0;
		virtual bool NotEquals(const IterableIterator &other) = 0;
		~IterableIterator(){}

};

class ZipperIterator : public IterableIterator {

	public:
	vector<int>::const_iterator left_begin_, right_begin_, left_end_, right_end_;

	explicit ZipperIterator(vector<int>::const_iterator left_begin,
                 vector<string>::const_iterator right_begin,
                 vector<int>::const_iterator left_end,
                 vector<string>::const_iterator right_end) : left_begin_{left_begin}, right_begin_{right_begin}, left_end_{left_end}, right_end_{right_end} {}

	virtual pair<int, string> Dereference() override;
	virtual IterableIterator &Next() override;
	virtual bool NotEquals(const IterableIterator &other) override;
};

class ProductIterator : IterableIterator {

};

class EnumerateIterator : IterableIterator {

};


class IterableIteratorWrapper : public IterableIterator{
	
	public:
		IterableIteratorWrapper(unique_ptr<IterableIterator> iterator);
		bool operator!=(const IterableIteratorWrapper &other);
		pair<int, string> operator*();
		IterableIteratorWrapper &operator++()
};

class Iterable{

	public:
		unique_ptr<IterableIterator> ConstBegin();
		unique_ptr<IterableIterator> ConstEnd();
		IterableIteratorWrapper cbegin() const;
		IterableIteratorWrapper cend() const;
		IterableIteratorWrapper begin() const;
		IterableIteratorWrapper end() const
};

class Zipper(){
	
	public:
		Zipper
};

class Product(){
};

class Enumerate{
};

int main(){


return 0;
}
