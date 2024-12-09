#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main() {
    	FILE* fd = fopen("input", "r");
	char ch;
	string s;
	while( (ch = fgetc(fd)) != EOF) s += ch;
	fclose(fd);

	vector<string> vec;
	string temp = "";
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '\n'){
			vec.push_back(temp);
			temp = "";
		} else{
			temp += s[i];
		}
	}

	int n = vec[0].length();
	vector<int>str;
	for(int i = 0; i < n; i++){
		int num = vec[0][i] - '0';
		if(i&1) { // Expand dots
			for(int j = 0; j < num; j++) str.push_back(-1);
		} else{
			for(int j = 0; j < num; j++) str.push_back(i / 2);
		}
	}
	n = str.size();
	int left = 0, rght = n - 1;
	while(left < n && str[left] != -1) left++;
	while(rght > left && str[rght] == -1) rght--;

	while(left < rght){
		swap(str[left], str[rght]);
		while(left <= rght && str[left] != -1) left++;
		while(rght >= left && str[rght] == -1) rght--;
	}
	long long res = 0;
	for(long long i = 0; i < n; i++) {
		if(str[i] == -1) break;
		res += i * str[i];
	}
	cout << res << endl;
    	return 0;
}

