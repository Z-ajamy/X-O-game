#include"../include/View.hpp"

View::View(int r, int c, const std::vector<std::vector<char>>& data)
: row(r), column(c), boardData(data) {}

View::~View(){}

void View::draw() const
{
    cout << "   ";
	for (int j = 0; j < column ; j++)
		{
			cout << j << "  ";
		}
		cout << endl;
	for (int i = 0; i < row ; i++)
	{
		cout << "  ";
		for (int n = 0; n < column* 3; n++)
            {
                cout << "-";
            }
            cout << endl ;
		cout << i<< " ";
		for (int j = 0; j < column ; j++)
		{   
            if (j == 0)
            {
                cout << "|";
                cout << boardData[i][j];
                cout << ":";
            }
            else if (j == column - 1)
            {
                cout << ":";
                cout << boardData[i][j];
                cout << "|";
            }
            
            else
            {
                cout << ":";
                cout << boardData[i][j];
                cout << ":";
            }
		}
		cout <<  endl;
		if(i == row - 1)
		{
			cout << "  ";
            for (int n = 0; n < column* 3; n++)
            {
                cout << "-";
            }
            cout << endl ;
		}
	}
}
