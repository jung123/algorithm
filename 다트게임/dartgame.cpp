// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
class dart_game{
	public :
		// ������ �� �Ҹ���
		dart_game();
		~dart_game();
		// ������
		void set_a(double _a);
		void set_b(double _b);
		void set_c(double _c);
		void set_d(double _d);
		void set_e(double _e);
		void set_var(double a,double b, double c, double d, double e);
		void set_xy(const double x,const double y);
		void init_var();
		// ����Լ�
		long long get_res();
		void calc_score();
		void calc_res(const int score);
	private :
		// ����
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
	// length����Ʈ ������ ��� ���
	if(length > e) return;
	// triple or double ���ϱ�.
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
	// 1,2,3,4 �и� ���ϱ� 
	quad[0] = (x > 0) ? 1:0;
	quad[1] = (y > 0) ? 1:0;
	// ���� ���ϱ� 
	// 1��и� 
	if((quad[0] == 1)&&(quad[1] == 1)){
		if((angle >= 0)&&(angle < 9)) score = 6;
		else if((angle > 9)&&(angle < 27)) score = 13;
		else if((angle > 27)&&(angle < 45)) score =4;
		else if((angle > 45)&&(angle < 63)) score =18;
		else if((angle > 63)&&(angle < 81)) score =1;
		else if((angle > 81)&&(angle <= 90)) score =20;
	}
	// 2��и� 
	if((quad[0] == 0)&&(quad[1] == 1)){
		if((angle >= 0)&&(angle < 9)) score = 11;
		else if((angle > 9)&&(angle < 27)) score =14;
		else if((angle > 27)&&(angle < 45)) score =9;
		else if((angle > 45)&&(angle < 63)) score =12;
		else if((angle > 63)&&(angle < 81)) score =5;
		else if((angle > 81)&&(angle <= 90)) score =20;
	}
	// 3��и� 
	if((quad[0] == 0)&&(quad[1] == 0)){
		if((angle >= 0)&&(angle < 9)) score = 11;
		else if((angle > 9)&&(angle < 27)) score =8;
		else if((angle > 27)&&(angle < 45)) score =16;
		else if((angle > 45)&&(angle < 63)) score =7;
		else if((angle > 63)&&(angle < 81)) score =19;
		else if((angle > 81)&&(angle <= 90)) score =3;
	}
	// 4��и� 
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
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	double a,b,c,d,e; // ������ 
	int n;	// test case�� ����� ��Ʈ�� ����� 
    int i;
    double x,y;
    long long res;
	int score; 
    dart_game mydart;
	scanf("%d", &TC);	// cin ��� ����
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		// ������ ������ �ޱ�
		
		cin >> a >> b >> c >> d >> e;
		try{
			mydart.set_var(a,b,c,d,e);
		}
		catch(int n){
			if(n == 1){
				cout << "�߸��� �Է°��Դϴ�.\n";
				//exit(1);
			}
		}
		// ���� �ް� ��Ʈ�� ��ǥ�ޱ� 
        cin >> n;
        for(i=0;i<n;i++){
        	cin >> x >> y;
        	mydart.set_xy(x,y);
        	// ���� �뿪 ���ϱ�.
			mydart.calc_score();
		}
        res = mydart.get_res();
        
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
        cout << res << "\n";
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
