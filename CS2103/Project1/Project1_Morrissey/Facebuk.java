
public  abstract class Facebuk  {
	protected String _name;
	protected Image _image;
	public String toString(){
		return _name;
	}
	public boolean equals(Object o){
		if(_name.equals(((Facebuk) o).getName())){
			return true;
		}
		else{
			return false;
		}
	}
	public String getName(){
		return _name;
	}
	
	public Image getImage(){
		return _image;
	}
}
