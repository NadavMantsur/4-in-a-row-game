#include <stdio.h>
#include <stdbool.h>

#define BOARD_MAX_SIDE 9
#define BOARD_MIN_SIDE 3
#define MIN_TOKENS 3
#define MOVE_MAX_SIZE 81

#define RED_SLOT_SYMBOL ('R')
#define YELLOW_SLOT_SYMBOL ('Y')
#define EMPTY_SLOT_SYMBOL (' ')
#define UNDO ('-1')
#define REDO ('-2')



//----------------------- Message Identifiers --------------------------//
#define MSG_GET_BOARD_ROWS   0
#define MSG_GET_BOARD_COLS   1
#define MSG_GET_NUMBER_TOKENS 2


//--------------------------- Board Edges ------------------------------//

#define BOARD_VERT_SEP  '|'
#define BOARD_LEFT_ANG '\\'
#define BOARD_RIGHT_ANG '/'
#define BOARD_BOTTOM  '-'
#define BOARD_BOTTOM_SEP '-'



//----------------------------------------------------------------------//


void print_welcome_message();

void print_read_game_params_message(int param);

void print_chose_color_message();

void print_chose_move_message(int player);

void print_enter_column_message();

void print_full_column_message();

void print_unavailable_undo_redo_message();


/*
 * Outputs game board.
 *
 * board - contains spaces for empty cells, 'Y' or 'R' for
 *         respective player cells.
 * board_side - contains board dimensions {rows, cols}
 */
void print_board(char board[][BOARD_MAX_SIDE], int board_side[]);

/*
 * Outputs winner or tie message.
 *
 * player_id - the id to be output. Pass <0 for tie.
 */
void print_winner(int player_id);

char CheckColorInput();

char SetPlayer2Color(char player1_color);

int Check_Rows_Size();

int Check_Cols_Size(int rows);

int Check_Token_Input(int rows, int cols);

bool Check_Full_Col(char board[][BOARD_MAX_SIDE], int chosen_col);

bool Check_Chosen_Move(char board[][BOARD_MAX_SIDE], int *count_ptr,
                       char player1_color, char player2_color, int num_of_rows, int toks, int num_of_cols, int board_side[2], int *moves,
                       int *count_moves_ptr);

void fixarray( char array[][BOARD_MAX_SIDE]){
    for(int row = 0; row<BOARD_MAX_SIDE; row++){
        for(int col = 0; col<BOARD_MAX_SIDE; col++){
            array[row][col] = ' ';
        }
    }
}

//--------------------------- Main Program -----------------------------//

int main() {
    char player1_color = CheckColorInput();
    //char *ptr_p1 = &player1_color;
    //char *ptr_player_turn = &player1_color;
    char player2_color = SetPlayer2Color(player1_color);

    //char *ptr_p2 = &player2_color;
    int num_of_rows = Check_Rows_Size();
    int num_of_cols = Check_Cols_Size(num_of_rows);
    int num_of_toks = Check_Token_Input(num_of_rows, num_of_cols);
    int moves[MOVE_MAX_SIZE];


    //Array's length is not meant to be changed at run-time
    //for initiate empty array.
    char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE];
    fixarray(board);
    int board_side[2] = {num_of_rows, num_of_cols};

    print_board(board, board_side);

    int count = 0;
    int *count_ptr = &count;
    int count_moves = 0;
    int *count_moves_ptr = &count_moves;
    //int chosen_col = Check_Chosen_Move(board, count_ptr, player1_color, player2_color) - 1;

    //check isFullcol R 5 6 3 2 2 2 2 2 2
    //check vertical R 5 6 3 1 2 1 2 1
    //check horizontal R56333221
    //check LR diag R56412233434414
    //check RL diag R5636554464
    //test R5631221122111
    //check tie R5531111122222444443333355555
    //check undo R 5 6 3 1 2 3 -1 -1 -1 -1

    //check undo R 5 6 3 1 -1 -1

    // test1 R 6 6 4 1 2 4 3 5 1 6 4 2 5 3 6 1 2 4 3 6 5 3 1 4 2 4 1 failed

    while (!Check_Chosen_Move(board, count_ptr, player1_color, player2_color, num_of_rows, num_of_toks, num_of_cols, board_side, moves,
                              count_moves_ptr)) {
    }

    return 0;
}


