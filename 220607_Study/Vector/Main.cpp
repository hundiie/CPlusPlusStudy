#include <vector>
#include <iostream>
#include <assert.h>
#include "Vector.h"
#include "New_Vector.h"
using namespace std;

int main()
{
    MyVector v(10);
    assert(v.GetCapacity() == 10);
    assert(v.GetSize() == 0);

    v.Add(1);
    v.Add(2);
    v.Add(3);
    v.Add(4);
    assert(v.GetSize() == 4);
    v.TrimToSize();
    assert(v.GetSize() == v.GetCapacity());
    assert(nullptr == v.FindById(5));
    assert(nullptr != v.FindById(3));
    v.Add(1); v.Add(1); v.Add(1);
    v.RemoveAll(1);
    assert(nullptr == v.FindById(1));
    assert(v.GetSize() == 3);
    cout << v.ToString() << endl;
    srand(time(nullptr));
    for (int i = 0; i < 100; ++i)
    {
        v.Add(1 + rand() % 4);
    }

    int nums = 0;
    MyVector* vecs = v.GroupById(&nums);
    assert(nums == 4);
    for (int i = 0; i < nums; ++i)
    {
        cout << vecs[i].ToString() << endl;
    }

    delete[] vecs;
    
    return 0;
}

    //TEST<float, 5> arr;
    //struct TEST { T Container[N]; };
    // 컴파일러는 컴파일 타임에 T에는 float을 대입하고  N에는 5를 대입함
 
    //결과 -> struct TEST { float Container[5]; };





  /*  vector<int> vec;
    vector<int> vec2(5);
    vector<int> vec3 = { 1, 2, 3, 4, 5 };
    vec.push_back(1);
    vec.push_back(2);
    vec.pop_back();
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
    }
    cout << endl;
    vec.pop_back();
    cout << boolalpha << vec.empty() << endl;
    cout << "Cap : " << vec.capacity() << endl;
    vec.reserve(10);
    cout << "New Cap : " << vec.capacity() << endl;
    vec2.insert(vec2.begin() + 2, 3);
    for (size_t elem : vec2)
    {
        cout << elem << ' ';
    }
    cout << endl;
    vec3.erase(vec3.begin());
    for (size_t i = 0; i < vec3.size(); ++i)
    {
        cout << vec3[i] << ' ';
    }
    cout << endl;
    MyVector mvec;
    MyVector mvec2(5);
    mvec.push_back(1);
    mvec.push_back(2);
    mvec.pop_back();
    for (size_t i = 0; i < mvec.size(); ++i)
    {
        cout << mvec[i];
    }
    cout << endl;
    mvec.pop_back();
    cout << boolalpha << mvec.empty() << endl;
    cout << "Cap : " << mvec.capacity() << endl;
    mvec.reserve(10);
    cout << "New Cap : " << mvec.capacity() << endl;
    mvec2.insert(mvec2.begin() + 2, 3);
    for (int elem : mvec2)
    {
        cout << elem << ' ';
    }
    cout << endl;
    cout << boolalpha << mvec2.contains(2) << endl;
    mvec2.erase(mvec2.begin());
    for (size_t i = 0; i < mvec2.size(); ++i)
    {
        cout << vec2[i] << ' ';
    }
    cout << endl;*/

