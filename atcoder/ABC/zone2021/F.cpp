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

const int MAX = (1<<19) + 100;
int cnt[MAX],uf[MAX];
set<int> bit[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) uf[e] = e;
	for(int e=0;e<m;e++){
		int r;
		cin >> r;
		cnt[r] = 1;
	}
	vector<pi> ans;
	for(int e=0;e<=18;e++){
		if((1<<e)==n) break;
		int rt = -1;
		for(int p=0;p<n;p++){
			if((p&(1<<e))&&cnt[p]==0){
				bit[e].insert(p);
			}
		}
	}
	for(int e=0;e<=18;e++){
		if((1<<e)==n) break;
		int rt = -1;
		for(int p=0;p<18;p++){
			if(sz(bit[p])>1||(sz(bit[p])==1&&e==p)){
				for(auto x : bit[p]){
					if(x&(1<<e)){
						rt = x;
						break;
					}
				}
				if(rt!=-1){
					bit[p].erase(rt);
					break;
				}
			}
		}
		if(rt==-1){
			cout << "-1";
			return;
		}
		for(int p=0;p<n;p++){
			int f1 = p;
			int f2 = p ^ rt;
			int s1 = find(f1);
			int s2 = find(f2);
			if(s1!=s2){
				ans.push_back(mk(f1,f2));
				uf[s1] = s2;
			}
		}
	}
	for(int e=0;e<sz(ans);e++) cout << ans[e].x << " " << ans[e].y << "\n";
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