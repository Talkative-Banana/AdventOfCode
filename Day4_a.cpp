#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int Valid(vector<int>& Seq, map<int, set<int>>& adj){
	int n = Seq.size();
	set<int> con, Visited;
	for(auto x : Seq) con.insert(x);
	for(int i = 0; i < n; i++){
		for(auto x : adj[Seq[i]]){
			if(con.count(x) != 0){
				if(Visited.count(x) == 0) return false;
			}
		}
		Visited.insert(Seq[i]);
	}
	return true;
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
	vector<vector<int>> order;
	int i;
	for(i = 0; i < vec.size(); i++){
		auto x = vec[i];
		if(x == ""){
			i++;
			break;
		} else{
			const char c = '|';
			int idx = find(begin(x), end(x), c) - begin(x);
			order.push_back({stoi(x.substr(0, idx)), stoi(x.substr(idx + 1))});
		}
	}

	vector<vector<int>> seq;
	for(i; i < vec.size(); i++){
		stringstream ss;
		ss << vec[i];
		string x;
		vector<int> temp;
		char delimiter = ',';
		while (getline(ss, x, delimiter)) {
        		temp.push_back(stoi(x)); // Add each split part to the vector
    		}
		seq.push_back(temp);
	}

	map<int, set<int>> adj;
	for(auto v : order){
		adj[v[1]].insert(v[0]);
	}

	int res = 0;
	for(auto S : seq){
		if(Valid(S, adj)){
			int mid = S.size() / 2;
			res += S[mid];
		}
	}
	cout << res << endl;
    	return 0;
}

