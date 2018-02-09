#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int M = 0; // 最大容量
	scanf("%d", &M);
	int N = 0; // 长度 1 ~ N
	scanf("%d", &N);
	int K = 0;
	scanf("%d", &K); // 要测几个

	stack<int> stk;
	vector<int> vi;

	int tmp = 0;

	for (int i = 0; i < K; i++) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			vi.push_back(tmp);
		}
		//for (int current = 0; current < N; current++) {
		int current = 0;
			for (int num = 1; num <= N; num++) {
				if (stk.size() == M)
					break;
				stk.push(num);
				while (!stk.empty() && stk.top() == vi[current]) {
					stk.pop();
					current++;
				}
			}
		//}
		if (stk.empty()) printf("YES\n");
		else printf("NO\n");
		while (!stk.empty())
			stk.pop();
		vi.clear();
	}

	return 0;
}