#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

void BFS_List(std::vector<std::vector<int>> &list)
{
    std::queue<int> q;
    std::vector<bool> visited(list.size(), false);

    for (int i = 0; i < list.size(); i++)
    {
        if (!visited[i])
        {
            q.push(i);
            while (!q.empty())
            {
                int vertex = q.front();
                q.pop();
                std::cout << vertex << std::endl;
                for (auto v : list[vertex])
                {
                    if (!visited[v])
                    {
                        q.push(v);
                    }
                }
                visited[vertex] = true;
            }
        }
    }
}

void dfs_list_recursive(std::vector<std::vector<int>> &list,
                        std::vector<bool> &discovered,
                        int vertex)
{
    discovered[vertex] = true;
    std::cout << vertex << std::endl;
    for (int v : list[vertex])
    {
        if (!discovered[v])
        {
            dfs_list_recursive(list, discovered, v);
        }
    }
}

void DFS_List_Recursive(std::vector<std::vector<int>> &list) 
{
    std::vector<bool> discovered(list.size(), false);
    
    for (int i = 0; i < list.size(); i++)
    {
        if (!discovered[i])
        {
            dfs_list_recursive(list, discovered, i);
        }
    }
}

void DFS_List_Iterative(std::vector<std::vector<int>> &list)
{
    std::vector<bool> discovered(list.size(), false);
    std::stack<int> st;

    for (int i = 0; i < list.size(); i++)
    {
        if (!discovered[i])
        {
            st.push(i);
            while (!st.empty())
            {
                int vertex = st.top();
                discovered[vertex] = true;
                std::cout << vertex << std::endl;
                st.pop();
                for (int v : list[vertex])
                {
                    if (!discovered[v])
                    {
                        st.push(v);
                    }
                }
            }
        }
    }
}

void dfs_list_recursive_postorder(std::vector<std::vector<int>> &list,
                        std::vector<bool> &visited,
                        int vertex)
{
    visited[vertex] = true;
    for (auto v : list[vertex]) {
        if (!visited[v])
        {
            dfs_list_recursive_postorder(list, visited, v);
        }
    }
    std::cout << vertex << std::endl;
}

void DFS_List_Recursive_PostOrder(std::vector<std::vector<int>> &list)
{
    std::vector<bool> visited(list.size(), false);
    for (int v = 0; v < list.size(); v++)
    {
        if (!visited[v])
        {
            dfs_list_recursive_postorder(list, visited, v);
        }
    }
}

void DFS_List_Iterative_PostOrder(std::vector<std::vector<int>> &list)
{
    std::stack<int> st;
    std::vector<bool> visited(list.size(), false);

    for (int i = 0; i < list.size(); i++)
    {
        if (!visited[i])
        {
            st.push(i);
            visited[i] = true;
            while (!st.empty())
            {
                bool added = false;
                for (auto v : list[st.top()])
                {
                    if (!visited[v])
                    {
                        st.push(v);
                        visited[v] = true;
                        added = true;
                    }
                }
                if (!added)
                {
                    int vertex = st.top();
                    st.pop();
                    std::cout << vertex << std::endl;
                }
            }
        }
    }
}

void BFS_Matrix(std::vector<std::vector<int>> &mat)
{
    std::vector<bool> discovered(mat.size(), false);
    std::queue<int> q;

    for (int i = 0; i < mat.size(); i++)
    {
        if (!discovered[i])
        {
            q.push(i);
            while (!q.empty())
            {
                int vertex = q.front();
                q.pop();
                discovered[vertex] = true;
                std::cout << vertex << std::endl;
                for (int j = 0; j < mat[vertex].size(); j++)
                {
                    if (mat[vertex][j] && !discovered[j])
                    {
                        q.push(j);
                    }
                }
            }
        }
    }
}

