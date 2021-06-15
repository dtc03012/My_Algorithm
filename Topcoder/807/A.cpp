#include <bits/stdc++.h>
using namespace std;

class HangmanHelper{
public:
	string show(string secretWord, string lettersGuessed){
		string xx = "";
		for(int e=0;e<(int)secretWord.size();e++){
			bool flag = false;
			for(int p=0;p<(int)lettersGuessed.size();p++){
				if(lettersGuessed[p]==secretWord[e]){
					flag = true;
				}
			}
			if(flag) xx += secretWord[e];
			else xx += "_";
		}
		return xx;
	}
};