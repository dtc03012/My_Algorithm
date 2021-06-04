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


lld tot = 1ll * 360 * 12 * 1e10;
lld plv[3],a,b,c;
pair<bool,pl> can(lld a1,lld ax,lld b1,lld bx,lld c1,lld cx){
	lld r1 = a - b - a1 + b1;
	if(r1%(ax-bx)) return mk(false,mk(0,1));
	lld nano1 = r1 / (ax - bx);
	if(nano1<0) return mk(false,mk(0,2));
	lld r2 = b - c - b1 + c1;
	if(r2%(bx-cx)) return mk(false,mk(0,3));
	lld nano2 = r2 / (bx - cx);
	if(nano2<0) return mk(false,mk(0,4));
	lld r3 = a - c - a1 + c1;
	if(r3%(ax-cx)) return mk(false,mk(0,5));
	lld nano3 = r3 / (ax - cx);
	if(nano3<0) return mk(false,mk(0,6));
	if(nano1!=nano2||nano1!=nano2||nano2!=nano3) return mk(false,mk(0,7));
	lld p1 = a - a1 - nano1*ax;
	lld p2 = b - b1 - nano1*bx;
	lld p3 = c - c1 - nano1*cx;
	if(nano1>=1e9) return mk(false,mk(0,8));
	if(p1!=p2||p1!=p3||p2!=p3) return mk(false,mk(0,8));
	lld x1 = a1 + ax*nano1 + p1;
	lld x2 = b1 + bx*nano1 + p1;
	lld x3 = c1 + cx*nano1 + p1;
	if(x1>x2||x2>x3||x1>x3) return mk(false,mk(0,0));
	if(x1!=a||x2!=b||x3!=c) return mk(false,mk(0,0));
	if(x1<0||x2<0||x3<0) return mk(false,mk(0,0));
	if(p1<0) return mk(false,mk(0,9));
	return mk(true,mk(nano1,p1));

}
void solve(int tc){
	plv[0] = 1;
	plv[1] = 12;
	plv[2] = 720;
	cout << "Case #" << tc << ": ";
	cin >> a >> b >> c;
	for(lld p=0;p<12;p++){
		for(lld q=0;q<60;q++){
			for(lld r=0;r<60;r++){
				if(true){
					lld h = (tot*p)/12 + (tot*q)/(12*60) + (tot*r)/(12*60*60);
					lld m = (tot*q)/60 + (tot*r)/(60*60);
					lld s = (tot*r)/60;
					lld arr[3] = {h,m,s};
					vector<int> v;
					v.push_back(0);
					v.push_back(1);
					v.push_back(2);
					do{
						for(int k=0;k<8;k++){
							if(true){
								lld arr2[3] = {arr[0],arr[1],arr[2]};
								for(int r=0;r<3;r++) if(k&(1<<r)) arr2[r] -= tot;
								pair<bool,pl> xx = can(arr2[v[0]],plv[v[0]],arr2[v[1]],plv[v[1]],arr2[v[2]],plv[v[2]]);
								if(xx.x){
									cout << p << " " << q << " " << r << " " << xx.y.x << "\n";
									return;
								}
							}
						}
					}while(next_permutation(all(v)));
				}
			}
		}
	}
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