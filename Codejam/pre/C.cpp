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

const int MAX = 111;
int ans[MAX];
void solve(int tc){
	int n,c;
	cin >> n >> c;
	if((((n*(n+1))/2)-1)<c||c<n-1){
		cout << "Case #"<< tc << ": IMPOSSIBLE\n";
		return; 
	}
	c -= (n-1);
	for(int e=1;e<=n;e++) ans[e] = 0;
	int ty = 0;
	int ll = 1,rr = n;
	for(int e=1;e<n;e++){
		int now = n - e;
		if(now<c){
			if(ty==0){
				ans[rr--] = e;
			}else{
				ans[ll++] = e;
			}
			c -= now;
			ty ^= 1;
		}else{
			if(ty==0){
				int rrn = rr - (now-c);
				ans[rrn] = e;
				int q = e + 1;
				for(int p=rrn-1;p>=ll;p--,q++) ans[p] = q;
				for(int p=rrn+1;p<=rr;p++,q++) ans[p] = q;
			}else{
				int lln = ll + (now-c);
				ans[lln] = e;
				int q = e + 1;
				for(int p=lln+1;p<=rr;p++,q++) ans[p] = q;
				for(int p=lln-1;p>=ll;p--,q++) ans[p] = q;
			}
			break;
		}
	}
	cout << "Case #" << tc << ": ";
	for(int e=1;e<=n;e++) cout << ans[e] << " " ;
	cout << "\n"; 
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}