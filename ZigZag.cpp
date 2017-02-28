#include <iostream>
using namespace std;
// https://community.topcoder.com/stat?c=problem_statement&pm=1259
class ZigZag{
	int *a, n, *DP_zig[2];
	public:
	ZigZag(int *b, int x){
		n = x;
		a = new int[n];
		DP_zig[0] = new int[n];
		DP_zig[1] = new int[n];
		int i=0;
		while(i<n) {
			a[i] = b[i], DP_zig[0][i] = DP_zig[1][i] = 0;
			i++;
		}
	}
	
	// O(N^2) time complexity
	int longestZigZag(){
		int i, j;
		for(i = n-1 ; i >= 0; i--){
			DP_zig[0][i] = DP_zig[1][i] = 1;			
			for(j = i+1; j < n; j++){
				if(a[i] < a[j]) update(DP_zig[1][i], 1 + DP_zig[0][j]); 
				else if(a[i] > a[j]) update(DP_zig[0][i], 1 + DP_zig[1][j]); 
			}
		}
		int ans = 0;
		i=0;
		while(i<n){
			update(ans, DP_zig[0][i]);
			update(ans, DP_zig[1][i]);
			i++;
		}
		return ans;
	}
	void update(int &x, int y){
		if(x < y) x = y;
	}
	
};
int main() {
	int i, n, *a;
	cin >> n;
	a = new int[n];
	for(i = 0; i < n; i++) cin >> a[i];
	ZigZag SOLUTION(a, n);
	cout << SOLUTION.longestZigZag() << endl;
	
	
	
	return 0;
}