#pragma once
#include <utility>

//int Ÿ�Ը� ����Ѵٰ� ����. ���������� ���ø��� ����Ͽ� � Ÿ���̴� ��밡���ϴ�.
class MyVector
{
public:
    // �⺻ ������
    MyVector() = default;

    // count��ŭ ������ �Ҵ�� ������
    explicit MyVector(size_t count)
        : _container(new int[count]), _size(count), _capacity(count)
    { 
        for (size_t i = 0; i < count; i++)
        {
            _container[i] = 0;
        }
    }

    // ���� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector(const MyVector& other)
        : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other[i];
        }
    }

    // �Ҵ� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
    MyVector& operator=(MyVector rhs)
    {
        std::swap(_container, rhs._container);
        std::swap(_size, rhs._size);
        std::swap(_capacity, rhs._capacity);

        return *this;
    }

    // �Ҹ���
    ~MyVector()
    {
        clear();
    }



    // ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�. (��� �����̳ʰ� ��� ���� ����)
    int* begin()
    {
        //���Ͱ� ��� �ִٸ� end() ��ȯ
        if (empty())
        {
            return end();
        }

        //���Ͱ� ������� �ʴٸ� ù��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        return _container; //ù��° ����
    }
    const int* begin() const
    {
        //���Ͱ� ��� �ִٸ� end() ��ȯ
        if (empty())
        {
            return end();
        }

        //���Ͱ� ������� �ʴٸ� ù��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        return _container; //ù��° ����
    }

    // ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        //end�� �������� ���� ����! �������� ��������
        //_container: �����̳��� �ּ�
        //_size: ���� ���� �ִ� ������ ����
        //_capacity: �ִ� ����
    int* end() { return _container + _size; }
    const int* end() const { return _container + _size; }

    // �����̳ʰ� ������� �˻��Ѵ�.
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

    // ������ ������ ��ȯ�Ѵ�.
    size_t size() const { return _size; }

    // ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.
    size_t capacity() const { return _capacity; }

    //��ŵ
    // pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�. ���� pos�� �������� ����� std::out_of_range ���ܰ� ��������.
    int& at(size_t pos);
    const int& at(size_t pos) const;

    // pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�. pos�� container�� ũ�⸦ ����� ���� ���� ó�� ���� �ʴ´�.
    int& operator[](size_t pos) { return _container[pos]; }
    const int& operator[](size_t pos) const { return _container[pos]; }

    // �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�. (�� ������ �� ȣ���ϸ� ���� ���. �츮�� ������ �ʿ� ����.) 
    int& front() { return *begin(); } //begin�� ������ ����
    const int& front() const { return *begin(); }

    // �����̳��� ������ ������ ������ ��ȯ�Ѵ�. (�� ������ �� ȣ���ϸ� ���� ���. �츮�� ������ �ʿ� ����.) 
    int& back() { return *(end() - 1); }
    const int& back() const { return *(end() - 1); }

    // �����̳ʸ� ����. (�޸� ����, _size, _capacity 0���� �ʱ�ȭ)
    void clear()
    {
        //�޸� ����
        delete[] _container;
        _container = nullptr;

        //���� �ʱ�ȭ
        _size = 0;
        _capacity = 0;
    }

    // pos ���� ��ġ�� value�� �����Ѵ�.
    // value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�.
    // pos�� �ݺ��ڿ� ���ؼ� ȣ���
    // �ݺ��ڸ� ��ȯ
    int* insert(int* pos, int value)
    {
        // 1. �󸶳� ������ �ִ���(�Űܾ� �ϴ���)�� �˾ƾ� �Ѵ�.
        int dist = pos - begin(); //ù ���ҷκ��� �󸶳� �������ִ���
        //dist�� �����ٸ�, ���� �뷮 Ȯ�� �� �������� �� �� ����.
        // ��ȿ�� �޸𸮸� ����ų �� �ֵ��� �ϱ� ����

        // 2. �뷮�� Ȯ���Ѵ�.
        if (_capacity == 0) //�������
        {
            reserve(1); //���⿡�� begin�� ��ȿȭ�ȴ�. �ٽ� ��ġ �˱�
            
            pos = begin() + dist; //�־�� �ϴ� ��ġ �ٽ� ����
        }
        else if (_size == _capacity) //���� ��
        {
            reserve(_capacity * 2);

            pos = begin() + dist; //�־�� �ϴ� ��ġ �ٽ� ����
        }

        // 3. ����
        for (int* iter = end(); iter != pos; iter--)
        {
            *iter = *(iter - 1);
        }

        *pos = value; //������ �߰�

        _size++; //���� ���� ����

        return pos; 
    }

    // pos�� ��ġ�� ���Ҹ� �����.
    // ������ ����� ���� �����͸� ��ȯ�Ѵ�.
    int* erase(int* pos)
    {
        //1. ���� ó��
        //��� �ִٸ�
        if (_size == 0)
        {
            return end();
        }

        // 2. ����
        int* last = end() - 1;
        for (int* iter = pos; iter != last; iter++)
        {
            *iter = *(iter + 1);
        }
        
        //�ʵ� ������Ʈ
        _size--;

        return pos;
    }

    // �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
    void push_back(int value)
    {
        //������ �տ� �־�� �ϴϱ�
        insert(end(), value);
    }

    // �����̳��� ������ ���Ҹ� �����Ѵ�.
    void pop_back() { erase(end() - 1); }

    // value�� �����ϴ��� �˻��Ѵ�. (������ ������ ����)
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

    // �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
    // newCapacity > _capacity��� ���ο� �޸𸮸� �Ҵ��ϰ�,
    // �׷��� �ʴٸ� �ƹ� ���۵� �������� �ʴ´�.
    // ������ ������� �ø��� �ʴ´�(_size)
    // # ����
    // vecotr v = {1,2,3,4,5};
    //  >> size = 5, capacity = 5
    // 
    // int* iter = v.begin();
    // 
    // v.reserve(10); //�Ҵ� �Ͼ
    // >> ���ο� ������ �Ҵ�, ���� �޸𸮿� �ִ� �����͸� �Űܿ´�.
    // 
    // >> ���� �޸𸮸� ����Ű�� ����
    // *iter = 20; //�� ����(�� �޸𸮴� ���̻� ��ȿ���� �ʴ´�) >> ��ȿȭ!
    //
    void reserve(size_t newCapacity)
    {
        //newCapacity�� _capacity ���� �� ū��
        if (_capacity >= newCapacity)
        {
            return;
        }

        //���ο� �Ҵ�
        int* newContainer = new int[newCapacity];

        //����
        for (size_t i = 0; i < _size; i++)
        {
            newContainer[i] = _container[i];
        }
        
        //���� �޸� ����
        delete[] _container;

        //���Ӱ� ������ ���� �Ҵ�
        _container = newContainer;
        _capacity = newCapacity;
    }
private:
    int*                _container = nullptr; //���� �Ҵ��� ���� ������
    size_t              _size = 0;      //���� ����
    size_t              _capacity = 0;  //���� ũ��(���� �� �ִ� �ִ� ���� ����)
};

