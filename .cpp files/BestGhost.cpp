#include "BestGhost.h"

/* function move of best ghost - this functiom find the next smart move of ghost to chase pacman */
void BestGhost::move(GameBoard& board,Position pacmanPos)
{
	char newMoveOfGhost;

	if (countMoveOfGhost%10==0 )
	{
		// every 10 iterations, we move one step randomally to seperate ghosts from each other on board
		NoviceGhost::move(board, pacmanPos);

		if(countMoveOfGhost == 30)
			countMoveOfGhost = 0;
	
	}
	else
	{
		string res = nextMoveOfBestGhost(board, getPosition(), pacmanPos);
		if (res.compare("notValid") != 0) {
			newMoveOfGhost = res[0];
			setNewMove(newMoveOfGhost);
			movement(board);
			countMoveOfGhost++;
		}
	}

}


// Check if the given cell is valid or not
bool BestGhost::isCellInBoard(GameBoard& board, int row, int col)
{
	return (row >= 0) && (col >= 0)
		&& (row < board.getLogicalRowSize()) && (col < board.getLogicalColSize());
}


// find the shortest path from ghost to pacman in board, using BFS algorithm
string BestGhost::nextMoveOfBestGhost(GameBoard& board, Position ghostPos, Position pacmanPos)
{

	// Stores the moves of the directions of adjacent cells
	int dRow[] = { -1, 0, 0, 1 }; // up, left, right, down
	int dCol[] = { 0, -1, 1, 0 }; // up, left, right, down

	int distances[25][80];
	memset(distances, -1, sizeof distances);
	distances[ghostPos.getY()][ghostPos.getX()] = 0;

	bool visited[25][80];
	memset(visited, false, sizeof visited);
	visited[ghostPos.getY()][ghostPos.getX()] = true;

	queue<Node> q;
	Node firstNode = { ghostPos, 0 };
	q.push(firstNode);
	string str = "notValid";

	while (!q.empty()) {

		Node currNode = q.front();
		Position pos = currNode.pt;

		if (pos.getX() == pacmanPos.getX() && pos.getY() == pacmanPos.getY()) {

			int currX = pos.getX(), currY = pos.getY();
			int dist = currNode.dist;

			distances[pos.getY()][pos.getX()] = dist;

			string pathmoves = "";

			while (currX != ghostPos.getX() || currY != ghostPos.getY()) {

				// Append Down
				if (currY > 0 && distances[currY - 1][currX] == dist - 1) {
					pathmoves += DOWN;
					currY--;
				}

				// Append Up
				if (currY < board.getLogicalRowSize() - 1 && distances[currY + 1][currX] == dist - 1) {
					pathmoves += UP;
					currY++;
				}

				// Append Right
				if (currX > 0 && distances[currY][currX - 1] == dist - 1) {
					pathmoves += RIGHT;
					currX--;
				}

				// Append Left
				if (currX < board.getLogicalColSize() - 1 && distances[currY][currX + 1] == dist - 1) {
					pathmoves += LEFT;
					currX++;
				}

				dist--;
			}

			// Reverse the backtracked path
			reverse(pathmoves.begin(), pathmoves.end());
			return pathmoves;
		}

		// Pop the start of queue
		q.pop();

		// Explore all adjacent directions
		for (int i = 0; i < 4; i++) {
			int row = pos.getY() + dRow[i]; // up, left, right, down { -1, 0, 0, 1 }
			int col = pos.getX() + dCol[i]; // up, left, right, down { 0, -1, 1, 0 }

			// If the current cell is valid cell and can be traversed
			if (isCellInBoard(board, row, col) && board.board[row][col] != '#' &&!visited[row][col]) {
				// Mark the adjacent cells as visited
				visited[row][col] = true;

				// Enqueue the adjacent cells
				Node adjCell = { Position(col, row), currNode.dist + 1 };
				q.push(adjCell);

				// Update the distance of the adjacent cells
				distances[row][col] = currNode.dist + 1;
			}
		}
	}

	// If the destination is not reachable
	return str;
}