class GameOfLife
{
public:
	bool GameOfLifeGrid[4][8];
	void GridSetup();
	void SetLiveState(bool alive, int x, int y);
	void SetStateBasedOnNeighbours(int x, int y);
	
private:
	
};