#include <iostream>
#include <map>
#include <GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair
{
public:
    KeyType first;
    ValueType second;
};

class GameEngineMap
{
private:
    class BinaryNode
    {
    public:
        BinaryNode* Parent = nullptr;
        BinaryNode* LeftChild = nullptr;
        BinaryNode* RightChild = nullptr;
        GameEnginePair Pair;

        BinaryNode* MinNode()
        {
            if (nullptr == LeftChild)
            {
                return this;
            }

            return LeftChild->MinNode();
        }

        BinaryNode* MaxNode()
        {
            if (nullptr == RightChild)
            {
                return this;
            }

            return RightChild->MaxNode();
        }

        BinaryNode* ParentNext(const KeyType& _Key)
        {
            if (Pair.first > _Key)
            {
                return this;
            } 

            if (nullptr == Parent)
            {
                return nullptr;
            } 

            return Parent->ParentNext(_Key);
        }

        BinaryNode* NextNode()
        {

            if (nullptr == RightChild)
            {
                return Parent->ParentNext(Pair.first);
            }

            return RightChild->MinNode();
        }


        void ChildChange(BinaryNode* _Old, BinaryNode* _New)
        {
            if (_Old == RightChild)
            {
                RightChild = _New;
            }

            if (_Old == LeftChild)
            {
                LeftChild = _New;

            }

            if (nullptr != _New)
            {
                _New->Parent = this;
            }
        }


        BinaryNode* find(const KeyType& _Key)
        {
            if (Pair.first == _Key)
            {
                return this;
            }
            else if (Pair.first > _Key)
            {
                if (nullptr == LeftChild)
                {
                    return nullptr;
                }

                return LeftChild->find(_Key);
            }
            else if (Pair.first < _Key)
            {
                if (nullptr == RightChild)
                {
                    return nullptr;
                }

                return RightChild->find(_Key);
            }

            return nullptr;

        }

        void Insert(const GameEnginePair& _Pair)
        {
            if (Pair.first > _Pair.first)
            {
                if (nullptr == LeftChild)
                {
                    LeftChild = new BinaryNode();
                    LeftChild->Pair = _Pair;
                    LeftChild->Parent = this;
                    return;
                }

                return LeftChild->Insert(_Pair);
            }
            else if (Pair.first < _Pair.first)
            {
                if (nullptr == RightChild)
                {
                    RightChild = new BinaryNode();
                    RightChild->Pair = _Pair;
                    RightChild->Parent = this;
                    return;
                }

                RightChild->Insert(_Pair);
            }
            else
            {
                MessageBoxAssert("Ű�� ��ġ�� pair�� insert�߽��ϴ�");
            }
        }

        void FirstOrder()
        {
            std::cout << Pair.first << std::endl;
            if (nullptr != LeftChild)
            {
                LeftChild->FirstOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->FirstOrder();
            }
        }

        void Relase()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->Relase();
            }
            if (nullptr != RightChild)
            {
                RightChild->Relase();
            }
            delete this;
        }

        // ���� ��ȸ
        void LastOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->LastOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->LastOrder();
            }
            std::cout << Pair.first << std::endl;
        }

        // ���� ��ȸ
        void MidOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->MidOrder();
            }
            std::cout << Pair.first << std::endl;
            if (nullptr != RightChild)
            {
                RightChild->MidOrder();
            }
        }

    public:
        BinaryNode()
        {

        }
        ~BinaryNode()
        {
        }
    };

public:
    class iterator
    {
        // ���� �и��� �������� �������� �����ڸ� ����ϰ� ������
        // � Ŭ���� ���Ը�ŭ�� ���� ���� public���� �����ϰڴ�.
        friend GameEngineMap;

    private:
        BinaryNode* CurNode;

    public:
        bool operator==(const iterator& _Other)
        {
            return _Other.CurNode == CurNode;
        }

        bool operator!=(const iterator& _Other)
        {
            return _Other.CurNode != CurNode;
        }

        GameEnginePair* operator->()
        {
            if (nullptr == CurNode)
            {
                return nullptr;
            }

            return &CurNode->Pair;
        }


        iterator& operator++()
        {
            CurNode = CurNode->NextNode();
            return *this;
        }
    };

