#ifndef __TWOSTACKS_HEADER__
#define __TWOSTACKS_HEADER__

template <class X> class TwoStacks {
	X *arr;
	int top1, top2, size;
	public:
		TwoStacks(int size);
		~TwoStacks();
		void push1(X data);
		void push2(X data);
		X pop1();
		X pop2();
		X peek1();
		X peek2();
};

template <class X> TwoStacks<X>::TwoStacks(int size) {
		arr = new X[size];
		this->size = size;
		top1 = -1;
		top2 = size;
}

template <class X> TwoStacks<X>::~TwoStacks() {
	delete[] arr;
}

template <class X> void TwoStacks<X>::push1(X data) {
	if(top1 < top2) {
		*(arr + ++top1) = data;	
	} else {
		std::cout<<"stack1 full!!!!"<<std::endl;
	}
}

template <class X> void TwoStacks<X>::push2(X data) {
	if(top2 > top1) {
		*(arr  + --top2) = data;
	} else {
		std::cout<<"stack2 full!!!!"<<std::endl;
	}

}

template <class X> X TwoStacks<X>::pop1() {
	if(top1 >= 0) {
		return *(arr + top1--);
	} else {
		std::cout<<"stack1 empty!!!!"<<std::endl;
	}
}

template <class X> X TwoStacks<X>::pop2() {
	if(top2 <= size - 1) {
		return *(arr + top2++);
	} else {
		std::cout<<"stack2 empty!!!"<<std::endl;
	}
}

template <class X> X TwoStacks<X>::peek1() {

	if(top1 >= 0) {
		return *(arr + top1);
	} else {
		std::cout<<"stack1 empty!!!!"<<std::endl;
	}
	
}

template <class X> X TwoStacks<X>::peek2() {
		if(top1 >= 0) {
		return *(arr + top2);
	} else {
		std::cout<<"stack1 empty!!!!"<<std::endl;
	}
}
#endif