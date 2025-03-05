import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.Scanner;

public class DynamicInvoker {

    /**
     * Dynamically creates an object of the specified class, invokes the specified method,
     * and returns the result.
     *
     * @param class_name         The name of the class.
     * @param method_name        The name of the method to invoke.
     * @param cons_arg_types     The types of the constructor arguments (either "int" or "String").
     * @param cons_arg_values    The values of the constructor arguments.
     * @param method_arg_types   The types of the method arguments (either "int" or "String").
     * @param method_arg_values  The values of the method arguments.
     * @return The result of the method invocation, or null if an error occurs.
     */
    public static Object perform(String class_name, String method_name, String[] cons_arg_types,
                                 String[] cons_arg_values, String[] method_arg_types, String[] method_arg_values) throws Exception{
        try {
            Class<?> clazz = Class.forName(class_name);
            Class<?>[] consParamTypes = new Class<?>[cons_arg_types.length];
            Object[] consArgs = new Object[cons_arg_types.length];
            for (int i = 0; i < cons_arg_types.length; i++) {
                if (cons_arg_types[i].equals("int")) {
                    consParamTypes[i] = int.class;
                    consArgs[i] = Integer.parseInt(cons_arg_values[i]);
                } else if (cons_arg_types[i].equals("String")) {
                    consParamTypes[i] = String.class;
                    consArgs[i] = cons_arg_values[i];
                } else {
                    throw new IllegalArgumentException("Invalid constructor argument type: " + cons_arg_types[i]);
                }
            }

            Constructor<?> constructor = clazz.getConstructor(consParamTypes);
            Object instance = constructor.newInstance(consArgs);

            // Convert method arguments to the correct types
            Class<?>[] methodParamTypes = new Class<?>[method_arg_types.length];
            Object[] methodArgs = new Object[method_arg_types.length];

            for (int i = 0; i < method_arg_types.length; i++) {
                if (method_arg_types[i].equals("int")) {
                    methodParamTypes[i] = int.class;
                    methodArgs[i] = Integer.parseInt(method_arg_values[i]);
                } else if (method_arg_types[i].equals("String")) {
                    methodParamTypes[i] = String.class;
                    methodArgs[i] = method_arg_values[i];
                } else {
                    throw new IllegalArgumentException("Invalid method argument type: " + method_arg_types[i]);
                }
            }

            Method method = clazz.getMethod(method_name, methodParamTypes);
            return method.invoke(instance, methodArgs);

        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            return null;
        }
    }


    public static void main(String[] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the class name: ");
        String className = scanner.nextLine();

        System.out.print("Enter the method name: ");
        String methodName = scanner.nextLine();

        System.out.print("Enter the number of constructor arguments: ");
        int consArgCount = Integer.parseInt(scanner.nextLine());
        String[] consArgTypes = new String[consArgCount];
        String[] consArgValues = new String[consArgCount];
        for (int i = 0; i < consArgCount; i++) {
            System.out.print("Enter type of constructor argument " + (i + 1) + " (int or String): ");
            consArgTypes[i] = scanner.nextLine();
            System.out.print("Enter value of constructor argument " + (i + 1) + ": ");
            consArgValues[i] = scanner.nextLine();
        }

        System.out.print("Enter the number of method arguments: ");
        int methodArgCount = Integer.parseInt(scanner.nextLine());
        String[] methodArgTypes = new String[methodArgCount];
        String[] methodArgValues = new String[methodArgCount];
        for (int i = 0; i < methodArgCount; i++) {
            System.out.print("Enter type of method argument " + (i + 1) + " (int or String): ");
            methodArgTypes[i] = scanner.nextLine();
            System.out.print("Enter value of method argument " + (i + 1) + ": ");
            methodArgValues[i] = scanner.nextLine();
        }

        Object result = perform(className, methodName, consArgTypes, consArgValues, methodArgTypes, methodArgValues);
        if (result != null) {
            System.out.println("Result: " + result);
        } else {
            System.out.println("No result or an error occurred.");
        }
        scanner.close();
    }
}