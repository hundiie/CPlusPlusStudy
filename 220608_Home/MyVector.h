#pragma once
#include <utility>

//int 타입만 사용한다고 가정. 살제에서는 템플릿을 사용하여 어떤 타입이던 사용가능하다.
class MyVector
{
public:
    // 기본 생성자
    MyVector() = default;

    // count만큼 공간이 할당된 생성자
    explicit MyVector(size_t count)
        : _container(new int[count]), _size(count), _capacity(count)
    { 
        for (size_t i = 0; i < count; i++)
        {
            _container[i] = 0;
        }
    }

    // 복사 생성자. 깊은 복사(deep copy)가 이뤄져야 한다.
    MyVector(const MyVector& other)
        : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other[i];
        }
    }

    // 할당 연산자. 깊은 복사(deep copy)가 이뤄져야 한다.
    MyVector& operator=(MyVector rhs)
    {
        std::swap(_container, rhs._container);
        std::swap(_size, rhs._size);
        std::swap(_capacity, rhs._capacity);

        return *this;
    }

    // 소멸자
    ~MyVector()
    {
        clear();
    }



    // 첫 번째 요소를 가리키는 반복자를 반환한다. (모든 컨테이너가 모두 갖고 있음)
    int* begin()
    {
        //벡터가 비어 있다면 end() 반환
        if (empty())
        {
            return end();
        }

        //벡터가 비어있지 않다면 첫번째 원소를 가리키는 반복자를 반환한다.
        return _container; //첫번째 원소
    }
    const int* begin() const
    {
        //벡터가 비어 있다면 end() 반환
        if (empty())
        {
            return end();
        }

        //벡터가 비어있지 않다면 첫번째 원소를 가리키는 반복자를 반환한다.
        return _container; //첫번째 원소
    }

    // 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다.
        //end의 역참조는 하지 말랑! 말랑말랑 몰랑몰랑
        //_container: 컨테이너의 주소
        //_size: 현재 갖고 있는 원소의 개수
        //_capacity: 최대 갯수
    int* end() { return _container + _size; }
    const int* end() const { return _container + _size; }

    // 컨테이너가 비었는지 검사한다.
    bool empty() const
    {
        if (_size == 0)
        {
            return true;
        }
        //if (begin() == end())
        //{
        //    return true;
        //}

        return false;
    }

    // 원소의 개수를 반환한다.
    size_t size() const { return _size; }

    // 현재 할당된 공간의 크기를 반환한다.
    size_t capacity() const { return _capacity; }

    //스킵
    // pos에 위치한 원소의 참조를 반환한다. 만약 pos가 범위에서 벗어나면 std::out_of_range 예외가 던져진다.
    int& at(size_t pos);
    const int& at(size_t pos) const;

    // pos에 위치한 원소의 참조를 반환한다. pos가 container의 크기를 벗어나도 따로 예외 처리 하지 않는다.
    int& operator[](size_t pos) { return _container[pos]; }
    const int& operator[](size_t pos) const { return _container[pos]; }

    // 컨테이너의 첫 번째 원소의 참조를 반환한다. (빈 벡터일 때 호출하면 오류 뜬다. 우리가 생각할 필요 없다.) 
    int& front() { return *begin(); } //begin의 역참조 값임
    const int& front() const { return *begin(); }

    // 컨테이너의 마지막 원소의 참조를 반환한다. (빈 벡터일 때 호출하면 오류 뜬다. 우리가 생각할 필요 없다.) 
    int& back() { return *(end() - 1); }
    const int& back() const { return *(end() - 1); }

    // 컨테이너를 비운다. (메모리 해제, _size, _capacity 0으로 초기화)
    void clear()
    {
        //메모리 해제
        delete[] _container;
        _container = nullptr;

        //변수 초기화
        _size = 0;
        _capacity = 0;
    }

    // pos 이전 위치에 value를 삽입한다.
    // value가 삽입된 곳을 가리키는 포인터를 반환한다.
    // pos는 반복자에 의해서 호출됨
    // 반복자를 반환
    int* insert(int* pos, int value)
    {
        // 1. 얼마나 떨어져 있는지(옮겨야 하는지)를 알아야 한다.
        int dist = pos - begin(); //첫 원소로부터 얼마나 떨어져있는지
        //dist가 없었다면, 이후 용량 확인 후 재조정을 할 수 없다.
        // 유효한 메모리를 가리킬 수 있도록 하기 위해

        // 2. 용량을 확인한다.
        if (_capacity == 0) //비어있음
        {
            reserve(1); //여기에서 begin이 무효화된다. 다시 위치 알기
            
            pos = begin() + dist; //넣어야 하는 위치 다시 설정
        }
        else if (_size == _capacity) //가득 참
        {
            reserve(_capacity * 2);

            pos = begin() + dist; //넣어야 하는 위치 다시 설정
        }

        // 3. 삽입
        for (int* iter = end(); iter != pos; iter--)
        {
            *iter = *(iter - 1);
        }

        *pos = value; //데이터 추가

        _size++; //원소 갯수 증가

        return pos; 
    }

    // pos에 위치한 원소를 지운다.
    // 삭제된 요소의 다음 포인터를 반환한다.
    int* erase(int* pos)
    {
        //1. 예외 처리
        //비어 있다면
        if (_size == 0)
        {
            return end();
        }

        // 2. 삭제
        int* last = end() - 1;
        for (int* iter = pos; iter != last; iter++)
        {
            *iter = *(iter + 1);
        }
        
        //필드 업데이트
        _size--;

        return pos;
    }

    // 컨테이너의 맨 끝에 원소를 추가한다.
    void push_back(int value)
    {
        //마지막 앞에 넣어야 하니까
        insert(end(), value);
    }

    // 컨테이너의 마지막 원소를 삭제한다.
    void pop_back() { erase(end() - 1); }

    // value가 존재하는지 검사한다. (실제로 있지는 않음)
    bool contains(int value)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (*(_container + i) == value)
            {
                return true;
            }
        }

        return false;
    }

    // 컨테이너의 용량을 newCapacity보다 같거나 크게 늘린다.
    // newCapacity > _capacity라면 새로운 메모리를 할당하고,
    // 그렇지 않다면 아무 동작도 수행하지 않는다.
    // 벡터의 사이즈는 늘리지 않는다(_size)
    // # 예시
    // vecotr v = {1,2,3,4,5};
    //  >> size = 5, capacity = 5
    // 
    // int* iter = v.begin();
    // 
    // v.reserve(10); //할당 일어남
    // >> 새로운 공간을 할당, 이전 메모리에 있던 데이터를 옮겨온다.
    // 
    // >> 이전 메모리를 가리키고 있음
    // *iter = 20; //논리 오류(이 메모리는 더이상 유효하지 않는다) >> 무효화!
    //
    void reserve(size_t newCapacity)
    {
        //newCapacity가 _capacity 보다 더 큰지
        if (_capacity >= newCapacity)
        {
            return;
        }

        //새로운 할당
        int* newContainer = new int[newCapacity];

        //복사
        for (size_t i = 0; i < _size; i++)
        {
            newContainer[i] = _container[i];
        }
        
        //기존 메모리 삭제
        delete[] _container;

        //새롭게 생성한 공간 할당
        _container = newContainer;
        _capacity = newCapacity;
    }
private:
    int*                _container = nullptr; //동적 할당을 위한 포인터
    size_t              _size = 0;      //원소 갯수
    size_t              _capacity = 0;  //벡터 크기(가질 수 있는 최대 원소 갯수)
};

