#include <iostream>
#include <string>

//���Ḯ��Ʈ�� �����͸� �����ϱ� ���� Ÿ��
//���� ����Ʈ�� �����͸� ���������� �ٷ�°� �ƴϰ� Node��� ������ �ٷ�

//���̳�� : ���� �����͸� ���� �ʰ� ������ ������ ���Ǽ��� ���ؼ��� ����

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

    // �⺻ ������
    ForwardList()
    {
        _head->Next = _end;
    }

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit ForwardList(size_t count)
        :ForwardList()
    {
        for (size_t i = 0; i < count; i++)
        {
            push_front(0);
        }
    }

    // ���� ������.
    ForwardList(const ForwardList& other)
        :ForwardList()
    {
        iterator inserted = before_begin();
        for (const_iterator iter =other.begin(); iter != other.end(); ++iter)
        {
            inserted = insert_after(inserted, *iter);
        }
    }

    // �Ҵ� ������
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

    // �Ҹ���
    ~ForwardList()
    {
        clear();

        delete _head;
        _head = nullptr;

        delete _end;
        _end = nullptr;
    }

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front()
    {
        return *begin();
    }
    const int& front() const
    {
        return *begin();
    }

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            before_begin()
    {
        return _head;
    }

    const_iterator      before_begin() const
    {
        return _head;
    }

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            begin()
    {
        return _head->Next;
    }
    const_iterator      begin() const
    {
        return _head->Next;
    }

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            end()
    {
        return _end;
    }
    const_iterator      end() const
    {
        return _end;
    }

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            insert_after(const_iterator pos, int value)
    {
        Node* newNode = new Node(value);
        Node* where = pos._p;

        newNode->Next = where->Next;
        where->Next = newNode;

        return newNode;
    }

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
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

    // ���� ��ҿ� value�� �����Ѵ�.
    void                push_front(int value)
    {
        insert_after(before_begin(), value);
    }

    // ���� ��Ҹ� �����Ѵ�.
    void                pop_front()
    {
        erase_after(before_begin());
    }

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
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


    // �����̳ʸ� ���������.
    void                clear()
    {
        while (false == empty())
        {
            pop_front();
        }
    }

    // value�� �ִ��� �˻��Ѵ�.
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
