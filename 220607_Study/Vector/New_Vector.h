#pragma once

//-------------------------------------------------------------------------------------------------
// ���� (vector) Ŭ���� �����ϱ�
//
// �� header ���Ͽ�����, ���� �Ի��������� ����������, ������ ���͸� �����ϱ� ����,
// MyVector ��� Ŭ������ �����ϰ� �ֽ��ϴ�.
//
// �ҽ��� �ּ��� �����Ͽ�, �ʿ��� ��ɵ��� �����Ͽ�,
// MyVector.h ���ϰ� MyVector.cpp, 2���� ������ �������ֽø� �˴ϴ�.
// (�����Ͻô� ���ϵ��� ���ڵ��� utf-8 �� �����ֽø� �����ϰڽ��ϴ�.)
//
// ����: std::vector �� ����, �̹� ������ ���͸� ���δ½����� �������� ���ð�,
//    ���� �ڽ��� �ڵ�� ����� ���� ��Ź�帳�ϴ�.
//
// ����: ����� �ۼ��� �κ��� ���� �Ϳ� ���� ������ �帮�ڸ�,
//    ���� �Ƿ��� �߿��ϰ� ����ٱ� ���ٴ�, �����⸦ ������ ���� �ѱ� ������ ã��,
//    ��� �ؼ��� ������ ������, ����/�н��ϴ� �ɷ��� �߿��ϱ� �����Դϴ�.
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
// ���Ͷ�? (http://www.cplusplus.com/reference/vector/vector/)
//
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements,
// which means that their elements can also be accessed using offsets on regular pointers
// to its elements, and just as efficiently as in arrays. But unlike arrays,
// their size can change dynamically, with their storage being handled automatically
// by the container.
//
// Internally, vectors use a dynamically allocated array to store their elements.
// This array may need to be reallocated in order to grow in size when new elements are inserted,
// which implies allocating a new array and moving all elements to it.
// This is a relatively expensive task in terms of processing time, and thus,
// vectors do not reallocate each time an element is added to the container.
//
// Instead, vector containers may allocate some extra storage to accommodate for possible growth,
// and thus the container may have an actual capacity greater than the storage strictly needed to
// contain its elements (i.e., its size). Libraries can implement different strategies for growth
// to balance between memory usage and reallocations, but in any case,
// reallocations should only happen at logarithmically growing intervals of size
// so that the insertion of individual elements at the end of the vector can be provided with
// amortized constant time complexity.
//-------------------------------------------------------------------------------------------------

#include <string>
#include <utility>
#include <sstream>
//-------------------------------------------------------------------------------------------------
// MyVector �� �����ϴ� ������Ʈ
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector Ŭ����.
//-------------------------------------------------------------------------------------------------
class MyVector
{
    using iterator = MyObject*;
    using const_iterator = a;
private:
    MyObject* _container;
    int  _size;
    int  _capacity;
        
    void reserve(int newCapacity)
    {
        if (_capacity >= newCapacity)
        {
            return;
        }
        MyObject* newContainer = new MyObject[newCapacity];

        for (size_t i = 0; i < _size; i++)
        {
            newContainer[i] = _container[i];
        }
        delete[] _container;
        _container = newContainer;
        _capacity = newCapacity;
    }

    iterator begin() { return _container; }
    const_iterator begin() const { return _container; }
    iterator end() { return _container + _size; }
    const_iterator end() const { return _container + _size; }

    iterator erase(iterator pos)
    {
        if (_size ==0)
        {
            return end();
        }

        iterator last = end() - 1;
        for (iterator iter = begin(); iter != end(); iter++)
        {

        }
    }

public: // ������, ���������, �Ҵ翬����, �Ҹ��ڸ� .cpp ���Ͽ� �����մϴ�.

    // Constructor.

    MyVector() = default;
    MyVector(int capacity)
        :_container(new MyObject[capacity]), _size(0), _capacity(capacity)
    {
    }
    // Copy constructor.
    MyVector(const MyVector& other)
    : _container(new MyObject[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other._container[i];
        }
    }
    // Assignment operator.
    MyVector& operator=(MyVector& other)
    {
        if (this == &other)
        {
            return *this;
        }
        MyVector temp(other);

        std::swap(_container, temp._container);
        std::swap(_size, temp._size);
        std::swap(_capacity, temp._capacity);

        return *this;
    }
    // Destructor.
    ~MyVector()
    {
        delete[] _container;
        _container = nullptr;
        _size = 0;
        _capacity = 0;
    }
public: // �Ʒ� ��� �Լ����� .cpp ���Ͽ� �����մϴ�.

    // Returns current capacity of this vector.
    int GetCapacity() const
    {
        return _capacity;
    }

    // Returns current size of this vector.
    int GetSize() const
    {
        return _size;
    }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id)
    {
        if (_size == _capacity)
        {
            reserve((_capacity == 0) ? 1 : _capacity * 2);
        }
    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_container[i]._id == MyObjectId)
            {
                return &_container[i];
            }
        }
        return nullptr;
    }

    // Trims the capacity of this vector to current size.
    void TrimToSize()/////////
    {
        if (_size ==_capacity)
        {
            return;
        }
        
    }

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index)
    {
        return _container[index];
    }

    // Returns string representation of the vector.
    std::string ToString() const
    {

    std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < _size; i++)
        {
            ss << _container[i]._id << ",";
        }
        ss << "]";

        return ss.str();

        //std::string str = "";
        //for (size_t i = 0; i < _size; i++)
        //{
        //    str[i] = _container[i]._id;
        //}
        //return str;
    }

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId)
    {
        iterator iter = begin();
        while (iter != end())
        {
            if (iter->_id == MyObjectId)
            {
                iter = erase(iter);
            }
            else
            {
                ++iter;
            }
        }
    }

    MyVector* GroupById(int* numGroups)
    {
        MyVector ids;
        for (size_t i = 0; i < _size; i++)
        {
            if (nullptr == ids.FindById(_container[i]._id))
            {
                ids.Add(_container[i]._id);
            }
        }
        int count = ids.GetSize();
        MyVector* result = new MyVector[count];

        for (size_t i = 0; i < _size; i++)
        {
            size_t index = ids.FindById(_container[i]._id) - ids.begin();
            result[index].Add(_container[i]._id);
        }

        *numGroups = count;
        return result;


    }
};
