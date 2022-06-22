#include <iostream>
#include <list>
#include <string>

using namespace std;
void print_container(const list<char>& c)
{
    for (char i : c)
    {
        cout << i;
    }
}

int main()
{
    list<char> _list;
    list<char>::iterator iter;
    iter = _list.begin();

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string a;
        cin >> a;
        for (int i = 0; i < a.size(); i++)
        {

            switch (a[i])
            {
            case'<':
            {
                if (iter != _list.begin())
                    iter--;
            }
            break;
            case'>':
            {
                if (iter != _list.end())
                    iter++;
            }
            break;
            case'-':
            {
                if (iter != _list.begin())
                {
                    iter--;
                    iter = _list.erase(iter);
                }
            }
            break;
            default:
                _list.insert(iter, a[i]);
                break;
            }

        }
        print_container(_list);
        cout << "\n";
        _list.clear();
        iter = _list.end();
    }
  //      _list.push_back('\n');

    return 0;
}