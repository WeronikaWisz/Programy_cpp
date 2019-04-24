#include<iostream>
#include<vector>
#include<memory>
#include<random>

using namespace std;

class ArrayFill {
	public:
		virtual int Value(int index) const =0;
};

void FillArray(size_t size, const ArrayFill &filler, vector<int> *v) {
	v->clear();
	v->reserve(size);
	for(size_t i = 0; i < size; i++) {
		v->emplace_back(filler.Value(i));
	}
}

class UniformFill : public ArrayFill {
	
	public:
		UniformFill(int value = 0) : value_{value} {}
		virtual int Value(int index) const override;
	private:
		int value_;
};

class IncrementalFill : public ArrayFill {

	public: 
		IncrementalFill(int start, int step = 1) : start_{start}, step_{step} {}
		virtual int Value(int index) const override;
	private:
		int start_, step_;
		
};

class RandomFill : public ArrayFill{ 
	public:
		RandomFill(default_random_engine generator, uniform_int_distribution<int> distribution) : myrandom{distribution(generator)} {}
		virtual int Value(int index) const override;
	private: 
		int  myrandom;
};

class SquaredFill : public ArrayFill{
	public:
		SquaredFill(int a = 1, int b = 0) : a_{a}, b_{b} {}
		virtual int Value(int index) const override;
	private:
		int a_,b_;
};

int UniformFill::Value(int index) const {
	return value_;
}

int IncrementalFill::Value(int index) const {
	int value_;
	value_ = start_ + index*step_;
	return value_;
}

int SquaredFill::Value(int index) const {
	int value_;
	value_ = a_ * index * index + b_;
	return value_;
}

int RandomFill::Value(int index) const {
	return myrandom;
}

void PrintVector(const vector<int> &v) {
    bool first = true;
    for(auto n : v) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << n;
 
    }
    cout<<endl;
}

int main(){

	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,100);

	vector<int> v1,v2,v3,v4;

	FillArray(6, UniformFill {77}, &v1);
	PrintVector(v1);
	FillArray(6, IncrementalFill {5,3}, &v2);
	PrintVector(v2);
	FillArray(6, SquaredFill {2,3}, &v3);
	PrintVector(v3);
	FillArray(6, RandomFill {generator, distribution}, &v4);
	PrintVector(v4);

return 0;
}