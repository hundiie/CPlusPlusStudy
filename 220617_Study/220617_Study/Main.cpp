#include <iostream>
#include <iomanip>
#include <string> // std::string�� ���� �ʹٸ� �� ����� �����ؾ� �Ѵ�.
#include <string_view>

class TEST
{
public:
    explicit TEST(int data) : _data(data) { }
    int GetData() const
    {
        return _data; 
    }

    void SetData(int data) { _data = data; }
private:
    int _data = 0;
};

// ����� ������ �ϰ� �ʹٸ� �Ʒ��� ����� ������ �ϸ� �ȴ�.
std::ostream& operator<<(std::ostream& oss, const TEST& a)
{
    return oss << "My Data : " << a.GetData();
}

// �Է��� ������ �ϰ� �ʹٸ� �Ʒ��� ����� ������ �ϸ� �ȴ�.
std::istream& operator>>(std::istream& iss, TEST& a)
{
    iss.ignore(sizeof("My Data : "), ':');

    int data;
    iss >> data;
    a.SetData(data);

    return iss;
}


using namespace std;
#define size 12

template <typename T>
void Print(string name, T age)
{
    cout << "|"<< setw(size) << left << name << "|" << setw(size) << right << age << "|" << "\n";
}



#define size2 4

int main()
{
    string a[size2] = { "���缺","������","�̴���","�̼���" };
    int b[size2] = {31, 28, 28, 25};


    cout << "---------------------------\n";
    Print("Name", "Age");
    cout << "---------------------------\n";
    
    for (int i = 0; i < size2; i++)
    {
        Print(a[i], b[i]);
    }
    
    cout << "---------------------------\n";

    cout << "---------------------------\n";
    Print("Name", "Age");
    cout << "---------------------------\n";

    for (int i = 0; i < size2; i++)
    {
        Print(a[i], b[i]);
    }

    cout << "---------------------------\n";


    return 0;
}