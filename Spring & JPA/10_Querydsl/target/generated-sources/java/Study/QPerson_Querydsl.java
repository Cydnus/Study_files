package Study;

import static com.querydsl.core.types.PathMetadataFactory.*;

import com.querydsl.core.types.dsl.*;

import com.querydsl.core.types.PathMetadata;
import javax.annotation.Generated;
import com.querydsl.core.types.Path;
import com.querydsl.core.types.dsl.PathInits;


/**
 * QPerson_Querydsl is a Querydsl query type for Person_Querydsl
 */
@Generated("com.querydsl.codegen.EntitySerializer")
public class QPerson_Querydsl extends EntityPathBase<Person_Querydsl> {

    private static final long serialVersionUID = -1578269862L;

    public static final QPerson_Querydsl person_Querydsl = new QPerson_Querydsl("person_Querydsl");

    public final ListPath<Address_Querydsl, QAddress_Querydsl> addresses = this.<Address_Querydsl, QAddress_Querydsl>createList("addresses", Address_Querydsl.class, QAddress_Querydsl.class, PathInits.DIRECT2);

    public final NumberPath<Integer> age = createNumber("age", Integer.class);

    public final NumberPath<Integer> id = createNumber("id", Integer.class);

    public final StringPath name = createString("name");

    public QPerson_Querydsl(String variable) {
        super(Person_Querydsl.class, forVariable(variable));
    }

    public QPerson_Querydsl(Path<? extends Person_Querydsl> path) {
        super(path.getType(), path.getMetadata());
    }

    public QPerson_Querydsl(PathMetadata metadata) {
        super(Person_Querydsl.class, metadata);
    }

}

