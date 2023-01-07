#include <iostream>

using namespace std;

//Non tail
int factorial( int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

 int main() {
	cout << factorial(4);
	return 0;
}

