
public class gameStateController extends Controller {
	
	private Puzzle winState;
	
	public gameStateController (Puzzle p) {
		super(p);
		int[][] winStateArray = new int[][] {
			{1,2,3},
			{4,0,4},
			{3,2,1}
		};
		winState = new Puzzle(winStateArray);
		
	}
	
	// return 0 for loss, 1 for win and 2 for in progress
	public int getState() {
		if(checkWin())
			return 1;
		else if (checkLoss())
			return 0;
		else
			return 2;
	}
	
	private boolean checkWin() {
		Tile[][] puzzle = super.getPuzzle().getPuzzleBoard();
		
		for(int i = 0; i<puzzle.length;i++) {
			for(int j=0; j<puzzle.length;j++) {
				if(puzzle[i][j].getCurrentSide() != winState.getPuzzleBoard()[i][j].getCurrentSide())
					return false;
			}
		}
		return true;
	}
	
	private boolean checkLoss() {
		for(int i = 0; i<super.getPresentNumbers().length;i++) 
			if(super.getPresentNumbers()[i] == 4)
				return true;
		
		return false;
	}
	

	
	
}
