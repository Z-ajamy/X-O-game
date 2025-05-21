#include <iostream>
#include "../include/Board.hpp"

using namespace std;

void test_initialization() {
    Board b(3, 3);
    cout << "[T] Board initialized to 3x3" << endl;
}

void test_set_and_get() {
    Board b(3, 3);
    b.setdata(1, 1, 'X');
    char val = b.getCell(1, 1);
    if (val == 'X')
        cout << "[T] Set and Get Cell works correctly" << endl;
    else
        cout << "[F] Set or Get failed" << endl;
}

void test_isCellEmpty() {
    Board b(3, 3);
    if (b.isCellEmpty(0, 0))
        cout << "[T] Empty cell recognized" << endl;
    b.setdata(0, 0, 'O');
    if (!b.isCellEmpty(0, 0))
        cout << "[T] Occupied cell recognized" << endl;
    else
        cout << "[F] Cell state not updated correctly" << endl;
}

void test_isFull() {
    Board b(2, 2);
    b.setdata(0, 0, 'X');
    b.setdata(0, 1, 'O');
    b.setdata(1, 0, 'X');
    b.setdata(1, 1, 'O');
    if (b.isFull())
        cout << "[T] Board full detection works" << endl;
    else
        cout << "[F] isFull failed" << endl;
}

void test_reset() {
    Board b(2, 2);
    b.setdata(0, 0, 'X');
    b.reset();
    if (b.isCellEmpty(0, 0))
        cout << "[T] Reset cleared the board" << endl;
    else
        cout << "[F] Reset failed" << endl;
}

void test_resize() {
    Board b(2, 2);
    b.resizeBoard(4, 4);
    if (b.getRowCount() == 4 && b.getColCount() == 4)
        cout << "[T] Resize successful" << endl;
    else
        cout << "[F] Resize failed" << endl;
}

int main() {
    cout << "===== Running Board Tests =====\n" << endl;

    test_initialization();
    test_set_and_get();
    test_isCellEmpty();
    test_isFull();
    test_reset();
    test_resize();

    cout << "\n===== Tests Finished =====" << endl;
    return 0;
}