void dfs_matrix_recursive(std::vector<std::vector<int>> &mat,
                          std::vector<bool> &discovered,
                          int vertex)
{
    discovered[vertex] = true;
    std::cout << vertex << std::endl;
    for (int j = 0; j < mat[vertex].size(); j++)
    {
        if (mat[vertex][j] && !discovered[j])
        {
            dfs_matrix_recursive(mat, discovered, j);
        }
    }
}

void DFS_Matrix_Recursive(std::vector<std::vector<int>> &mat)
{
    std::vector<bool> discovered(mat.size(), false);

    for (int i = 0; i < mat.size(); i++)
    {
        if (!discovered[i])
        {
            dfs_matrix_recursive(mat, discovered, i);
        }
    }
}

void DFS_Matrix_Iterative(std::vector<std::vector<int>> &mat)
{
    std::vector<bool> discovered(mat.size(), false);
    std::stack<int> st;

    for (int i = 0; i < mat.size(); i++)
    {
        if (!discovered[i])
        {
            st.push(i);
            while (!st.empty())
            {
                int vertex = st.top();
                st.pop();
                discovered[vertex] = true;
                std::cout << vertex << std::endl;
                for (int j = 0; j < mat[vertex].size(); j++)
                {
                    if (mat[vertex][j] && !discovered[j])
                    {
                        st.push(j);
                    }
                }
            }
        }
    }
}

// Loop through each vertex twice so O(N^2)
void Djikstras(std::vector<std::vector<std::pair<int, int>>> &list,
                int start,
                int end)
{
    std::vector<int> minDistance(list.size(), INT_MAX);
    std::vector<bool> processed(list.size(), false);
    std::vector<int> parent(list.size(), -1);

    minDistance[start] = 0;
    parent[start] = start;
    while (!processed[end])
    {
        int minVertex = 0;
        int minDist = INT_MAX;
        for (int i = 0; i < minDistance.size(); i++)
        {
            if (minDistance[i] < minDist && !processed[i])
            {
                minVertex = i;
                minDist = minDistance[i];
            }
        }
        
        for (int j = 0; j < list[minVertex].size(); j++)
        {
            int weight = list[minVertex][j].second;
            int vertex = list[minVertex][j].first;
            if (
                (weight + minDistance[minVertex] < minDistance[vertex]))
            {
                minDistance[vertex] = minDistance[minVertex] + weight;
                parent[vertex] = minVertex;
            }
        }
        processed[minVertex] = true;
    }

    std::cout << "Min distance from " << start << " to " << end << " is: " <<
                 minDistance[end] << std::endl;
    std::cout << "Path in reverse: " << end;
    int vertex = parent[end];
    while (vertex != start)
    {
        std::cout << " " << vertex;
        vertex = parent[vertex];
    }
    std::cout << " " << start << std::endl;
}

class myComparator
{
    public:
        bool operator() (const std::pair<int, int> &p1,
                         const std::pair<int, int> &p2)
        {
            return (p1.second > p2.second);
        }
};

// Use a heap to store the min distances, so O(NlogN)
void DjikstrasFaster(std::vector<std::vector<std::pair<int, int>>> &list,
                     int start,
                     int end)
{
    std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>,
                        myComparator> distMinHeap;
    std::vector<int> minDistance(list.size(), INT_MAX);
    std::vector<bool> processed(list.size(), false);
    std::vector<int> parent(list.size(), -1);

    minDistance[start] = 0;
    parent[start] = start;
    distMinHeap.push(std::make_pair(start, 0));
    while (!processed[end])
    {
        int minVertex = distMinHeap.top().first;
        distMinHeap.pop();
        
        for (int j = 0; j < list[minVertex].size(); j++)
        {
            int vertex = list[minVertex][j].first;
            int weight = list[minVertex][j].second;
            if ((minDistance[minVertex] + weight < minDistance[vertex]) &&
                 !processed[vertex])
            {
                minDistance[vertex] = minDistance[minVertex] + weight;
                distMinHeap.push(std::make_pair(vertex, minDistance[vertex]));
                parent[vertex] = minVertex;
            }
        }
        
        processed[minVertex] = true;
    }

    std::cout << "Min distance from " << start << " to " << end << " is: " <<
                 minDistance[end] << std::endl;
    std::cout << "Path in reverse: " << end;
    int vertex = parent[end];
    while (vertex != start)
    {
        std::cout << " " << vertex;
        vertex = parent[vertex];
    }
    std::cout << " " << start << std::endl;
}

