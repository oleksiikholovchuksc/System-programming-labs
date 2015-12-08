package lab6;

import java.lang.annotation.Retention;
import static java.lang.annotation.RetentionPolicy.RUNTIME;
import lab6.Product.Author;


@Author(whoWroteThis = "me")
public class Product {

    private String m_name;
    private int m_id;

    public String publicField;

    @Retention(RUNTIME)
    public @interface Author {
        public String whoWroteThis();
    }

    public Product(String name, int id) {
        m_name = name;
        m_id = id;
    }

    public String getName() {
        return m_name;
    }

    public int getId() {
        return m_id;
    }

}