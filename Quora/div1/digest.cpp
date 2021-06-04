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

const int MAX = 202;
int UU[MAX][MAX],US1[MAX][MAX],US2[MAX][MAX],VV1[MAX][MAX],VV2[MAX][MAX];
vector<int> v1[MAX],v2[MAX];
bool tmr(pi a,pi b){
	if(a.y!=b.y) return a.y > b.y;
	return a.x < b.x;
}
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		int k;
		scanf("%d",&k);
		US1[k][e] = 1;
		v1[k].push_back(e);
	}
	int p,q;
	scanf("%d%d",&p,&q);
	for(int e=0;e<p;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		UU[a][b] = 1;
	}
	for(int e=0;e<q;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		US2[a][b] = 1;
		v2[a].push_back(b);
	}
	for(int e=1;e<=m;e++){
		for(int p=1;p<=m;p++){
			if(e==p) continue;
			bool suc = false;
			for(int q=0;q<sz(v1[p]);q++){
				int nx = v1[p][q];
				if(US2[e][nx]) suc = true;
			}
			if(suc) VV1[e][p] = 1;
		}
	}
	for(int e=1;e<=m;e++){
		for(int p=1;p<=m;p++){
			if(e==p) continue;
			bool suc = false;
			for(int q=0;q<sz(v2[p]);q++){
				int nx = v2[p][q];
				if(US2[e][nx]) suc = true;
			}
			if(suc) VV2[e][p] = 1;	
		}
	}
	for(int e=1;e<=m;e++){
		vector<pi> v;
		for(int p=1;p<=n;p++){
			if(US1[e][p]||US2[e][p]){
				v.push_back(mk(p,-1));
			}else{
				int tot = 0;
				for(int q=1;q<=m;q++){
					if(e==q) continue;
					int f1 = 0;
					if(UU[e][q]) f1 = 3;
					else{
						if(VV1[e][q]) f1 = 2;
						else if(VV2[e][q]) f1 = 1;
					}
					int f2 = 0;
					if(US1[q][p]) f2 = 2;
					else{
						if(US2[q][p]) f2 = 1;
					}
					tot += f1*f2;
				}
				v.push_back(mk(p,tot));
			}
		}
		sort(all(v),tmr);
		for(int e=0;e<3;e++) printf("%d ",v[e].x);

		printf("\n");
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