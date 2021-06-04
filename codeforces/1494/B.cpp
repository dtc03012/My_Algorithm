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

bool can(int x,int n){
	if(x>=0&&x<=n-2) return true;
	return false;
}
void solve(int tc){
	int n,u,r,d,l;
	scanf("%d%d%d%d%d",&n,&u,&r,&d,&l);
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	bool suc = false;
	do{
		for(int p=0;p<(1<<4);p++){
			int nu = u,nr = r,nd = d,nl = l;
			for(int q=0;q<4;q++){
				if(p&(1<<q)){
					if(v[q]==0){
						nu--;
						nl--;
					}
					if(v[q]==1){
						nu--;
						nr--;
					}
					if(v[q]==2){
						nd--;
						nl--;
					}
					if(v[q]==3){
						nr--;
						nd--;
					}
				}
			}
			if(can(nu,n)&&can(nr,n)&&can(nd,n)&&can(nl,n)) suc = true;
		}
	}while(next_permutation(all(v)));
	if(suc) printf("YES\n");
	else printf("NO\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}