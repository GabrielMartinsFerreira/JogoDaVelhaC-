#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';

void draw_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void player_turn() {
    int choice;
    cout << "Player " << player << ", escolha uma posição: ";
    cin >> choice;

    int row = --choice / 3;
    int col = choice % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "Posição já escolhida, escolha outra" << endl;
        player_turn();
    }
}

char check_win() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return '/';
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    draw_board();

    while (true) {
        player_turn();
        draw_board();

        if (check_win() == 'X') {
            cout << "Jogador X venceu!" << endl;
            break;
        } else if (check_win() == 'O') {
            cout << "Jogador O venceu!" << endl;
            break;
        }

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }

    return 0;
}
