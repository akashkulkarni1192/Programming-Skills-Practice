

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/DownloadServlet2")
public class DownloadServlet2 extends HttpServlet {
	private static final long serialVersionUID = 1L;

    public DownloadServlet2() {
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter wr = response.getWriter();
		BufferedReader bf = new BufferedReader(new FileReader(new File("/home/akash/Desktop/file2.txt")));
		String msg;
		wr.print("<html><body>");
		while((msg=bf.readLine())!=null){
			wr.print(msg+"<br>");
		}
		wr.print("</body></html>");
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
