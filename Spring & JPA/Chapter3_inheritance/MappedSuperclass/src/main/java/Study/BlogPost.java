package Study;

import javax.persistence.Column;
import javax.persistence.Entity;

@Entity
public class BlogPost extends Publication {

    @Column
    private String url;

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }
}
