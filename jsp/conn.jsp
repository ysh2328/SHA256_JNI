<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Oracle Connection Test</title>
</head>
<body>
<%@page import="java.sql.*" %>
<%@page import="ysh.Cal" %>
<%@page import="ysh.Sha" %>
<h2> '톰캣 +  Oracle' 연결 TEST.. </h2>
<%
        try{
                String driverName="oracle.jdbc.driver.OracleDriver";
                String dbURL = "jdbc:oracle:thin:@localhost:1521:ORCL";
                Class.forName(driverName);
                Connection conn = DriverManager.getConnection(dbURL,"SYSTEM","0000");
                out.println("Oracle Database 에 접속 성공!");
                conn.close();
        }catch(Exception e){
                out.println("Oracle Database 에 접속 오류!!");
                out.println(e.getMessage());
                e.printStackTrace();
        }
	
	out.println(System.getProperty("java.library.path"));
	//System.loadLibrary("Cal");
	Cal cal = new Cal();
	Sha sha = new Sha();
	
        out.println(cal.add(1,2));
        out.println(cal.minus(1,2));
	out.println(sha.sha256("123"));
%>
</body>
</html>
