// Thuat toan BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n;
int matrix[1001][1001];
bool visited[1001];
void Init();
void BFS(int u);
int main()
{
	int u;
	Init();
	cout << "Chon dinh bat dau: ";
	cin >> u;
	BFS(u);
	return 0;
}
//nhập dữ liệu
void Init()	// gồm 1 mảng 2 chiều , chỉ có số 0 và 1
{

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> matrix[i][j];
		}
		visited[i] = false;
		//đánh dấu chưa đi qua
	}
}

void BFS(int u)
{
	cout << "BFS(" << u << "): ";
	queue<int> Q;
	Q.push(u);
	visited[u] = true;
	while (!Q.empty())
	{
		int s = Q.front();
		cout << s << " ";
		Q.pop();
		for (int t = 1; t <= n; t++)
		{
			if (visited[t] == false && matrix[s][t] == 1)
			{
				Q.push(t);
				// đánh dấu đường đã đi qua
 				visited[t] = true;
			}
		}
	}
}