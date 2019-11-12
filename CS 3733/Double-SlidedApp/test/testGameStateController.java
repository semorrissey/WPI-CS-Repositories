import org.junit.Test;

import junit.framework.TestCase;

public class testGameStateController extends TestCase {
	private Model m;
	private App a;

	public testGameStateController(String name) {
		super(name);
		m = new Model();
		a =  new App(m);
		a.start();
	}

	@Test
	public void testCheckWin() {

		Puzzle test =  new Puzzle();
		Tile exampleTile = new Tile(2,3);
		exampleTile.setTileID(7);

		tileMovementController something = new tileMovementController(test,exampleTile);

		//check for Win

		test.printPuzzle();
		System.out.print("\n");
		something.moveTile();

		Tile tileTwo = new Tile(3,2);
		tileTwo.setTileID(8);

		something.setGivenTile(tileTwo);
		something.moveTile();


		Tile tileThree = new Tile(4,1);
		tileThree.setTileID(5);

		something.setGivenTile(tileThree);
		something.moveTile();

		Tile tileFour = new Tile(1,4);
		tileFour.setTileID(4);

		something.setGivenTile(tileFour);
		something.moveTile();

		Tile tileFive = new Tile(2,3);
		tileFive.setTileID(3);

		something.setGivenTile(tileFive);
		something.moveTile();

		Tile tileSix = new Tile(1,4);
		tileSix.setTileID(0);

		something.setGivenTile(tileSix);
		something.moveTile();

		Tile tileSeven = new Tile(4,1);
		tileSeven.setTileID(1);

		something.setGivenTile(tileSeven);
		something.moveTile();


		something.setGivenTile(tileFive);
		something.moveTile();
		test.printPuzzle();
		
		gameStateController testing = new gameStateController(test);
		
		assertEquals(1, testing.getState());
	}
	
	@Test
	public void testCheckLoss() {
		Puzzle test =  new Puzzle();
		Tile exampleTile = new Tile(2,3);
		exampleTile.setTileID(7);

		tileMovementController something = new tileMovementController(test,exampleTile);

		something.moveTile();
		
		Tile tileOne = new Tile(1,4);
		tileOne.setTileID(4);
		
		something.setGivenTile(tileOne);
		something.moveTile();
		
		Tile tileTwo = new Tile(2,3);
		tileTwo.setTileID(3);
		
		something.setGivenTile(tileTwo);
		something.moveTile();
		
		test.printPuzzle();
		
		gameStateController testing = new gameStateController(test);

		assertEquals(0, testing.getState());
	}

}
