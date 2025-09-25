import java.sql.*;

public class JdbcExample {

    public static void main(String[] args) {

        // Database connection details
        String url = "jdbc:mysql://localhost:3306/testdb";
        String user = "root";
        String password = "pds2003@MS";

        try {
            // Load the JDBC driver (optional in newer Java versions)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish connection
            Connection conn = DriverManager.getConnection(url, user, password);

            // Create a statement
            Statement stmt = conn.createStatement();

            // Execute query
            ResultSet rs = stmt.executeQuery("SELECT * FROM Employees");

            // Process results
            while (rs.next()) {
                int id = rs.getInt("emp_id");
                String name = rs.getString("name");
                double salary = rs.getDouble("salary");

                System.out.println(id + " | " + name + " | " + salary);
            }

            // Close resources
            rs.close();
            stmt.close();
            conn.close();

        } catch (ClassNotFoundException e) {
            System.out.println("JDBC Driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Database error.");
            e.printStackTrace();
        }

    }

}
