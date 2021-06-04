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
int A[MAX],B[MAX],vis[MAX];
pi C[MAX],D[MAX];
map<int,int> ch1,ch2;
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&A[e]);
	for(int e=0;e<n;e++) scanf("%d",&B[e]);
	for(int e=0;e<n;e++) C[e] = mk(A[e],e);
	for(int e=0;e<n;e++) D[e] = mk(B[e],e);
	sort(C,C+n);
	sort(D,D+n);
	bool suc = true;
	for(int e=0;e<n;e++) if(C[e].x>D[e].x) suc = false;
	if(!suc) printf("No");
	else{
		bool suc = false;
		for(int e=0;e<n;e++){
			if(ch1[A[e]]) suc = true;
			ch1[A[e]] = 1;
		}
		for(int e=0;e<n;e++){
			if(ch2[B[e]]) suc = true;
			ch2[B[e]] = 1;
		}
		if(suc) printf("Yes");
		else{
			vector<pi> v;
			for(int e=0;e<n;e++) v.push_back(mk(D[e].y,C[e].y));
			sort(all(v));
			int tot = 0,st = 0;
			while(vis[st]==0){
				tot++;
				vis[st] = 1;
				st = v[st].y;
			}
			if(tot==n){
				bool suc = false;
				for(int e=1;e<n;e++){
					if(C[e].x<=D[e-1].x) suc = true;
				}
				if(suc) printf("Yes");
				else printf("No");
			}
			else printf("Yes");
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}