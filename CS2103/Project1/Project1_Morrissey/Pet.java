import java.util.ArrayList;

public class Pet extends User {
private Person owner;


	public Pet(String name, Image image){
		super(name,image);
		
		
	}
	

	public void setFriends(ArrayList<User> friends){
		super.setFriends(friends);
	}
	public ArrayList<User> getFriends(){
		return super.getFriends();
	}

	public void setOwner(Person owner){
		this.owner = owner;
	}
	
}