//---------------------- Printing Functions ----------------------------//

// message number 0 = "Welcome to 4-in-a-row game! \n"
void print_welcome_message() {
    printf("Welcome to 4-in-a-row game! \n");
}

// message number 1 = "Please enter number of rows:"
// message number 2 = "Please enter number of columns:"
// message number 3 = "Please enter number of tokens:"
void print_read_game_params_message(int param) {
    char const *const possible_params[] = {"rows", "columns", "tokens"};

    printf("Please enter number of %s: ", possible_params[param]);
}

// message number 4 = "Please choose starting color (Y)ellow or (R)ed: "
void print_chose_color_message() {
    printf("Please choose starting color (Y)ellow or (R)ed: ");
}

// message number 5 = "Your move, player <player>. "
void print_chose_move_message(int player) {
    printf("Your move, player %d. ", player);
}

// message number 6
void print_enter_column_message() {
    printf("Please enter column: ");
}

void print_full_column_message() {
    printf("Column full. ");
}

void print_unavailable_undo_redo_message() {
    printf("No moves to undo/redo. ");
}

void print_board(char board[][BOARD_MAX_SIDE], int board_side[]) {
    for (int row = 0; row < board_side[0]; ++row) {
        printf("\n%c", BOARD_VERT_SEP);
        for (int col = 0; col < board_side[1]; ++col)
            printf("%c%c", board[row][col], BOARD_VERT_SEP);
    }
    printf("\n%c", BOARD_LEFT_ANG);
    for (int ii = 0; ii < board_side[1] - 1; ++ii)
        printf("%c%c", BOARD_BOTTOM, BOARD_BOTTOM_SEP);
    printf("%c%c\n", BOARD_BOTTOM, BOARD_RIGHT_ANG);
}

void print_winner(int player_id) {
    if (player_id >= 0)
        printf("Player %d won! \n", player_id);
    else
        printf("That's a tie. \n");
}

//-------------------------- More Functions ----------------------------//

// check if the input of t he color is correct
char CheckColorInput() {
    print_welcome_message();
    char player1_color = '0';
    print_chose_color_message();
    scanf(" %c", &player1_color);
    while (player1_color != YELLOW_SLOT_SYMBOL &&
           player1_color != RED_SLOT_SYMBOL) {
        print_chose_color_message();
        scanf(" %c", &player1_color);
    }

    return player1_color;
}

// set player 2 color after player 1 chose a color
char SetPlayer2Color(char player1_color) {
    if (player1_color == YELLOW_SLOT_SYMBOL)
        return RED_SLOT_SYMBOL;
    else
        return YELLOW_SLOT_SYMBOL;
}

// check if 3 < rows < 9
int Check_Rows_Size() {
    char rows = 0;
    print_read_game_params_message(MSG_GET_BOARD_ROWS);
    scanf(" %c", &rows);
    rows = rows - '0';
    while (rows < BOARD_MIN_SIDE || rows > BOARD_MAX_SIDE) {
        print_read_game_params_message(MSG_GET_BOARD_ROWS);
        scanf(" %c", &rows);
        rows = rows - '0';
    }
    return rows;
}

// check if 3 < columns < 9
int Check_Cols_Size(int rows) {
    print_read_game_params_message(MSG_GET_BOARD_COLS);
    char cols = 0;
    scanf(" %c", &cols);
    cols = cols - '0';
    while ((cols < BOARD_MIN_SIDE || cols > BOARD_MAX_SIDE) || cols < rows) {
        print_read_game_params_message(MSG_GET_BOARD_COLS);
        scanf(" %c", &cols);
        cols = cols - '0';

    }

    return cols;
}

//return the minimum size of the board
int min(int rows, int cols) {
    if (rows <= cols)
        return rows;
    else
        return cols;
}

