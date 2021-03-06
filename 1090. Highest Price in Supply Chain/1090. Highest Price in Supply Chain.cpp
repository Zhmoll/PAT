#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre;
vector<int> ccount;
int DFS(int current) {
	if (current == -1) return -1;
	if (ccount[current] != -1) return ccount[current];
	ccount[current] = DFS(pre[current]) + 1;
	return ccount[current];
}

int main() {
	int N;
	double P, r, sum = 0;
	scanf("%d %lf %lf", &N, &P, &r);
	pre.resize(N);
	ccount.resize(N);
	int root, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp == -1) root = i;
		pre[i] = tmp;
	}
	fill(ccount.begin(), ccount.end(), -1);
	ccount[root] = 0;
	int opt = -1;
	int opt_count = 0;
	for (int i = 0; i < N; i++) {
		int dfs = DFS(i);
		if (dfs > opt) {
			opt = dfs;
			opt_count = 1;
		}
		else if (dfs == opt) {
			opt_count++;
		}
	}
	double max_price = P;
	for (int i = 0; i < opt; i++) {
		max_price = max_price * (1 + r / 100);
	}
	printf("%.2lf %d", max_price, opt_count);
	return 0;
}

//#include <cstdio>
//#include <vector>
//using namespace std;
//// 迭代
//
//vector<int> level;
//int opt = 0, opt_count = 0;
//void findLevel(vector<int> &father) {
//	for (int i = 0; i < father.size(); i++) {
//		if (level[i] != 0) continue;
//		vector<int> path;
//		int current = i;
//		while (father[current] != -1) {
//			if (level[current] != 0) break;
//			path.push_back(current);
//			current = father[current];
//		}
//		int cnt = 1;
//		while (!path.empty()) {
//			level[path.back()] = level[current] + cnt++;
//			path.pop_back();
//		}
//		if (level[i] > opt) {
//			opt = level[i];
//			opt_count = 1;
//		}
//		else if (level[i] == opt) {
//			opt_count++;
//		}
//	}
//}
//
//int main() {
//	int N;
//	double P, r;
//	scanf("%d%lf%lf", &N, &P, &r);
//	vector<int> father;
//	level.resize(N, 0);
//	int tmp;
//	int root;
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &tmp);
//		father.push_back(tmp);
//		if (tmp == -1) root = i;
//	}
//	findLevel(father);
//	double price = P;
//	double g = 1 + r / 100;
//	for (int i = 0; i < opt; i++) {
//		price *= g;
//	}
//	printf("%.2f %d", price, opt_count);
//	return 0;
//}