// Another way to do this is to store an N x N matrix of edges
// and just check if (edges[i][j]) because you initialize to all
// 0s, otherwise you store the edge weight. Just check that
// each time rather than having to make a pair of vertices and edges
// Plus, with this approach, you don't necessarily need a vector
// of your tree. You could just print the vertices each time you
// add them, and store a variable int numEdges. Have your while
// loop check the condition (numEdges < V - 1) because having
// V vertices added to your tree is that same as V-1 edges
//
// Either the above or the below is not the most efficient.
// A better way is to keep a distance array which stores the
// shortest edge away from the current tree for that vertex
// Then you only need to check each vertex for that, so O(N^2)
// An even better way is to store the edges in a heap or even a
// Fibonacci heap
void Prims(std::vector<std::vector<std::pair<int, int>>> &list)
{
    std::vector<int> msp;
    std::vector<bool> discovered(list.size(), false);

    msp.push_back(0);
    discovered[0] = true;
    int totalWeight = 0;

    while (msp.size() < list.size())
    {
        std::pair<int, int> minNode = std::make_pair(-1, INT_MAX);
        for (int v : msp)
        {
            for (int i = 0; i < list[v].size(); i++)
            {
                std::pair<int, int> node = list[v][i];
                if (node.second < minNode.second && !discovered[node.first])
                {
                    minNode = node;
                }
            }
        }
        discovered[minNode.first] = true;
        msp.push_back(minNode.first);
        totalWeight += minNode.second;
    }

    std::cout << "Min span tree order: ";
    for (int v : msp)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "Total weight: " << totalWeight << std::endl;
}

void Merge(std::vector<std::tuple<int, int, int>> &edges,
           int start,
           int half,
           int end)
{
    int i = start;
    int j = half + 1;
    std::vector<std::tuple<int, int, int>> temp(end - start + 1);

    int k = 0;
    while (i <= half && j <= end)
    {
        if (std::get<0>(edges[i]) < std::get<0>(edges[j]))
        {
            temp[k++] = edges[i++];
        }
        else
        {
            temp[k++] = edges[j++];
        }
    }

    while (i <= half)
    {
        temp[k++] = edges[i++];
    }
    while (j <= end)
    {
        temp[k++] = edges[j++];
    }

    k--;
    while (k >= 0)
    {
        edges[start + k] = temp[k];
        k--;
    }
}

void MergeSort(std::vector<std::tuple<int, int, int>> &edges,
               int start,
               int end)
{
    if (end > start)
    {
        int half = (start + end) / 2;
        MergeSort(edges, start, half);
        MergeSort(edges, half + 1, end);
        Merge(edges, start, half, end);
    }
}

bool HasCycle(std::vector<std::vector<int>> &mat)
{
    std::vector<bool> visited(mat.size(), false);
    std::stack<int> st;
    std::vector<int> parent(mat.size(), -1);

    for (int i = 0; i < mat.size(); i++)
    {
        if (!visited[i])
        {
            st.push(i);
            parent[i] = i;
            while (!st.empty())
            {
                int vertex = st.top();
                visited[vertex] = true;
                st.pop();
                for (int j = 0; j < mat[vertex].size(); j++)
                {
                    if (mat[vertex][j])
                    {
                        if (visited[j] && parent[vertex] != j)
                        {
                            return true;
                        }
                        else if (!visited[j])
                        {
                            st.push(j);
                            parent[j] = vertex;
                        }
                    }
                }

            }
        }
    }
    return false;
}

