#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, H;
struct person {
	int id; // 8-digit
	int virtue, talent;
	int total;
	int rank; // 圣人是1，君子是2，愚人是3，剩余的愚人是4
	person(int id, int virtue, int talent) :id(id), virtue(virtue), talent(talent) {
		total = talent + virtue;
		if (virtue >= H && talent >= H) rank = 1;
		else if (talent < H && virtue >= H) rank = 2;
		else if (talent < H && virtue < H && virtue >= talent) rank = 3;
		else rank = 4;
	}
};

vector<person> input;

bool cmp(person &a, person &b) {
	// tie  virtue递减 / id递增;
	if (a.rank != b.rank) return a.rank < b.rank;
	else if (a.total != b.total) return a.total > b.total;
	else if (a.virtue != b.virtue) return a.virtue > b.virtue;
	else return a.id < b.id;
}

int main() {
	scanf("%d%d%d", &N, &L, &H);
	// 都超过L才能有rank
	// 双超过H sage，total递减排列
	// talent grades below H but virtue grades not，noblemen，total递减排列
	// both grades below H, but with virtue not lower than talent，fool men，total递减排列
	// The rest of people whose grades both pass the L line are ranked after the "fool men". 
	int ID_Number, Virtue_Grade, Talent_Grade;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &ID_Number, &Virtue_Grade, &Talent_Grade);
		if (Virtue_Grade < L || Talent_Grade < L)
			continue;
		input.push_back(person(ID_Number, Virtue_Grade, Talent_Grade));
	}
	sort(input.begin(), input.end(), cmp);
	printf("%d\n", input.size());
	for (int i = 0; i < input.size(); i++) {
		printf("%08d %d %d\n", input[i].id, input[i].virtue, input[i].talent);
	}
	return 0;
}