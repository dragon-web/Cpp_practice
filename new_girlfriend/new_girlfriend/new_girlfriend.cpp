#include"common.h"

/*class Person
{
private:
	string name;
	short age;
public:
	void eat();
	void habit();
};
class Girl:public Person
{
private:
	string 
}


float f(float x, float y, float z) {
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
	for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

int main() {
	cout << "骚年，想要个对象吗" << endl;
	string mind;
	string true_mind("Yes");
	cin >> mind;
	if (mind == true_mind)
	{
		cout << "很好，我们来创建个对象吧" << endl;
		cout << "输入你梦想中对象的名字（没有就写苍老师）" << endl;














		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
		_TCHAR buffer[25][80] = { _T(' ') };
		_TCHAR ramp[] = _T(".:-=+*#%@");
		int count = 0;
		int count1 = 0;
		//system("color F4");
		for (float t = 0.0f;; t += 0.1f) {
			int sy = 0;
			float s = sinf(t);
			float a = s * s * s * s * 0.2f;

			for (float z = 1.3f; z > -1.2f; z -= 0.1f) {
				_TCHAR* p = &buffer[sy++][0];
				float tz = z * (1.2f - a);
				for (float x = -1.5f; x < 1.5f; x += 0.05f) {
					float tx = x * (1.2f + a);
					float v = f(tx, 0.0f, tz);
					if (v <= 0.0f) {
						float y0 = h(tx, tz);
						float ny = 0.01f;
						float nx = h(tx + ny, tz) - y0;
						float nz = h(tx, tz + ny) - y0;
						float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
						float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
						*p++ = ramp[(int)(d * 5.0f)];
					}
					else
						*p++ = ' ';
				}
			}

			for (sy = 0; sy < 25; sy++) {
				COORD coord = { 0, sy };
				SetConsoleCursorPosition(o, coord);
				WriteConsole(o, buffer[sy], 79, NULL, 0);
			}
			if (count <= 10) {
				printf("I Love You ———.Mua~\n");//表白内容 
				printf("            By flf");// 表白者的名字 
				count++;
			}
			else {
				printf("You Are My Best Lover.\n");
				printf("           future`");
				count++;
				if (count >= 20) {
					count = 0;
				}
			}
			Sleep(33);
		}
	}
}*/



string a;
int main() {
	int k;
	cin >> k >> a;
	//第一阶段（横）
	for (int j = 0; j < a.size(); j++) {
		if (a[j] == '1' || a[j] == '4') {
			cout << " ";
			for (int h = 1; h <= k; h++) {
				cout << " ";
			}
			cout << "  ";
		}
		else {
			cout << " ";
			for (int h = 1; h <= k; h++) {
				cout << "-";
			}
			cout << "  ";
		}
	}
	cout << endl;
	//第二阶段（竖）
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '1' || a[j] == '2' || a[j] == '3' || a[j] == '7') {
				cout << " ";
				for (int h = 1; h <= k; h++) {
					cout << " ";
				}
				cout << "| ";
			}
			else if (a[j] == '0' || a[j] == '4' || a[j] == '8' || a[j] == '9') {
				cout << "|";
				for (int h = 1; h <= k; h++) {
					cout << " ";
				}
				cout << "| ";
			}
			else {
				cout << "|";
				for (int h = 1; h <= k; h++) {
					cout << " ";
				}
				cout << "  ";
			}
		}
		cout << endl;
	}
	//第三阶段 （横）
	for (int j = 0; j < a.size(); j++) {
		if (a[j] == '0' || a[j] == '1' || a[j] == '7') {
			cout << " ";
			for (int h = 1; h <= k; h++) {
				cout << " ";
			}
			cout << "  ";
		}
		else {
			cout << " ";
			for (int h = 1; h <= k; h++) {
				cout << "-";
			}
			cout << "  ";
		}
	}
	cout << endl;
	//第四阶段（竖）
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '1' || a[j] == '3' || a[j] == '4' || a[j] == '5' || a[j] == '7' || a[j] == '9') {
				cout << " ";
				for (int h = 1; h <= k; h++) {
					cout << " ";
				}
				cout << "| ";
			}
			else if (a[j] == '0' || a[j] == '6' || a[j] == '8') {
				cout << "|";
				for (int h = 1; h <= k; h++) {
					cout << " ";
				}
				cout << "| ";
			}
			else {
				cout << "|";
				for (int h = 1; h <= k; h++) {
					cout << " ";
				}
				cout << "  ";
			}
		}
		cout << endl;
	}
	//第五阶段（横）
	for (int j = 0; j < a.size(); j++) {
		if (a[j] == '1' || a[j] == '4' || a[j] == '7') {
			cout << " ";
			for (int h = 1; h <= k; h++) {
				cout << " ";
			}
			cout << "  ";
		}
		else {
			cout << " ";
			for (int h = 1; h <= k; h++) {
				cout << "-";
			}
			cout << "  ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
