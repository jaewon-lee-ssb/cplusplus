//#include <iostream>
//#include <random>
//#include <fstream>
//#include <algorithm>
//#include <iomanip>
//
//using namespace std;
//
//int main()
//{
// ifstream in{ "정수 1억개.txt" };
// int* p = new int[100'000'000];
// int num;
// int cnt{ };
// cout << "읽어오는 중";
// while (in >> num)
// {
// p[cnt++] = num;
// if (!(cnt % 1'000'000))
// cout << ".";
// }
// cout << endl;
//
// cnt = 0;
// cout << "정렬하는 중";
// sort( p, p+100'000'000, [&cnt](int a, int b) {
// if (!(++cnt % 1'000'000))
// cout << ".";
// return a < b;
// });
// cout << endl;
// cout << cnt << endl;
//
// for (int i = 0; i < 1'000; ++i)
// cout << setw(20) << p[100'000'000 - 1 - 1000 + i];
//}


#include <iostream>
#include <string>
#include <random>
#include <math.h>
using namespace std;

mt19937 dre;
uniform_int_distribution<> uid{ 0, 100 };

class Balloon {
private:
	float x;
	float y;

public:
	Balloon() {
		x = uid(dre);
		y = uid(dre);
	}
	virtual ~Balloon() {}

	void Print() const {
		cout << "X좌표: " << x << ", Y좌표: " << y << endl;
	}

	bool Check(const char x, const char y) const {
		if (sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y)) <= 20)
			return true;
		return false;
	}
};

//[문제] 풍선 100개를 생성한다.
// 풍선의 x, y값을 [0, 100] 사이의 랜덤값으로 설정한다.
// 위치 (50, 50)에서 반경 20의 영향을 미치는 폭탄이 터졌다.
// 폭탄의 영향권에 있는 풍선의 정보를 출력하라
// 풍선(x,y)
// 전체 영향받은 풍선의 개수를 출력하라

int main()
{
	const char x = 50;
	const char y = 50;
	Balloon balloons[100];

	int count = 0;

	for (const auto& balloon : balloons)
		if (balloon.Check(x, y))
			++count;

	cout << "영향을 받은 풍선의 갯수: " << count << endl;
}