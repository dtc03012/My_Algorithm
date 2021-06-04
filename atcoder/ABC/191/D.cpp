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
	string xx,yy,rr;
	cin >> xx >> yy >> rr;
	lld x=0,y=0,r=0;
	int mm = 0,ty = 0,f1=0,f2=0,f3=0;
	for(int e=0;e<sz(xx);e++){
		if(xx[e]=='-'){
			f1++;
			continue;
		}
		if(xx[e]=='.'){
			ty = 1;
			continue;
		}
		if(ty) mm++;
		x = x*10 + (xx[e]-'0');
	}
	for(int e=0;e<4-mm;e++) x *= 10;
	mm = 0;ty = 0;
	for(int e=0;e<sz(yy);e++){
		if(yy[e]=='-'){
			f2++;
			continue;
		}
		if(yy[e]=='.') {
			ty = 1;
			continue;
		}
		if(ty) mm++;
		y = y*10 + (yy[e]-'0');
	}
	for(int e=0;e<4-mm;e++) y *= 10;
	mm = 0;ty =  0;
	for(int e=0;e<sz(rr);e++){
		if(rr[e]=='-'){
			f3++;
			continue;
		}
		if(rr[e]=='.'){
			ty = 1;
			continue;
		}
		if(ty) mm++;
		r = r*10 + (rr[e]-'0');
	}
	for(int e=0;e<4-mm;e++) r *= 10;
	if(f1) x *= -1;
	if(f2) y *= -1;
	if(f3) r *= -1;
	lld tot = 0;
	for(lld e=-2000000000;e<=2000000000;e+=10000){
		if(abs(e-x)>r) continue;
		lld xlen = (e-x)*(e-x);
		lld ll = -200000,rr = 200000,y1 = 200001,mid;
		while(ll<=rr){
			mid = (ll+rr)/2;
			lld rmid = mid * 10000;
			if(rmid<=y){
				if((y-rmid)*(y-rmid)+xlen<=r*r){
					y1 = min(y1,mid);
					rr = mid - 1;
				}else{
					ll = mid + 1;
				}
			}else{
				rr = mid - 1;
			}
		}
		if(y1==200001){
			y1 = y/10000;
			if(y>=0&&(y%10000)) y1++;
		}
		ll = -200000;rr = 200000;
		lld y2 = -200001;
		while(ll<=rr){
			mid = (ll+rr)/2;
			lld rmid = mid * 10000;
			if(rmid>=y){
				if((y-rmid)*(y-rmid)+xlen<=r*r){
					y2 = max(y2,mid);
					ll = mid + 1;
				}else{
					rr = mid - 1;
				}
			}else{
				ll = mid + 1;
			}
		}
		if(y2==-200001){
			y2 = y/10000;
			if(y<0&&(y%10000)) y2--;
		}
		if(y1<=y2) tot += (y2-y1+1);	
	}
	printf("%lld\n",tot);
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