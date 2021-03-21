#include<iostream>
#include <conio.h>  
using namespace std;
#define MAX 100

int edge[MAX][MAX]
{
	//0, 1, 2, 3, 4, 5, 6, 7
	 {0, 0, 0, 0, 0, 0, 0, 0}, //row 0
	 {0, 0, 5, 0, 3, 0, 0, 0}, //row 1
	 {0, 0, 0, 1, 0, 0, 0, 0}, //row 2
	 {0, 0, 0, 0, 0, 6, 0, 8}, //row 3
	 {0, 0, 0, 0, 0, 2, 2, 0}, //row 4
	 {0, 0, 4, 0, 0, 0, 0, 0}, //row 5
	 {0, 0, 0, 0, 0, 0, 0, 3}, //row 6
	 {0, 0, 0, 0, 0, 4, 0, 0}, //row 7
};
//chứa matrix trọng số
int trace[MAX]; //đường đi
int numV = 7 /*số điểm*/,
finish = 7 /*điểm kết thúc*/,
start = 1 /*bắt đầu*/,
front = 1, // điểm đầu hàng đợi ưu tiên
rear = 1,  //điểm cuối hàng đợi ưu tiên
u, v;
typedef struct node
{
	int vertex/* điểm*/;
	int cost /* trọng số*/;
}node;
node queue[MAX];
void enqueue(int vertex, int cost);
node dequeue();
int isEmty();
void ucs();
int main()
{
	ucs();
	if (trace[finish] == 0)
		cout << "not found";
	else
	{
		while (finish != start)
		{
			printf_s("%d <-", finish);
			finish = trace[finish];
		}
		cout << start;
	}
	return 0;
	//getch();
}
void enqueue(int vertex, int cost)
{
	node v;
	v.vertex = vertex;
	v.cost = cost;
	int index;
	for (index = front; index <= rear; index++) //tìm vị trí hàng đợi ưu tiên
		if (v.cost < queue[rear].cost) //điểm hiện tại có chi phí nhỏ hơn chi phí của điểm trong hàng đợi ưu tiên
			break;
	if (index == rear + 1) //điểm đang xét có chi phí lớn nhất 
	{
		rear++;
		queue[rear] = v; //được đưa vào cuối hàng đợi
	}
	else
	{
		for (int k = rear; k >= index; k--) //chèn điểm đang xét vào vị trí nào đó trong hàng đợi
			queue[k + 1] = queue[k];
		queue[index] = v;
		rear++;
	}
}
node dequeue()
{
	node u = queue[front];
	front++;
	return u;
}
int isEmty()
{
	if (front > rear) //kiểm tra hàng đợi có bị rỗng không
		return 1;
	return 0;
}
void ucs()
{
	node nodestart;
	nodestart.vertex = start;
	nodestart.cost = 0;
	queue[front] = nodestart;
	trace[front] = -1;
	do
	{
		u = dequeue().vertex;
		if (u == finish)
			break;
		for (int v = 1; v <= numV; v++)
			if (edge[u][v] != 0 /*có đường đi từ u tới v?*/ && trace[v] == 0 /*điểm v đã được xét?*/)
			{
				enqueue(v, edge[u][v]);
				trace[v] = u;
			}
	} while (!isEmty());
}