#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string str("");
		cin >> str;
		
		str += ' ';
		int result = 0;
		for (int i = 0; i < str.size(); i++) {
			result = i;
			if (str[i] - 'a' != i) {
				break;
			}
			
		}

		printf("#%d ", test_case);
		cout << result;
		printf("\n");
	}
			
	return 0;

}