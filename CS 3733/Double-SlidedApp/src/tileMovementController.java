import java.util.ArrayList;

public class tileMovementController extends Controller {
	private Tile givenTile;
	private Tile[][] puzzleBoard;
	private Tile emptySpace;
	  
	
	public tileMovementController(Puzzle p, Tile t) {
		super(p);
		givenTile = t;
		puzzleBoard = super.getPuzzle().getPuzzleBoard();
		
	}
	//read some input, find place on board where input was made and make the change
	
	public boolean validMove() {
		if(givenTile.getCurrentSide() == 0)
			return false;
		int[] tileLocation = getLocation(givenTile);
		int thisPosX = tileLocation[0];
		int thisPosY = tileLocation[1];
		int MIN_X = 0;
		int MIN_Y = 0;
		int MAX_X = puzzleBoard.length-1; 
		int MAX_Y = puzzleBoard.length-1;
		int startPosX = (thisPosX - 1 < MIN_X) ? thisPosX : thisPosX-1;
		int startPosY = (thisPosY - 1 < MIN_Y) ? thisPosY : thisPosY-1;
		int endPosX =   (thisPosX + 1 > MAX_X) ? thisPosX : thisPosX+1;
		int endPosY =   (thisPosY + 1 > MAX_Y) ? thisPosY : thisPosY+1;


		for (int rowNum=startPosX; rowNum<=endPosX; rowNum++) {
		    for (int colNum=startPosY; colNum<=endPosY; colNum++) {
		        // All the neighbors will be grid[rowNum][colNum]
		    	if(puzzleBoard[rowNum][colNum].getCurrentSide() == 0) {
		    		emptySpace = puzzleBoard[rowNum][colNum];
		    		return true;
		    	}
		    }
		}
		return false;
	}
	
	public int[] getLocation(Tile t) {
		int rowLocation = 0;
		int colLocation = 0;
		for(int i = 0; i<puzzleBoard.length;i++) {
			for(int j=0; j<puzzleBoard.length; j++) {
				//change so it compares the objects themselves
				if(puzzleBoard[i][j].getTileID() == t.getTileID()) {
					rowLocation = i;
					colLocation = j;
					break;
				}
					
			}
		}
		return new int[] {rowLocation,colLocation};
	}
	
	public void moveTile() {
		//flip the chosen tile into the empty space
		if(validMove()) {
			int[] tileLocationE = getLocation(emptySpace);
			int[] tileLocationG = getLocation(givenTile);
			givenTile.flip();
			puzzleBoard[tileLocationE[0]][tileLocationE[1]] = givenTile;
			puzzleBoard[tileLocationG[0]][tileLocationG[1]] = emptySpace;
			}
			
	}
	
	public void setGivenTile(Tile t) {
		givenTile = t;
	}
}


