#include "Heap.h"

const int& Heap::top() const
{
	return _container.front();
}

// ���� ������� üũ�Ѵ�.
bool Heap::empty() const
{
	return _container.empty();
}

// ���� ũ�⸦ ��ȯ�Ѵ�.
size_t Heap::size() const
{
	return _container.size();
}

// ���� ���� �����Ѵ�.
void Heap::push(int value)
{
	//1. �� ���� ������ ����
	_container.push_back(value);
	//2. ���� �Һ����� ���� �� ������ �����͸� �ٲ��ش�.
	// HACK : ù ���� 1�� ����                             

	size_t currentIndex = size();
	while (currentIndex > 1)
	{
		size_t parentIndex = currentIndex / 2;

		if (_container[parentIndex - 1] >= _container[currentIndex - 1])
		{
			break;
		}

		swap(_container[parentIndex - 1], _container[currentIndex - 1]);
		currentIndex = parentIndex;
	}

	/*
	int index = _container.size();
	if (_container[1] > _container[index])
	{
		while (value > _container[index / 2])
		{
			swap(_container[index], _container[index / 2]);
			index /= 2;
		}
	}
	else
	{
		while (value < _container[index / 2])
		{
			swap(_container[index], _container[index / 2]);
			index /= 2;
		}
	}
	*/
}

// ������ ���� �����Ѵ�.
/*
void Heap::pop()
{
	
	size_t Index = _container.back();
	_container.pop_back();

	size_t currentIndex = _container.size();
	size_t ParentIndex = 1;

	while (true)
	{
		size_t LeftIndex = ParentIndex * 2;
		size_t RightIndex = LeftIndex + 1;

		if (LeftIndex < currentIndex)
		{
			break;
		}

		size_t child = LeftIndex;
		if (RightIndex <= currentIndex && _container[LeftIndex - 1] <= _container[RightIndex - 1])
		{
			child = RightIndex;
		}

		if (_container[ParentIndex - 1] >= _container[child - 1])
		{
			break;
		}

		swap(_container[ParentIndex - 1], _container[child - 1]);
		ParentIndex = child;
	}
	
}
*/

void Heap::pop()
{
	// 1. ������ ��带 ��Ʈ ���� �����´�
	_container[0] = _container.back();

	// 2. ������ ��带 �����Ѵ�.
	_container.pop_back();

	// 3. ���� �Һ����� ������ �� ���� �ڽ��̶� ��ü�Ѵ�.
	const size_t currentSize = _container.size(); // �ε��� ��ȿ�� üũ�� ���ؼ� ����Ѵ�.
	size_t currentIndex = 1;
	while (true)
	{
		size_t left = currentIndex * 2;
		size_t right = left + 1;

		// 3-1. �ڽ��� �����ؾ� �Ѵ�.
		if (left < currentIndex)
		{
			break;
		}

		// 3-2. ���� �ڽİ� ������ �ڽ� �� �� ū ������ �ٲ۴�.
		size_t child = left;
		if (right <= currentSize && _container[left - 1] < _container[right - 1])
		{
			child = right;
		}

		// 3-3. �ٲ� �ڽ��� ���ٸ� �����Ѵ�.
		if (_container[currentIndex - 1] >= _container[child - 1])
		{
			break;
		}

		std::swap(_container[currentIndex - 1], _container[child - 1]);
		currentIndex = child;
	}
}