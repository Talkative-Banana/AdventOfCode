#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<vector<int>> nums;
    string line;
    while (getline(cin, line)) {
        	istringstream line_stream(line);
        	vector<int> row;
        	int x;
       		while (line_stream >> x) {
            		row.push_back(x);
        	}
        	nums.push_back(row);
    	}

    	int res = 0;
	for(int i = 0; i < nums.size(); i++){
		int diff = nums[i][1] - nums[i][0], count = 0;
		bool isvalid = (abs(diff) >= 1) && (abs(diff) <= 3);
		for(int j = 2; j < nums[i].size(); j++){
			if(diff > 0){ // Increasing
				int tmp = nums[i][j] - nums[i][j-1];
				isvalid &= (tmp >= 1 && tmp <= 3);
			} else{ // Decreasing
				int tmp = nums[i][j] - nums[i][j-1];
				isvalid &= (tmp >= -3 && tmp <= -1);
			}
		}
		if(isvalid){
			res++;
		}
	}
	cout << res << endl;	
    return 0;
}

