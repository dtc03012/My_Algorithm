#include <bits/stdc++.h>

using namespace std;



std::random_device rd;
std::mt19937 mersenne(rd());
int makeRandomNum(int l,int r,int mod){
	std::uniform_int_distribution<> die(l,r); // l ~ r die(l,r)
	return die(mersenne)%mod;
}
int main(void){
	printf("%d\n",makeRandomNum(2,100,7));
}