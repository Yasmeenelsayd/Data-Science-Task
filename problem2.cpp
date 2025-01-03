#include <iostream>
#include<string>

using namespace std;
int main()
{
	string x;
	cin >> x;

	int l = x.length();
	for (int i = 0; i < l; i++)
	{
		int digit = x[i] - '0';

		if (9 - digit < digit)
		{
			if (i == 0 && 9 - digit == 0)
				continue;
			x[i] = (9 - digit) + '0';
		}
	}
	cout << x << endl;
}
