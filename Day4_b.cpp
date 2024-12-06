#include <iostream>
#include <string>
#include <vector>
using namespace std;


void filldp(int I, int J, vector<vector<char>>& matrix, vector<vector<int>> &dp){	
	// Up
	int i = I, j = J, k = 0, n = matrix.size(), m = matrix[0].size();
	if((matrix[i+1][j+1] == 'M' && matrix[i-1][j-1] == 'S') || 
	(matrix[i+1][j+1] == 'S' && matrix[i-1][j-1] == 'M')){
		k++;
	}

	if((matrix[i+1][j-1] == 'M' && matrix[i-1][j+1] == 'S') || 
	(matrix[i+1][j-1] == 'S' && matrix[i-1][j+1] == 'M')){
		k++;
	}
	
	dp[I][J] = k / 2;
	return;
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
	int n = vec.size(), m = vec[0].length();
	vector<vector<char>> matrix(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			matrix[i][j] = vec[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, 0));

	for(int i = 1; i < n-1; i++){
		for(int j = 1; j < m-1; j++){
			if(matrix[i][j] == 'A'){
				filldp(i, j, matrix, dp);
			}
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 'A'){
				res += dp[i][j];
			}
		}
	}
	cout << res << endl;
    	return 0;
}
