
public class Model {
	private Puzzle puzzle;
	public Model() {
		puzzle =  new Puzzle();
	}
	
	public Puzzle getPuzzle() {
		return puzzle;
	}
	public void setPuzzle(Puzzle p) {
		puzzle = p;
	}
}