// Long brute force way
// void Kruskals(std::vector<std::vector<std::pair<int,int>>> &list)
// {
//     // Edge weight, node 1, node 2
//     std::vector<std::tuple<int, int, int>> edges;
//     std::vector<std::vector<bool>> added(list.size(), std::vector<bool>(list.size(), false));
//     for (int i = 0; i < list.size(); i++)
//     {
//         for (std::pair<int, int> j : list[i])
//         {
//             if (!added[i][j.first])
//             {
//                 edges.push_back(std::make_tuple(j.second, i, j.first));
//                 added[i][j.first] = true;
//                 added[j.first][i] = true;
//             }
//         }
//     }

//     MergeSort(edges, 0, edges.size() - 1);

//     std::vector<std::vector<int>> adj_mat(list.size(), std::vector<int>(list.size(), 0));
//     std::vector<std::tuple<int, int, int>> mst;
//     for (std::tuple<int, int, int> edge : edges)
//     {
//         int node1 = std::get<1>(edge);
//         int node2 = std::get<2>(edge);
//         mst.push_back(edge);
//         adj_mat[node1][node2] = 1;
//         adj_mat[node2][node1] = 1;
//         if (HasCycle(adj_mat))
//         {
//             mst.pop_back();
//             adj_mat[node1][node2] = 0;
//             adj_mat[node2][node1] = 0;
//         }
//     }

//     int totalWeight = 0;
//     std::cout << "Min span tree order: ";
//     for (std::tuple<int, int, int> edge : mst)
//     {
//         std::cout << "(" << std::get<1>(edge) << ","
//                   << std::get<2>(edge) << ")" << " ";
//         totalWeight += std::get<0>(edge);
//     }
//     std::cout << std::endl;
//     std::cout << "Total weight: " << totalWeight << std::endl;
// }

std::pair<int, int>& GetParent(std::vector<std::pair<int, int>> &parent,
                               int vertex)
{
    int p = parent[vertex].first;
    while (p != parent[p].first)
    {
        p = parent[p].first;
    }
    return parent[p];
}

// Better implementation using built-in std::sort and union find
// data structure
void Kruskals(std::vector<std::vector<std::pair<int, int>>> &list)
{
    // Didn't define the graph well so organize into a better structure
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            int weight = std::get<1>(list[i][j]);
            int node1 = i;
            int node2 = std::get<0>(list[i][j]);
            std::pair<int, int> nodes = std::make_pair(node1, node2);
            edges.push_back(std::make_pair(weight, nodes));
        }
    }

    std::sort(edges.begin(), edges.end());

    std::vector<std::pair<int, int>> parent(list.size());
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = std::make_pair(i, 1);
    }

    std::vector<std::pair<int, std::pair<int, int>>> mst;
    for (std::pair<int, std::pair<int, int>> edge : edges)
    {
        std::pair<int, int> &parent1 = GetParent(parent, edge.second.first);
        std::pair<int, int> &parent2 = GetParent(parent, edge.second.second);
        if (parent1.first != parent2.first)
        {
            if (parent1.second > parent2.second)
            {
                parent2.first = parent1.first;
            }
            else if (parent2.second > parent1.second)
            {
                parent1.first = parent2.first;
            }
            else
            {
                parent2.first = parent1.first;
                parent1.second++;
            }
            mst.push_back(std::make_pair(edge.first, std::make_pair(edge.second.first, edge.second.second)));
        }
    }

    int totalWeight = 0;
    for (std::pair<int, std::pair<int, int>> edge : mst)
    {
        std::cout << "(" << edge.second.first << ","
                  << edge.second.second << ")" << std::endl;
        totalWeight += edge.first;
    }
    std::cout << "Total weight: " << totalWeight << std::endl;
}

