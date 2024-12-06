#include <iostream>
#include <string>
#include <vector>
using namespace std;

void filldp(int I, int J, vector<vector<char>>& matrix, vector<vector<int>> &dp){	
	// Up
	int i = I, j = J, k = 0, n = matrix.size(), m = matrix[0].size();
	string XMAS = "XMAS";
	while(i >= 0 && k < 4 && matrix[i][j] == XMAS[k]){
		i--, k++;
	}
	dp[I][J] += (k == 4);
	
	// Down
	i = I, j = J, k = 0;
	while(i < n && k < 4 && matrix[i][j] == XMAS[k]){
		i++, k++;
	}
	dp[I][J] += (k == 4);
	
	// Left	
	i = I, j = J, k = 0;
	while(j >= 0 && k < 4 && matrix[i][j] == XMAS[k]){
		j--, k++;
	}
	dp[I][J] += (k == 4);
	
	// Right
	i = I, j = J, k = 0;
	while(j < m && k < 4 && matrix[i][j] == XMAS[k]){
		j++, k++;
	}
	dp[I][J] += (k == 4);
	
	// NE
	i = I, j = J, k = 0;
	while(j < m && i >= 0 && k < 4 && matrix[i][j] == XMAS[k]){
		i--, j++, k++;
	}
	dp[I][J] += (k == 4);
	
	// SE	
	i = I, j = J, k = 0;
	while(j < m && i < n && k < 4 && matrix[i][j] == XMAS[k]){
		i++, j++, k++;
	}
	dp[I][J] += (k == 4);
	
	// SW	
	i = I, j = J, k = 0;
	while(j >= 0 && i < n && k < 4 && matrix[i][j] == XMAS[k]){
		i++, j--, k++;
	}
	dp[I][J] += (k == 4);
	// NW
	i = I, j = J, k = 0;
	while(j >= 0 && i >= 0 && k < 4 && matrix[i][j] == XMAS[k]){
		i--, j--, k++;
	}
	dp[I][J] += (k == 4);
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

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 'X'){
				filldp(i, j, matrix, dp);
			}
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 'X'){
				res += dp[i][j];
			}
		}
	}
	cout << res << endl;
    	return 0;
}
