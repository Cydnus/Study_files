package Study;

import static com.querydsl.core.types.PathMetadataFactory.*;

import com.querydsl.core.types.dsl.*;

import com.querydsl.core.types.PathMetadata;
import javax.annotation.Generated;
import com.querydsl.core.types.Path;
import com.querydsl.core.types.dsl.PathInits;


/**
 * QAddress_Querydsl is a Querydsl query type for Address_Querydsl
 */
@Generated("com.querydsl.codegen.EntitySerializer")
public class QAddress_Querydsl extends EntityPathBase<Address_Querydsl> {

    private static final long serialVersionUID = 720008645L;

    private static final PathInits INITS = PathInits.DIRECT2;

    public static final QAddress_Querydsl address_Querydsl = new QAddress_Querydsl("address_Querydsl");

    public final StringPath city = createString("city");

    public final NumberPath<Integer> id = createNumber("id", Integer.class);

    public final QPerson_Querydsl person;

    public final StringPath street = createString("street");

    public final StringPath zipCode = createString("zipCode");

    public QAddress_Querydsl(String variable) {
        this(Address_Querydsl.class, forVariable(variable), INITS);
    }

    public QAddress_Querydsl(Path<? extends Address_Querydsl> path) {
        this(path.getType(), path.getMetadata(), PathInits.getFor(path.getMetadata(), INITS));
    }

    public QAddress_Querydsl(PathMetadata metadata) {
        this(metadata, PathInits.getFor(metadata, INITS));
    }

    public QAddress_Querydsl(PathMetadata metadata, PathInits inits) {
        this(Address_Querydsl.class, metadata, inits);
    }

    public QAddress_Querydsl(Class<? extends Address_Querydsl> type, PathMetadata metadata, PathInits inits) {
        super(type, metadata, inits);
        this.person = inits.isInitialized("person") ? new QPerson_Querydsl(forProperty("person")) : null;
    }

}

