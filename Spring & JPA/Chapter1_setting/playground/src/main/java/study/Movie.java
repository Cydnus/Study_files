package study;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Movie {
    @Id
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
