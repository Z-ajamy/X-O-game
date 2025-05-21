#include "../include/Board.hpp"
#include <iostream>

using namespace std;

int main() {
    int rows = 3;
    int cols = 3;

    Board board(rows, cols);


    const auto& initialData = board.getdata();

    cout << "Initial Board state:" << endl;
    for (const auto& row : initialData) {
        for (char c : row)
            cout << "[" << c << "]";
        cout << endl;
    }

    board.setdata(0, 0, 'X');
    board.setdata(1, 1, 'O');
    board.setdata(2, 2, 'X');

    const auto& updatedData = board.getdata();

    cout << "\nUpdated Board state:" << endl;
    for (const auto& row : updatedData) {
        for (char c : row)
            cout << "[" << c << "]";
        cout << endl;
    }

    return 0;
}
