#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 22;
int arr[MAX],dp[(1<<MAX)][3];
void solve(int tc){
	int n;
	scanf("%d",&n);
	int tot = 0;
	for(int e=0;e<n;e++){
		scanf("%d",&arr[e]);
		tot += arr[e];
	}
	if(tot%4==0){
		tot /= 4;
		for(int e=0;e<(1<<n);e++) dp[e][0] = dp[e][1] = dp[e][2] = 0;
		for(int e=0;e<n;e++){
			dp[(1<<e)][0] = arr[e];
			if(arr[e]==tot) dp[(1<<e)][1] = 1;
		}
		int st = 1;
		for(int e=3;e<(1<<n);e++){
			if(e==(1<<(st+1))) st++;
			if(dp[e][0]) continue;
			dp[e][0] = dp[e^(1<<st)][0] + arr[st];
			if(dp[e][0]==tot) dp[e][1] = 1;
		}
		for(int e=0;e<n;e++){
			for(int p=0;p<(1<<n);p++){
				if((p&(1<<e))&&dp[p^(1<<e)][1]) dp[p][1] = 1;
				if(dp[p][0]==tot*2&&dp[p][1]) dp[p][2] = 1;
			}
		}
		bool suc = false;
		int lim = (1<<n) - 1;
		for(int e=0;e<(1<<n);e++) if(dp[e][2]&&dp[e^lim][2]) suc = true;
		if(suc) printf("yes\n");
		else printf("no\n");
	}else{
		printf("no\n");
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}