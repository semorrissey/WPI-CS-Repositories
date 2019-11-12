import org.junit.Test;

import junit.framework.TestCase;

public class testPuzzle extends TestCase {

	public testPuzzle(String name) {
		super(name);
	}
	
	@Test
	public void testGenerateInitState() {
		Puzzle p =  new Puzzle();
		int[][] initArray = new int[][]{
			{1,4,3},
			{2,1,4},
			{0,2,3}
		};
		
		int[][] finalArray = new int[3][3];
		
		for(int i =0; i<finalArray.length; i++) {
			for(int j=0; j<finalArray.length; j++) {
				finalArray[i][j] = p.getTile(i, j).getCurrentSide();
			}
		}
		
		boolean isGood = true;
		
		for(int i = 0; i<finalArray.length; i++) {
			for(int j = 0; j<finalArray.length;j++) {
				if(initArray[i][j] != finalArray[i][j])
					isGood = false;
			}
		}
		
		assertEquals(true, isGood);
		
	}

}
