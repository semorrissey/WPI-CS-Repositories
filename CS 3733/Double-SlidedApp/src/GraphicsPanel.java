import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class GraphicsPanel extends JPanel implements MouseListener {
	private static final int rows = 3;
	private static final int cols = 3;

	private static final int size = 80; // Pixels
	private Font font;
	private Font fontM;
	private Puzzle puzzle;
	private int moves;

	public GraphicsPanel(Puzzle p) {
		font = new Font("SansSerif", Font.BOLD, size/2);
		fontM = new Font("SansSerif", Font.BOLD, 20);
		this.setPreferredSize(
				new Dimension(size * cols, size*rows));
		this.setBackground(Color.black);
		this.addMouseListener(this);
		puzzle = p;
		moves = 0;
	}

	public void setPuzzle(Puzzle p) {
		puzzle = p;
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		for (int r=0; r<rows; r++) {
			for (int c=0; c<cols; c++) {
				int x = c * size;
				int y = r * size;
				String text = Integer.toString(puzzle.getTile(r, c).getCurrentSide());
				boolean empty = puzzle.getTile(r,c).getEmpty();
				if (text != null && !empty) {
					if(puzzle.getTile(r, c).getFlipState()) {
						g.setColor(Color.black);
						g.fillRect(x+2, y+2, size-4, size-4);
						g.setColor(Color.white);
						g.setFont(font);
						g.drawString(text, x+20, y+(3*size)/4);
					}else {
						g.setColor(Color.gray);
						g.fillRect(x+2, y+2, size-4, size-4);
						g.setColor(Color.black);
						g.setFont(font);
						g.drawString(text, x+20, y+(3*size)/4);
					}
				}
				else if(empty) {
					g.setColor(Color.yellow);
					g.fillRect(x+2, y+2, size-4, size-4);
				}
			}
		}
		g.setColor(Color.WHITE);
		g.setFont(fontM);
		g.drawString("MOVES: "+ Integer.toString(moves), 3*size, 1*size);
	}


	public void mousePressed(MouseEvent e) {
		int col = e.getX()/size;
		int row = e.getY()/size;

		Tile clickedTile = puzzle.getTile(row, col);

		tileMovementController movement = new tileMovementController(puzzle, clickedTile);
		movement.moveTile();
		if(movement.validMove())
			moves++;
		this.repaint();
		
		gameStateController gameState =  new gameStateController(puzzle);
		if(gameState.getState() == 1) {
			JOptionPane.showMessageDialog(null, "You Won!");
			moves = 0;
		}
		else if(gameState.getState() == 0) {
			Object[] choices = {"Reset", "Quit"};
			Object defaultChoice = choices[0];
			int input = JOptionPane.showOptionDialog(this,
			             "You Lose",
			             "",
			             JOptionPane.YES_NO_OPTION,
			             JOptionPane.QUESTION_MESSAGE,
			             null,
			             choices,
			             defaultChoice);
		        if(input == 0){
		           puzzle.resetPuzzle();
		           moves = 0;
		           this.repaint();
		        }else{
		        	
		            System.exit(0);
		        }
		}
	}
	public void mouseClicked (MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
	public void mouseEntered (MouseEvent e) {}
	public void mouseExited  (MouseEvent e) {}
}
