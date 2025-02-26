package in_class.Reflection;
import practice.HW_Test_Item.Treasure;

public class ClassReflect {
public static void main(String[] args) {
    try{
    Class<?> class1 = Treasure.class; //assuming ExampleClass available
    System.out.println("Method 1: " + class1.getName());
    // 2. Using getClass() from an Object
    Treasure obj = new Treasure();
    Class<?> class2 = obj.getClass();
    System.out.println("Method 2: " + class2.getName());
    // 3. Using Class.forName() (Dynamic Loading)
    Class<?> class3 = Class.forName("Treasure"); 
    System.out.println("Method 3: " + class3.getName());
    } catch (ClassNotFoundException e) { e.printStackTrace();}

}
}