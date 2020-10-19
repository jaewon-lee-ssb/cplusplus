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
// ifstream in{ "���� 1�ﰳ.txt" };
// int* p = new int[100'000'000];
// int num;
// int cnt{ };
// cout << "�о���� ��";
// while (in >> num)
// {
// p[cnt++] = num;
// if (!(cnt % 1'000'000))
// cout << ".";
// }
// cout << endl;
//
// cnt = 0;
// cout << "�����ϴ� ��";
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
		cout << "X��ǥ: " << x << ", Y��ǥ: " << y << endl;
	}

	bool Check(const char x, const char y) const {
		if (sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y)) <= 20)
			return true;
		return false;
	}
};

//[����] ǳ�� 100���� �����Ѵ�.
// ǳ���� x, y���� [0, 100] ������ ���������� �����Ѵ�.
// ��ġ (50, 50)���� �ݰ� 20�� ������ ��ġ�� ��ź�� ������.
// ��ź�� ����ǿ� �ִ� ǳ���� ������ ����϶�
// ǳ��(x,y)
// ��ü ������� ǳ���� ������ ����϶�

int main()
{
	const char x = 50;
	const char y = 50;
	Balloon balloons[100];

	int count = 0;

	for (const auto& balloon : balloons)
		if (balloon.Check(x, y))
			++count;

	cout << "������ ���� ǳ���� ����: " << count << endl;
}