// check if token input is available
int Check_Token_Input(int rows, int cols) {
    print_read_game_params_message(MSG_GET_NUMBER_TOKENS);
    char toks = 0;
    scanf(" %c", &toks);
    int minSize = min(rows, cols);
    toks = toks - '0';
    while (toks < MIN_TOKENS || toks > minSize) {
        print_read_game_params_message(MSG_GET_NUMBER_TOKENS);
        scanf(" %c", &toks);
        toks = toks - '0';
    }

    return toks;
}

//return true if col is full
bool Check_Full_Col(char board[][BOARD_MAX_SIDE], int chosen_col) {
    chosen_col--;
    if (board[0][chosen_col] != RED_SLOT_SYMBOL && board[0][chosen_col] != YELLOW_SLOT_SYMBOL)
        return false;
    return true;
}

// return false if not full
bool CheckFull(char board[][BOARD_MAX_SIDE], int num_of_cols) {

    for (int col = 0; col < num_of_cols; col++) {
        if (board[0][col] != RED_SLOT_SYMBOL &&
            board[0][col] != YELLOW_SLOT_SYMBOL) {
            return false;
        }
    }
    return true;
}


//return true if there is vertical seq
bool CheckVerticalSeq(char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], int toks, char color_turn, int num_of_rows, int num_of_cols) {
    int count = 1;
    char color = '0';
    for (int col = 0; col < num_of_cols; col++) {
        color = board[0][col];
        for (int row = 1; row < num_of_rows; row++) {
            if (color == board[row][col] && color == color_turn) {
                count++;
                if (count == toks) {
                    return true;
                }
            } else {
                //row += count;
                count = 1;
            }
            color = board[row][col];
        }
    }

    return false;
}

//return true if there is horizontal seq
bool
CheckHorizontalSeq(char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], int toks, char color_turn, int num_of_rows, int num_of_cols) {
    int count = 1;
    char color = board[0][0];
    for (int row = 0; row < num_of_rows; row++) {
        color = board[row][0];
        for (int col = 1; col < num_of_cols; col++) {
            if (color == board[row][col] && color == color_turn) {
                count++;
                if (count == toks) {
                    return true;
                }
            } else {
                //col += count;
                count = 1;
            }
            color = board[row][col];
        }
    }

    return false;
}

//return true if there is left - right diagonal seq
bool
CheckLRDiagSeq(char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], int toks, char color_turn, int num_of_rows, int num_of_cols) {
    int count = 1;
    for (int col = 0; col <= num_of_cols - toks; col++) {

        for (int row = num_of_rows - 1; row >= toks - 1; row--) {
            if (board[row][col] == board[row - 1][col + 1] && board[row][col] == color_turn) {
                count++;
                row--;
                col++;
                for (int i = 0; i < toks - 2; i++) {
                    if (board[row][col] == board[row - 1][col + 1]) {
                        count++;
                    }
                    row--;
                    col++;
                }
                if (count == toks) {
                    return true;
                }
            }
        }
        count = 1;
    }

    return false;
}

//return true if there is right - left diagonal seq
bool
CheckRLDiagSeq(char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], int toks, char color_turn, int num_of_rows, int num_of_cols) {
    int count = 1;
    for (int col = num_of_cols - 1; col >= toks - 1; col--) {
        for (int row = num_of_rows - 1; row >= toks - 1; row--) {
            if (board[row][col] == board[row - 1][col - 1] && board[row][col] == color_turn) {
                count++;
                row--;
                col--;
                for (int i = 0; i < toks - 2; i++) {
                    if (board[row][col] == board[row - 1][col - 1]) {
                        count++;
                    }
                    row--;
                    col--;
                }
                if (count == toks) {
                    return true;
                }
            }
            count = 1;
        }
    }
    return false;
}

// return true if the game is over
int GameOver(char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], int toks,
             int player_id, char color_turn, int num_of_cols, int num_of_rows) {
    if (CheckVerticalSeq(board, toks, color_turn, num_of_rows, num_of_cols) ||
        CheckHorizontalSeq(board, toks, color_turn, num_of_rows, num_of_cols) ||
        CheckLRDiagSeq(board, toks, color_turn, num_of_rows, num_of_cols) ||
        CheckRLDiagSeq(board, toks, color_turn, num_of_rows, num_of_cols))
        return player_id;
    else if (CheckFull(board, num_of_cols)) {
        return -1;
    } else
        return 0;

}

