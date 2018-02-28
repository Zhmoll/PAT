#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct record {
	string name;
	int month, day, hour, minute;
	bool online;
};
int rate[24];
vector<record> input;
map<string, vector<record>> result;

bool cmp_by_name(record &a, record &b) {
	if (a.name != b.name) return a.name < b.name;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.day != b.day) return a.day < b.day;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else if (a.minute != b.minute) return a.minute < b.minute;
	return false;
}

int main() {
	for (int i = 0; i < 24; i++) {
		cin >> rate[i];
	}
	int N;
	cin >> N;
	string name, action;
	int month, day, hour, minute;
	for (int i = 0; i < N; i++) {
		cin >> name;
		scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
		cin >> action;
		record a;
		a.name = name;
		a.month = month;
		a.day = day;
		a.hour = hour;
		a.minute = minute;
		a.online = (action == "on-line") ? true : false;
		input.push_back(a);
	}
	sort(input.begin(), input.end(), cmp_by_name);

	for (int i = 1; i < input.size(); i++) {
		if (input[i - 1].name == input[i].name
			&& input[i - 1].online && !input[i].online) {
			result[input[i].name].push_back(input[i - 1]);
			result[input[i].name].push_back(input[i]);
		}
	}

	for (map<string, vector<record>>::iterator it = result.begin();
		it != result.end(); it++) {
		string name = it->first;
		vector<record> *vi = &(it->second);
		printf("%s %02d\n", name.c_str(), vi->front().month);
		double total_amount = 0;
		for (int i = 0; i < vi->size(); i += 2) {
			int day_diff = vi->at(i + 1).day - vi->at(i).day;
			int hour_diff = vi->at(i + 1).hour - vi->at(i).hour;
			int minute_diff = vi->at(i + 1).minute - vi->at(i).minute;
			int time_diff = day_diff * 24 * 60 + hour_diff * 60 + minute_diff;
			double amount = 0;

			if (day_diff == 0 && hour_diff == 0) {
				amount += minute_diff * rate[vi->at(i).hour];
			}
			else {
				amount += rate[vi->at(i).hour] * (60 - vi->at(i).minute);
				amount += rate[vi->at(i + 1).hour] * vi->at(i + 1).minute;
				int hour = vi->at(i).hour + 1;
				while (true) {
					if (hour == 24) {
						hour = 0;
						day_diff--;
					}
					if (hour == vi->at(i + 1).hour && day_diff == 0) break;
					amount += rate[hour] * 60;
					hour++;
				}
			}
			total_amount += amount;

			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				vi->at(i).day, vi->at(i).hour, vi->at(i).minute,
				vi->at(i + 1).day, vi->at(i + 1).hour, vi->at(i + 1).minute,
				time_diff, amount/100);
		}
		printf("Total amount: $%.2f\n", total_amount/100);
	}

	return 0;
}