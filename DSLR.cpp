#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
#define MAX 10000
using namespace std;

int check[MAX]; string result[MAX];
queue<int> q;
void Init(){
	for(int i=0; i< MAX; i++){
		check[i]= 0; result[i]= "";
	}
}
int D(int num){
	int temp= (num*2) % 10000;
	return temp;
}
int S(int num){
	int temp= num-1;
	if(temp< 0){
		temp= 9999;
	}
	return temp;
}
int L(int num){
	int temp= (num%1000)*10 + num/1000;
	return temp;
}
int R(int num){
	int temp= num/10 + (num%10) * 1000;
	return temp;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int num; scanf("%d", &num);
	for(int i=0; i< num; i++){
		int start, ans; scanf("%d %d", &start, &ans);
		Init();
		check[start]= 1;
		q.push(start);
		while( !q.empty() ){
			int now= q.front(); q.pop();
			int next= D(now);
			if( !check[ next ] ){
				string str= result[now]; str.append("D");
				check[ next ]= 1;
				result[next]= str;
				q.push(next);
			}
			next= S(now);
			if( !check[ next ] ){
				string str= result[now]; str.append("S");
				check[ next ]= 1;
				result[next]= str;
				q.push(next);
			}
			next= L(now);
			if( !check[ next ] ){
				string str= result[now]; str.append("L");
				check[ next ]= 1;
				result[next]= str;
				q.push(next);
			}
			next= R(now);
			if( !check[ next ] ){
				string str= result[now]; str.append("R");
				check[ next ]= 1;
				result[next]= str;
				q.push(next);
			}
		}
		cout << result[ans] << endl;
	}
	return 0;
}
