class Solution{
    
public:
bool placeNum(vector<vector<char>> &board, int row, vector<bool> hor, vector<bool> ver, vector<bool> box){
	for (int row=0; row<9; row++){
		for (int col=0; col<9; col++){
			if (board[row][col] == '.'){
				for (int num=0; num<9; num++){
					if (!hor[9*num+row] && !ver[9*num+col] && !box[9*num+(row/3)*3+col/3]){
						board[row][col] = '0' + num + 1;
						hor[9*num + row] = true;
						ver[9*num + col] = true;
						box[9*num + (row/3)*3 + col/3] = true;
						if (placeNum(board, row+1, hor, ver, box)){
							return true;
						} else{
							board[row][col] = '.';
							hor[9*num + row] = false;
							ver[9*num + col] = false;
							box[9*num + (row/3)*3 + col/3] = false;
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
				hor[num*9 + row] = true;
				ver[num*9 + col] = true;
				box[num*9 + (row/3)*3 + col/3] = true;
			}
		}
	}
	placeNum(board, 0, hor, ver, box);
}
};
