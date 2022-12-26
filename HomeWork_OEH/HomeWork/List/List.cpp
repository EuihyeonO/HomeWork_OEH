#include <iostream>
#include <list>
#include <vector>
#include <GameEngineDebug.h>



// 1. 릭없애오세요 
// 2. push_front 만들어 오세요.

typedef int DataType;

class GameEngineList
{

private:
	class ListNode
	{
	public:
		ListNode* Front = nullptr;
		ListNode* Back = nullptr;
		DataType Value;



	public:
		ListNode() {}
		~ListNode() {}

	};

public:
	class iterator
	{
		// 나는 분명히 여러가지 접근제한 지정자를 사용하고 있지만
		// 어떤 클래스 에게만큼은 나의 모든걸 public으로 공개하겠다.
		friend GameEngineList;

	private:
		ListNode* CurNode;

	public:
		iterator& operator++()
		{
			CurNode = CurNode->Back;
			return *this;
		}

		DataType& operator*() const noexcept
		{
			return CurNode->Value;
		}

		bool operator!=(const iterator _Iter) const noexcept
		{
			return _Iter.CurNode != CurNode;
		}

	};


public:
	GameEngineList()
	{
		FrontNode = new ListNode();
		BackNode = new ListNode();

		// List를 만드는 방식중 더미노드 방식이라고 합니다.
		FrontNode->Back = BackNode;
		BackNode->Front = FrontNode;
	}

	// constrcuter destructer
	GameEngineList(size_t _Count)
	{
	}

	~GameEngineList()
	{
		delete FrontNode;
		delete BackNode;
	}


	// delete Function
	GameEngineList(const GameEngineList& _Other) = delete;
	GameEngineList(GameEngineList&& _Other) noexcept
	{
		// 최적화때문에 이걸 사용합니다.
	}
	GameEngineList& operator=(GameEngineList&& _Other) noexcept = delete;

	size_t size()
	{
		return DataSize;
	}

	iterator begin()
	{
		iterator Return = iterator();
		Return.CurNode = FrontNode->Back;
		return Return;
	}

	iterator end()
	{
		iterator Return = iterator();
		Return.CurNode = BackNode;
		return Return;
	}

	void erase(const iterator& Iter)
	{
		ListNode* Node = Iter.CurNode;

		if (BackNode == Node || FrontNode == Node)
		{
			return;
		}

		if (nullptr == Node)
		{
			return;
		}

		ListNode* DeleteFrontNode = Node->Front;
		ListNode* DeleteBackNode = Node->Back;

		delete Node;
		Node = nullptr;

		DeleteFrontNode->Back = DeleteBackNode;
		DeleteBackNode->Front = DeleteFrontNode;


		return;
	}

	void clear()
	{
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* FrontNode = BackNode->Front;
		FrontNode->Back = NewNode;
		BackNode->Front = NewNode;

		NewNode->Front = FrontNode;
		NewNode->Back = BackNode;

		++DataSize;

	}

	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* BackNode = FrontNode->Back;
		BackNode->Front = NewNode;
		FrontNode->Back = NewNode;

		NewNode->Front = FrontNode;
		NewNode->Back = BackNode;

		++DataSize;
	}

	void resize(size_t _Count)
	{
	}

	void DeleteList() // 동적할당된 노드로 인해 Leak이 남지않게 하기 위한 Delete함수
	{
		if (DataSize == 0)
		{
			return;
		} //연결된 노드가 없으면 리턴

		if (FrontNode->Back == BackNode)
		{
			return;
		} //프론트노드와 백노드 사이의 데이터가 모두 지워지면 리턴
	
		ListNode* MyNode = FrontNode->Back;
		ListNode* MyNextNode = MyNode->Back;

		FrontNode->Back = MyNextNode;
		MyNextNode->Front = FrontNode;

		delete MyNode; //MyNode의 앞노드와 뒷노드를 이어준 후 MyNode를 delete
		
		DeleteList(); //모든 데이터가 delete 될 때 까지 재귀호출
	}

private:
	size_t DataSize = 0;
	ListNode* FrontNode = nullptr;
	ListNode* BackNode = nullptr;
};


int main()
{
	LeckCheck();

	std::cout << "stdList" << std::endl;
	{
		// push_back
		// 노드형 시퀸스 자료구조 입니다.

		// 크기가 정해져있지 않습니다.
		std::list<size_t> IntList = std::list<size_t>();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_front(i);
			// 내부에 존재하는 배열의 크기입니다.
			// std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// 내가 집어넣은 데이터의 크기입니다.
			std::cout << "Size" << IntList.size() << std::endl;
		}

		{
			std::list<size_t>::iterator StartIter = IntList.begin();
			std::list<size_t>::iterator EndIter = IntList.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}

			int a = 0;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "myList" << std::endl;

	{
		// push_back
		// 노드형 시퀸스 자료구조 입니다.

		// 크기가 정해져있지 않습니다.
		GameEngineList IntList = GameEngineList();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_front(i);
			// 내부에 존재하는 배열의 크기입니다.
			// std::cout << "Capacity" << IntVector.capacity() << std::endl;
			// 내가 집어넣은 데이터의 크기입니다.
			std::cout << "Size" << IntList.size() << std::endl;
		}


		{
			GameEngineList::iterator StartIter = IntList.begin();

			++StartIter;

			IntList.erase(StartIter);
		}

		{

			GameEngineList::iterator StartIter = IntList.begin();
			GameEngineList::iterator EndIter = IntList.end();

			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}

			int a = 0;
		}

		IntList.DeleteList();
	}
}