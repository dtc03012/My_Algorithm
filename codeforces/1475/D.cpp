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
int arr[MAX],B[MAX];
lld tot[MAX];
vector<int> v[2];
bool tmr(int a,int b){
	return a > b;
}
int find(int r,lld val){
	if(val<=0) return 0;
	int wh = lower_bound(tot,tot+r,val) - tot;
	if(wh==r) return -1;
	return (wh+1)*2;
}
void solve(int tc){
	v[0].clear();v[1].clear();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	for(int e=0;e<n;e++) scanf("%d",&B[e]);
	for(int e=0;e<n;e++){
		if(B[e]==1) v[0].push_back(arr[e]);
		else v[1].push_back(arr[e]);
	}
	sort(all(v[0]),tmr);
	sort(all(v[1]),tmr);
	if(sz(v[1])==0){
		int mx = -1,tot = 0;
		for(int p=0;p<sz(v[0]);p++){
			if(tot+v[0][p]>=m){
				mx = p+1;
				break;
			}
			tot += v[0][p];
		}
		printf("%d\n",mx);
	}else{
		tot[0] = v[1][0];
		for(int e=1;e<sz(v[1]);e++) tot[e] = tot[e-1] + v[1][e];
		int mx = find(sz(v[1]),m);
		int tot = 0;
		for(int e=0;e<sz(v[0]);e++){
			tot += v[0][e];
			int kk = find(sz(v[1]),m-tot);
			if(kk!=-1){
				if(mx==-1) mx = kk + (e+1);
				else mx = min(mx,kk+(e+1));
			}
		}
		printf("%d\n",mx);
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