#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct record {
	char plate[8];
	int hh, mm, ss;
	int stamp;
	bool in;
	record(char plate[], int hh, int mm, int ss, char action[]) :hh(hh), mm(mm), ss(ss) {
		strcpy(this->plate, plate);
		if (strcmp(action, "in") == 0) in = true;
		else in = false;
		stamp = hh * 3600 + mm * 60 + ss;
	}
};

bool cmp0(record &a, record &b) {
	if (strcmp(a.plate, b.plate) != 0)
		return strcmp(a.plate, b.plate) < 0;
	return a.stamp < b.stamp;
}

bool cmp1(record &a, record &b) {
	return a.stamp < b.stamp;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<record> vi, vii;
	char plate[8], action[5];
	int hh, mm, ss;
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d %s", plate, &hh, &mm, &ss, action);
		vi.push_back(record(plate, hh, mm, ss, action));
	}

	map<string, int> stop_time;
	set<string> max_time_plate;
	int max_time = 0;
	sort(vi.begin(), vi.end(), cmp0);
	for (int i = 0; i < vi.size() - 1; i++) {
		if (strcmp(vi[i].plate, vi[i + 1].plate) == 0
			&& vi[i].in && !vi[i + 1].in) {
			vii.push_back(vi[i]);
			vii.push_back(vi[i + 1]);
			int time_diff = vi[i + 1].stamp - vi[i].stamp;
			stop_time[vi[i].plate] += time_diff;
			if (stop_time[vi[i].plate] > max_time) {
				max_time = stop_time[vi[i].plate];
				max_time_plate.clear();
				max_time_plate.insert(vi[i].plate);
			}
			else if (stop_time[vi[i].plate] == max_time) {
				max_time_plate.insert(vi[i].plate);
			}
		}
	}
	sort(vii.begin(), vii.end(), cmp1);

	int car_count = 0;
	for (int i = 0, posi = 0; i < K; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int current_stamp = hh * 3600 + mm * 60 + ss;

		while (posi < vii.size() && current_stamp >= vii[posi].stamp) {
			string plate = vii[posi].plate;
			if (vii[posi].in)
				car_count++;
			else if (!vii[posi].in)
				car_count--;
			posi++;
		}
		printf("%d\n", car_count);
	}
	set<string>::iterator it = max_time_plate.begin();
	for (int i = 0; i < max_time_plate.size(); i++, it++) {
		printf("%s ", (*it).c_str());
	}
	printf("%02d:%02d:%02d", max_time / 3600, (max_time % 3600) / 60, max_time % 60);
	return 0;
}