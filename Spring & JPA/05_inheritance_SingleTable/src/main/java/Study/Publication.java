package Study;

import javax.persistence.*;

@Entity
@Inheritance(strategy = InheritanceType.SINGLE_TABLE)
@DiscriminatorColumn(name="PUB_TYPE")
public abstract class Publication {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "PUBLICATION_ID", updatable = false, nullable = false)
    protected Long id;

    @Column
    protected String title;

    @Column(name = "version")
    private int version;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getVersion() {
        return version;
    }

    public void setVersion(int version) {
        this.version = version;
    }
}
