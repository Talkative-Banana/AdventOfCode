#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
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
	int n = vec.size(), m = vec[0].length();
	vector<vector<char>> matrix(n, vector<char>(m));
	
	int startx = 0, starty = 0;
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			matrix[i][j] = vec[i][j];
			if(vec[i][j] == '^'){
				startx = i;
				starty = j;
			}
		}
	}

	queue<vector<int>> q;
	q.push({1, startx, starty});
	set<vector<int>> Visited;

	// 1 up
	// 2 rght
	// 3 down
	// 4 left
	while(!q.empty()){
		auto vec = q.front(); q.pop();
		int d = vec[0], X = vec[1], Y = vec[2];
		
		if(Visited.count(vec)) break;
		// Mark X
		matrix[X][Y] = 'X';
		// Mark as Visited
		Visited.insert(vec);

		if(d == 1) { // Up
			if(X == 0) break;
			if(matrix[X-1][Y] != '#'){
				q.push({1, X-1, Y});
			} else{
				q.push({2, X, Y});
			}
		} else if(d == 2) { // rght
			if(Y == m-1) break;
			if(matrix[X][Y+1] != '#'){
				q.push({2, X, Y+1});
			} else{
				q.push({3, X, Y});
			}
		} else if(d == 3) { // Up
			if(X == n-1) break;
			if(matrix[X+1][Y] != '#'){
				q.push({3, X+1, Y});
			} else{
				q.push({4, X, Y});
			}
		} else if(d == 4) { // Up
			if(Y == 0) break;
			if(matrix[X][Y-1] != '#'){
				q.push({4, X, Y-1});
			} else{
				q.push({1, X, Y});
			}
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res += matrix[i][j] == 'X';
	cout << res << endl;
	for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cout << matrix[i][j];
                }
                cout << endl;
        }
    	return 0;
}

