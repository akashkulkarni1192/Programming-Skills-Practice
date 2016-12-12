package pack;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;

@WebServlet("/WallServlet")
public class WallServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
   
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String service = request.getParameter("service");
		WallClass wall = new WallClass();
		if(service.equals("addFriend")){
			String friendID = request.getParameter("friendName");
			String userID = request.getParameter("username");
			wall.addFriend(userID,friendID);
			
			
			BasicDBObject findQuery = new BasicDBObject("_id",userID);
			DataBaseConnector connect = new DataBaseConnector();
			DB db = DataBaseConnector.getDatabase();
			DBCollection userProfile = db.getCollection("userProfile");
			DBCursor cur = userProfile.find(findQuery);
			BasicDBObject userFound = (BasicDBObject) cur.next();
			request.setAttribute("userFound", userFound);
			RequestDispatcher rd =request.getRequestDispatcher("userProfile.jsp");  
	        rd.forward(request, response);
		}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
