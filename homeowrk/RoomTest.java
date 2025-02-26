

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The test class RoomTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class RoomTest
{
    /**
     * Default constructor for test class RoomTest
     */
    public RoomTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    @After
    public void tearDown()
    {
    }

    @Test
    public void testExits()
    {
        Room Lobby = new Room("Lobby", "a waiting room");
        assertNotNull(Lobby.getExitDirections());
        assertEquals(null, Lobby.getExit("west"));
        Room Office = new Room("Office", "a large office");
        Room auditorium = new Room("Large Auditorium", "1,346 seats\n" + //
                        "Audio system, Large screen for presentations and movie-watching.\n" + //
                                                        "" );
        Room aquarium = new Room("Aquarium Library", "Loud Studying Area" );
        aquarium.getLongDescription();
        aquarium.setExit("east", );
        Room MainBuilding_1st_floor = new Room("AUA Main Building", "It contains the Library , the Administration Office");
        MainBuilding_1st_floor.setExit("south", null);
        Room Library = new Room("Papazian Library", "7 study rooms, books, computers");
        // Study rooms with east exits to the Library
        Lobby.setExit("west", Office);
        assertEquals(Office, Lobby.getExit("west"));
    }
}

