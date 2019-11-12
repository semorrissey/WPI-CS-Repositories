
public class Possession extends Facebuk {
private float possesionPrice;
private Person owner;

	public Possession(String name, Image image, float price){
		_name = name;
		_image = image;
		possesionPrice = price;
		
	}
	
	public void setOwner(Person owner){
		this.owner = owner;
	}
	

	public float getPrice(){
		return possesionPrice;
	}
}
