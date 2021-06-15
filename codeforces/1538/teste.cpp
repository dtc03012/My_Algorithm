#include <stdio.h>
#include<assert.h>
#include <bits/stdc++.h>
using namespace std;
using lld = long long int;
void wahaha(bool x){
	if(!x){
		int res=0;
		for(int i=2;i>=0;i++){
			res += i;
		}
		printf("%d\n",res);
	}
}
int n;
lld m;
lld a[3000009];
bool valid(lld x){
	lld prev = a[0];
	if(a[0] + x >= m)prev = 0;
	int i;
	prev++;
	for(i=1;i<n;i++){
		lld tl = a[i];
		lld tr = a[i] + x;
		// 7 8 9 --> 7 0 1
		lld tr2 = -1;
		if(tr >= m) tr2 = tr - m ;
		tr = min(tr,m-1);
		tr2 = min(tr2,m-1);
		if(prev<=tr2) prev++;
		else{
			if(tr<prev) return false;
			prev = max(prev,tl);
			prev++;
		}
	}
	return true;
}
int main() {
	scanf("%d %lld",&n,&m);
	// wahaha(n<=m);
	// wahaha(1 <= n && m <= 300000);
	int i, j, k;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		a[i]--;
	}
	lld l = 0;
	lld r = 2*m;
	lld ans = m;
	while(l<=r){
		lld mid = (l+r)/2;
		if(valid(mid)){
			r = mid - 1;
			ans = min(ans,mid);
		}
		else{
			l = mid + 1;
		}
	}
	// wahaha(valid(l));
	printf("%lld\n",ans);
	return 0;
}