// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
class dart_game{
	public :
		// 생성자 및 소멸자
		dart_game();
		~dart_game();
		// 접근자
		void set_a(double _a);
		void set_b(double _b);
		void set_c(double _c);
		void set_d(double _d);
		void set_e(double _e);
		void set_var(double a,double b, double c, double d, double e);
		void set_xy(const double x,const double y);
		void init_var();
		// 멤버함수
		long long get_res();
		void calc_score();
		void calc_res(const int score);
	private :
		// 변수
		int plus,score;
		double a,b,c,d,e;
		double x,y,abs_x,abs_y;
		double length;
		double angle;
		long long res;
};
dart_game::dart_game(){
	init_var();
}
dart_game::~dart_game(){
}
void dart_game::init_var(){
	a = b = c = d = e = x = y = length = angle = res = abs_x = abs_y = plus = score = 0;
}
void dart_game::set_a(double _a){
	if(_a < 1 ) throw 1;
	a = _a;
}
void dart_game::set_b(double _b){
	b = _b;
}
void dart_game::set_c(double _c){
	c = _c;
}
void dart_game::set_d(double _d){
	d = _d;
}
void dart_game::set_e(double _e){
	e = _e;
}
void dart_game::set_var(double a,double b, double c, double d, double e){
	try{
		set_a(a);	
	}
	catch(int n){
		if(n == 1) throw 1;
	}
	if(a <1 || a> b) throw 1;
	if(b > c) throw 1;
	if(c > d) throw 1;
	if(d > e) throw 1;
	if(e > 20000) throw 1;
	set_b(b);
	set_c(c);
	set_d(d);
	set_e(e);
}
void dart_game::set_xy(const double _x,const double _y){
//	if((_x > 30000)||(_x < -30000)) exit(1);
//	if((_y < -30000)||(_y > 30000)) exit(1);
	x = _x;
	y = _y;
	abs_x = (x > 0) ? x : fabs(x);
	abs_y = (y > 0) ? y : fabs(y);
	length = sqrt((abs_x*abs_x) + (abs_y*abs_y));
	angle = atan(abs_y/abs_x) * (180/M_PI);
}
long long dart_game::get_res(){
	return res;
}
void dart_game::calc_score(){
	score = plus = 0;
	int quad[2];
	// length가다트 밖으로 벗어난 경우
	if(length > e) return;
	// triple or double 정하기.
	if(length < a) {
		calc_res(50);
		return;	
	}
	else if((length > b) && (length < c)) plus = 3;
	else if((length > d) && (length < e)) plus = 2;
	else {
		plus =1;	
	}
	// x = 0 or y= 0 or x = y = 0
	if((x==0)||(y==0)){
		if(x==0){
			if(y > 0) score = 20;
			else score = 3;
		}
		if(y==0){
			if(x > 0) score = 6;
			else score = 11;
		}
		calc_res(score * plus);
		return;
	}
	// 1,2,3,4 분면 정하기 
	quad[0] = (x > 0) ? 1:0;
	quad[1] = (y > 0) ? 1:0;
	// 점수 정하기 
	// 1사분면 
	if((quad[0] == 1)&&(quad[1] == 1)){
		if((angle >= 0)&&(angle < 9)) score = 6;
		else if((angle > 9)&&(angle < 27)) score = 13;
		else if((angle > 27)&&(angle < 45)) score =4;
		else if((angle > 45)&&(angle < 63)) score =18;
		else if((angle > 63)&&(angle < 81)) score =1;
		else if((angle > 81)&&(angle <= 90)) score =20;
	}
	// 2사분면 
	if((quad[0] == 0)&&(quad[1] == 1)){
		if((angle >= 0)&&(angle < 9)) score = 11;
		else if((angle > 9)&&(angle < 27)) score =14;
		else if((angle > 27)&&(angle < 45)) score =9;
		else if((angle > 45)&&(angle < 63)) score =12;
		else if((angle > 63)&&(angle < 81)) score =5;
		else if((angle > 81)&&(angle <= 90)) score =20;
	}
	// 3사분면 
	if((quad[0] == 0)&&(quad[1] == 0)){
		if((angle >= 0)&&(angle < 9)) score = 11;
		else if((angle > 9)&&(angle < 27)) score =8;
		else if((angle > 27)&&(angle < 45)) score =16;
		else if((angle > 45)&&(angle < 63)) score =7;
		else if((angle > 63)&&(angle < 81)) score =19;
		else if((angle > 81)&&(angle <= 90)) score =3;
	}
	// 4사분면 
	if((quad[0] == 1)&&(quad[1] == 0)){
		if((angle >= 0)&&(angle < 9)) score = 6;
		else if((angle > 9)&&(angle < 27)) score =10;
		else if((angle > 27)&&(angle < 45)) score =15;
		else if((angle > 45)&&(angle < 63)) score =2;
		else if((angle > 63)&&(angle < 81)) score =17;
		else if((angle > 81)&&(angle <= 90)) score =3;
	}
	calc_res(score * plus);
}
void dart_game::calc_res(const int _score){
	res += _score;
}
int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	double a,b,c,d,e; // 반지름 
	int n;	// test case당 몇발의 다트를 쏘는지 
    int i;
    double x,y;
    long long res;
	int score; 
    dart_game mydart;
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		// 구역의 반지름 받기
		
		cin >> a >> b >> c >> d >> e;
		try{
			mydart.set_var(a,b,c,d,e);
		}
		catch(int n){
			if(n == 1){
				cout << "잘못된 입력값입니다.\n";
				//exit(1);
			}
		}
		// 갯수 받고 다트의 좌표받기 
        cin >> n;
        for(i=0;i<n;i++){
        	cin >> x >> y;
        	mydart.set_xy(x,y);
        	// 점수 대역 정하기.
			mydart.calc_score();
		}
        res = mydart.get_res();
        
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
        cout << res << "\n";
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
