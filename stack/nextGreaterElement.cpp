#include<iostream>

using namespace std;

void printNGE(int* inp, int size) {
	int nge;
	for(int i = 0; i < size; i++) {
		nge = -1;
		for(int j = i; j < size; j++) {
			if(inp[i] < inp[j]) {
				nge = inp[j];
				break;
			}
		}
		cout<<inp[i]<<" -------> "<<nge<<endl;
	}

	cout<<endl;
}

int main(void) {
	int input[] = {5,4,3,2,1};
	int size = sizeof(input)/sizeof(int);
	printNGE(input, size);
	return 0;
}