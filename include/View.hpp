#ifndef VIEW_HPP
#define VIEW_HPP
#include<vector>
#include<iostream>
using namespace std;


class View
{
private:
    int row , column;
    const std::vector<std::vector<char>>& boardData;;
public:
    View(int r, int c, const std::vector<std::vector<char>>& data);
    ~View();

    void draw() const;
};


#endif
