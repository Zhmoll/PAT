#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	cin >> N;

	int tmp, max = 0;
	vector<int> vi;
	vector<bool> isBigger;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vi.push_back(tmp);
		if (tmp > max) {
			max = tmp;
			isBigger.push_back(true);
		}
		else {
			isBigger.push_back(false);
		}
	}

	int min = 1e9 + 1;
	vector<bool> isSmaller(N);
	for (int i = N - 1; i >= 0; i--) {
		if (vi[i] < min) {
			min = vi[i];
			isSmaller[i] = true;
		}
		else {
			isSmaller[i] = false;
		}
	}

	vector<int> result;
	for (int i = 0; i < N; i++) {
		if (isBigger[i] && isSmaller[i]) {
			result.push_back(vi[i]);
		}
	}

	cout << result.size() << endl;
	if (result.size() == 0) cout << endl;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1)
			cout << " ";
	}

	return 0;
}