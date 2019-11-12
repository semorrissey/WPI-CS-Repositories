
public class Controller {
	private Puzzle puzzle;
	private int[] presentNumbers;
	
	public Controller(Puzzle p) {
		puzzle = p;
		presentNumbers = new int[5];
		Tile[][] currentBoard = puzzle.getPuzzleBoard();
		for(int i = 0; i<currentBoard.length; i++) {
			for(int j=0; j<currentBoard.length; j++) {
				presentNumbers[currentBoard[i][j].getCurrentSide()]++;
			}
		}
	}
	
	public Puzzle getPuzzle() {
		return puzzle;
	}
	
	public int[] getPresentNumbers() {
		return presentNumbers;
	}
}
