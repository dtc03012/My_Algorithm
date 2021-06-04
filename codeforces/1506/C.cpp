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


void solve(int tc){
	string a;
	string b;
	cin >> a >> b;
	int ans = sz(a) + sz(b);
	for(int e=0;e<sz(a);e++){
		for(int p=sz(a)-1;p>=e;p--){
			for(int r=0;r<sz(b);r++){
				for(int t=sz(b)-1;t>=r;t--){
					if(p-e==t-r){
						bool suc = true;
						for(int q=0;q<=p-e;q++){
							if(a[q+e]!=b[r+q]) suc = false;
						}
						if(suc){
							ans = min(ans,sz(a)+sz(b)-(p-e+1)*2);
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
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