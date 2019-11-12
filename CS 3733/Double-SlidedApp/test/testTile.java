import org.junit.Test;

import junit.framework.TestCase;

public class testTile extends TestCase {
	public testTile(String name) {
		super(name);
	}

	@Test
	public void testFlip() {
		Tile exampleTile = new Tile(2,3);
		exampleTile.setTileID(7);
		exampleTile.flip();
		
		assertEquals(3, exampleTile.getCurrentSide());
	}
}
