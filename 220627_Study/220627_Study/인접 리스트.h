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
    // 두 정점이 인접한지 확인한다.
    bool        IsAdjacent(int start, int end)
    {

    }
    // 차수를 구한다.
    int         GetDegree(int node)
    {

    }
        // 진입 차수를 구한다.
    int         GetInDegree(int node)
    {

    }

        // 진출 차수를 구한다.
    int         GetOutDegree(int node)
    {
    }
        // 간선을 추가한다.
    void        AddEdge(int start, int end, int weight = 1)
    {

        }
        // 간선을 제거한다.
    void        DeleteEdge(int start, int end)
    {

    }
            
        // 출력한다.
        // 예시..
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
