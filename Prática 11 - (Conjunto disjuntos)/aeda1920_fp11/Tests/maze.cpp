#include "maze.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>

using namespace std;

DisjointSets Maze::getSets() const {
    return maze;
}

void Maze::printMaze() const
{
    cout << setw(3) << " ";
    for (int j=0; j<ncols; j++) {
        cout << setw(6) << "______";
    }
    for (int i=0; i<nrows; i++) {
        cout << endl;
        cout << setw(3) << "|";
        for (int j=0; j<ncols-1; j++) {
            int val = i*nrows+j;
            cout << setw(3) << val<<setw(3);
            if (noWalls.empty() ||
                (find(noWalls.begin(),noWalls.end(),pair<int,int>(val,val+1)) == noWalls.end() &&
                 find(noWalls.begin(),noWalls.end(),pair<int,int>(val+1,val)) == noWalls.end())
                    )
                cout << "|";
            else
                cout <<" ";
        }
        int val = i*nrows+ncols-1;
        cout << setw(3) << val<<setw(3) << "|";
        cout <<endl;
        cout << setw(3) << " ";
        for (int j=0; j<ncols; j++) {
            int val = i*nrows+j;
            if (i<nrows-1) {
                if ( noWalls.empty() ||
                     (find(noWalls.begin(), noWalls.end(), pair<int, int>(val, val + ncols)) == noWalls.end()
                      && find(noWalls.begin(), noWalls.end(), pair<int, int>(val+ncols, val)) == noWalls.end())
                        )
                    cout << setw(6) << "______";
                else
                    cout << setw(6) << " ";
            } else
                cout << setw(6) << "______";
        }

    }
    cout <<endl << endl;
}



// a implementar

Maze::Maze(int rows, int cols) {
    this->ncols = cols;
    this->nrows = rows;
    this->maze =  DisjointSets (ncols*nrows);
}

vector<int> Maze::getNeighbours(int x) const {
    vector<int> res;
    if(x%ncols > 0){ // há elementos a esquerda
        res.push_back(x-1);
        //cout << " elemento " << x << " possui o elementos " << x-1 <<" a esquerda \n";
    }
    if((x+1)%ncols > 0) { // há elementos a direita
        res.push_back(x+1);
        //cout << " elemento " << x << " possui o elementos " << x + 1 << " a direita \n";
    }if((x+ncols)<(ncols*nrows)){ // há vizinho abaixo
        res.push_back(x+5);
        //cout << " elemento " << x << " possui o elementos " << x + 5 << " abaixo \n";
    }
    if(((x-ncols)>=0)){ // há vizinhos acima;
        res.push_back(x-5);
        //cout << " elemento " << x << " possui o elemento " << x - 5 << " acima \n";
    }
    return res;
}

void Maze::buildRandomMaze() {
    srand(time(NULL));
    vector<int> height;
    int i = 0;
    int j;
    while(this->maze.getNumberOfSets() != 1){
        height =this->getNeighbours(i);
        j = height[rand() % height.size()];

        if(this->maze.find(j) != this->maze.find(i) && this->maze.find(j) == j){
            this->maze.unionSets(i, j);
            noWalls.emplace_back(i,j);
        }
        (i+1==ncols*nrows) ? i = 0 : i++;
    }
}

