#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n = 1000;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	sort(begin(a), end(a));
	sort(begin(b), end(b));
	long long res = 0;
	for(int i = 0; i < n; i++){
		res += abs(a[i] - b[i]);
	}
	cout << res << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
