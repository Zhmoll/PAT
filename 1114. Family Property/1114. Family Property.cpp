#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int father[10005];
struct Asset {
	int id;
	int sets, area;
	double avg_sets;
	double avg_area;
	set<int> member;
	Asset() {
		sets = 0;
		area = 0;
	}
}asset[10005];

void init() {
	for (int i = 0; i < 10000; i++) {
		father[i] = i;
	}
}

int getFather(int i) {
	int root = i;
	while (father[root] != root) root = father[root];
	while (father[i] != i) {
		int tmp = i;
		i = father[i];
		father[tmp] = root;
	}
	return root;
}

void Union(int a, int b) {
	if (a == -1 || b == -1) return;
	int roota = getFather(a);
	int rootb = getFather(b);
	if (roota != rootb) {
		if (roota < rootb)
			father[rootb] = roota;
		else
			father[roota] = rootb;
	}
}

struct Record {
	int id, father, mother, M_estate, Area;
	vector<int> child;
};

bool cmp(Asset a, Asset b) {
	if (a.sets == 0 || b.sets == 0) return a.avg_area > b.avg_area;
	if (a.avg_area != b.avg_area) return a.avg_area > b.avg_area;
	else return a.id < b.id;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<Record> input(N);
	init();
	int k, child;
	// 输入
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &input[i].id, &input[i].father, &input[i].mother, &k);
		Union(input[i].id, input[i].father);
		Union(input[i].id, input[i].mother);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			input[i].child.push_back(child);
			Union(input[i].id, child);
		}
		scanf("%d%d", &input[i].M_estate, &input[i].Area);
	}

	// 统计
	for (int i = 0; i < N; i++) {
		int current = getFather(input[i].id);
		asset[current].id = current;
		asset[current].sets += input[i].M_estate;
		asset[current].area += input[i].Area;
		asset[current].member.insert(input[i].id);
		if (input[i].father != -1) asset[current].member.insert(input[i].father);
		if (input[i].mother != -1) asset[current].member.insert(input[i].mother);
		for (int j = 0; j < input[i].child.size(); j++) {
			asset[current].member.insert(input[i].child[j]);
		}
	}

	int count = 0;
	for (int i = 0; i < 10000; i++) {
		if (asset[i].member.size() != 0) {
			asset[i].avg_area = ((double)asset[i].area) / asset[i].member.size();
			asset[i].avg_sets = ((double)asset[i].sets) / asset[i].member.size();
			count++;
		}
	}

	sort(asset, asset + 10000, cmp);
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%04d %d %.3f %.3f\n", asset[i].id, asset[i].member.size(), asset[i].avg_sets, asset[i].avg_area);
	}

	return 0;
}