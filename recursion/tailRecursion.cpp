#include <iostream>


using namespace std;

 int tailFibonacci(int n,  int a = 1,  int b = 1) {
	if (n == 1) return a;
	else if (n == 2) return b;
	else return tailFibonacci(n - 1, b, a + b);
}
int tailFactorial( int n,  int result = 1) {
	if (n == 0) return result;
	return tailFactorial(n - 1, result * n);
}
int main() {
	for(int i=1;i<10;i++){
	cout << tailFibonacci(i)<<" ";
	}
	cout<<endl;
	cout << "factorial is "<<tailFactorial(5);

	return 0;
}
