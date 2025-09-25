import java.sql.*;

public class PreparedStatementExample {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/testdb";
        String user = "root";
        String password = "MySQL_password";

        try (Connection conn = DriverManager.getConnection(url, user, password)) {

            // 1. Create PreparedStatement with placeholders
            String sql = "INSERT INTO Employees (emp_id, name, salary) VALUES (?, ?, ?)";
            PreparedStatement pstmt = conn.prepareStatement(sql);

            // 2. Set values for placeholders
            pstmt.setInt(1, 3);          // emp_id = 3
            pstmt.setString(2, "Charlie"); // name = Charlie
            pstmt.setDouble(3, 7000.00); // salary = 7000

            // 3. Execute the update
            int rows = pstmt.executeUpdate();
            System.out.println(rows + " row(s) inserted.");

            pstmt.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
