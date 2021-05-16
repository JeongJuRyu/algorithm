// vector를 2차원 배열로 선언할 때
// vector를 복사할 때 사용법 잘 익히기

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	vector<vector<int>> board(rows + 1, vector<int>(columns + 1));
	int num = 0;
	for (int i = 1; i <= rows; ++i)
		for (int j = 1; j <= columns; ++j)
			board[i][j] = ++num;

	for (auto query : queries) {
		vector<vector<int>> temp(board);
		int min = 10000;
		// 위의 ㅡ 부분
		for (int j = query[1] + 1; j <= query[3]; ++j) {
			temp[query[0]][j] = board[query[0]][j - 1];
			if (min > temp[query[0]][j]) min = temp[query[0]][j];
		}
		// 오른쪽 ㅣ 부분
		for (int i = query[0] + 1; i <= query[2]; ++i) {
			temp[i][query[3]] = board[i - 1][query[3]];
			if (min > temp[i][query[3]]) min = temp[i][query[3]];
		}
		// 아래의 ㅡ 부분
		for (int j = query[3] - 1; j >= query[1]; --j) {
			temp[query[2]][j] = board[query[2]][j + 1];
			if (min > temp[query[2]][j]) min = temp[query[2]][j];
		}
		// 왼쪽의 ㅣ 부분
		for (int i = query[2] - 1; i >= query[0]; --i) {
			temp[i][query[1]] = board[i + 1][query[1]];
			if (min > temp[i][query[1]]) min = temp[i][query[1]];
		}
		board = temp;
		answer.push_back(min);
	}

	return answer;
}