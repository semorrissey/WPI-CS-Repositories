import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.BorderLayout;
import javax.swing.JToolBar;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JButton;
import java.awt.Button;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;
import java.awt.event.KeyEvent;
import java.awt.event.InputEvent;
import javax.swing.JPanel;

public class App {

	private JFrame frmDoubleslided;
	private GraphicsPanel g;
	private Model model;

	/**
	 * Launch the application.
	 */
	public void start(){
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					App App = new App(model);
					App.frmDoubleslided.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public App(Model m) {
		model = m;
		initialize();
	}

	
	
	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		g = new GraphicsPanel(model.getPuzzle());
		
		frmDoubleslided = new JFrame();
		frmDoubleslided.setTitle("Double-Slided");
		frmDoubleslided.setBounds(100, 100, 380, 300);
		frmDoubleslided.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmDoubleslided.getContentPane().setLayout(new BorderLayout(0, 0)); 
		
		JPanel panel = new JPanel();
		frmDoubleslided.getContentPane().add(panel, BorderLayout.CENTER);
		frmDoubleslided.add(g, BorderLayout.CENTER);
		
		JMenuBar menuBar = new JMenuBar();
		frmDoubleslided.setJMenuBar(menuBar);
		
		JMenu mnNewMenu_1 = new JMenu("Double-Slided");
		menuBar.add(mnNewMenu_1);
		
		JMenuItem mntmNewMenuItem = new JMenuItem("Quit Application");
		mntmNewMenuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q, InputEvent.CTRL_MASK));
		
		 class exitApp implements ActionListener {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		}
		 
		mntmNewMenuItem.addActionListener(new exitApp());
		mnNewMenu_1.add(mntmNewMenuItem);
	
		
		JMenu mnNewMenu = new JMenu("Puzzle");
		menuBar.add(mnNewMenu);
		
		JMenuItem mntmNewMenuItem_1 = new JMenuItem("Reset Puzzle");
		mntmNewMenuItem_1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, InputEvent.CTRL_MASK));
		
		class resetPuzzle implements ActionListener {
			public void actionPerformed(ActionEvent e) {
				Puzzle tempP = model.getPuzzle();
				tempP.resetPuzzle();
				g.repaint();
			}
		}
		
		mntmNewMenuItem_1.addActionListener(new resetPuzzle());
		mnNewMenu.add(mntmNewMenuItem_1);
		
	}
}
