import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

public class TestPerson {
    public static Object perform(String class_name, String method_name, String[] cons_arg_types,
    String[] cons_arg_values, String[] method_arg_types, String[] method_arg_values) throws Exception {

    Class<?> n_class = Class.forName(class_name);
    Class<?> n_const_arg_types[] = new Class[cons_arg_types.length];
    Object[] constr_values = new Object[cons_arg_values.length];
    

    
    for (int i = 0;  i<cons_arg_types.length;i++) {
        if(cons_arg_types[i].equals("String")){
            n_const_arg_types[i] = String.class;
            constr_values[i] = cons_arg_values[i];
        }
        else if (cons_arg_types[i].equals("int")){
            n_const_arg_types[i] = int.class;
            constr_values[i]= Integer.parseInt(cons_arg_values[i]);
        }
        else throw new IllegalArgumentException("Either 'int' or 'String' should have been assigned");
    }
        Constructor<?> ctr = n_class.getConstructor(n_const_arg_types);
        Object obj = ctr.newInstance(constr_values);


        Class<?>[] method_arg_Types = new Class<?>[method_arg_types.length];
        Object[] method_val = new Object[method_arg_types.length];
        for (int i = 0; i < method_arg_types.length; i++) {
            if(method_arg_types[i].equals("String")){
                method_arg_Types[i] = String.class;
                method_val[i] = method_arg_values[i];
            }
            else if(method_arg_types[i].equals("int")){
                method_arg_Types[i] = int.class;
                method_val[i] = Integer.parseInt(method_arg_values[i]);
            }
            else throw new IllegalArgumentException("Either 'int' or 'String' should have been assigned");

        }
        Method method = n_class.getMethod(method_name, method_arg_Types);
        return method.invoke(obj, method_val);
}
    public static void main(String args[]) throws Exception {
    Class<?> c = Person.class;

    Class<?>[] ar = new Class[]{String.class, String.class};
    Constructor<?> ctr = c.getConstructor(ar);
    Object[] x = new Object[]{"Simon", "Baloian"};
    Object o = ctr.newInstance(x);
    System.out.println(o);
//     String[] constr_arg_Type = new String[]{"String", "String", "int", "int", "int"};
//     String[] constr_arg_value  = new String[]{"Armen", "Tatunts", "12", "21", "23"};
//     Method[] ms = c.getDeclaredMethods(); 
// for (int i = 0; i < ms.length; ++i)	{
// 	String mname = ms[i].getName();
// 	Class retType = ms[i].getReturnType();
// 	System.out.print("Method : " + mname + " returns " + retType.getName() + "parameters : ( ");
// 	Class[] params = ms[i].getParameterTypes();
//  	for (int k = 0; k < params.length; ++k)	{
// 		String paramType = params[k].getName();
// 		System.out.print(paramType + " ");
// 	}
// 	System.out.println(") ");
// }
String className = "Person";
String methodName = "addAge";
String[] consArgTypes = {"String", "String", "int", "int", "int"};
String[] consArgValues = {"Andrea", "Castillo", "60", "70", "168"};
String[] methodArgTypes = {"int"};
String[] methodArgValues = {"10"};

    // String cl_Name = "Person";
    // Method addAgeMethod = c.getMethod("addAge", int.class);
    // addAgeMethod.invoke(o, 5); 
    // System.out.println(o);
    // String class_Name = Class.forName("Person");
    Object ob_method = perform(className, methodName,consArgTypes,consArgValues,methodArgTypes,methodArgValues);  
    System.out.println(ob_method);  
    // Method changeNameMethod = c.getMethod("changeName", String.class, String.class);
    // changeNameMethod.invoke(o, "John", "Doe"); 
    System.out.println(o);

    // ar = new Class[]{String.class, String.class, int.class, int.class, int.class};
    // ctr = c.getConstructor(ar);
    // x = new Object[]{"Andrea", "Castillo", 60, 70, 168};
    // o = ctr.newInstance(x);
    // System.out.println(o);
}
}
