import java.lang.reflect.Constructor;

public class Main{

    // public static Object perform(String class_name, String method_name, String[] cons_arg_types, String[] cons_arg_values, String[] method_arg_types, String[] method_arg_values){
    //     Class<?> c = Class.forName("class_name");

    //     Class<?> c_person = Class.forName("Person");
    //     Class<?>[] ar_int = new Class[]{String.class, String.class, int.class, int.class, int.class};
    //     Constructor<?> ctr_person = c_person.getConstructor(ar_int);
    //     Object[] per_obj = new Object[]{"Arin", "Tantooshyan", 23, 154, 12};
    //     Object p_obj = ctr_person.newInstance(per_obj);
    //     System.out.println(p_obj);

    // }
public static void main(String[] args) throws Exception {
    // Creating a Person object using Reflection on my Person.java
    Class<?> pers = Person.class;
    
    Class<?> arr[] = new Class[]{String.class, String.class, int.class, int.class, int.class};
    Constructor<?> ctr = pers.getConstructor(arr);
    Object[] obj = new Object[]{"Aren", "Lava", 123, 123, 23};
    Object p_o = ctr.newInstance(obj);
    System.out.println(p_o.toString());
    // Gets all the constructors, for the Person we 3 constructors
    Constructor<?>[] ctors = pers.getConstructors();

    for (int i = 0; i < ctors.length; ++i) {
	System.out.print("Constructor (");
	Class<?>[] params = ctors[i].getParameterTypes(); // all the parameters used in that i-th constructor, gets the multiparameter constrctur first
	for (int k = 0; k < params.length; ++k) {
        // String String int int int
		String paramType = params[k].getName();
		System.out.print(paramType + " ");
	}
	System.out.println(")");
}
    // Field[] publicFields = pers.getFields();  
    // for (int i = 0; i < publicFields.length; ++i) {
    //         String fieldName = publicFields[i].getName();
    //         Class<?> typeClass = publicFields[i].getType();
    //         System.out.println("\nField: " + fieldName + " of type " + typeClass.getName()+"\n");
    //         }
    
}
}
