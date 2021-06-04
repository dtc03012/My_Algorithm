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
short bs[(1<<26)];
void solve(int tc){
	string a;
	cin >> a;
	int ans = 0;
	for(int e=1;e<=26;e++){
		int ll = 0,rr = -1,vis[26],tot=0,bit=0;
		memset(vis,0,sizeof(vis));
		for(;rr<sz(a);){
			while(tot<e&&rr+1<sz(a)){
				rr++;
				if(vis[a[rr]-'A']==0){
					tot++;
					bit ^= (1<<(a[rr]-'A'));
				}
				vis[a[rr]-'A']++;
				if(tot==e) break;
			}
			if(tot!=e) break;
			if(bs[bit]!=tc){
				bs[bit] = tc;
				ans++;
			}
			vis[a[ll]-'A']--;
			if(vis[a[ll]-'A']==0){
				bit ^= (1<<(a[ll]-'A'));
				tot--;
			}
			ll++;
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