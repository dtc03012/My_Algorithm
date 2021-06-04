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
const int MAX = 505050;
void solve(int tc){
	int n;
	string a,b;
	cin >> n >> a >> b;
	vector<int> v;
	for(int e=0;e<n;e++) if(a[e]=='1') v.push_back(e);
	lld ans = 0;
	bool suc = true;
	int st = 0;
	for(int e=0;e<n;e++){
		if(b[e]=='1'){
			if(sz(v)==st){
				suc = false;
				break;
			}else{
				for(;st<sz(v);st++){
					if(v[st]<e){
						if(st==sz(v)-1){
							suc = false;
						}else{
							ans += v[st+1] - v[st];
							st++;
						}	
					}else{
						break;
					}
				}
				if(st==sz(v)){
					suc = false;
				}
				if(!suc) break;
				ans += v[st] - e;
				st++;
			}
		}
	}
	int df = sz(v) - st;
	if(df%2) suc = false;
	if(!suc) printf("-1\n");
	else{
		for(;st<sz(v);){
			ans += v[st+1] - v[st];
			st += 2;
		}
		printf("%lld",ans);
	}

}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}