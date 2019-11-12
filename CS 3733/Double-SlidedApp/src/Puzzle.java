
public class Puzzle {
	private Tile[][] puzzleBoard;
	//array that states where each type of tile belongs in the initial configuration
	private int[][] initArray;
	private boolean premade;

	public Puzzle() {
		puzzleBoard = new Tile[3][3];
		initArray = new int[][]{
			{1,4,3},
			{2,1,4},
			{0,2,3}
		};
		premade = false;
		generateInitState();
	}

	public Puzzle (int[][] premadeState) {
		puzzleBoard = new Tile[3][3];
		initArray= premadeState;
		premade = true;
		generateInitState();
	}

	//creates and add necessary tiles to puzzleBoard
	private void generateInitState() {
		int idCount = 0;
		for(int i = 0; i<puzzleBoard.length; i++) {
			for (int j = 0; j<puzzleBoard.length; j++) {
				int tileFront = initArray[i][j];
				Tile newTile;
				if(tileFront == 0)
					newTile = new Tile(tileFront, tileFront);
				else
					newTile = new Tile(tileFront, 5-tileFront);
				newTile.setTileID(idCount);
				if(premade == false) {
					if(idCount == 1 ) {
						newTile.setSides(1, 4);
						newTile.flip();
					}
					else if(idCount == 4) {
						newTile.setSides(4,1);
						newTile.flip();
					}
				}
				puzzleBoard[i][j] = newTile;
				idCount++;
			}
		}
	}

	public void printPuzzle() {
		for(int i = 0; i< puzzleBoard.length; i++) {
			System.out.print("\n");
			for(int j = 0; j<puzzleBoard.length; j++) {
				System.out.print(puzzleBoard[i][j].getCurrentSide());
			}
		}
	}

	public Tile getTile(int r, int c) {
		return puzzleBoard[r][c];

	}

	public Tile[][] getPuzzleBoard(){
		return puzzleBoard;
	}

	public void resetPuzzle() {
		generateInitState();
	}


}
