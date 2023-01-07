#include <iostream>


using namespace  std;

// n number of disks from 'source' to 'destination' with the help of 'auxiliary'
void towerOfHanoi(int n, char source, char des, char aux) {
	if (n == 1) {
		cout << "\nMove 1 disk from " << source << " to " << des;
		return;
	}
	towerOfHanoi(n - 1, source, aux, des);
	cout << "\nMove 1 disk from " << source << " to " << des;
	towerOfHanoi(n - 1, aux, des, source);
}

int main() {
	towerOfHanoi(6, 'A', 'B', 'C');
	return 0;
}
