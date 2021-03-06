#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int M, N, K, tmp;
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		vector<int> seq;
		stack<int> stk;
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			seq.push_back(tmp);
		}
		int current = 0;
		for (int j = 1; j <= N; j++) {
			stk.push(j);
			if (stk.size() > M) break;
			while (!stk.empty() && stk.top() == seq[current]) {
				stk.pop();
				current++;
			}
		}
		if (stk.size() != 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}