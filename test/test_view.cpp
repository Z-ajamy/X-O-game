#include "../include/View.hpp"

using namespace std;

int main() {
    int rows = 3;
    int cols = 3;

    vector<vector<char>> testBoard = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', ' ', ' '}
    };

    View view(rows, cols, testBoard);
    cout << "Testing View::draw() output:" << endl;
    view.draw();

    return 0;
}
