import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Logger;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;


public class SQLJDBC {
	final static Logger log = Logger.getLogger("debug");
	final static boolean debug = false;
	Connection con;
	JTabbedPane tabbedPane;
	JFrame formFrame,menuFrame,frame;
	JTextField userNameField,usnField,nameField,branchField,companyField,companyCategoryField,usnDisplayField,usnDeleteField;
	JPasswordField passwordField;
	JButton connectButton,insertButton,enterButton,displayButton,deleteButton,logoutButton,findButton,deleteRecord,backButton,findAll;
	JPanel uPanel,pPanel,formPanel,menuPanel,insertPanel,usnPanel,namePanel,branchPanel,companyPanel,companyCategoryPanel,displayPanel,deletePanel,disPanel;
	JLabel uLabel,pLabel,usnLabel,nameLabel,branchLabel,companyLabel,companyCategoryLabel,usnDisplayLabel,usnDeleteLabel;
	public static void main(String[] args) {
		SQLJDBC sqlObject = new SQLJDBC();
		sqlObject.setGraphicDesign();
	}
	public void setGraphicDesign(){
		frame = new JFrame("JDBC Application");
		tabbedPane = new JTabbedPane();

		userNameField = new JTextField(10);
		passwordField = new JPasswordField(10);
		connectButton = new JButton("Connect");
		
		uPanel = new JPanel();
		uPanel.add(new JLabel("Admin Name :"));
		uPanel.add(userNameField);
		
		pPanel = new JPanel();
		pPanel.add(new JLabel("Password :"));
		pPanel.add(passwordField);
		
		
		ConnectClass connectObject = new ConnectClass();
		connectButton.addActionListener(connectObject);
		formPanel = new JPanel();
		formPanel.setLayout(new BoxLayout(formPanel, BoxLayout.Y_AXIS));
		formPanel.add(uPanel);
		formPanel.add(pPanel);
		formPanel.add(connectButton);
		
		tabbedPane.add("Login",formPanel);
		frame.getContentPane().add(tabbedPane,BorderLayout.CENTER);
		frame.setLocation(400, 200);
		frame.setSize(500,250);
		frame.setVisible(true);
		
		menuPanel = new JPanel();
		menuPanel.setLayout(new BoxLayout(menuPanel,BoxLayout.Y_AXIS));

		insertButton = new JButton("Insert");
		displayButton = new JButton("Display");
		deleteButton = new JButton("Delete");
		logoutButton = new JButton("Log Out");
		
		InsertClass insertObject = new InsertClass();
		insertButton.addActionListener(insertObject);

		DisplayClass displayObject = new DisplayClass();
		displayButton.addActionListener(displayObject);
		
		DeleteClass deleteObject = new DeleteClass();
		deleteButton.addActionListener(deleteObject);
		
		LogoutClass logObject = new LogoutClass();
		logoutButton.addActionListener(logObject);
		
		menuPanel.add(insertButton);
		menuPanel.add(displayButton);
		menuPanel.add(deleteButton);
		menuPanel.add(logoutButton);
		tabbedPane.add("Menu",menuPanel);
		
		insertPanel = new JPanel();
		
		usnPanel= new JPanel();
		usnLabel = new JLabel("USN : ");
		usnField = new JTextField(10);
		usnPanel.add(usnLabel);
		usnPanel.add(usnField);
		
		namePanel= new JPanel();
		nameLabel = new JLabel("Name : ");
		nameField = new JTextField(10);
		namePanel.add(nameLabel);
		namePanel.add(nameField);
		
		branchPanel= new JPanel();
		branchLabel = new JLabel("Name : ");
		branchField = new JTextField(10);
		branchPanel.add(branchLabel);
		branchPanel.add(branchField);
		
		companyPanel= new JPanel();
		companyLabel = new JLabel("Company : ");
		companyField = new JTextField(10);
		companyPanel.add(companyLabel);
		companyPanel.add(companyField);
		
		companyCategoryPanel= new JPanel();
		companyCategoryLabel = new JLabel("Comp Category : ");
		companyCategoryField = new JTextField(10);
		companyCategoryPanel.add(companyCategoryLabel);
		companyCategoryPanel.add(companyCategoryField);
		
		enterButton = new JButton("Enter");
		EnterClass enterObject = new EnterClass();
		enterButton.addActionListener(enterObject);
		
		insertPanel.setLayout(new BoxLayout(insertPanel,BoxLayout.Y_AXIS));
		insertPanel.add(usnPanel);
		insertPanel.add(namePanel);
		insertPanel.add(branchPanel);
		insertPanel.add(companyPanel);
		insertPanel.add(companyCategoryPanel);
		insertPanel.add(enterButton);

		tabbedPane.add("Insert Details",insertPanel);
		
		
		
		ChangeListener changeListener = new ChangeListener() {
	      public void stateChanged(ChangeEvent changeEvent) {
	        JTabbedPane sourceTabbedPane = (JTabbedPane) changeEvent.getSource();
	        int index = sourceTabbedPane.getSelectedIndex();
	        if(index==1){
	        	tabbedPane.setEnabledAt(1,true);
	        	tabbedPane.setEnabledAt(3,false);
	        	tabbedPane.setEnabledAt(2,false);
	        	tabbedPane.setEnabledAt(4,false);
	        	tabbedPane.setEnabledAt(0,false);
	        }
	      }
	    };
	    tabbedPane.addChangeListener(changeListener);
		
		
		
		displayPanel = new JPanel();
		displayPanel.setLayout(new BorderLayout());
		disPanel = new JPanel();
		usnDisplayLabel = new JLabel("USN :");
		disPanel.add(usnDisplayLabel);
		usnDisplayField = new JTextField(10);
		disPanel.add(usnDisplayField);
		findButton = new JButton("Find");
		
		FindClass findObject = new FindClass();
		findButton.addActionListener(findObject);
		disPanel.add(findButton);
		
		findAll = new JButton("Find All");
		FindAllClass fObject= new FindAllClass();
		findAll.addActionListener(fObject);
		disPanel.add(findAll);
		displayPanel.add(disPanel,BorderLayout.NORTH);
		
		tabbedPane.add("Find Record",displayPanel);
		
		deletePanel = new JPanel();
		usnDeleteLabel = new JLabel("USN :");
		deletePanel.add(usnDeleteLabel);
		usnDeleteField = new JTextField(10);
		deletePanel.add(usnDeleteField);
		deleteRecord = new JButton("Delete");
		deleteRecord.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				try {
					
					String usn = usnDeleteField.getText();
					Statement st = con.createStatement();
					String query = "Delete from placement where usn = '"+usn+"';";
					st.executeUpdate(query);
					st.close();
				} catch (SQLException e1) {
					
					e1.printStackTrace();
				}
				tabbedPane.setEnabledAt(1,true);
				
			}
			
		});
		
		deletePanel.add(deleteRecord);
		tabbedPane.add("Delete Record",deletePanel);
		
		tabbedPane.setEnabledAt(0,true);
		tabbedPane.setEnabledAt(1,false);
		tabbedPane.setEnabledAt(2,false);
		tabbedPane.setEnabledAt(3,false);
		tabbedPane.setEnabledAt(4,false);
	}
	public class ConnectClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			
			String userName = userNameField.getText();
			String password = passwordField.getText();
			String DB_URL = "jdbc:mysql://localhost:3306/placementDB";
			
			if(userName.equals("root") && password.equals("hitit")){
				try{
					
					Class.forName("com.mysql.jdbc.Driver");
					con = DriverManager.getConnection(DB_URL,userName,password);
					System.out.println("Connected to Database");
					tabbedPane.setEnabledAt(0, false);
					tabbedPane.setEnabledAt(1,true);
					tabbedPane.setSelectedIndex(1);
				}catch(Exception e1){
					e1.printStackTrace();
				}
			}
			else{
				
				
			}
		}
	}
	public class InsertClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			tabbedPane.setEnabledAt(1, false);
			tabbedPane.setEnabledAt(2, true);
			tabbedPane.setSelectedIndex(2);			
		}
	}
	public class EnterClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			tabbedPane.setEnabledAt(2, false);
			tabbedPane.setEnabledAt(1, true);
			tabbedPane.setSelectedIndex(1);	
			try {
				Statement st = con.createStatement();
				String usn = usnField.getText();
				String name = nameField.getText();
				String branch = branchField.getText();
				String company = companyField.getText();
				String companyCategory = companyCategoryField.getText();
				String query = "insert into placement values('"+usn+"','"+name+"','"+branch+"','"+company+"','"+companyCategory+"');";
				st.executeUpdate(query);
				st.close();
			} catch (SQLException e1) {
				e1.printStackTrace();
			}	
		}
	}
	public class DisplayClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			tabbedPane.setEnabledAt(1, false);
			tabbedPane.setEnabledAt(3, true);
			tabbedPane.setSelectedIndex(3);	
			
		}
	}
	public class FindClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String usn = usnDisplayField.getText();
			try {
				Statement st = con.createStatement();
				String query = "Select * from placement where usn = '"+usn+"';";
				ResultSet rs = st.executeQuery(query);
				JPanel detPanel = new JPanel();
				detPanel.setLayout(new BoxLayout(detPanel, BoxLayout.Y_AXIS));
				if(rs.next()){
					JLabel uLabel = new JLabel("Usn : "+rs.getString(1));
					JLabel nLabel = new JLabel("Name : "+rs.getString(2));
					JLabel bLabel = new JLabel("Branch : "+rs.getString(3));
					JLabel cLabel = new JLabel("Company : "+rs.getString(4));
					JLabel ccLabel = new JLabel("CompanyCategory : "+rs.getString(5));
					detPanel.add(uLabel);
					detPanel.add(nLabel);
					detPanel.add(bLabel);
					detPanel.add(cLabel);
					detPanel.add(ccLabel);
					displayPanel.add(detPanel,BorderLayout.CENTER);
					frame.setVisible(true);
				}
				
			} catch (SQLException e1) {
				
				e1.printStackTrace();
			}
			tabbedPane.setEnabledAt(1,true);
		}
	}
	public class DeleteClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			tabbedPane.setEnabledAt(1, false);
			tabbedPane.setEnabledAt(4, true);
			tabbedPane.setSelectedIndex(4);	
			
		}
	}
	public class LogoutClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			tabbedPane.setEnabledAt(1, false);
			tabbedPane.setEnabledAt(0, true);
			tabbedPane.setSelectedIndex(0);	
			userNameField.setText("");
			passwordField.setText("");
			try {
				con.close();
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
			
		}
	}
	public class FindAllClass implements ActionListener{
		public void actionPerformed(ActionEvent e) {
	
			try {
				Statement st = con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);;
				String query = "Select * from placement ;";
				ResultSet rs = st.executeQuery(query);
				JPanel detPanel = new JPanel();
				detPanel.setLayout(new BoxLayout(detPanel,BoxLayout.Y_AXIS));
				while(rs.next()){
					detPanel.add(new JLabel("Usn : "+rs.getString(1)));
					detPanel.add(new JLabel("Name : "+rs.getString(2)));
					detPanel.add(new JLabel("Branch : "+rs.getString(3)));
					detPanel.add(new JLabel("Company : "+rs.getString(4)));
					detPanel.add(new JLabel("CompanyCategory : "+rs.getString(5)));
					detPanel.add(new JLabel("------------------------------------"));
				}				
				JScrollPane scrollBar = new JScrollPane(detPanel,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
				displayPanel.add(scrollBar);
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
			tabbedPane.setEnabledAt(1,true);
		}
	}
	
}	
