#include <string>
#include <iostream>
using namespace std;

int main() {
	string sci;
	cin >> sci;
	int xiaoshu = 0;
	// 获取e后面的小数位数
	int e_posi = sci.find("E");
	string e_str = sci.substr(e_posi + 1);
	sscanf(e_str.c_str(), "%d", &xiaoshu);
	// 获取e前面的小数位数
	xiaoshu -= e_posi - 3;
	string result = sci.substr(0, 2) + sci.substr(3, e_posi - 3);
	if (xiaoshu >= 0) {
		for(int i=0;i<xiaoshu;i++)
			result.append("0");
	}
	else {
		xiaoshu = -xiaoshu;
		if (result.length() - 1 > xiaoshu) {
			int chadian = result.length() - xiaoshu;
			result.insert(chadian, ".");
		}
		else {
			int buling = xiaoshu - result.length() + 2;
			for(int i=0;i<buling;i++)
				result.insert(1, "0");
			result.insert(2, ".");
		}
	}
	if (result[0] == '+')
		result.erase(0, 1);
	cout << result;
	return 0;
}