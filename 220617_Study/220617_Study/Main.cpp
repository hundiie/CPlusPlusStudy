#include <iostream>
#include <iomanip>
#include <string> // std::string을 쓰고 싶다면 이 헤더를 포함해야 한다.
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

// 출력을 재정의 하고 싶다면 아래와 비슷한 선언을 하면 된다.
std::ostream& operator<<(std::ostream& oss, const TEST& a)
{
    return oss << "My Data : " << a.GetData();
}

// 입력을 재정의 하고 싶다면 아래와 비슷한 선언을 하면 된다.
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
    string a[size2] = { "김재성","용준헌","이다훈","이세나" };
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