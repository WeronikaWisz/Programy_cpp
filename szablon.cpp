#include<iostream>

using namespace std;

template<class T>
class Array {
 public: 
  Array(size_t sz) : array_{new T[sz]}, sz_{sz}, cap_{0} {}
  ~Array() {
    delete[] array_;
  }
 
  T &operator[](size_t index) {
     return array_[index];
  }
  
  void push(T value){
      if(cap_<=sz_){
        array_[cap_] = value;
	cap_=cap_+1;
      }
  }

  T find_max(){
      T max = array_[0];
      for(int i=0;i<sz_;i++){
          if(max<array_[i]){
		max = array_[i];
	   }
      }
      return max; 
  }	
  
 
 private:
  T *array_;
  size_t sz_;
  int cap_;
};

int main(){

Array<int> Tab(10);
for(int i=0;i<10;i++){
	Tab[i] = 2*i;
}
cout << Tab.find_max() << endl;	

return 0;
}
