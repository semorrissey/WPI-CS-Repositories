import java.util.ArrayList;

public class Moment extends Facebuk {

private ArrayList<Person> momentParticipants;
private ArrayList momentSmileValues;

	public Moment(String name, Image image, ArrayList<Person> participants, ArrayList smileValues){
		_name = name;
		_image = image;
		momentParticipants = participants;
		momentSmileValues = smileValues;
	}

	public ArrayList<Person> getParticipants(){
		return momentParticipants;
	}
	public ArrayList getSmileValues(){
		return momentSmileValues;
		
	} 
}
