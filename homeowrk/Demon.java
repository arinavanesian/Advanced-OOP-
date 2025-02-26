/** DONE
 * This is a demon class, which can damage the player
 ** 
*/
public class Demon extends Item {
    private int damageValue;

    public Demon(String name, boolean canTake, int damageValue) {
        super(name = "Demon", canTake = false); 
        this.damageValue = damageValue;
    }

    
    /**Getter for the amount of damage that can be done by the demon
     * @return damageValue
     */
    public int getDamageValue() {
        return damageValue;
    }

    /**
     * Overriding the Item getDescription method
     * to give the info of the demon object
     * @param player
     */
    @Override
    public void getDescription(){
        System.out.println("This Item is a\n" + this.getName() + "Damage Value: "+this.damageValue);
    }

    /**
     * By getting the reference to the player this demon interacts with
     * it damages the player 
     * @param player
     */
    public void damage(Player player) {
        System.out.println("You encountered a demon! You lost " + damageValue + " health.");
        player.takeDamage(damageValue);
    }
}