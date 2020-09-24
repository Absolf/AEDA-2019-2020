#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <vector>
#include <iostream>
using namespace std;

class DisjointSets
{
    vector<int> set;
public:
    DisjointSets();
    DisjointSets(const DisjointSets &m1);
    DisjointSets(int n);
    int find(int v) const;
    void unionSets(int root1, int root2);
    int getNumberOfSets() const;
};

#endif
