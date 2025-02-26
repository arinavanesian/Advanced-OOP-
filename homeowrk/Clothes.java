
public class Clothes extends Item {
    private int value;
    private boolean isRare;

    public Clothes(String name, double weight, int value, boolean canTake) {
        super(name, weight = 2.0, canTake);
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public boolean isRare() {
        return isRare;
    }

    public void setRare(boolean isRare) {
        this.isRare = isRare;
    }
    @Override
    public void getDescription(){
        System.out.println("This is " + getName() + 
        "\n(Value: " + value + 
        ", Weight: " + getWeight() + 
        ", Rare: " + (isRare() ? "Rare" : "Standard") + ")");
     }

    /**AddTaking refere
     * @param player
     */
    public void wear(Player player) {
        System.out.println("You wore " + getName() + 
                   "\n(Value: " + value + 
                   ", Weight: " + getWeight() + 
                   ", Rare: " + (isRare() ? "Rare" : "Standard") + ")");

    }

}



