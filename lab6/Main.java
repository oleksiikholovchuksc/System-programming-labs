package lab6;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.annotation.Annotation;


public class Main {

    public static void main(String[] args) {
        try{
            Class c = Class.forName("lab6.Product");
            Constructor constructor = c.getConstructor(String.class, int.class);
            Product prod = (Product)constructor.newInstance("Some product", 322);

            // get fields
            Class productClass = prod.getClass();
            Field[] publicFields = productClass.getDeclaredFields();
            for(Field field : publicFields) {
                String fieldType = field.getType().getName();
                String fieldName = field.getName();

                System.out.println(fieldType + " " + fieldName);
            }

            // get methods
            Method[] methods = productClass.getMethods();
            for(Method method : methods) {
                String returnType = method.getReturnType().getName();
                String name = method.getName();

                System.out.println(returnType + " " + name);
            }

            // get annotations
            Annotation[] annotations = productClass.getAnnotations();
            for(Annotation annotation : annotations) {
                String type = annotation.annotationType().getName();

                System.out.println(type);
            }
        }
        catch(ClassNotFoundException ex) {}
        catch(NoSuchMethodException ex) {}
        catch(InstantiationException ex) {}
        catch(IllegalAccessException ex) {}
        catch(InvocationTargetException ex) {}
    }

}