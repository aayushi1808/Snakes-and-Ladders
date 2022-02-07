#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct block
{	int step_number;
	int distance;
};
int min_steps(int board[], int length)
{	list<block> q;
	block temp = {0, 0};
	q.push_back(temp);
	bool* visited = new bool[length];
	for (int i = 0; i < length; ++i)
		visited[i] = false;
	while (q.empty() == false)
	{	temp = q.front();
		q.pop_front();
		if (temp.distance == length - 1)
			break;
		for (int i = temp.distance + 1; (i <= temp.distance + 6) && (i < length); i++)
		{	if (visited[i] == false)
			{	block temp1;
				temp1.step_number = temp.step_number + 1;
				visited[i] = true;
				if (board[i] != -1)
					temp1.distance = board[i];
				else
					temp1.distance = i;
				q.push_back(temp1);

			}
		}
	}
	return temp.step_number;
}
int main()
{	int board[1000], length;
	cout << "Enter the size of board:-\n";
	cin >> length;
	for (int i = 0; i < length; i++)
		board[i] = -1;
	int ladders, snakes;
	cout << "Enter the number of ladders in the board:-\n";
	cin >> ladders;
	cout << "Enter the number of snakes in the board :-\n";
	cin >> snakes;
	cout << "enter the ladders:-\n";
	for (int i = 0; i < ladders; i++)
	{	int x, y;
		cout << "from:- ";
		cin >> x;
		cout << "to :- ";
		cin >> y;
		board[x] = y;
	}
	cout << "enter the snakes:-\n";
	for (int i = 0; i < snakes; i++)
	{	int x, y;
		cout << "from:- ";
		cin >> x;
		cout << "to :- ";
		cin >> y;
		board[x] = y;
	}
	cout << "the minimum number of steps to be taken to complete the board:-\n" << min_steps(board, length);
}