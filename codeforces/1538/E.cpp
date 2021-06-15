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

lld calc(int x){
	if(x<10) return x;
	vector<int> v;
	int rx = x;
	while(rx){
		v.push_back(rx%10);
		rx /= 10;
	}
	lld ans = 0;
	reverse(all(v));
	lld f1 = 0,ten = 1;
	for(int e=0;e<sz(v);e++) ten *= 10;
	for(int e=0;e<sz(v);e++){
		ten /= 10;
		for(int p=0;p<10;p++){
			if(e==0&&p>v[e]) continue;
			if(p<v[e]){
				ans += f1 + 1;
			}else{
				ans += f1;
			}
		}
		f1 = f1 * 10 + v[e];
	}
	return ans;
}
void solve(int tc){
	int l,r;
	cin >> l >> r;
	cout << calc(r) - calc(l) << "\n";
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