int UndoRedo(int chosen_col, int *moves, int *count_moves) {
    int ret_col = 0;
    if (chosen_col == -1) {
        (*count_moves)--;
        ret_col = moves[*count_moves];

    } else {
        ret_col = moves[(*count_moves) + 1];
    }
    return ret_col;
}

void Undo(char board[BOARD_MAX_SIDE][BOARD_MAX_SIDE], int num_of_rows, int delete_col, int board_side[2]) {
    for (int row = 0; row < num_of_rows; row++) {
        if (board[row][delete_col] == RED_SLOT_SYMBOL || board[row][delete_col] == YELLOW_SLOT_SYMBOL) {
            board[row][delete_col] = ' ';
            break;
        }
    }
    print_board(board, board_side);
}

bool retGameOver(int ret_game_over) {
    if (ret_game_over == 0) {
        return false;
    }
    print_winner(ret_game_over);

    return true;
}

bool Enter_To_Board(char board[][BOARD_MAX_SIDE], char color_turn, int chosen_col, int num_of_rows, int toks, int player_turn,
                    int num_of_cols, int board_side[2], int *moves, int *count_moves) {
    if (chosen_col == -1) {
        int delete_col = UndoRedo(chosen_col, moves, count_moves);
        //delete from bord
        Undo(board, num_of_rows, delete_col, board_side);
    }
    if (chosen_col == -2) {
        chosen_col = UndoRedo(chosen_col, moves, count_moves);
    }
    chosen_col--;
    for (int row = num_of_rows - 1; row >= 0; row--) {
        if (board[row][chosen_col] != RED_SLOT_SYMBOL && board[row][chosen_col] != YELLOW_SLOT_SYMBOL) {
            board[row][chosen_col] = color_turn;
            moves[*count_moves] = chosen_col;
            (*count_moves)++;
            print_board(board, board_side);
            break;
        }
    }
    return retGameOver(GameOver(board, toks, player_turn, color_turn, num_of_cols, num_of_rows));

}

bool isLegalInput(int c, int *count_moves) {
    if (c == -1 && (*count_moves) == 0) {
        return false;
    } else if ((c >= -2) && (c <= 9) && (c != 0)) {
        return true;
    }
    return false;
}

char Player_Color(int player_turn, char player1_color, char player2_color) {
    char color_turn = '0';
    if (player_turn == 1) {
        color_turn = player1_color;
    } else {
        color_turn = player2_color;
    }
    return color_turn;
}

int Player_Move_MSG(int *count) {

    int player_turn = *count % 2 + 1;


    print_chose_move_message(player_turn);
    print_enter_column_message();

    return player_turn;
}

//check the chosen move and return false if the game is not over
bool Check_Chosen_Move(char board[][BOARD_MAX_SIDE], int *count_ptr,
                       char player1_color, char player2_color, int num_of_rows, int toks, int num_of_cols, int board_side[2], int *moves,
                       int *count_moves) {
    int player_turn = Player_Move_MSG(count_ptr);
    char color_turn = Player_Color(player_turn, player1_color, player2_color);
    int chosen_col = 0;
    scanf(" %d", &chosen_col);
    //bool isdigit = isDigit(chosen_col);
    //chosen_col = chosen_col - '0';
    bool is_full = Check_Full_Col(board, chosen_col);

    while (!isLegalInput(chosen_col, count_moves) || is_full) {
        if (is_full) {
            print_full_column_message();
        } else if (*count_moves == 0) {
            print_unavailable_undo_redo_message();
        }
        Player_Move_MSG(count_ptr);
        scanf(" %d", &chosen_col);
        //isdigit = isDigit(chosen_col);
        //chosen_col = chosen_col - '0';
        is_full = Check_Full_Col(board, chosen_col);
    }
    *count_ptr += 1;

    return Enter_To_Board(board, color_turn, chosen_col, num_of_rows, toks, player_turn, num_of_cols, board_side, moves, count_moves);
}
