#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void display_board() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

bool is_valid_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

bool has_won(char player) {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;
    int row, col;
    bool game_over = false;

    while (!game_over) {
        display_board();
        cout << "Player " << current_player << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;
        if (is_valid_move(row, col)) {
            board[row][col] = current_player;
            if (has_won(current_player)) {
                display_board();
                cout << "Player " << current_player << " has won!\n";
                game_over = true;
            } else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '
                       && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '
                       && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
                display_board();
                cout << "It's a tie!\n";
                game_over = true;
            } else {
                current_player = (current_player == player1) ? player2 : player1;
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}
