package study;

import javax.persistence.*;

@Entity
public class Movie {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "Movie_id")
    private Long movieid;

    @Column(name = "Name")
    private String moviename;

    public String getMoviename() {
        return moviename;
    }
    public Long getMovieid() {
        return movieid;
    }
    public void setMoviename( String name ) {
        moviename = name;
    }
    public void setMovieid( Long ID) {
        movieid = ID;
    }
    
    @Override
    public String toString()
    {
    	return "Movie{" +
    			"Movie_id = " + movieid+
    			"Movie_Name = '" + moviename +"\'}";
    }
    
}
