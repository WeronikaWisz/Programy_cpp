#include<iostream>
#include<string>
#include <cstring>

using namespace std;

class Object
{
public:
    virtual ~Object(){}
};

class Vector : public Object
{
protected:
    Object**start;
    Object**end;
    int capacity;
public:
    Vector(){start=end=0;capacity=0;}
    virtual ~Vector(){if(start)delete start;}
    int getSize()const{return end-start;}
    int getCapacity()const{return capacity;}
   
    bool reserve(int newCapacity);
    bool pushBack(Object*object);
    Object*get(int index)const
    {
       if(index<0 || index>=(end-start))return 0;
       return start[index];
    }
    friend class Iterator;
};

bool Vector::pushBack(Object*object)
{
    if(capacity==getSize() && 
    !reserve(capacity+16))return false;
    *end=object;
    end++;
    return true;
}
 
bool Vector::reserve(int newCapacity)
{
    if(newCapacity < capacity)return false;
    Object**tmp=new Object*[newCapacity];
    if(capacity){
        memcpy(tmp,start,capacity*sizeof(Object*));
       delete []start;
    }
    end=tmp+(end-start);
    capacity=newCapacity;
    start=tmp;
    return true;
}

class Int: public Object
{
public:
    int value;
    Int(int v=0){value=v;}
};

class String: public Object
{
public:
    string value;
    String(string v=0){value=v;}
};

class Iterator
{
    const Vector&vector;
    Object**current;
public:
    Iterator(const Vector&v)
    :vector(v),current(v.start) {}
    Iterator&operator++(){current++;return *this;}
    Iterator&operator++(int){current++;return *this;} 
    operator bool()const{return current<vector.end;}
    Object*get()const{return *current;}
};

class Zipper{
	public:

	void zip(Vector vi, Vector vs){
		for(Iterator it(vi),its(vs);it,its;it++,its++){
       			Int*pint=dynamic_cast<Int*>(it.get());
       			if(pint)cout<<"("<<pint->value<<", ";
      			String*pints=dynamic_cast<String*>(its.get());
       			if(pints)cout<<pints->value<<")"<<endl;
		}
	}
};

class Enumerate{
	public:

	void enu(Vector vs){
		int i=0;
		for(Iterator its(vs);its;its++){
      			String*pints=dynamic_cast<String*>(its.get());
       			if(pints)cout<<"("<<i++<<", "<<pints->value<<")"<<endl;
		}
	}
	

}; 

class Product{
	public:

	void pro(Vector vi, Vector vs){
		Iterator its(vs);
		while(its){
		String*pints=dynamic_cast<String*>(its.get());
		for(Iterator it(vi);it;it++){
       			Int*pint=dynamic_cast<Int*>(it.get());
       			if(pint)cout<<"("<<pint->value<<", ";
       			if(pints)cout<<pints->value<<")"<<endl;
		}
		its++;
		}
	}
	
};
	
 
int main()
{
    Vector vi, vs;
    vi.pushBack(new Int(4));
    vi.pushBack(new Int(77));
    vi.pushBack(new Int(-91));
    vs.pushBack(new String("4"));
    vs.pushBack(new String("9991"));
    vs.pushBack(new String("adfskld"));
    Zipper z;
    Enumerate e;
    Product p;
	
    cout<<"Zipper: "<<endl;
    z.zip(vi,vs);
    cout<<"Enumerate: "<<endl;
    e.enu(vs);
    cout<<"Product: "<<endl;
    p.pro(vi,vs);
  
return 0;
}