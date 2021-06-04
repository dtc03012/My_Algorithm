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

const int MAX = 5050;
lld arr[MAX];
int vis[MAX],n;
bool can(lld x){
	memset(vis,0,sizeof(vis));
	for(int e=0;e<n-1;e++){
		if(vis[e]) continue;
		if(arr[e]>=x) return true;
		for(int p=e+1;p<n-1;p++){
			if(arr[e]+arr[p]>=x&&vis[p]==0){
				vis[p] = 1;
				vis[e] = 1;
				break;
			}
		}
		if(vis[e]==0) return false;
	}
	return true;
}
void solve(int tc){
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	if(n<=2){
		cout << "0";
		return;
	}
	sort(arr,arr+n);
	for(int e=0;e<n;e++) cout << arr[e] << " ";
	cout << endl;
	lld ll = -1e9,rr = arr[n-1],mid,ans=-1e9;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(can(mid)){
			ans = max(ans,mid);
			ll = mid + 1;
		}else rr = mid - 1;
	}
	cout << arr[n-1] - ans ;
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}