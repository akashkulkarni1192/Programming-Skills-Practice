

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/AdderServlet")
public class AdderServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		response.setContentType("text/html");
		PrintWriter writer = response.getWriter();
		writer.print("<html><head><title>AdditionResult</title></head>");
		try{
			int param1 = Integer.parseInt(request.getParameter("param1"));
			int param2 = Integer.parseInt(request.getParameter("param2"));
			
			writer.print("<body>Result = "+(param1+param2));
			
		}catch(NumberFormatException e){
			writer.print("Invalid input ( only integers accepted )");
		}
		writer.print("</body></html>");
		writer.close();
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
