#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;
// 이걸 구조체로 만들어서 처리하자 !! 
class Rectangle{
	public :
		unsigned long long area;
		int blx, bly, urx, ury;
		vector<int> include_Rectable;
		
		void init(int _blx, int _bly, int _urx, int _ury,unsigned long long _area);
};

int pointing[5000];
Rectangle RectangleArray[5000];
int Rectangle_sort(const void *arg1, const void *arg2);
int res;
int get_res(int i, int k);

int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
    
    int n,m,k,i,tmp;
    unsigned long long temp_area = 0;
    int blx, bly, urx, ury;
	scanf("%d\n", &T);	
	for(test_case = 1; test_case <= T; test_case++) {
		res = 0; 
		scanf("%d %d %d\n",&n,&m,&k);
		for(i=0;i<k;i++){
			scanf("%d %d %d %d\n",&blx,&bly,&urx,&ury);
			RectangleArray[i].init(blx,bly,urx,ury,(urx-blx)*(ury-bly));
			pointing[i] = 5001;
		}
		//
		qsort(RectangleArray,k,sizeof(Rectangle),Rectangle_sort);
		// 여기까지 넓이를 통해 정렬을 한 상태이다 !!!
		// 여기의 로직을 다시 손봐야한다. 여기서 시간복잡도가n^2가 많아진다 !!
		for(i=0;i<k;i++){
			for(tmp=i+1;tmp<k;tmp++){
				// 포함되는지 확인한다. !!
				if((RectangleArray[tmp].blx > RectangleArray[i].blx) 
					&& (RectangleArray[tmp].urx < RectangleArray[i].urx)
					&& (RectangleArray[tmp].bly > RectangleArray[i].bly)
					&& (RectangleArray[tmp].ury < RectangleArray[i].ury))
				{
					pointing[tmp] = i;
					RectangleArray[i].include_Rectable.push_back(tmp);
				}
			}
		}
		// 여기에서 포함관계를 확인한다. !! 
		for(i=0;i<k;i++){
			if(pointing[i] != 5001) continue;
			tmp = get_res(i,k);
			if(tmp > res) res = tmp;
		}
		printf("Case #%d\n", test_case);
        printf("%d\n",res);
	}

	return 0;
}

void Rectangle::init(int _blx, int _bly, int _urx, int _ury,unsigned long long _area){
	blx = _blx;
	bly = _bly;
	urx = _urx;
	ury = _ury;
	area = _area;
	include_Rectable.clear();
}

int Rectangle_sort(const void *arg1, const void *arg2){
	if( (*(Rectangle *)arg1).area > (*(Rectangle *)arg2).area ) return -1;
	else if( (*(Rectangle *)arg1).area == (*(Rectangle *)arg2).area ) return 0;
	else return 1;
}

int get_res(int i, int k){
	int tmp, tmp1;
	vector<int>::iterator ivec;
	tmp = 1;
	for(ivec = RectangleArray[i].include_Rectable.begin(); ivec != RectangleArray[i].include_Rectable.end(); ivec++)
	{
		tmp1 = 1;
		if(pointing[*ivec] == i){
			tmp1 += get_res(*ivec,k);
			if(tmp1 > tmp) tmp = tmp1;
		}		
	}
	return tmp;
}
