package helloworld.wyyadd.sql;

import java.sql.*;

public class Bookstore {
	
	public void Insert() {
		try {
			//load and register driver
			Class.forName("com.mysql.cj.jdbc.Driver");
			//generate JDBC connection
			//String dbURL = "jdbc:mysql://localhost:3306/BOOKSTORE?user=wyyadd&password=Wyyadd000216.";
			String dbURL = "jdbc:mysql://localhost:3306/BOOKSTORE?user=USER&password=PASSWORD";
			Connection connection = DriverManager.getConnection(dbURL);
			//generate preparedStatement
			String sql = "INSERT INTO bookstore (store_name, Sales, Date) values(?, ?, ?)";
			PreparedStatement pstmt = connection.prepareStatement(sql);
			//delete all from bookstore table
			String delete_sql = "DELETE FROM bookstore";
			Statement statement = connection.createStatement();
			statement.executeUpdate(delete_sql);

			//add a record
			pstmt.setString(1, "Los Angeles");
			pstmt.setDouble(2, 1500);
			pstmt.setDate(3, java.sql.Date.valueOf("1999-01-09"));
			pstmt.addBatch();
			pstmt.clearParameters();

			pstmt.setString(1, "San Diego");
			pstmt.setDouble(2, 250);
			pstmt.setDate(3, java.sql.Date.valueOf("1999-01-07"));
			pstmt.addBatch();
			pstmt.clearParameters(); 

			pstmt.setString(1, "Los Angeles");
			pstmt.setDouble(2, 300);
			pstmt.setDate(3, java.sql.Date.valueOf("1999-01-08"));
			pstmt.addBatch();
			pstmt.clearParameters();

			pstmt.setString(1, "Boston");
			pstmt.setDouble(2, 7000);
			pstmt.setDate(3, java.sql.Date.valueOf("1999-01-08"));
			pstmt.addBatch();
			pstmt.clearParameters();

			//executeBatch
			pstmt.executeBatch();
			pstmt.clearBatch();

			//close connection
			connection.close();
		}catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void Read() {
		try {
			//load and register driver
			Class.forName("com.mysql.cj.jdbc.Driver");
			//generate JDBC connection
			String dbURL = "jdbc:mysql://localhost:3306/BOOKSTORE?user=wyyadd&password=Wyyadd000216.";
			//generate statement
			Connection connection = DriverManager.getConnection(dbURL);
			Statement statement = connection.createStatement();
			String sqlQuery = "SELECT * FROM bookstore";
			//get result
			ResultSet rs = statement.executeQuery(sqlQuery);
			
			//print format
			System.out.println("store_name\tSales\tDate");
			System.out.println("----------------------------");
			while(rs.next()) {
				System.out.printf("%-10s\t%-5s\t%s\n",rs.getString("store_name"),rs.getInt("Sales"),rs.getDate("Date"));
			}
			
			//close connection
			connection.close();  
		}catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bookstore foo = new Bookstore();
		foo.Insert();
		foo.Read();
	}
}
