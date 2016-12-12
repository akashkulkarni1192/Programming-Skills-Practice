import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.HashMap;
import java.util.Scanner;
public class FileHandler {
	public static void main(String[] args) {
		FileHandler handler = new FileHandler();
		handler.inputIntoFile();
		handler.outputFromFile();
	}
	public void inputIntoFile(){
		Scanner scan = new Scanner(System.in);
		String word,vec;
		String[] firstLine = new String[4];
		int hap,sad,ang,sur;
		HashMap map = new HashMap();
		File file = new File("vectorValues.txt");
		if(file.exists()==false){
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			FileInputStream fin = new FileInputStream("vectorValues.txt");
			ObjectInputStream in = new ObjectInputStream(fin);
			HashMap tokenVector = new HashMap();
			try{
				tokenVector = (HashMap) in.readObject();
				fin.getChannel().truncate(0);
			}catch(Exception e){
				
			}finally{
				in.close();
				fin.close();
			}
			FileOutputStream fout = new FileOutputStream("vectorValues.txt");
			ObjectOutputStream os = new ObjectOutputStream(fout);
			while(true){
				if(scan.nextInt()==0)
					break;
				scan.nextLine();
				System.out.println("Enter word : ");
				word = scan.nextLine(); //giving input normal word
				System.out.println("Enter Vector values <happy,sad,angry,surprise> :");				
				vec = scan.nextLine(); //giving input as vector : "8 5 6 7"
				firstLine = vec.split(" ");
				//Here I am trying to print
				for(String s:firstLine)
					System.out.println("Splitted part : "+s);
				hap = Integer.parseInt(firstLine[0]); 
				sad = Integer.parseInt(firstLine[1]);
				ang = Integer.parseInt(firstLine[2]);
				sur = Integer.parseInt(firstLine[3]); 
				
				tokenVector.put(word, new Vector(hap,sad,ang,sur));
			
				System.out.println("Enter more : (0 for no) : ");
			
			}
			os.writeObject(tokenVector);
			os.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public void outputFromFile(){
		//System.out.println("Entry");
		try{
			ObjectInputStream in = new ObjectInputStream(new FileInputStream("vectorValues.txt"));
			HashMap tokenVector = new HashMap();
			tokenVector = (HashMap) in.readObject();
			for(Object key : tokenVector.keySet()){
				System.out.println(key +" : "+tokenVector.get(key) );
			}
		}catch(Exception e){
			e.printStackTrace();
		}
		//System.out.println("Exit");
	}
}
class Vector implements Serializable{
	int happy,sad,angry,surprise;
	public Vector(int hap,int sad,int ang,int sur){
		happy = hap;
		this.sad = sad;
		angry = ang;
		surprise = sur;
	}
	public String toString(){
		return ""+happy+" "+sad+" "+angry+" "+surprise+"\n";
	}
}