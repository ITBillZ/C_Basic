#define ROW 3
#define COL 3

void play();
void init_board(char board[ROW][COL], int row, int col);
void display_board(char board[ROW][COL], int row, int col);
int place(char board[ROW][COL], int x, int y, int player);
int is_over(char board[ROW][COL], int cnt);
int is_win(char board[ROW][COL], int player);