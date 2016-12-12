<%@page import="com.mongodb.DBCollection"%>
<%@page import="com.mongodb.BasicDBList"%>
<%@page import="org.omg.CORBA.Request"%>
<%@page import="com.mongodb.BasicDBObject"%>
<%@page import="java.util.Iterator" %>
<%@page import="com.mongodb.DB" %>
<%@page import="com.mongodb.DBCursor" %>
<%@page import="pack.DataBaseConnector" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="en">
	<head>
		<title>Profile and wall</title>
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		
		<link rel="stylesheet" href="bootstrap/css/bootstrap.css" type="text/css">
	</head>
	<body>
			<%! 
					BasicDBObject userFound;
					BasicDBList friendList;
					Iterator<Object> it;
					BasicDBObject findQuery;
					DBCollection coll;
					DB db;
					DBCursor cursor;
					DataBaseConnector dbConnector;
				%>
				<%
					userFound=(BasicDBObject)request.getAttribute("userFound");
				%>
				
		<div class="container">
			<div class="row">
				<div class="col-md-8">
					<h4>FriendSpace</h4>
				</div>
				<div class="col-md-2" align="right">
					<button type="button">Chatbox</button>
				</div>
				<div class="col-md-2" align="right">
					<form action="login" method="get">
						<input type="hidden" name="username" value="<%= userFound.get("_id")%>">
						<input type="submit" value="Logout">
					</form>
				</div>
			</div>
			<hr>
			<div class="col-md-3 profile">
				<img src="images/profile.png" alt="profile-pic" width="100%" height="100%" >
				<hr>
				<h3><%=userFound.get("givenName") %></h3>
				
				<div class="row">
					<div class="col-md-4">
						<h4>status......</h4>
					</div>
					<div class="col-md-8" align="center">
						<button type="button">Edit</button>
					</div>
					<div class="col-md-12" align="left">
						<p>This is my status for today.....</p>
					</div>
				</div>	
			</div>
			<div class="col-md-6" style="border-left:1px solid #000;height:520px">
				<div class="row">
					<h3 align="center">Welcome to FriendSpace</h3>
				</div>
				<hr>
				<div class="wall" style="width: 100%; height: 400px; overflow-y: scroll;">
					<div align="center" style="width:95%;height:100px;border:1px solid black;">
						Post 1
					</div>
					<hr>
					<div align="center" style="width:95%;height:100px;border:1px solid black;">
						Post 2
					</div>
					<hr>
					<div align="center" style="width:95%;height:100px;border:1px solid black;">
						Post 3
					</div>
					<hr>
					<div align="center" style="width:95%;height:100px;border:1px solid black;">
						Post 4
					</div>
					<hr>
				</div>	
			</div>
			<div class="col-md-3" style="border-left:1px solid #000;height:520px">
				<div class="row">
					<h3 align="center">Online Friends</h3>
				</div>
				<hr>
				<div class="wall" style="width: 100%; height: 300px; overflow-y: scroll">
				
				<%
				 try{	
					System.out.println("start");
					dbConnector=new DataBaseConnector();
					db=DataBaseConnector.getDatabase();
					//coll=db.getCollection("userProfile");
					System.out.println("coll");
					//findQuery = new BasicDBObject("_id",userFound.getString("_id"));
					//cursor = coll.find(findQuery);
					//friendList = (BasicDBList) cursor.next().get("friendList");
					friendList=(BasicDBList)userFound.get("friendList");
					it = friendList.iterator();
				
					while(it.hasNext()){
						BasicDBObject friend = (BasicDBObject) it.next();
						findQuery = new BasicDBObject("_id",friend.getString("userName"));
						coll = db.getCollection("registeredUser");
						cursor = coll.find(findQuery);
						if(cursor.next().get("isOnline").equals("true")){%>
							<div align="center" style="width:95%;height:20%;">
								<a href=""><button style="width:100%;	height:70%"><%=friend.getString("userName")%></button></a>
							</div>
						<%}
					}
				}catch(Exception E){
						E.printStackTrace();	
				}
				%>
				</div>
				<hr>
				<div class="row">
					<h4 align="center">Add more friends</h4>
					<form action="wall" method="get">
						<input type="hidden" name="service" value="addFriend">
						<input type="hidden" name="username" value="<%= userFound.get("_id")%>">
						FriendID : <input type="text" name="friendName"><br><br>
						<input type="submit" value=" Friend++">
					</form>
				</div>
			</div>
		</div>
	</body>	
</html>