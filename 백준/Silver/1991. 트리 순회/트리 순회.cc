#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int arr[2][27];

void preOrder(int x, string& str) {
	if (x < 0) {
		return;
	}
	str.push_back(x + 'A');
	preOrder(arr[0][x], str);
	preOrder(arr[1][x], str);
}

void inOrder(int x, string& str) {
	if (x < 0) {
		return;
	}
	inOrder(arr[0][x], str);
	str.push_back(x + 65);
	inOrder(arr[1][x], str);
}

void postOrder(int x, string& str) {
	if (x < 0) {
		return;
	}
	postOrder(arr[0][x], str);
	postOrder(arr[1][x], str);
	str.push_back(x + 65);
}

int main() {
	int n;
	cin >> n;

	char value, left, right;
	for (int i = 0; i < n; i++) {
		cin >> value >> left >> right;
		arr[0][value - 'A'] = left - 'A';
		arr[1][value - 'A'] = right - 'A';

	}
	
	string str = "";
	preOrder(0, str);
	cout << str << "\n";

	str = "";
	inOrder(0, str);
	cout << str << "\n";

	str = "";
	postOrder(0, str);
	cout << str << "\n";

	return 0;

}