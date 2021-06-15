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
	int a,b,k;
	cin >> a >> b >> k;
	int f1 = 0,f2 = 0;
	int k1 = a,k2 = b;
	for(int e=2;e*e<=a;e++){
		if(k1%e==0){
			int cnt = 0;
			while(k1%e==0){
				k1 /= e;
				cnt++;
			}
			f1 += cnt;
		}
	}
	if(k1!=1){
		f1++;
	}
	for(int e=2;e*e<=b;e++){
		if(k2%e==0){
			int cnt = 0;
			while(k2%e==0){
				k2 /= e;
				cnt++;
			}
			f2 += cnt;
		}
	}
	if(k2!=1){
		f2++;
	}
	if(k>=2){
		if(f1+f2>=k) cout << "YES\n";
		else cout << "NO\n";
	}else{
		if(a!=b&&((a%b)==0||(b%a)==0)) cout << "YES\n";
		else cout << "NO\n";
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