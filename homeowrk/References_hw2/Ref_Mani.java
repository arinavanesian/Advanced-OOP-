import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
public class Ref_Mani {

public static void main(String args[]) throws Exception {
    Class<?> c = Person.class;

    Class<?>[] ar = new Class[]{String.class, String.class};

    Constructor<?> ctr = c.getConstructor(ar);
    
    Object[] x = new Object[]{"Simon", "Baloian"};
    
    Object o = ctr.newInstance(x);
    
    System.out.println(o);
    
    Method addAgeMethod = c.getMethod("addAge", int.class);
    
    addAgeMethod.invoke(o, 5); // Add 5 years to the age
    
    System.out.println(o);
    
    Method changeNameMethod = c.getMethod("changeName", String.class, String.class);
    
    changeNameMethod.invoke(o, "John", "Doe"); // Change name to John Doe
    System.out.println(o);
    
    ar = new Class[]{String.class, String.class, int.class, int.class, int.class};
    ctr = c.getConstructor(ar);
    x = new Object[]{"Andrea", "Castillo", 60, 70, 168};
    o = ctr.newInstance(x);
    System.out.println(o);
}

}
