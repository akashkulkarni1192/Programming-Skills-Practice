

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/DownloadServlet1")
public class DownloadServlet1 extends HttpServlet {
	private static final long serialVersionUID = 1L;

    public DownloadServlet1() {
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//ServletContext sc = getServletContext();
		
		response.setContentType("text/html");
		PrintWriter wr = response.getWriter();
		BufferedReader bf = new BufferedReader(new FileReader("/home/akash/Desktop/file1.txt"));
		//BufferedReader bf = new BufferedReader(new FileReader("/home/akash/Dropbox/Back\\ Up\\ Programs/Java\\ WorkBase/workspace2.0/ServletFileDownload/file1.txt"));
		String msg;
		wr.print("<html><body><p>");
		while((msg=bf.readLine())!=null){
			wr.print(msg+"<br>");
		}
		wr.print("</p></body></html>");
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
