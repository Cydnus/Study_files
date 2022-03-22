
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class test {
    public static void main(String[] args) {
        Connection con = null;
        PreparedStatement pstmt = null;   
        ResultSet rs = null;
        try {
            Class.forName("org.mariadb.jdbc.Driver");
            
            con = DriverManager.getConnection(
                "jdbc:mariadb://192.168.0.52:3306/jpa_playground",
                "sangho",
                "sangho");

        	System.out.println("Success to connect");
        	
            pstmt = con.prepareStatement("select * from Movie");
            
            rs = pstmt.executeQuery();
            
        	System.out.println("Success to Query");
            
        } catch(Exception e) {
        	System.out.println("Fail to connect");
            e.printStackTrace();
        } finally {
            try {
                if(rs != null) {
                    rs.close(); // ���� ����
                }
                
                if(pstmt != null) {
                    pstmt.close(); // ���û��������� ȣ�� ��õ
                }
            
                if(con != null) {
                    con.close(); // �ʼ� ����
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
