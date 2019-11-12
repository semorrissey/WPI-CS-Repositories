
public class Tile{
	private boolean flipState;
	private int[] tileSides;
	private int currentSide;
	private int ID;
	private boolean isEmpty;
	
	public Tile(int sideOne, int sideTwo) {
		tileSides = new int[] {sideOne,sideTwo};
		flipState = false;
		currentSide = tileSides[0];
		ID = 0;
		if(sideOne == 0 || sideTwo == 0) 
			isEmpty = true;
		else
			isEmpty = false;
	
		
	}
	
	public void flip() {
		flipState = !flipState;
		
		if(flipState)
			currentSide = tileSides[1];
		else
			currentSide = tileSides[0];
	}
	
	public boolean getEmpty() {
		return isEmpty;
	}
	
	public int getCurrentSide() {
		return currentSide;
	}
	
	public void setCurrentSide(int p) {
		currentSide = p;
	}
	
	public void setSides(int o, int t) {
		tileSides[0] = o;
		tileSides[1] = t;
	}
	
	public boolean getFlipState() {
		return flipState;
	}
	
	public int getTileID() {
		return ID;
	}
	public void setTileID(int c){
		ID = c;
	}

}
