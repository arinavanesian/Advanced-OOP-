import java.util.ArrayList;
import java.util.List;

public class SingleClassCollection<T> {
    private List<T> elements = new ArrayList<>();
    private Class<?> type = null; // Stores the type of the first added element

    public void add(T element) {
        if (element == null) {
            throw new IllegalArgumentException("Null values are not allowed.");
        }
        if (type == null) {
            type = element.getClass(); // Set type on first insertion
        } else if (!type.equals(element.getClass())) {
            throw new IllegalArgumentException("All elements must be of type: " + type.getName());
        }
        elements.add(element);
    }

    public List<T> getElements() {
        return new ArrayList<>(elements); // Return a copy to ensure encapsulation
    }
}