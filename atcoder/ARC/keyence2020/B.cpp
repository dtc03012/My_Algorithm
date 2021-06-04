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

const int MAX = 101010;
pi arr[MAX];
set<int> s;
int num = 1;
map<int,int> mm;
int dp[MAX*2];
bool tmr(pi a,pi b){
	return a.y < b.y;
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		int x,l;
		scanf("%d%d",&x,&l);
		arr[e] = mk(x-l,x+l);
		s.insert(arr[e].x);
		s.insert(arr[e].y);
	}
	for(set<int>::iterator it = s.begin();it!=s.end();it++) mm[*it] = num++;
	for(int e=0;e<n;e++){
		arr[e].x = mm[arr[e].x];
		arr[e].y = mm[arr[e].y];
	}
	sort(arr,arr+n,tmr);
	int st = 1,ans = 0;
	for(int e=0;e<n;e++){
		while(st<arr[e].y){
			dp[st] = max(dp[st],dp[st-1]);
			st++;
		}
		dp[arr[e].y] = max(dp[arr[e].y],dp[arr[e].x]+1);
		ans = max(ans,dp[arr[e].y]);
	}
	printf("%d",ans);
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