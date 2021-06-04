#include <bits/stdc++.h>

using namespace std;


class IncorrectCancellation{
public:
	int can(int x,int y){
		
	}
	int find(int D){
		for(int e=1;e<D;e++){
			if(can(e,D)){
				return e;
			}
		}
		return -1;
	}
};