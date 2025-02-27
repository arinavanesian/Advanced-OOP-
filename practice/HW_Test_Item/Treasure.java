package practice.HW_Test_Item;

public class Treasure {
private int value;
private String loc;
public Treasure(){}
public Treasure(int value, String loc) {
    this.value = value;
    this.loc = loc;
}
@Override
public String toString() {
    return "Treasure [value=" + value + ", loc=" + loc + ", getClass()=" + getClass() + "]";
}
public int getValue() {
    return value;
}
public void setValue(int value) {
    this.value = value;
}
public String getLoc() {
    return loc;
}
public void setLoc(String loc) {
    this.loc = loc;
}   
}