import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;


public class ClientClass {
	public static void main(String[] args) {
		try {
			Socket server = new Socket("127.0.0.1",6000);
			BufferedReader serverReader = new BufferedReader(new InputStreamReader(server.getInputStream()));
			PrintWriter serverWriter = new PrintWriter(server.getOutputStream());
			String content ;
			while(true){
				content="";
				System.out.println("Enter File Name : ");
				String fileName = new Scanner(System.in).next();
				serverWriter.println(fileName);	
				serverWriter.flush();
				System.out.println("Content : ");
				while(!((content=serverReader.readLine()).equals("null"))){
					System.out.println(content);
					
				}
				System.out.println("Client closing Server reading");
			}
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
