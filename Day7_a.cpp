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

bool func(int idx, long long f, long long n, long long elem, vector<long long>& Vec){
	// BaseCase
	if(idx == n) return f == elem;
	bool res = false;
	res |= func(idx + 1, f * Vec[idx], n, elem, Vec);
	res |= func(idx + 1, f + Vec[idx], n, elem, Vec);
	return res;
}

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
	vector<pair<long long, vector<long long>>> V;
	for(auto v : vec){
		string temp = "";
		long long elem; vector<long long> res;
		for(int i = 0; i < v.length(); i++){
			if(v[i] == ':'){
				elem = stoll(temp);
				temp = ""; i++;
			} else if((v[i] == ' ')){
				res.push_back(stoll(temp));
				temp = "";
			} else {
				temp += v[i];
			}
		}
		res.push_back(stoll(temp));
		V.push_back({elem, res});
	}
	
	long long n = V.size(), res = 0;
	for(int i = 0; i < n; i++){
		res += func(1, V[i].second[0], V[i].second.size(), V[i].first, V[i].second) ? V[i].first : 0;
	}
	cout << res << endl;
    	return 0;
}

