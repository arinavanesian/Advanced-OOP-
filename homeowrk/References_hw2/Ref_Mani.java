import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.awt.Rectangle;
import java.awt.Shape;
public class Ref_Mani {

public static void main(String args[]) throws Exception {
    Class<?> c = Person.class;

    // Create an instance using the two-argument constructor
    Class<?>[] ar = new Class[]{String.class, String.class};
    Constructor<?> ctr = c.getConstructor(ar);
    Object[] x = new Object[]{"Simon", "Baloian"};
    Object o = ctr.newInstance(x);
    System.out.println(o);

    // Dynamically invoke (use the .invoke()) the addAge method
    Method addAgeMethod = c.getMethod("addAge", int.class);
    addAgeMethod.invoke(o, 5); // Add 5 years to the age
    System.out.println(o);

    // Dynamically invoke(use the .invoke()) the changeName method
    Method changeNameMethod = c.getMethod("changeName", String.class, String.class);
    changeNameMethod.invoke(o, "John", "Doe"); // Change name to John Doe
    System.out.println(o);

    // Create an instance using the five-argument constructor
    ar = new Class[]{String.class, String.class, int.class, int.class, int.class};
    ctr = c.getConstructor(ar);
    x = new Object[]{"Andrea", "Castillo", 60, 70, 168};
    o = ctr.newInstance(x);
    System.out.println(o);

    Class<?> c_ = Rectangle.class;
    Class<?>[] intArgsClass = new Class[]{ int.class, int.class };
    Object[] intArgs = new Object[]{Integer.valueOf(12),Integer.valueOf(24)};
    Constructor<?> ctor = c_.getConstructor(intArgsClass);
    Rectangle r = (Rectangle) ctor.newInstance(intArgs);
    System.out.println(r.getWidth());
}

}
