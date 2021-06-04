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

const int MAX = 202020;
int arr[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	vector<pi> v;
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		v.push_back(mk(arr[e],e));
	}
	vector<int> ans;
	sort(all(v));
	lld tot = 0;
	for(int e=0;e<sz(v)-1;e++) tot += v[e].x;
	ans.push_back(v[sz(v)-1].y);
	for(int e=sz(v)-2;e>=0;e--){
		if(tot<(lld)v[e+1].x) break;
		ans.push_back(v[e].y);
		tot -= v[e].x;
	}
	sort(all(ans));
	printf("%d\n",sz(ans));
	for(int e=0;e<sz(ans);e++) printf("%d ",ans[e]);
		printf("\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}