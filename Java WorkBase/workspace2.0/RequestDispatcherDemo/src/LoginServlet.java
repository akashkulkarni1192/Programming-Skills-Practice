import java.io.*;  
import javax.servlet.*;  
import javax.servlet.http.*;  
  
  
public class LoginServlet extends HttpServlet {  
  
public void doPost(HttpServletRequest request, HttpServletResponse response)  
        throws ServletException, IOException {  
  
    response.setContentType("text/html");  
    PrintWriter out = response.getWriter();  
    out.print("Login Servlet Printed");
          
    String n=request.getParameter("userName");  
    String p=request.getParameter("userPass");  
          
    if(p.equals("welcome me")){  
        RequestDispatcher rd=request.getRequestDispatcher("welcome");  
        rd.forward(request, response);  
    }  
    else{  
        out.print("Sorry UserName or Password Error!");  
        RequestDispatcher rd=request.getRequestDispatcher("/index.html");  
        rd.include(request, response);  
                      
        }  
   }  
  
}  