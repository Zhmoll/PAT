#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	priority_queue<double, vector<double>, greater<double>> q;
	int len;
	for (int i = 0; i < N; i++) {
		scanf("%d", &len);
		q.push(len);
	}

	while (q.size() != 1) {
		double len1 = q.top();
		q.pop();
		double len2 = q.top();
		q.pop();
		q.push((len1 + len2) / 2);
	}

	printf("%d", (int)(q.top()));
	return 0;
}