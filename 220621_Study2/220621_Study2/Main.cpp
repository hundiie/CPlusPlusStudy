#include <iostream>
#include <list>
#include <forward_list>
#include <vector>

using namespace std;

int main()
{
	list<char> str;
	string c;
	cin >> c;

	for (int i = 0; i < c.size(); i++)
	{
		str.push_back(c[i]);
	}

	list<char>::iterator iter;
	iter = str.end();
	
	int cas;
	cin >>cas;
	
	for (int i = 0; i < cas; i++)
	{
		char n1;
		cin >> n1;

		switch (n1)
		{
		case 'L':
		{
			if (iter != str.begin())
			{
				--iter;
			}
		}
			break;
		case 'D':
		{
			if (iter != str.end())
			{
				++iter;
			}
		}
			break;
		case 'B':
		{
			if (iter != str.end())
			{
				--iter;
				str.erase(iter);
			}
		}
			break;
		case 'P':
		{
			char chr;
			cin >>chr;
			
			str.insert(iter, chr);
		}
			break;
		default:
			break;
		}
	}

	for (char i : str) {
		std::cout << i << " ";
	}
	std::cout << '\n';



	



}