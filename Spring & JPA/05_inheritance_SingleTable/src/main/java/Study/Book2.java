package Study;

import javax.persistence.*;

@Entity
@DiscriminatorValue("BOOK")
public class Book2 extends Publication {

    @Column
    private int pages;

    public int getPages() {
        return pages;
    }

    public void setPages(int pages) {
        this.pages = pages;
    }
}
