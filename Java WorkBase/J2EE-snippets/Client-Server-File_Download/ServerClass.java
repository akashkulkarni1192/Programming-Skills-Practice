import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class ServerClass {
	public static void main(String[] args) {
		try {
			ServerSocket server = new ServerSocket(6000);
			while(true){
				Socket client = server.accept();
				
				BufferedReader clientReader = new BufferedReader(new InputStreamReader(client.getInputStream()));
				PrintWriter clientWriter = new PrintWriter(client.getOutputStream());
			
				String fileName,content="",msg;
				System.out.println("Server Check");
				while((fileName=clientReader.readLine())!=null){
					
					content="";
					msg="";
					System.out.println("Client requested for File : "+fileName);
					BufferedReader file = new BufferedReader(new FileReader(new File(fileName)));
					while((msg=file.readLine())!=null)
						content = content + msg + "\n";
					content = content + null;
					clientWriter.println(content);
					clientWriter.flush();
					
				}
				System.out.println("Server Closing File reading loop");
				
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
