import org.junit.Test;

import junit.framework.TestCase;

/**
 * 
 */

/**
 * @author semor
 *
 */
public class testMovementController extends TestCase {
	private Model m;
	private App a;
	/**
	 * @param name
	 */
	public testMovementController(String name) {
		super(name);
		m = new Model();
		a =  new App(m);
		a.start();
	}

	@Test
	public void testMovement() {

		Puzzle test =  new Puzzle();
		Tile exampleTile = new Tile(2,3);
		exampleTile.setTileID(7);

		tileMovementController something = new tileMovementController(test,exampleTile);
		something.moveTile();
	}
	
	@Test
	public void testValid() {
		Puzzle test =  new Puzzle();
		Tile exampleTile = new Tile(2,3);
		exampleTile.setTileID(7);

		tileMovementController something = new tileMovementController(test,exampleTile);
		
		assertEquals(true, something.validMove());
		
		Tile exampleTileTwo = new Tile(1,4);
		exampleTileTwo.setTileID(0);
		something.setGivenTile(exampleTileTwo);
		
		assertEquals(false, something.validMove()); 
	}
	
	
	@Test
	public void testGetLocation() {
		Puzzle test =  new Puzzle();
		Tile exampleTile = new Tile(2,3);
		exampleTile.setTileID(7);
		
		tileMovementController something = new tileMovementController(test,exampleTile);
		
		int[] location = something.getLocation(exampleTile);
		
		boolean isGood = false;
		
		if(location != null)
			isGood = true; 
		assertEquals(true, isGood);

		
	}

}
