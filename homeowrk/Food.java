public class Food extends Item {
    private int healthValue;
    public Food(String name, double weight, boolean canTake, int healthValue) {
        super(name, weight, canTake);
        this.healthValue = healthValue;
    }
    
    public int getHealthValue() {
        return healthValue;
    }
    @Override
    public void getDescription(){
        System.out.println("This is a \n" + this.getName() + "\nHealth Value: "+this.healthValue);
    }
    /**Player eats the food
     * and it replenishes the health
     * @param player
     */
    public void eat(Player player) {
        System.out.println("You ate " + getName() + " and gained " + healthValue + " health.");
        player.setHealth((player.getHealth()+healthValue));
    }
}