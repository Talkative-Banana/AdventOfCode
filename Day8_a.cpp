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
	vector<vector<char>> V;
	for(auto v : vec){
		vector<char> tmp;
		for(int i = 0; i < vec[0].length(); i++) tmp.push_back(v[i]);
		V.push_back(tmp);
	}

	map<char, set<pair<int, int>>> locs;
	int n = V.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(V[i][j] != '.') locs[V[i][j]].insert({i, j});
		}
	}

	auto Valid = [&](pair<int, int>& ptr1, pair<int ,int>& ptr2){
		int x1 = ptr1.first, y1 = ptr1.second, x2 = ptr2.first, y2 = ptr2.second;
		set<pair<int, int>> res;
		if(x1 < x2){
			if(y1 < y2){ // left top - right bottom
				if(((x2 + (x2 - x1)) < n) && ((y2 + (y2 - y1)) < n)){
					res.insert(make_pair(x2 + x2 - x1, y2 + y2 - y1));
				}
				if(((x1 - (x2 - x1)) >= 0) && ((y1 - (y2 - y1)) >= 0)){
					res.insert(make_pair(x1 + x1 - x2, y1 + y1 - y2));
				}
			} else{ // top right - bottom left
				if(((x2 + (x2 - x1)) < n) && ((y2 - (y1 - y2)) >= 0)){
					res.insert(make_pair(x2 + x2 - x1, y2 + y2 - y1));
				}
				if(((x1 - (x2 - x1)) >= 0) && ((y1 + (y1 - y2)) < n)){
					res.insert(make_pair(x1 + x1 - x2, y1 + y1 - y2));
				}
			}
		}
		return res;
	};

	set<pair<int, int>> pos;
	for(auto [c, s] : locs){
		for(auto ptr1 : s){
			for(auto ptr2 : s){
				if(ptr1 == ptr2) continue;
				auto P = Valid(ptr1, ptr2);
				for(auto p : P) pos.insert(p);
			}
		}
	}
	cout << pos.size() << endl;
    	return 0;
}

