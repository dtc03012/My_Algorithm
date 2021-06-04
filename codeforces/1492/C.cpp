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
int ll[MAX],rr[MAX];
void solve(int tc){
	int n,m;
	string a,b;
	cin >> n >> m >> a >> b;
	int xx = 0;
	for(int p=0;p<sz(b);p++){
		for(;xx<sz(a);xx++){
			if(a[xx]==b[p]) break;
		}
		ll[p] = xx++;
	}
	reverse(all(a));
	reverse(all(b));
	xx = 0;
	for(int p=0;p<sz(b);p++){
		for(;xx<sz(a);xx++){
			if(a[xx]==b[p]) break;
		}
		rr[sz(b)-p-1] = sz(a)-xx-1;
		xx++;
	}
	int ans = 0;
	for(int p=0;p<sz(b)-1;p++){
		ans = max(ans,rr[p+1]-ll[p]);
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