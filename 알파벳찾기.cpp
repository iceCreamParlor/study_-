#include <stdio.h>
using namespace std;
char alphabet[26];bool check[26];
int index= -1;
int main()
{
	freopen("input.txt", "r", stdin);
	char c; 
	for(int i=0; i<26; i++)
		alphabet[i]= -1;
	while( scanf("%c", &c) != EOF){
		index++;
		if(!check[c-97]){
			alphabet[c-97]= index;
			check[c-97]= 1;
		}
	}
	for(int i=0; i<26; i++)
		printf("%d ", alphabet[i]);
	return 0;
}
