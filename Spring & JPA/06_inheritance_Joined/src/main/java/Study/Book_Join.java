package Study;

import javax.persistence.*;

@Entity
@DiscriminatorValue("BOOK")
public class Book_Join extends Publication_Join {

    @Column
    private int pages;

    public int getPages() {
        return pages;
    }

    public void setPages(int pages) {
        this.pages = pages;
    }
}
