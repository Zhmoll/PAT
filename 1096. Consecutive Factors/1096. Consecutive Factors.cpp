#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int source = N;
	vector<int> tmp_path, path;
	for (int i = 2; i <= sqrt(source); i++) {
		for (int j = i; j <= sqrt(source); j++) {
			if (N % j == 0) {
				N /= j;
				tmp_path.push_back(j);
				if (tmp_path.size() > path.size()) {
					path = tmp_path;
				}
			}
			else {
				tmp_path.clear();
				N = source;
				break;
			}
		}
	}
	int size = path.size();
	if (size == 0) {
		path.push_back(source);
		size = 1;
	}

	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d", path[i]);
		if (i != size - 1) printf("*");
	}
	return 0;
}