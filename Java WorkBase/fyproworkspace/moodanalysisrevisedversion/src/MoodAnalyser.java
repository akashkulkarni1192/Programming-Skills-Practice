import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.HashMap;


public class MoodAnalyser { 
	public static void main(String args[]){
		MoodAnalyser mood = new MoodAnalyser();
		mood.outputFromFile();
	}
	public void outputFromFile(){
		try{
			ObjectInputStream in = new ObjectInputStream(new FileInputStream("emptyContent.txt"));
			HashMap tokenVector = new HashMap();
			tokenVector = (HashMap) in.readObject();
			for(Object key : tokenVector.keySet()){
				System.out.println(key +" : "+tokenVector.get(key) );
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
