#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int puzzle[9], answer[9]; bool visit[10000000000];
int result, cnt; 
vector<int> myvec;
queue<int> q;

void regist( int temp ){
	visit[temp]= true;
}
bool check(int temp){
	if( visit[temp] ) {return true;}
	else {return false;}
}
void swap(int i1, int i2){
	int temp= puzzle[i1];
	puzzle[i1]= puzzle[i2];
	puzzle[i2]= temp;
}
bool answercheck(){
	for(int i=0; i<9; i++){
		if( answer[i] != puzzle[i] ) return false;
	}
	return true;
}
int convert(){
	int temp, digit= 100000000;
	
	for(int i= 0; i< 9 ; i++){
		temp+= puzzle[i]* digit; digit/= 10;
	}
	return temp;
}
void bfs(int index){
	while(!q.empty()){
		int temp= q.front(); q.pop();
		if( check( temp ) == true ) {return;}
		regist(temp);
		
		if( answercheck() == true ) {
			myvec.push_back(result);
			return;
		}

		if(index-1 >= 0){
			swap(index, index-1);
			result++;
			bfs(index-1);
			swap(index, index-1);
			result--;
		}
		if(index+1 < 3){
			swap(index, index+1);
			result++;
			bfs(index+1);
			swap(index, index+1);
			result--;
		}
		if(index-3 >= 0){
			swap(index, index-3);
			result++;
			bfs(index-3);
			swap(index, index-3);
			result--;
		}
		if(index+3 < 9){
			swap(index, index+3);
			result++;
			bfs(index+3);
			swap(index, index+3);
			result--;
		}
		else return;
	}
}
void answerinit(){
	answer[0]= 1; answer[1]= 2; answer[2]= 3;
	answer[3]= 4; answer[4]= 5; answer[5]= 6;
	answer[6]= 7; answer[7]= 8; answer[8]= 0;	
}
int main(){
	freopen("input.txt", "r", stdin);
	int index;
	for(int i=0; i<9 ; i++){
		scanf("%d", &puzzle[i]);
		if(!puzzle[i])
			index= i;
	}
	answerinit();
	int temp= convert();
	q.push(temp);
	bfs(index);
	int mini= 99999;;
	if( !myvec.empty() )	printf("-1");
	else{
		for( auto itr= myvec.begin(); itr!= myvec.end(); itr++ ){
			mini= min(mini, *itr);
		}
	}
	printf("%d", mini);
	return 0;
}