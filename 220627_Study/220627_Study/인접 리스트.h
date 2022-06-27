#pragma once

enum class EGraphType
{
    Matrix,
    List
};

template <EGraphType type, size_t N>
class MyGraph;

template <size_t N>
class MyGraph<EGraphType::List, N>
{
public:
    // �� ������ �������� Ȯ���Ѵ�.
    bool        IsAdjacent(int start, int end)
    {

    }
    // ������ ���Ѵ�.
    int         GetDegree(int node)
    {

    }
        // ���� ������ ���Ѵ�.
    int         GetInDegree(int node)
    {

    }

        // ���� ������ ���Ѵ�.
    int         GetOutDegree(int node)
    {
    }
        // ������ �߰��Ѵ�.
    void        AddEdge(int start, int end, int weight = 1)
    {

        }
        // ������ �����Ѵ�.
    void        DeleteEdge(int start, int end)
    {

    }
            
        // ����Ѵ�.
        // ����..
        // [ 1 ] : [ (3,1) (4,3) ]
        // [ 2 ] :
        // [ 3 ] :
        // [ 4 ] :
        // [ 5 ] : [ (2, 4) (3, 5) ]
    void        Print()
    {
        
    }
private:
    array<vector<std::pair<int, int>>, N>       _edges;
};
