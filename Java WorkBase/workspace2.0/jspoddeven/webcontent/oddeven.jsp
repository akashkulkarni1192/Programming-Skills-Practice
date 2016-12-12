<%@page import="java.util.Random"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<table color="green" align="center" border="2">
		<tr>
			<th>Number</th>
			<th>Odd/Even</th>
		</tr>
		<% for(int i=1;i<10;i++){ %>
		<% int	num= new Random().nextInt(100); %>
		<%		if(num%2==1) {%>
		<tr>
			<td><%= num%></td>
			<td>Odd</td>
		</tr>
		<%		}else{ %>
		<tr>
			<td><%= num%></td>
			<td>Even</td>
		</tr>
		<%		} %>
		<%	} %>
	</table>
</body>
</html>