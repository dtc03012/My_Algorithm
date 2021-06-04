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

const int MAX = 18;
lld arr[MAX];
void solve(int tc){
	int n;
	lld l,r;
	cin >> n >> l >> r;
	for(int e=0;e<n;e++) cin >> arr[e];
	lld ans = 0;
	for(int e=1;e<(1<<n);e++){
		lld tot = 0,vv = 1;
		bool error = false;
		for(int p=0;p<n;p++){
			if(e&(1<<p)){
				tot++;
				lld f1 = __gcd(vv,arr[p]);
				vv = (vv*arr[p])/f1;
				if(vv>r){
					error = true;
					break;
				}
			}
		}
		if(!error){
			lld f = (r/vv) - ((l-1)/vv);
			if(tot%2) ans += f;
			else ans -= f;
		}
	}
	cout << ans;
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