public:
    void insert(const GameEnginePair& _Pair)
    {
        if (nullptr == RootNode)
        {
            RootNode = new BinaryNode();
            RootNode->Pair = _Pair;
            return;
        }

        RootNode->Insert(_Pair);
    }

    iterator find(const KeyType& _Key)
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->find(_Key);
        return NewIter;
    }

    BinaryNode* erase(const iterator& _Other)
    {
        BinaryNode* DeleteNode = _Other.CurNode;
        BinaryNode* ParentNode = DeleteNode->Parent;
        BinaryNode* LeftChildNode = DeleteNode->LeftChild;
        BinaryNode* RightChildNode = DeleteNode->RightChild;

        if (nullptr == DeleteNode)
        {
            MessageBoxAssert("end�� �����Ϸ��� �߽��ϴ�.");
            return nullptr;
        }

        if (nullptr == LeftChildNode && nullptr == RightChildNode)
        {
            BinaryNode* returnNode = DeleteNode->NextNode();

            if (nullptr != ParentNode)
            {
                ParentNode->ChildChange(DeleteNode, nullptr);
            }

            if (RootNode == DeleteNode)
            {
                RootNode = nullptr;
            }

            delete DeleteNode;
            DeleteNode = nullptr;
            return returnNode;
        }

        BinaryNode* ChangeNode = nullptr;
        BinaryNode* ChangeParentNode = nullptr;

        if (nullptr != LeftChildNode)
        {
            ChangeNode = LeftChildNode->MaxNode();
            ChangeParentNode = ChangeNode->Parent;
        }
        else if (nullptr != RightChildNode)
        {
            ChangeNode = RightChildNode->MinNode();
            ChangeParentNode = ChangeNode->Parent;
        }

        if (nullptr != ChangeParentNode)
        {
            ChangeParentNode->ChildChange(ChangeNode, ChangeNode->LeftChild);
        }

        if (nullptr != ParentNode)
        {
            ParentNode->ChildChange(DeleteNode, ChangeNode);
        }

        if (LeftChildNode != ChangeNode)
        {
            ChangeNode->LeftChild = LeftChildNode;

            if (LeftChildNode != nullptr)
            {
                LeftChildNode->Parent = ChangeNode;
            }

        }
        if (RightChildNode != ChangeNode)
        {
            ChangeNode->RightChild = RightChildNode;

            if (RightChildNode != nullptr)
            {
                RightChildNode->Parent = ChangeNode;
            }
        }

        if (RootNode == DeleteNode)
        {
            RootNode = ChangeNode;
        }

        delete DeleteNode;
        DeleteNode = nullptr;

        return ChangeNode->NextNode();
    }


    iterator begin()
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->MinNode();
        return NewIter;
    }


    iterator end()
    {
        iterator NewIter;
        NewIter.CurNode = nullptr;
        return NewIter;
    }

    // ���� ��ȸ
    void FirstOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->FirstOrder();
    }

    void Relase()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->Relase();
        RootNode = nullptr;
    }

    // ���� ��ȸ
    void LastOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->LastOrder();
    }

    // ���� ��ȸ
    void MidOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->MidOrder();
    }

    ~GameEngineMap()
    {
        if (nullptr != RootNode)
        {
            RootNode->Relase();
            RootNode = nullptr;
        }
    }


public:
    BinaryNode* RootNode = nullptr;
};

GameEnginePair make_pair(KeyType _Key, KeyType _Value)
{
    return { _Key , _Value };
}

int main()
{
    LeckCheck();

    //{
    //    // ������˰����� ����� �ڰ����� Ž�� 2�� Ʈ�� �ڷᱸ���Դϴ�.
    //    //      Key  Value
    //    std::map<const char*, MonsterData> DataMap;

    //    DataMap.insert(std::make_pair("��ũ", MonsterData{ 10, 100 }));
    //    // Ű�� ��ġ�� ����� ���µ� 
    //    DataMap.insert(std::make_pair("�巡��", MonsterData{ 50, 1000 }));


    //    std::map<const char*, MonsterData>::iterator StartIter = DataMap.begin();
    //    std::map<const char*, MonsterData>::iterator EndIter = DataMap.end();

    //    for (; StartIter != EndIter; ++StartIter)
    //    {
    //        // for�� Ű��
    //        // StartIter.operator->().first
    //        std::cout << "Key : " << StartIter->first << std::endl;
    //        std::cout << "Value : " << StartIter->second.Att << std::endl;

    //    }

    //}


    {
        std::map<int, int> DataMap;

        DataMap.insert(std::make_pair(10, 10));
        DataMap.insert(std::make_pair(2, 2));
        DataMap.insert(std::make_pair(5, 5));
        DataMap.insert(std::make_pair(7, 7));
        DataMap.insert(std::make_pair(8, 8));
        DataMap.insert(std::make_pair(3, 3));
        DataMap.insert(std::make_pair(20, 20));

        std::map<int, int>::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        std::map<int, int>::iterator DeleteNextIter = DataMap.erase(DataMap.find(2));
        //std::map<int, int>::iterator StartIter = DataMap.begin();
        //std::map<int, int>::iterator EndIter = DataMap.end();

        //for (; StartIter != EndIter; ++StartIter)
        //{
        //    std::cout << StartIter->first << std::endl;
        //}

        int a = 0;

    }

    {
        std::map<int, int> DataMap;

        DataMap.insert(std::make_pair(1, 1));
        DataMap.insert(std::make_pair(2, 1));
        DataMap.insert(std::make_pair(3, 1));
        DataMap.insert(std::make_pair(4, 1));
        DataMap.insert(std::make_pair(5, 1));
        DataMap.insert(std::make_pair(6, 1));
        DataMap.insert(std::make_pair(7, 1));
    }

    {
        GameEngineMap DataMap;

        DataMap.insert(make_pair(20, 1));
        DataMap.insert(make_pair(2, 1));
        DataMap.insert(make_pair(10, 1));
        DataMap.insert(make_pair(3, 1));
        DataMap.insert(make_pair(5, 1));
        DataMap.insert(make_pair(4, 1));
        DataMap.insert(make_pair(15, 1));
        DataMap.insert(make_pair(16, 1));
        DataMap.insert(make_pair(30, 1));
        DataMap.insert(make_pair(25, 1));

        GameEngineMap::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        GameEngineMap node;
        node.RootNode = DataMap.erase(DataMap.find(16)); 
        //������ ��带 ������ ���Ŀ� �� �� ���� ���� ��
        int a = 0;

        GameEngineMap::iterator StartIter = DataMap.begin();
        GameEngineMap::iterator EndIter = DataMap.end();

        for (;
            StartIter != EndIter;
            ++StartIter
            )
        {
            if (StartIter->first == 8)
            {
                int a = 0;
            }

            std::cout << StartIter->first << std::endl;
        }


    }


}
