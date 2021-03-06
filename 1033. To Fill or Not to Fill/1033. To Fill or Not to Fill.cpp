#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;

struct station {
	double price;
	double distance;
};

vector<station> node;
int Capacity, Destination, disPerUnit, N;

bool cmp(station &a, station &b) {
	return a.distance < b.distance;
}

bool needFullOil = true;

int findMinPriceStation(int start, double maxDistance) {
	double price = node[start].price;
	double length = 0;
	int posi = -1;
	double minprice = INF;
	needFullOil = true;
	for (int i = start + 1; i < node.size() && length + node[i].distance - node[i - 1].distance <= maxDistance ; i++) {
		length += node[i].distance - node[i - 1].distance;
		if (node[i].price < price) { // 加正好油开过去
			needFullOil = false;
			posi = i;
			break;
		}
		if (node[i].price < minprice) { // 加满油开过去
			needFullOil = true;
			minprice = node[i].price;
			posi = i;
		}
	}
	// 超出距离也没找到加油站就加满油开过去返回最长距离
	return posi;
}

int main() {
	scanf("%d%d%d%d", &Capacity, &Destination, &disPerUnit, &N);
	double per;
	double dis;
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &per, &dis);
		station a = { per,dis };
		node.push_back(a);
	}
	sort(node.begin(), node.end(), cmp);
	station dest = { 0,Destination };
	node.push_back(dest);
	
	if (node[0].distance != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}

	int i = 0;
	double sum = 0.0;
	double currentDistance = 0.0;
	double currentOil = 0.0;
	double maxdistance = Capacity * disPerUnit;

	while (i != N) {	
		if ((Destination - currentDistance) / disPerUnit <= currentOil) {
			break;
		}

		int posi = findMinPriceStation(i, maxdistance);
		
		if (posi == -1) {
			printf("The maximum travel distance = %.2f", currentDistance + maxdistance);
			return 0;
		}
		else if (needFullOil) {
			sum += (Capacity - currentOil)*node[i].price;
			currentOil = Capacity - (node[posi].distance - node[i].distance) / disPerUnit;
			currentDistance = node[posi].distance;
			i = posi;
			continue;
		}
		else {
			// 加到正好的油
			double needOil = (node[posi].distance - node[i].distance) / disPerUnit;
			if (needOil > currentOil) {
				sum += (needOil - currentOil) * node[i].price;
				currentOil = needOil;
			}				
			currentOil -= needOil;
			currentDistance = node[posi].distance;
			i = posi;
			continue;
		}
	}
	printf("%.2f", sum);
	return 0;
}