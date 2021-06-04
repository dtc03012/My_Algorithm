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
	int n,k;
	cin >> n >> k;
	string a;
	cin >> a;
	int ll = -1,rr = -1;
	for(int e=0;e<n;e++){
		if(a[e]=='*'){
			if(ll==-1) ll = e;
		}
	}
	for(int e=n-1;e>=0;e--){
		if(a[e]=='*'){
			if(rr==-1) rr = e;
		}
	}
	if(ll==-1){
		cout << "0\n";
	}else if(ll==rr){
		cout << "1\n";
	}else{
		int last = ll,ans = 2,llast = ll;
		for(int e=ll+1;e<rr;e++){
			if(a[e]=='*'){
				if(rr-last<=k) break;
				if(e-last<=k){
					if(e-llast<=k&&last!=llast){
						last = e;
					}else{
						ans++;
						llast = last;
						last = e;
					}
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
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}