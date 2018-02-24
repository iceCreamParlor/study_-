#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<char> alpha;
bool check(string &password){
	int ja=0, mo=0;
	for( char x: password ){
		if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
		{
			mo++;
		}
		else ja++;
	}
	return ja>=2 && mo>= 1;
}
void go( int n, vector<char> &alpha, string password, int i ){
	if( password.length()== n ){
		if(check(password))
			cout << password<< endl;
		return;
	}
	if( i>= alpha.size() ) return;
	go(n, alpha, password+ alpha[i], i+1);
	go(n, alpha, password, i+1);
}
int main(){
	freopen("input.txt", "r", stdin);
	string password= "";
	char trash;
	int n, length, ntemp; scanf("%d %d", &n, &length);
	ntemp= length;
	scanf("%c", &trash);
	while(ntemp> 0){
		char temp; scanf("%c", &temp);
		if(temp != ' '){
			alpha.push_back(temp);
			ntemp--;
		}
	}
	sort(alpha.begin(), alpha.end());
	go(n, alpha, password, 0);
	return 0;
}