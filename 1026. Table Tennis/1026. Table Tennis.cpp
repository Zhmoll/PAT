#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct play {
	int arrive;
	int process;
	bool vip;
};

vector<play> input;
bool cmp(play &a, play &b) {
	return a.arrive < b.arrive;
}

int main() {
	int N;
	scanf("%d", &N);
	int hh, mm, ss, process, tag;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &process, &tag);
		play one;
		one.vip = tag;
		one.arrive = hh * 3600 + mm * 60 + ss;
		if (process > 120) one.process = 120 * 60;
		else one.process = process * 60;
		input.push_back(one);
	}
	sort(input.begin(), input.end(), cmp);

	int K, M, tmp;
	scanf("%d%d", &K, &M);
	vector<int> table(K + 1, 8 * 3600);
	vector<bool> table_is_vip(K + 1); // table 从1开始
	vector<int> table_count(K + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		table_is_vip[tmp] = true;
	}

	int current = 0;
	deque<int> wait_q;
	for (int time = 8 * 3600; time < 21 * 3600; time++) {
		// 有人来了
		if (current < N && input[current].arrive == time) {
			wait_q.push_back(current);
			current++;
		}

		// 先处理vip桌子，队列里面有vip的就让先用
		for (int posi = 1; posi <= K; posi++) {
			if (!table_is_vip[posi] || table[posi] > time) continue;

			deque<int>::iterator it = wait_q.begin();
			for (; it != wait_q.end(); it++) {
				if (input[*it].vip) {
					table[posi] = time + input[*it].process;
					printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",
						input[*it].arrive / 3600, input[*it].arrive % 3600 / 60, input[*it].arrive % 60,
						time / 3600, time % 3600 / 60, time % 60, round((time - input[*it].arrive) / 60.0));
					wait_q.erase(it);
					table_count[posi]++;
					break;
				}
			}
		}

		// 后处理普通桌子
		for (int posi = 1; posi <= K; posi++) {
			if (wait_q.empty() || table[posi] > time) continue;
			// 现在都可以让普通人来用
			int front = wait_q.front();
			table[posi] = time + input[front].process;
			printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",
				input[front].arrive / 3600, input[front].arrive % 3600 / 60, input[front].arrive % 60,
				time / 3600, time % 3600 / 60, time % 60, round((time - input[front].arrive) / 60.0));
			wait_q.pop_front();
			table_count[posi]++;
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d", table_count[i]);
		if (i != K) printf(" ");
	}
	return 0;
}