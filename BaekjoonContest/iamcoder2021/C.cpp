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

const int MAX = 303030;
char S[MAX];
int L,R,D,U,L1,R1,D1,U1,kk;
int f(int x){
	int NL1 = L1+x,NR1 = R1+x;
	int ND1 = D1+(kk-x),NU1 = U1+(kk-x);
	int tot = max(L-NL1,0) + max(R-NR1,0) + max(D-ND1,0) + max(U-NU1,0);
	return tot;
}
void solve(int tc){
	int n,que;
	scanf("%d%d%s",&n,&que,&S);
	for(int e=0;e<n;e++){
		if(S[e]=='U') U++;
		if(S[e]=='D') D++;
		if(S[e]=='R') R++;
		if(S[e]=='L') L++;
	}
	int ox = R - L , oy = U - D;
	while(que--){
		int x,y;
		scanf("%d%d",&x,&y);
		int tot = 1e9;
		bool suc = true;
		if(abs(x)+abs(y)>n) suc = false;
		else if((n-abs(x)-abs(y))%2) suc = false;
		else{
			kk = (n-abs(x)-abs(y))/2;
			L1=0;R1=0;D1=0;U1=0;
			if(y>0) U1= y;
			if(y<0) D1=-y;
			if(x>0) R1=x;
			if(x<0) L1=-x;
			int ll =0,rr = kk;
			while(rr-ll>=3){
				int lv = (ll*2+rr)/3,rv= (ll+rr*2)/3;
				if(f(lv)>f(rv)) ll = lv;
				else rr = rv;
			}
			int mx = 1e9;
			for(int e=ll;e<=rr;e++) mx = min(mx,f(e));
			tot = mx;
		}
		if(!suc) tot = -1;
		printf("%d\n",tot);
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