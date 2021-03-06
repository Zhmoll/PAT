#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<set<int>> Adj;
vector<bool> gender;
int N, M, K;
bool next_gender;
bool opposite;
vector<int> ans;

void travel(int start, int end) {
	ans.clear();
	if (gender[start] && !gender[end] || !gender[start] && gender[end])
		opposite = true;
	else if (gender[start] && gender[end] || !gender[start] && !gender[end])
		opposite = false;

	next_gender = gender[start];

	vector<int> vi;
	for (set<int>::iterator it = Adj[start].begin(); it != Adj[start].end(); it++) {
		int fri1 = *it;
		if (fri1 == end) continue;
		if (gender[fri1] == next_gender) vi.push_back(fri1);
	}

	if (opposite) next_gender = !next_gender;

	for (int i = 0; i < vi.size(); i++) {
		int fri1 = vi[i];
		for (set<int>::iterator it = Adj[fri1].begin(); it != Adj[fri1].end(); it++) {
			int fri2 = *it;
			if (fri2 == start) continue;
			if (gender[fri2] == next_gender) {
				// 找fri2有没有目标朋友
				bool found = false;
				for (set<int>::iterator it = Adj[fri2].begin(); it != Adj[fri2].end(); it++) {
					if (*it == end) {
						found = true;
						break;
					}
				}
				if (!found) continue;
				ans.push_back(fri1);
				ans.push_back(fri2);
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	gender.resize(10005);
	Adj.resize(10005);
	char str1[10], str2[10];
	int p1, p2;
	for (int i = 0; i < M; i++) {
		scanf("%s %s", str1, str2);
		sscanf(str1, "%d", &p1);
		sscanf(str2, "%d", &p2);
		if (str1[0] == '-')	gender[abs(p1)] = false;
		else gender[abs(p1)] = true;
		if (str2[0] == '-')	gender[abs(p2)] = false;
		else gender[abs(p2)] = true;
		Adj[abs(p1)].insert(abs(p2));
		Adj[abs(p2)].insert(abs(p1));
	}
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%s %s", str1, str2);
		sscanf(str1, "%d", &p1);
		sscanf(str2, "%d", &p2);
		if (str1[0] == '-')	gender[abs(p1)] = false;
		else gender[abs(p1)] = true;
		if (str2[0] == '-')	gender[abs(p2)] = false;
		else gender[abs(p2)] = true;
		travel(abs(p1), abs(p2));
		printf("%d\n", ans.size() / 2);
		for (int i = 0; i < ans.size(); i += 2) {
			printf("%04d %04d\n", ans[i], ans[i + 1]);
		}
	}

	return 0;
}