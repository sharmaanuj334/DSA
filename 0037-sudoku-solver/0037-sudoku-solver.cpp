class Solution{
    
public:
bool isValid(int row, int col, char c, vector<vector<char>> board){
	for (int i=0; i<9; i++){
		if (board[row][i] == c) return false;
		if (board[i][col] == c) return false;
		if (board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
	}
	return true;
}
public:
bool placeNum(vector<vector<char>> &board){
	for (int row=0; row<9; row++){
		for (int col=0; col<9; col++){
			if (board[row][col] == '.'){
				for (int num=0; num<9; num++){
					char c = '0' + num + 1;
					if (isValid(row, col, c, board)){
						board[row][col] = c;
						if (placeNum(board)){
							return true;
						} else{
							board[row][col] = '.';
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}
public:
void solveSudoku(vector<vector<char>> &board){
	vector<bool> hor(81, false);
	vector<bool> ver(81, false);
	vector<bool> box(81, false);
	for (int row=0; row<board.size(); row++){
		for (int col=0; col<board.size(); col++){
			char c = board[row][col];
			if (c != '.'){
				int num = c - '1';
			}
		}
	}
	placeNum(board);
}

};
