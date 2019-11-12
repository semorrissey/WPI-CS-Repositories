package exam;

public class ArrayList<T> {
	private T[] _data;
	 int _numElements;
	 private static final int INITIAL_SIZE = 128;
	 public static void main(String[] args){
		 ArrayList<String> list = new ArrayList<String>();
		 list.add("X");
		 list.add("B");
		 list.add("M");
		 list.add("A");
		 list.add("B");
		 list.add("X");
		 list.add("D");
		 list.condense();
		 for (int i = 0; i < list.size(); i++) {
		  System.out.println(list.get(i));
		 }
	 }
	 @SuppressWarnings("unchecked")
	public ArrayList(){
		 _data =(T[]) new Object[INITIAL_SIZE];
	 }
	 public int size () {
	 return _numElements;
	 }
	 public T get (int index) {
	 return _data[index];
	 }
	 @SuppressWarnings("unchecked")
	public void add (T o) {
	 if (_numElements == _data.length) {
		 final T[] newArray = (T[]) new Object[_data.length * 2];
		 for (int i = 0; i < _data.length; i++) {
			 newArray[i] = _data[i];
			 }
		 _data = newArray;
	 }
	 _data[_numElements] = o;
	 _numElements++;
	 }
	 public void remove(int index){
		 if (index < 0 || index >= _numElements) {
			 throw new IllegalArgumentException("Invalid index!");
			 }
		 for (int i = index; i < _numElements - 1; i++) {
			 _data[i] = _data[i + 1];
			 }
		 _numElements--;
	 }
	 
	 public void condense () {
	for(int j=0;j<_numElements;j++){
	  T o1 = _data[j];
		 for(int i=j+1; i<_numElements; i++){
		if(o1.equals(_data[i])){
			remove(i);
		}
			
	  }
	}
	 }
}
