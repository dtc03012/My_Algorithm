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
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) printf("NO\n");
		else if(x==y) printf("YES\n");
		else{
			vector<int> v1,v2;
			for(int e=0;e<30;e++) if(x&(1<<e)) v1.push_back(e);
			for(int e=0;e<30;e++) if(y&(1<<e)) v2.push_back(e);
			if(sz(v2)>sz(v1)) printf("NO\n");
			else{
				bool ans = true;
				int e;
				int lastn = sz(v1) - 1;
				for(e=sz(v2)-1;e>=0;e--){
					if(v2[e]==v1[lastn]){
						lastn--;
						continue;
					}
					else{
						if(v2[e]>v1[lastn]){
							int df = sz(v1) - sz(v2) + 1;
							lastn -= df;
							e--;
							for(;lastn>=0;lastn--){
								if(v2[e]>=v1[lastn]) e--;
							}
							if(e!=-1){
								ans = false;
							}
							break;
						}
						else{
							ans = false;
							break;
						}
					}
				}
				if(lastn!=-1) ans = false;
				if(ans) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
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