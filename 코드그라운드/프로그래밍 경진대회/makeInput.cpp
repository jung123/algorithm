#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	freopen("test.txt","w",stdout);
	int i,j,k;
	srand( (unsigned)time(NULL) );
	int n=0;
	int tc =5;
	printf("%d\n",tc);
	
	for(i=1;i<=tc;i++){
		n = rand() % 300000;
		printf("%d\n",n);
		for(j=0;j<n;j++){
			printf("%d\n",rand() % n);
		}
	}
	return 0;
}
