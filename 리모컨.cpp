#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

vector<int> myvec, mych;
int result;

bool possible(int ch){  //ch ä�η� �̵��� �� �ִ��� üũ�� �ִ� �Լ�
	vector<int> mytemp;
	if(ch==0){
		for( int j=0; j< myvec.size(); j++ )
			if(myvec[j] == 0) return false;
		
		return true;
	}
	while( ch> 0 ){
		int resid= ch% 10;
		mytemp.push_back(resid);
		ch /= 10;
	}
	for( int i= 0; i< mytemp.size(); i++ )
		for( int j=0; j< myvec.size(); j++ )
			if( mytemp[i] == myvec[j] ) return false;

	return true;
}
int digit(int ch){  //ch ä���� �� �ڸ� ������ üũ�� �ִ� �Լ�
 	int mydigit=0;
	if(ch ==0 ) return 1;
	while( ch> 0 ){
		ch /= 10; mydigit++;
	}
	return mydigit;
}
void compute(int ch){  //����� ä�η� �̵��ؼ� ���� ���� ������? -/ +��ư�� �̿��ϴ� ���� ������?
	result = abs(ch- 100);
	for( int i= 0; i<= MAX; i++ )
		if( possible(i) )
			result = min( result, abs(ch- i )+ digit(i) );
}
int main()
{
	freopen("input.txt","r", stdin);
	int ch; scanf("%d", &ch);
	int num; scanf("%d", &num);
	for(int i=0 ; i< num; i++){
		int temp; scanf("%d", &temp);
		myvec.push_back(temp);
	}
	int temp= ch;
	while( temp> 0 ){
		int resid= temp% 10;
		mych.push_back(resid);
		temp /= 10;
	}
	compute(ch);
	printf("%d", result);
	return 0;
}
