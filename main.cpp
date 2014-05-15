#include <iostream>
#include <fstream>
#include <queue>
#define BIGNR 9999999
using namespace std;
int n,a[1000][1000],x,y;
int t[1000],d[1000],viz[1000];
queue <int> que;

int distMin()
{
	int indMin=1, dMin=BIGNR;
	for (int i = 1; i <= n;i++)
	if (dMin > d[i] && viz[i] == 0)
		indMin = i, dMin = d[i];
	return indMin;
}

void print(int nod)
{
	if (nod>0)
	{
		print(t[nod]);
		cout << nod << " ";
	}
}

void Dijkstra(int nod)
{
	for (int i = 1; i <= n; i++)
		d[i] = BIGNR;
	d[nod] = 0;
	for (int i = 1; i <= n; i++)
		t[i] = -1;
	for (int i = 1; i < n; i++)
	{
		int minD = distMin();
		viz[minD] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (viz[j] == 0 && a[minD][j] && d[minD] + a[minD][j] < d[j])
				d[j] = d[minD] + a[minD][j],t[j]=minD;
		}
	}

}

int main()
{
	ifstream f("graf.in");
	ofstream g("graf.out");
	f >> n >> x >> y;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		f >> a[i][j];

	Dijkstra(x);
	cout <<"Distanta minima e: "<< d[y] << "\nSi drumul e: ";
	print(y);

	system("pause");
	return 0;
}