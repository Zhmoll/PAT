#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Pair {
	int hh, mm, ss;
	int arrive;
	int serve_hh, serve_mm, serve_ss;
	int playtime;
	bool vip;
	Pair(int hh, int mm, int ss, int playtime, bool vip) :hh(hh), mm(mm), ss(ss), playtime(playtime), vip(vip) {
		arrive = hh * 3600 + mm * 60 + ss;
	};
};
vector<Pair> player;

bool cmp(Pair a, Pair b) {
	if (a.hh != b.hh) return a.hh < b.hh;
	else if (a.mm != b.mm) return a.mm < b.mm;
	else if (a.ss != b.ss) return a.ss < b.ss;
}
int main() {
	int N;
	scanf("%d", &N);
	int hh, mm, dd, p, tag, tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &dd, &p, &tag);
		player.push_back(Pair(hh, mm, dd, p, tag));
	}
	int K, M;
	scanf("%d %d", &K, &M);
	vector<bool> is_vip_table(K + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		is_vip_table[tmp] = true;
	}
	sort(player.begin(), player.end(), cmp);

	queue<Pair*> q;
	queue<Pair*> vip_q;
	vector<Pair*> table(K + 1);
	vector<int> table_serve_count(K + 1);
	// fill(table.begin(), table.end(), NULL);

	for (int i = 8 * 3600, point = 0; i <= 21 * 3600; i++) {
		if (point < N && player[point].arrive == i) {
			// 此时有运动员到达
			if (player[point].vip)
				vip_q.push(&player[point]);
			else
				q.push(&player[point]);
			point++;
		}

		while (!q.empty() || !vip_q.empty()) {
			bool change = false;
			// 结束桌子
			int first_table = -1;
			int first_vip_table = -1;
			for (int i = 1; i <= K; i++) {
				if (table[i] != NULL && table[i]->arrive + table[i]->playtime * 60 == i) {
					// 桌子时间到了
					table[i] = NULL;
				}
				if (first_table == -1) first_table = i;
				if (first_vip_table == -1 && is_vip_table[i]) first_vip_table = i;
			}

			// 进入桌子
			// 判断哪个队列的头来得早
			bool vip_earlier = false;
			if (!vip_q.empty()) {
				if (q.empty()) {
					vip_earlier = true;
				}
				else if (vip_q.front()->arrive < q.front()->arrive) {
					vip_earlier = true;
				}
			}

			int table_num=-1;
			queue<Pair*> *process_q;
			if (vip_earlier) {
				if (first_vip_table != -1) {
					// 用viptable
					table_num = first_vip_table;
					process_q = &vip_q;
				}
				else if (first_table != -1) {
					// 用table
					table_num = first_table;
					process_q = &vip_q;
				}
			}
			else {
				if (!vip_q.empty() && first_vip_table != -1) {
					// 用viptable
					table_num = first_vip_table;
					process_q = &vip_q;
				}
				else if (first_table != -1) {
					// 用table
					table_num = first_table;
					process_q = &q;
				}
			}

			if (table_num != -1) {
				table[table_num] = process_q->front();
				table_serve_count[table_num]++;
				int wait_minute = (i - process_q->front()->arrive) / 60;
				process_q->front()->serve_hh = i / 3600;
				process_q->front()->serve_mm = i / 60 - i / 3600 * 60;
				process_q->front()->serve_ss = i % 60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
					process_q->front()->hh, process_q->front()->mm, process_q->front()->ss, // 到达时间
					process_q->front()->serve_hh, process_q->front()->serve_mm, process_q->front()->serve_ss, // 服务时间					
					wait_minute); // 等待时间
				process_q->pop();
				change = true;
			}

			if (!change) break;
		}
	}
	return 0;
}