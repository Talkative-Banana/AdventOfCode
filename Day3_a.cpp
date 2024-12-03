#include <iostream>
#include <string>
using namespace std;

int Compute(int idx, string& s, int n){
	if (s.substr(idx, 4) != "mul(") return 0;
	int f = 0;
	string temp1 = "", temp2 = "";
	for(int i = idx + 4; i < n; i++){
		if(s[i] == ','){
			f = 1;
		} else if(s[i] == ')'){
			break;
		} else{
			if(((s[i] - '0') <= 9) && ((s[i] - '0') >= 0)){
				if(!f) temp1 += s[i];
				else temp2 += s[i];
			} else{
				return 0;
			}
		}
	}
	if(temp1.empty() || temp2.empty()) return 0;
	return stoll(temp1) * stoll(temp2);
}

int main() {
    	FILE* fd = fopen("input", "r");
	char ch;
	string s;
	while( (ch = fgetc(fd)) != EOF) s += ch;
	fclose(fd);
	long long res = 0;
	int n = s.length();
	for(int i = 0; i < n; i++){
		res += Compute(i, s, n);
	}
	cout << res << endl;
    	return 0;
}

