import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import java.util.ArrayList;

/**
 * This is a SUBSET of the unit tests with which we will grade your code.
 *
 * Make absolute sure that your code can compile together with this tester!
 * If it does not, you may get a very low grade for your assignment.
 */
public class FacebukPartialTester {
	private Person _barack, _michelle, _kevin, _ina, _joe, _malia;
	private Pet _bo, _sunny;
	private Moment _meAndBarack;
	private ArrayList _michelleAndBarack, _michelleJoeBoAndMalia;

	@Before
	public void setUp () {
		initPeople();
		initPets();
		initGroups();
		initPossessions();
		initMoments();
	}

	private void initPeople () {
		_michelle = new Person("Michelle", new Image("Michelle.png"));
		_barack = new Person("Barack", new Image("Barack.png"));
		_kevin = new Person("Kevin", new Image("Kevin.png"));
		_ina = new Person("Ina", new Image("Ina.png"));
		_joe = new Person("Joe", new Image("Joe.png"));
		_malia = new Person("Malia", new Image("Malia.png"));
	}

	private void initPets () {
		_bo = new Pet("Bo", new Image("Bo.png"));
		_sunny = new Pet("Sunny", new Image("Sunny.png"));

		_bo.setOwner(_michelle);
		_sunny.setOwner(_michelle);
	}

	private void initGroups () {
		// Kevin, Barack, and Ina
		final ArrayList michelleFriends = new ArrayList();
		michelleFriends.add(_kevin);
		michelleFriends.add(_barack);
		michelleFriends.add(_ina);

		// Michelle and Barack
		_michelleAndBarack = new ArrayList();
		_michelleAndBarack.add(_michelle);
		_michelleAndBarack.add(_barack);

		// Michelle, Joe, Bo, and Malia
		_michelleJoeBoAndMalia = new ArrayList();
		_michelleJoeBoAndMalia.add(_michelle);
		_michelleJoeBoAndMalia.add(_joe);
		_michelleJoeBoAndMalia.add(_bo);
		_michelleJoeBoAndMalia.add(_malia);

		// Malia and Sunny
		final ArrayList maliaAndSunny = new ArrayList();
		maliaAndSunny.add(_malia);
		maliaAndSunny.add(_sunny);

		// Michelle
		final ArrayList michelleList = new ArrayList();
		michelleList.add(_michelle);

		// Bo
		final ArrayList boList = new ArrayList();
		boList.add(_bo);

		// Set people's friend lists
		_michelle.setFriends(michelleFriends);
		_malia.setFriends(boList);
		_sunny.setFriends(boList);
		_barack.setFriends(michelleList);
		_kevin.setFriends(michelleList);
		_ina.setFriends(michelleList);
	
		// Finish configuring pets
		_bo.setFriends(maliaAndSunny);
		_sunny.setFriends(boList);
		final ArrayList boAndSunny = new ArrayList();
		boAndSunny.add(_bo);
		boAndSunny.add(_sunny);
		_michelle.setPets(boAndSunny);
	}

	private void initPossessions () {
		final Possession boxingBag = new Possession("BoxingBag", new Image("BoxingBag.png"), 20.0f);
		boxingBag.setOwner(_michelle);
		final ArrayList michellePossessions = new ArrayList();
		michellePossessions.add(boxingBag);
		_michelle.setPossessions(michellePossessions);
	}

	private void initMoments () {
		// Smiles
		final ArrayList michelleAndBarackSmiles = new ArrayList();
		michelleAndBarackSmiles.add(0.25f);
		michelleAndBarackSmiles.add(0.75f);

		final ArrayList michelleJoeBoAndMaliaSmiles = new ArrayList();
		michelleJoeBoAndMaliaSmiles.add(0.2f);
		michelleJoeBoAndMaliaSmiles.add(0.3f);
		michelleJoeBoAndMaliaSmiles.add(0.4f);
		michelleJoeBoAndMaliaSmiles.add(0.5f);

		// Moments
		_meAndBarack = new Moment("Me & Barack", new Image("MeAndBarack.png"), _michelleAndBarack, michelleAndBarackSmiles);
		final Moment meJoeAndCo = new Moment("Me, Joe & co.", new Image("MeJoeAndCo.png"), _michelleJoeBoAndMalia, michelleJoeBoAndMaliaSmiles);

		final ArrayList michelleMoments = new ArrayList();
		michelleMoments.add(_meAndBarack);
		michelleMoments.add(meJoeAndCo);
		_michelle.setMoments(michelleMoments);

		final ArrayList barackMoments = new ArrayList();
		barackMoments.add(_meAndBarack);
		_barack.setMoments(barackMoments);

		final ArrayList joeMoments = new ArrayList();
		joeMoments.add(meJoeAndCo);
		_joe.setMoments(joeMoments);

		final ArrayList maliaMoments = new ArrayList();
		maliaMoments.add(meJoeAndCo);
		_malia.setMoments(maliaMoments);

		final ArrayList boMoments = new ArrayList();
		boMoments.add(meJoeAndCo);
		_bo.setMoments(boMoments);
	}

