#include "Heap.h"

const int& Heap::top() const
{
	return _container.front();
}

// 힙이 비었는지 체크한다.
bool Heap::empty() const
{
	return _container.empty();
}

// 힙의 크기를 반환한다.
size_t Heap::size() const
{
	return _container.size();
}

// 힙에 값을 삽입한다.
void Heap::push(int value)
{
	//1. 맨 끝에 데이터 삽입
	_container.push_back(value);
	//2. 힙의 불변성을 만족 할 때까지 데이터를 바꿔준다.
	// HACK : 첫 노드는 1로 생각                             

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

// 힙에서 값을 제거한다.
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
	// 1. 마지막 노드를 루트 노드로 가져온다
	_container[0] = _container.back();

	// 2. 마지막 노드를 제거한다.
	_container.pop_back();

	// 3. 힙의 불변성을 만족할 때 까지 자식이랑 교체한다.
	const size_t currentSize = _container.size(); // 인덱스 유효성 체크를 위해서 사용한다.
	size_t currentIndex = 1;
	while (true)
	{
		size_t left = currentIndex * 2;
		size_t right = left + 1;

		// 3-1. 자식이 존재해야 한다.
		if (left < currentIndex)
		{
			break;
		}

		// 3-2. 왼쪽 자식과 오른쪽 자식 중 더 큰 쪽으로 바꾼다.
		size_t child = left;
		if (right <= currentSize && _container[left - 1] < _container[right - 1])
		{
			child = right;
		}

		// 3-3. 바꿀 자식이 없다면 종료한다.
		if (_container[currentIndex - 1] >= _container[child - 1])
		{
			break;
		}

		std::swap(_container[currentIndex - 1], _container[child - 1]);
		currentIndex = child;
	}
}