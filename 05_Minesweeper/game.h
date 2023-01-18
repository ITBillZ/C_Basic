#define ROW 6
#define COL 6
#define MINE -1 // mine
#define MINE_NUM 4

void play();
void init_board(int board[ROW][COL]);  
void display_board(int board[ROW][COL], int state[ROW][COL]);
int mark_mine(int state[ROW][COL], int x, int y);
int click(int board[ROW][COL], int state[ROW][COL], int x, int y);
int is_win(int board[ROW][COL], int state[ROW][COL]);
void dfs(int board[ROW][COL], int state[ROW][COL], int is_visit[ROW][COL]);