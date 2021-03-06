#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;
int N, M, K, Q;
vector<int> processing_time;
vector<int> window;
vector<int> done;
vector<deque<int>> q;

int findMinQ() {
	int minpeople = q[0].size();
	int posi_people = 0;
	for (int i = 1; i < N; i++) {
		if (q[i].size() < minpeople) {
			minpeople = q[i].size();
			posi_people = i;
		}
	}
	return posi_people;
}

int findMinTime() {
	int mintime = window[0];
	int posi = 0;
	for (int i = 1; i < N; i++) {
		if (window[i] < mintime) {
			mintime = window[i];
			posi = i;
		}
	}
	return posi;
}

bool checkComplish() {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (!q[i].empty()) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	processing_time.resize(K + 1);
	done.resize(K + 1);
	window.resize(N, 8 * 60);
	q.resize(N);

	for (int i = 1; i <= K; i++) {
		scanf("%d", &processing_time[i]);
	}

	for (int i = 1; i <= K; i++) {
		// 找队列最少的窗口
		int posi = findMinQ();
		if (q[posi].size() < M) {
			// 队列未满
			if (q[posi].empty()) {
				// 队列为空就直接入队，更新窗口完成时间
				window[posi] += processing_time[i];
				done[i] = window[posi];
			}
			q[posi].push_back(i);
		}
		else {
			// 队列已满
			// 找最早结束时间的窗口
			int posi = findMinTime();
			if (!q[posi].empty()) {
				q[posi].pop_front();
				window[posi] += processing_time[q[posi].front()];
				done[q[posi].front()] = window[posi];
			}
			else {
				window[posi] += processing_time[i];
				done[i] = window[posi];
			}
			q[posi].push_back(i);
		}
	}

	// 处理剩余队列人员
	while (true) {
		int posi = findMinTime();
		if (!q[posi].empty())
			q[posi].pop_front();
		if (!q[posi].empty()) {
			window[posi] += processing_time[q[posi].front()];
			done[q[posi].front()] = window[posi];
		}
		else {
			window[posi] = INF;
		}
		if (checkComplish()) break;
	}

	int query;
	for (int i = 0; i < Q; i++) {
		scanf("%d", &query);
		if (done[query] - processing_time[query] >= 17 * 60) {
			printf("Sorry\n");
		}
		else {
			printf("%02d:%02d\n", done[query] / 60, done[query] % 60);
		}
	}
	return 0;
}