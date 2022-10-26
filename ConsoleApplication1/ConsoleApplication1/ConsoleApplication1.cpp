
// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	collection;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string p;
		int n;
		string value;
		bool isreverse = false;
		bool errorcheck = false;
		deque<string>  x;
		cin >> p;
		cin >> n;
		cin >> value;
		value = value.erase(0, 1);
		value += ',';
		value = value.erase(value.size() - 2, 1);
		int splitlen = 0;
		if (n > 0)
		{
			for (int j = 0; j < value.size(); j++)
			{
				if (value[j] == ',' || value[j] == '\n')
				{
					x.push_back(value.substr(splitlen, j-splitlen));
					splitlen = j + 1;
				}
			}
		}
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] == 'R')
			{
				isreverse = !isreverse;
			}
			else if (p[j] == 'D')
			{
				if (x.size() > 0)
				{
					if (isreverse)
					{
						x.pop_back();
					}
					else
					{
						x.pop_front();
					}
				}
				else
				{
					cout << "error" << '\n';
					errorcheck = true;
					break;
				}
			}
		}
		if (!errorcheck)
		{
			string answer;
			while (x.size() > 0)
			{
				if (isreverse)
				{
					answer+= x.back();
					x.pop_back();
				}
				else
				{
					answer += x.front();
					x.pop_front();
				}
				if (x.size() > 0)
				{
					answer += ',';
				}
			}
			cout << '[' <<answer<< ']' << '\n';
		}
	}
}
