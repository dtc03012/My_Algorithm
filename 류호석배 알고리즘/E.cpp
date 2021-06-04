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
typedef unsigned long long int ulld;
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
	string a,b;
	cin >> a >> b;
	ulld lim = (1ll<<63);
	ulld xx = lim - 1;
	lim += xx;
	reverse(all(a));
	reverse(all(b));
	int ans = 0;
	ulld x,y,z;
	for(ulld e=2;e<=36;e++){
		for(ulld p=2;p<=36;p++){
			if(e==p) continue;
			ulld a1 = 0,a2 = 0,k1 = 1,k2 = 1;
			bool suc1 = true,suc2 = true;
			for(int q=0;q<sz(a);q++){
				ulld now = 0;
				if(a[q]>='0'&&a[q]<='9') now = a[q] - '0';
				if(a[q]>='a'&&a[q]<='z') now = a[q] - 'a' + 10;
				if(now>=e){
					suc1 = false;
					break;
				}
				if(now>ulld(lim/k1)){
					suc1 = false;
					break;
				}
				now *= k1;
				if(a1>lim-now){
					suc1 = false;
					break;
				}
				a1 += now;
				if(q==sz(a)-1) break;
				if(e>ulld(lim/k1)){
					suc1 = false;
					break;
				}
				k1 *= e;
			}
			for(int q=0;q<sz(b);q++){
				ulld now = 0;
				if(b[q]>='0'&&b[q]<='9') now = b[q] - '0';
				if(b[q]>='a'&&b[q]<='z') now = b[q] - 'a' + 10;
				if(now>=p){
					suc2 = false;
					break;
				}
				if(now>ulld(lim/k2)){
					suc2 = false;
					break;
				}
				now *= k2;
				if(a2>lim-now){
					suc2 = false;
					break;
				}
				a2 += now;
				if(q==sz(b)-1) break;
				if(p>ulld(lim/k2)){
					suc2 = false;
					break;
				}
				k2 *= p;
			}
			if(suc1&&suc2&&a1==a2){
				ans++;
				x = e;
				y = p;
				z = a1;
			}
		}
	}
	if(ans==0){
		cout << "Impossible";
	}else if(ans>1){
		cout << "Multiple";
	}else{
		cout << z << " " << x << " " << y;
	}
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