	@Test
	public void testEquals () {
		assertEquals(_michelle, new Person("Michelle", new Image("Michelle.png")));
		assertEquals(_michelle, new Person("Michelle", new Image("Michelle2.png")));  // should still work
		assertNotEquals(_michelle, _barack);
	}

	@Test
	public void testFindBestMoment () {
		assertEquals(_michelle.getOverallHappiestMoment(), _meAndBarack);
	}

	@Test
	public void testGetFriendWithWhomIAmHappiest () {
		assertEquals(_michelle.getFriendWithWhomIAmHappiest(), _barack);
	}

	@Test
	public void testFriendRequest1 () {
		Person person1 = new Person("person1", new Image("person1.png"));
		Person person2 = new Person("person2", new Image("person2.png"));
		Pet pet1 = new Pet("pet1", new Image("pet1.png"));

		FriendRequest friendRequest1 = new FriendRequest(person1, person2);
		// Make sure the code also compiles for making friend requests for people and pets
		FriendRequest friendRequest2 = new FriendRequest(person1, pet1);
	}

	@Test(expected = IllegalArgumentException.class)
	public void testFriendRequest2 () {
		Person person1 = new Person("person1", new Image("person1.png"));
		Person person2 = new Person("person2", new Image("person2.png"));
		Person person3 = new Person("person3", new Image("person3.png"));
		FriendRequest friendRequest = new FriendRequest(person1, person2);
		// This should raise an IllegalArgumentException:
		friendRequest.approve(person3);
	}

	// TODO: write more methods to test addFriend
	@Test
	public void testaddFriend(){
		Person person1 = new Person("person1", new Image("person1.png"));
		Person person2 = new Person("person2", new Image("person2.png"));
		person1.addFriend(person2);
		ArrayList<Person> friendsTest = new ArrayList<Person>();
		friendsTest.add(person2);
		assertEquals(friendsTest, person1.getFriends());
	}
	@Test
	public void testaddFriend2(){
		Person person1 = new Person("person1", new Image("person1.png"));
		Pet pet1 = new Pet("pet1", new Image("pet1.png"));
		person1.addFriend(pet1);
		ArrayList<User> friendsTest = new ArrayList<User>();
		friendsTest.add(pet1);
		assertEquals(friendsTest, person1.getFriends());
	}
	
