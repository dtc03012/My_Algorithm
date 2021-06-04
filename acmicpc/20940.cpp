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

const int MAX = 1000101;
int mod,num[MAX];
lld gcdarr[MAX],lcmarr[MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld divs(lld a,lld b){
	return (a*calc(b,mod-2))%mod;
}
lld makeans1(int n){
	lld ans1 = 0;
	for(int e=1;e<=n;e++){
		lld tot1 = (1ll*e*(e+1))/2;
		tot1 = (tot1*tot1)%mod;
		ans1 = (ans1+tot1)%mod;
	}
	return ans1;
}
lld SgetGcd(int n){
	lld ans = 0;
	for(int e=1;e<=n;e++){
		if(num[e]==-1) continue;
		lld f = 1ll*(n/e)*(n/e);
		f %= mod;cf
		if(num[e]%2==0) ans = (ans+f)%mod;
		else{
			ans -= f;
			ans = (ans%mod+mod)%mod;
		}
	}
	return ans;
}
lld AgetGcd(int n){
	lld ans1 = 0;
	for(int e=1;e<=n;e++) ans1 = (ans1+SgetGcd(e)*e)%mod;
	return ans1;
}
lld SgetLcm(int n){
	lld ans = 0;
	for(int e=1;e<=n;e++){
		if(num[e]==-1) continue;
		lld f = (n/e);
		f = ((f*(f+1))/2)%mod;
		f = (f*e)%mod;
		f = (f*f)%mod;
		if(num[e]%2==0) ans = (ans+f)%mod;
		else{
			ans -= f;
			ans = (ans%mod+mod)%mod;
		}
	}
	return ans;
}
lld AgetLcm(int n){
	lld ans1 = 0;
	for(int e=1;e<=n;e++) ans1 = (ans1+SgetLcm(e))%mod;
	return ans1;
}
lld makeans2(int n){
	return (AgetGcd(n)*AgetLcm(n))%mod;
}
void solve(int tc){
	for(int e=2;e<MAX;e++){
		if(num[e]==0){
			for(int p=e;p<MAX;p+=e){
				if(num[p]==-1) continue;
				if((p/e)%e==0) num[p] = -1;
				else num[p]++;
			}
		}
	}
	int n;
	scanf("%d%d",&n,&mod);
	printf("%lld\n%lld",makeans1(n),makeans2(n));
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