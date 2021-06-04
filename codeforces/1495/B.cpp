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
int arr[MAX],rrw[MAX],rrl[MAX],llw[MAX],lll[MAX],dp[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	rrw[n] = 1;
	rrl[n] = 1;
	for(int e=n-1;e>=1;e--){
		if(arr[e]<arr[e+1]){
			rrl[e] = rrl[e+1] + 1;
			rrw[e] = 1;
		}else{
			rrl[e] = 1;
			rrw[e] = rrw[e+1] + 1;
		}
	}
	llw[1] = 1;
	lll[1] = 1;
	for(int e=2;e<=n;e++){
		if(arr[e]<arr[e-1]){
			lll[e] = lll[e-1] + 1;
			llw[e] = 1;
		}else{
			lll[e] = 1;
			llw[e] = llw[e-1] + 1;
		}
	}
	int mxy = 0;
	vector<int> wh;
	for(int e=1;e<=n;e++){
		if(lll[e]>mxy){
			wh.clear();
			wh.push_back(e-lll[e]+1);
			mxy = lll[e];
		}else if(lll[e]==mxy) wh.push_back(e-lll[e]+1);
		if(rrl[e]>mxy){
			wh.clear();
			wh.push_back(e+rrl[e]-1);
			mxy = rrl[e];
		}else if(rrl[e]==mxy) wh.push_back(e+rrl[e]+1);
	}
	wh.erase(unique(all(wh)),wh.end());
	int ans = 0;
	for(int e=2;e<n;e++){
		if(arr[e]>arr[e-1]&&arr[e]>arr[e+1]){
			int mx = min(llw[e],rrw[e]);
			if(mx==2) continue;
			if(mx<mxy) continue;
			if(mx>mxy){
				ans++;
				continue;
			}
			if(sz(wh)>1) continue;
			if(mxy%2==0) continue;
			ans++;
		}
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
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}