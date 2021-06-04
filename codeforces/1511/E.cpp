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

const lld mod = 998244353;
const int MAX = 303030;
string arr[MAX];
lld two[MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	int tot = 0;
	for(int p=0;p<n;p++){
		cin >> arr[p];
		for(int q=0;q<m;q++){
			if(arr[p][q]=='o') tot++;
		}
	}
	if(tot<2){
		cout << "0\n";
	}else{
		lld ans = 0;
		two[0] = 1;
		for(int e=1;e<MAX;e++) two[e] = (two[e-1]*2)%mod;
		for(int e=0;e<n;e++){
			int xx = 0;
			for(int p=0;p<m;p++){
				if(arr[e][p]=='o'){
					xx++;
				}else{
					for(int q=2;q<=xx;q++){
						lld vv = (1ll*(xx-q+1)*two[tot-q])%mod;
						if(q%2==0){
							ans = (ans+vv)%mod;
						}else{
							ans = (ans-vv)%mod;
							ans = (ans%mod+mod)%mod;
						}
					}
					xx = 0;
				}
			}
			for(int q=2;q<=xx;q++){
				lld vv = (1ll*(xx-q+1)*two[tot-q])%mod;
				if(q%2==0){
					ans = (ans+vv)%mod;
				}else{
					ans = (ans-vv)%mod;
					ans = (ans%mod+mod)%mod;
				}
			}
		}
		for(int p=0;p<m;p++){
			int xx = 0;
			for(int e=0;e<n;e++){
				if(arr[e][p]=='o'){
					xx++;
				}else{
					for(int q=2;q<=xx;q++){
						lld vv = (1ll*(xx-q+1)*two[tot-q])%mod;
						if(q%2==0){
							ans = (ans+vv)%mod;
						}else{
							ans = (ans-vv)%mod;
							ans = (ans%mod+mod)%mod;
						}
					}
					xx = 0;
				}
			}
			for(int q=2;q<=xx;q++){
				lld vv = (1ll*(xx-q+1)*two[tot-q])%mod;
				if(q%2==0){
					ans = (ans+vv)%mod;
				}else{
					ans = (ans-vv)%mod;
					ans = (ans%mod+mod)%mod;
				}
			}
		}
		cout << ans << "\n";
	}
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