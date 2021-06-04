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
int arr[MAX],cnt[MAX];
vector<int> v;
int getidx(int x){
	return lower_bound(all(v),x) - v.begin();
}
void solve(int tc){
	v.clear();
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		v.push_back(arr[e]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int e=1;e<=n;e++){
		arr[e] = getidx(arr[e]);
	}
	for(int e=0;e<sz(v);e++) cnt[e] = 0;
	for(int e=1;e<=n;e++) cnt[arr[e]]++;
	vector<int> k;
	for(int e=0;e<sz(v);e++) k.push_back(cnt[e]);
	sort(all(k));
	int ans = 1e9;
	for(int e=0;e<sz(k);e++){
		int mx = k[e];
		ans = min(ans,n-mx*(sz(k)-e));
	}
	printf("%d\n",ans);
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