	// TODO: write more methods to test approve
	@Test
	public void testApprove () {
		Person person1 = new Person("person1", new Image("person1.png"));
		Person person2 = new Person("person2", new Image("person2.png"));
		ArrayList<User> friendsTest1 = new ArrayList<User>();
		ArrayList<User> friendsTest2 = new ArrayList<User>();
		FriendRequest friendRequest1 = new FriendRequest(person1, person2);
		friendRequest1.approve(person1);
		friendRequest1.approve(person2);
		friendsTest1.add(person2);
		friendsTest2.add(person1);
		assertEquals(friendsTest1, person1.getFriends());
		assertEquals(friendsTest2, person2.getFriends());
		
	}
	@Test
	public void testApprove2 () {
		Person person1 = new Person("person1", new Image("person1.png"));
		Pet pet1 = new Pet("pet1", new Image("pet1.png"));
		ArrayList<User> friendsTest1 = new ArrayList<User>();
		ArrayList<User> friendsTest2 = new ArrayList<User>();
		FriendRequest friendRequest2 = new FriendRequest(person1, pet1);
		friendRequest2.approve(person1);
		friendRequest2.approve(pet1);
		friendsTest1.add(pet1);
		friendsTest2.add(person1);
		assertEquals(friendsTest1,person1.getFriends());
		assertEquals(friendsTest2, pet1.getFriends());
		
	}
	@Test
	public void testApprove3 () {
		Pet pet2 = new Pet("pet2", new Image("pet2.png"));
		Pet pet1 = new Pet("pet1", new Image("pet1.png"));
		ArrayList<User> friendsTest1 = new ArrayList<User>();
		ArrayList<User> friendsTest2 = new ArrayList<User>();
		FriendRequest friendRequest2 = new FriendRequest(pet2, pet1);
		friendRequest2.approve(pet2);
		friendRequest2.approve(pet1);
		friendsTest1.add(pet1);
		friendsTest2.add(pet2);
		assertEquals(friendsTest1,pet2.getFriends());
		assertEquals(friendsTest2, pet1.getFriends());
		
	}
	// TODO: write more methods to test getFriendWithWhomIAmHappiest 
	@Test
	public void testGetFriendWithWhomIAmHappiest1(){
		Person p1 = new Person("person1", new Image("person1.png"));
		Person p2 = new Person("person2", new Image("person2.png"));
		Person p3 = new Person("person3", new Image("person3.png"));
		Person p4 = new Person("person4", new Image("person4.png"));
		ArrayList participants = new ArrayList();
		participants.add(p1);
		participants.add(p2);
		participants.add(p3);
		participants.add(p4);
		ArrayList smileValues = new ArrayList();
		smileValues.add(10);
		smileValues.add(2);
		smileValues.add(5);
		smileValues.add(7);
		Moment newMoment = new Moment("newMoment", new Image("newMoment.png"), participants, smileValues);
		assertEquals(p4, p1.getFriendWithWhomIAmHappiest());
	}
	
	// TODO: write more methods to test getOverallHappiestMoment 
	
	// TODO: write methods to test isClique 
	@Test
	public void testIsClique(){
		Person p1 = new Person("person1", new Image("person1.png"));
		Person p2 = new Person("person2", new Image("person2.png"));
		Person p3 = new Person("person3", new Image("person3.png"));
		Person p4 = new Person("person4", new Image("person4.png"));
		p1.addFriend(p2);
		p1.addFriend(p3);
		p1.addFriend(p4);
		p2.addFriend(p1);
		p2.addFriend(p3);
		p3.addFriend(p1);
		p3.addFriend(p2);
		p4.addFriend(p1);
		assertEquals(true,p1.isClique(p1.findMaximumCliqueOfFriends()));
	}
	@Test
	public void testIsClique2(){
		assertEquals(true, User.isClique(_michelleAndBarack));
	}
	@Test
	public void testIsClique3(){
		assertEquals(false, User.isClique(_michelleJoeBoAndMalia));
	}
	@Test
	public void testIsClique4(){
		ArrayList<User> friends = new ArrayList<User>();
		assertEquals(true, User.isClique(friends));
	}
	
	// TODO: write methods to test findMaximumCliqueOfFriends
	@Test
	public void testMaximumCliqueOfFriends2(){
		ArrayList ina = new ArrayList();
		ina.add(_ina);
		assertEquals(ina, _michelle.findMaximumCliqueOfFriends());
	}

	@Test
	public void testFindMaximumCliqueOfFriends(){
		Person pe1 = new Person("person1", new Image("person1.png"));
		Person pe2 = new Person("person2", new Image("person2.png"));
		Person pe3 = new Person("person3", new Image("person3.png"));
		Person pe4 = new Person("person4", new Image("person4.png"));
		pe1.addFriend(pe2);
		pe1.addFriend(pe3);
		pe1.addFriend(pe4);
		pe2.addFriend(pe1);
		pe2.addFriend(pe3);
		pe3.addFriend(pe1);
		pe3.addFriend(pe2);
		pe4.addFriend(pe1);
		
		ArrayList<User> friendsTest = new ArrayList<User>();
		friendsTest.add(pe2);
		friendsTest.add(pe3);
		assertEquals(friendsTest, pe1.findMaximumCliqueOfFriends());
		
		
	}
	

}
