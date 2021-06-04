#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
class MinMaxGame{
public:
	int lastNumber(vector <int> A){
		int f1 = A[0], f2 = A[sz(A)-1];
		if(sz(A)%2==0){
			return min(f1,f2);
		}else{
			return max(f1,f2);
		}
	}
};
void solve(int tc){
	
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}