// A better way is to store your data based on edges and iterate
// through that, which will contain the linked vertices. The
// outer loop is supposed to run V-1 times while the inner loop
// is supposed to run E times for a runtime of O(VE)
void BellmanFord(std::vector<std::vector<std::pair<int, int>>> &list,
                 int start,
                 int end)
{
    std::vector<int> minDistance(list.size(), INT_MAX);

    minDistance[start] = 0;
    bool updated = true;
    for (int i = 0; i < minDistance.size() - 1; i++)
    {
        if (!updated)
        {
            break;
        }
        for (int j = 0; j < minDistance.size(); j++)
        {
            if (minDistance[j] == INT_MAX)
            {
                continue;
            }
            else
            {
                updated = false;
                for (int k = 0; k < list[j].size(); k++)
                {
                    int vertex = list[j][k].first;
                    int weight = list[j][k].second;
                    if (minDistance[j] + weight < minDistance[vertex])
                    {
                        minDistance[vertex] = minDistance[j] + weight;
                        updated = true;
                    }
                }
            }
        }
    }

    bool hasNegCycle = false;
    for (int i = 0; i < list.size(); i++)
    {
        if (hasNegCycle)
        {
            break;
        }
        for (int j = 0; j < list[i].size(); j++)
        {
            int vertex = list[i][j].first;
            int weight = list[i][j].second;
            if (minDistance[i] + weight < minDistance[vertex])
            {
                hasNegCycle = true;
                break;
            }
        }
    }

    if (hasNegCycle)
    {
        std::cout << "Error: Negative cycle exists" << std::endl;
    }
    else
    {
        std::cout << "Min distance to " << end << " is: " << minDistance[end] << std::endl;
    }
}

// This is for an undirected graph. If you have a directed
// graph, then instead of having a parent array, make an
// array called recurStack which stores which vertices have
// been encountered on the current dfs tree. Reset the vertex
// value as you pop it off the stack
bool HasCycleDFS(std::vector<std::vector<int>> &mat)
{
    std::vector<bool> visited(mat.size(), false);
    std::vector<int> parent(mat.size(), -1);
    std::stack<int> st;

    for (int i = 0; i < mat.size(); i++)
    {
        if (!visited[i])
        {
            st.push(i);
            parent[i] = i;
            while (!st.empty())
            {
                int vertex = st.top();
                st.pop();
                visited[vertex] = true;
                for (int j = 0; j < mat[vertex].size(); j++)
                {
                    if (mat[vertex][j] && j != parent[vertex])
                    {
                        if (visited[j])
                        {
                            return true;
                        }
                        else
                        {
                            st.push(j);
                            parent[j] = vertex;
                        }
                    }
                }
            }
        }
    }

    return false;
}

// For a directed graph so we aren't checking if we are
// looking at an edge that points back to your parent
void TopSortDFS(std::vector<std::vector<int>> &mat)
{
    std::stack<int> topOrder;
    std::vector<bool> processed(mat.size(), false);
    std::stack<int> st;
    
    for (int i = 0; i < mat.size(); i++)
    {
        if (!processed[i])
        {
            st.push(i);
            while (!st.empty())
            {
                int vertex = st.top();
                bool noEdgesLeft = true;
                for (int j = 0; j < mat[vertex].size(); j++)
                {
                    if (mat[vertex][j] && !processed[j])
                    {
                        // CHECK FOR CYCLES HERE
                        st.push(j);
                        noEdgesLeft = false;
                    }
                }

                if (noEdgesLeft)
                {
                    processed[st.top()] = true;
                    topOrder.push(st.top());
                    st.pop();
                }
            }
        }
    }

    std::cout << "Topological order: ";
    while (!topOrder.empty())
    {
        std::cout << topOrder.top() << " ";
        topOrder.pop();
    }
    std::cout << std::endl;
}

void TopSortInDegree(std::vector<std::vector<int>> &mat)
{
    std::queue<int> topOrder;
    std::vector<int> degree(mat.size(), 0);
    std::vector<bool> processed(mat.size(), false);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j])
            {
                degree[j]++;
            }
        }
    }

    while (topOrder.size() < mat.size())
    {
        for (int i = 0; i < mat.size(); i++)
        {
            if (degree[i] == 0 && !processed[i])
            {
                topOrder.push(i);
                for (int j = 0; j < mat[i].size(); j++)
                {
                    if (mat[i][j])
                    {
                        degree[j]--;
                    }
                }
                processed[i] = true;
            }
        }
    }

    std::cout << "Topological order: ";
    while (!topOrder.empty())
    {
        std::cout << topOrder.front() << " ";
        topOrder.pop();
    }
    std::cout << std::endl;
}

