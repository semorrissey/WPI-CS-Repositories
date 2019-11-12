import java.util.ArrayList;

public class Person extends User {
private ArrayList<Possession> possessions;
private ArrayList<Pet> pets;

	public Person(String name, Image image){
		super(name, image);
		possessions = new ArrayList<Possession>();
	}
	
	
	
	public ArrayList<User> getFriends(){
		return super.getFriends();
	}
	public void setPets(ArrayList<Pet> pets){
		this.pets = pets;
	}
	public void setPossessions(ArrayList<Possession> possesions){
		this.possessions = possesions;
	}
	
	
	
}
