#include<iostream>

using namespace std;

class Base {
	int a;
public:
	int b;

	Base(int a, int b): a(a), b(b) { cout<<"constructer calling...."<<endl; }
	~Base() { cout<<"destructer calling...."<<endl; }

	virtual int getData() { return this->b; }

	void operator+(Base &o);
	void operator++(int x);

};	

void Base::operator+(Base &o) {
	this->b = this->b + o.b;
}

void Base::operator++(int x) {
	this->b++;
}


class Derived: public Base {
	int d;
public:
	Derived(int a, int b, int d): d(d), Base(a, b) {} 
	int getData() { return d; }
	void ok() { cout<<"calling okay"<<endl; }
};

void test(Base *t) {
	cout<<t->getData()<<endl;
}

int main(void) {

 	Base *t = new Derived(10, 20, 30);
 

 	cout<<t->getData()<<endl;

	(*t)++;
	(*t)++;
	(*t)++;


	delete t;

	return 0;
}