// Use BFS here for practice, but can use DFS as well
// because both traverse all connected components of
// the starting node
void NumConnectedComponents(std::vector<std::vector<int>> &list)
{
    std::queue<int> q;
    std::vector<bool> visited(list.size(), false);
    int numConnectedComps = 0;

    for (int i = 0; i < list.size(); i++)
    {
        if (!visited[i])
        {
            q.push(i);
            while (!q.empty())
            {
                int vertex = q.front();
                q.pop();
                for (int j = 0; j < list[vertex].size(); j++)
                {
                    if (!visited[list[vertex][j]])
                    {
                        q.push(list[vertex][j]);
                    }
                }
                visited[vertex] = true;
            }
            numConnectedComps++;
        }
    }

    std::cout << "Number of connected components is: " << numConnectedComps << std::endl;
}

// For a shorter way to write this, look at
// https://www.topcoder.com/thrive/articles/kosarajus-algorithm-for-strongly-connected-components
// It's more code efficient to use recursion rather than iterative
void ListStronglyConnectedComponents(std::vector<std::vector<int>> &list)
{
    std::stack<int> st;
    std::vector<bool> visited(list.size(), false);
    std::stack<int> finishingTimeOrder;

    for (int i = 0; i < list.size(); i++)
    {
        if (!visited[i])
        {
            st.push(i);
            while (!st.empty())
            {
                int vertex = st.top();
                visited[vertex] = true;
                bool noEdgesLeft = true;
                for (int j = 0; j < list[vertex].size(); j++)
                {
                    if (!visited[list[vertex][j]])
                    {
                        noEdgesLeft = false;
                        st.push(list[vertex][j]);
                    }
                }

                if (noEdgesLeft)
                {
                    finishingTimeOrder.push(st.top());
                    st.pop();
                }
            }
        }
    }

    std::vector<std::vector<int>> rList(list.size());
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            rList[list[i][j]].push_back(i);
        }
        visited[i] = false;
    }

    while(!finishingTimeOrder.empty())
    {
        int vertex = finishingTimeOrder.top();
        finishingTimeOrder.pop();
        if (visited[vertex])
        {
            continue;
        }
        visited[vertex] = true;
        std::cout << vertex << " ";
        bool noMoreEdges = true;
        for (int i = 0; i < rList[vertex].size(); i++)
        {
            if (!visited[rList[vertex][i]])
            {
                finishingTimeOrder.push(rList[vertex][i]);
                noMoreEdges = false;
            }
        }
        if (noMoreEdges)
        {
            std::cout << std::endl;
        }
    }
}

