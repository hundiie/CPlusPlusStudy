#include <iostream>
#include <string>

//연결리스트는 데이터를 저장하기 위한 타입
//연결 리스트는 데이터를 직접적으로 다루는게 아니고 Node라는 것으로 다룸

//더미노드 : 실제 데이터를 담지 않고 오로지 구현의 편의성을 위해서만 존재

using namespace std;
class ForwardList
{
    struct Node
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0;
        Node* Next = nullptr;
    };

public:
    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr);
        ~const_iterator();

        const int&          operator*() const;
        const int*          operator->() const;
        const_iterator&     operator++();
        const_iterator      operator++(int);
        bool                operator==(const const_iterator& rhs) const;
        bool                operator!=(const const_iterator& rhs) const;
        bool                operator==(nullptr_t p) const;
        bool                operator!=(nullptr_t p) const;

    public:
        Node* _p = nullptr;
    };

    class iterator : public const_iterator
    {
    public:
        using const_iterator::const_iterator;

        int& operator*() const;
        int* operator->() const;
        iterator& operator++();
        iterator        operator++(int);
    };

    // 기본 생성자
    ForwardList()
    {
        _head->Next = _end;
    }

    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    explicit ForwardList(size_t count)
        :ForwardList()
    {
        for (size_t i = 0; i < count; i++)
        {
            push_front(0);
        }
    }

    // 복사 생성자.
    ForwardList(const ForwardList& other)
        :ForwardList()
    {
        iterator inserted = before_begin();
        for (const_iterator iter =other.begin(); iter != other.end(); ++iter)
        {
            inserted = insert_after(inserted, *iter);
        }
    }

    // 할당 연산자
    ForwardList& operator=(const ForwardList& rhs)
    {
        if (&rhs != this)
        {
            ForwardList temp(rhs);
            std::swap(_head, temp._head);
            std::swap(_end, temp._end);
        }
        return*this;
    }

    // 소멸자
    ~ForwardList()
    {
        clear();

        delete _head;
        _head = nullptr;

        delete _end;
        _end = nullptr;
    }

    // 첫 번째 요소를 반환한다.
    int& front()
    {
        return *begin();
    }
    const int& front() const
    {
        return *begin();
    }

    // 시작 전 요소를 가리키는 반복자를 반환한다.
    iterator            before_begin()
    {
        return _head;
    }

    const_iterator      before_begin() const
    {
        return _head;
    }

    // 시작 요소를 가리키는 반복자를 반환한다.
    iterator            begin()
    {
        return _head->Next;
    }
    const_iterator      begin() const
    {
        return _head->Next;
    }

    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    iterator            end()
    {
        return _end;
    }
    const_iterator      end() const
    {
        return _end;
    }

    // pos 다음에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    iterator            insert_after(const_iterator pos, int value)
    {
        Node* newNode = new Node(value);
        Node* where = pos._p;

        newNode->Next = where->Next;
        where->Next = newNode;

        return newNode;
    }

    // pos 다음 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    iterator            erase_after(const_iterator pos)
    {
        if (empty())
        {
            return end();
        }

        Node* where = pos._p;
        Node* removed = where->Next;

        where->Next = removed->Next;
        removed->Next = nullptr;

        return removed;
    }

    // 시작 요소에 value를 삽입한다.
    void                push_front(int value)
    {
        insert_after(before_begin(), value);
    }

    // 시작 요소를 제거한다.
    void                pop_front()
    {
        erase_after(before_begin());
    }

    // 컨테이너가 비었는지 판단한다.
    bool                empty() const
    {
        if (begin() == end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    // 컨테이너를 비워버린다.
    void                clear()
    {
        while (false == empty())
        {
            pop_front();
        }
    }

    // value가 있는지 검사한다.
    bool contains(int value) const
    {
        for(const_iterator iter = begin(); iter != end(); ++iter)
        {
            if (*iter ==value)
            {
                return true;
            }
        }
        return false;
    }
private:
    Node* _head = new Node();
    Node* _end = new Node();
};
