#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
//... Объявление переменных чтения, записи из файла (потоки чтения)
ifstream input_file("in.txt");
ofstream output_file("out.txt");
vector < vector<int> > g;
vector <int> color; // цвет вершины (0, 1, или 2)
vector<int> time_in, time_out; // "времена" захода и выхода из вершины
 
int dfs_timer = 0; // "таймер" для определения времён
int n, i, ch, vector_i, list_i;
 
bool dfs(int v)
{
    for (int i=1; i<g[v].size(); i++)
    {
        if (color[g[v][i]]==1 && color[v]==2 ||
            color[g[v][i]]==2 && color[v]==1)
            return false;
        else if (color[v]==1) {
            if (g[v][i] == 2)
                continue;
            color[g[v][i]] = 2;
        }
        else {
            if (g[v][i] == 1)
                continue;
            color[g[v][i]] = 1;
        }
        return dfs(g[v][i]);
    }
    return true;
}
 
int main(){
	input_file >> n;
    for (i = 0; i <= n; i++){
        color.push_back(0);
    }
    color[1]=1;
    g.push_back(vector<int>());
    for (int i = 1; i <= n; i++){
        int t = -1;
        g.push_back(vector<int>());
        g[i].push_back(0);
        while (true)
        {
			input_file >> t;
            if (t == 0)
                break;
            g[i].push_back(t);
        }
    }
 
    bool ok = dfs(1);
 
    if (ok == true)
    {
		output_file<< "YES" << endl; //добавить вывод вершин входящих в доли графа
        vector<int> white, black;
        for (int i=1; i<=n; i++)
            if (color[i]==1)
                white.push_back(i);
            else
                black.push_back(i);
 
        sort(white.begin(), white.end());
        sort(black.begin(), black.end());
 
        if (white[0]<black[0])
        {
            for (int i=0; i<white.size(); i++)
				output_file << white[i] << " ";
			output_file << endl << "0" << endl;
            for (int i=0; i<black.size(); i++)
				output_file << black[i] << " ";
        }
        else
        {
            for (int i=0; i<black.size(); i++)
				output_file << black[i] << " ";
			output_file << endl << "0" << endl;
            for (int i=0; i<white.size(); i++)
				output_file << white[i] << " ";
        }
    }
    else
		output_file  << "NO"; //добавить вывод вершин входящих в доли графа
    return 0;
    }
