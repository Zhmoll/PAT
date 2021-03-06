#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 100000;
const int sqrN = 316;

vector<int> st;
vector<int> block(sqrN);
vector<int> table(maxn);

void peekMedian() {
	if (st.empty()) {
		printf("Invalid\n");
	}
	else {
		int mid = st.size();
		if (mid % 2 == 1) mid = (mid + 1) / 2;
		else mid = mid / 2;

		int sum = 0;
		int idx = 0;
		while (sum + block[idx] < mid) {
			sum += block[idx++];
		}
		int num = idx * sqrN;
		while (sum + table[num] < mid) {
			sum += table[num++];
		}
		printf("%d\n", num);
	}
}

void Push(int x) {
	st.push_back(x);
	block[x / sqrN]++;
	table[x]++;
}

void Pop() {
	if (st.empty() == true) {
		printf("Invalid\n");
	}
	else {
		int x = st.back();
		st.pop_back();
		block[x / sqrN]--;
		table[x]--;
		printf("%d\n", x);
	}
}

int main() {
	int x, query;
	char cmd[20];
	scanf("%d", &query);

	for (int i = 0; i < query; i++) {
		scanf("%s", cmd);
		if (strcmp(cmd, "Push") == 0) {
			scanf("%d", &x);
			Push(x);
		}
		else if (strcmp(cmd, "Pop") == 0) {
			Pop();
		}
		else {
			peekMedian();
		}
	}
	return 0;
}