bool IsBipartite(std::vector<std::vector<int>> &list)
{
    std::queue<int> q;
    std::vector<int> color(list.size(), -1);

    for (int i = 0; i < list.size(); i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;
            while(!q.empty())
            {
                int vertex = q.front();
                q.pop();
                for (int j = 0; j < list[vertex].size(); j++)
                {
                    int v = list[vertex][j];
                    if (color[v] == -1)
                    {
                        q.push(v);
                        color[v] = 1 - color[vertex];
                    }
                    else if (color[v] != 1 - color[vertex])
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    // Our graph
    // 0 -- 2 -- 3 -- 6     4
    // | \       |          |
    // |  \      |          |
    // 8   5     1          9
    // |
    // |
    // 7

    std::vector<std::vector<int>> adj_list(10);

    adj_list[0].push_back(2); adj_list[0].push_back(5); adj_list[0].push_back(8);
    adj_list[1].push_back(3);
    adj_list[2].push_back(0); adj_list[2].push_back(3);
    adj_list[3].push_back(2); adj_list[3].push_back(6); adj_list[3].push_back(1);
    adj_list[4].push_back(9);
    adj_list[5].push_back(0);
    adj_list[6].push_back(3);
    adj_list[7].push_back(8);
    adj_list[8].push_back(0); adj_list[8].push_back(7);
    adj_list[9].push_back(4);

    std::cout << "CONFIRMING LIST SETUP" << std::endl;
    std::vector<int>::iterator iter;
    for (int i = 0; i < adj_list.size(); i++) {
        for (iter = adj_list[i].begin(); iter != adj_list[i].end(); iter++) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "BFS WITH LIST" << std::endl;
    BFS_List(adj_list);
    std::cout << std::endl;

    std::cout << "DFS RECURSIVE WITH LIST PRE ORDER" << std::endl;
    DFS_List_Recursive(adj_list);
    std::cout << std::endl;

    std::cout << "DFS ITERATIVE WITH LIST PRE ORDER" << std::endl;
    DFS_List_Iterative(adj_list);
    std::cout << std::endl;

    std::cout << "DFS RECURSIVE WITH LIST POST ORDER" << std::endl;
    DFS_List_Recursive_PostOrder(adj_list);
    std::cout << std::endl;

    std::cout << "DFS ITERATIVE WITH LIST POST ORDER" << std::endl;
    DFS_List_Iterative_PostOrder(adj_list);
    std::cout << std::endl;

    std::cout << "COUNT CONNECTED COMPONENTS" << std::endl;
    NumConnectedComponents(adj_list);
    std::cout << std::endl;

    std::cout << "CHECK BIPARTITE" << std::endl;
    if (IsBipartite(adj_list))
    {
        std::cout << "Graph is bipartite" << std::endl;
    }
    else
    {
        std::cout << "Graph is not bipartite" << std::endl;
    }
    std::cout << std::endl;
    
    std::vector<std::vector<int>> adj_mat(10, std::vector<int>(10, 0));
    for (int i = 0; i < adj_list.size(); i++)
    {
        for (int j : adj_list[i])
        {
            adj_mat[i][j]++;
        }
    }

    std::cout << "CONFIRMING MATRIX SETUP" << std::endl;
    for (int i = 0; i < adj_mat.size(); i++)
    {
        for (int j = 0; j < adj_mat[0].size(); j++)
        {
            std::cout << adj_mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "BFS WITH MATRIX" << std::endl;
    BFS_Matrix(adj_mat);
    std::cout << std::endl;

    std::cout << "DFS RECURSIVE WITH MATRIX" << std::endl;
    DFS_Matrix_Recursive(adj_mat);
    std::cout << std::endl;

    std::cout << "DFS ITERATIVE WITH MATRIX" << std::endl;
    DFS_Matrix_Iterative(adj_mat);
    std::cout << std::endl;

    // Dijkstra's and minimum spanning tree graph
    // https://en.wikipedia.org/wiki/File:Dijkstra_Animation.gif
    // Decrement each vertex so that we start from 0
    std::vector<std::vector<std::pair<int, int>>> list(6);
    list[0].push_back(std::make_pair(1, 7));
    list[0].push_back(std::make_pair(2, 9));
    list[0].push_back(std::make_pair(5, 14));
    list[1].push_back(std::make_pair(0, 7));
    list[1].push_back(std::make_pair(2, 10));
    list[1].push_back(std::make_pair(3, 15));
    list[2].push_back(std::make_pair(0, 9));
    list[2].push_back(std::make_pair(1, 10));
    list[2].push_back(std::make_pair(3, 11));
    list[2].push_back(std::make_pair(5, 2));
    list[3].push_back(std::make_pair(1, 15));
    list[3].push_back(std::make_pair(2, 11));
    list[3].push_back(std::make_pair(4, 6));
    list[4].push_back(std::make_pair(3, 6));
    list[4].push_back(std::make_pair(5, 9));
    list[5].push_back(std::make_pair(0, 14));
    list[5].push_back(std::make_pair(4, 9));

    std::cout << "DIJKSTRA'S" << std::endl;
    DjikstrasFaster(list, 0, 4);
    std::cout << std::endl;

    std::cout << "MIN SPAN TREE PRIMS" << std::endl;
    Prims(list);
    std::cout << std::endl;

    std::cout << "MIN SPAN TREE KRUSKALS" << std::endl;
    Kruskals(list);
    std::cout << std::endl;

    std::cout << "BELLMAN FORD'S" << std::endl;
    BellmanFord(list, 0, 4);
    std::cout << std::endl;

    // Graph taken from
    // https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#/media/File:6n-graf.svg
    // Decrement each vertex so that we start from 0
    std::vector<std::vector<int>> mat(6, std::vector<int>(6, 0));
    mat[0][1] = 1; mat[0][4] = 1;
    mat[1][0] = 1; mat[1][4] = 1; mat[1][2] = 1;
    mat[2][1] = 1; mat[2][3] = 1;
    mat[3][2] = 1; mat[3][5] = 1;
    mat[4][0] = 1; mat[4][1] = 1; mat[4][3] = 1;
    mat[5][3] = 1;

    std::cout << "CYCLE CHECK DFS" << std::endl;
    if(HasCycleDFS(mat))
    {
        std::cout << "Has a cycle" << std::endl;
    }
    else
    {
        std::cout << "Does not have a cycle" << std::endl;
    }
    std::cout << std::endl;

    mat[2][1] = 0; mat[1][2] = 0;
    mat[1][0] = 0; mat[0][1] = 0;
    std::cout << "CYCLE CHECK DFS" << std::endl;
    if(HasCycleDFS(mat))
    {
        std::cout << "Has a cycle" << std::endl;
    }
    else
    {
        std::cout << "Does not have a cycle" << std::endl;
    }
    std::cout << std::endl;

    // Graph taken from
    // https://en.wikipedia.org/wiki/File:Directed_acyclic_graph_2.svg
    // No decrementing vertices here due to too many gaps
    // Just make all 0s for the missing vertices
    std::vector<std::vector<int>> dagMat(12, std::vector<int>(12, 0));
    dagMat[5][11] = 1;
    dagMat[7][11] = 1; dagMat[7][8] = 1;
    dagMat[3][8] = 1; dagMat[3][10] = 1;
    dagMat[11][2] = 1; dagMat[11][9] = 1; dagMat[11][10] = 1;
    dagMat[8][9] = 1;

    std::cout << "TOPOLOGICAL SORT DFS" << std::endl;
    TopSortDFS(dagMat);
    std::cout << std::endl;

    std::cout << "TOPOLOGICAL SORT INDEGREE" << std::endl;
    TopSortInDegree(dagMat);
    std::cout << std::endl;

    // Graph taken from
    // https://images.ctfassets.net/piwi0eufbb2g/6oUnkJaqwSOwrkEAbLAho3/d4aa587a030f9e870abc88e993cc0e2a/image.png
    std::vector<std::vector<int>> strongList(8);
    strongList[0].push_back(1);
    strongList[1].push_back(2);
    strongList[2].push_back(0); strongList[2].push_back(3);
    strongList[3].push_back(4);
    strongList[4].push_back(5); strongList[4].push_back(7);
    strongList[5].push_back(6);
    strongList[6].push_back(7); strongList[6].push_back(4);

    std::cout << "LIST STRONGLY CONNECTED COMPONENTS" << std::endl;
    ListStronglyConnectedComponents(strongList);
    std::cout << std::endl;

    // Triangle
    std::vector<std::vector<int>> bpList(3);
    bpList[0].push_back(1); bpList[0].push_back(2);
    bpList[1].push_back(0); bpList[1].push_back(2);
    bpList[2].push_back(0); bpList[2].push_back(1);

    if (IsBipartite(bpList))
    {
        std::cout << "Graph is bipartite" << std::endl;
    }
    else
    {
        std::cout << "Graph is not bipartite" << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}