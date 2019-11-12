package exam;

public class CountingListImpl<T> implements CountingList<T> {
	 private static class Node<T> {
		 Node _next, _prev;
		 T _data;
		 int _counter;
		 }

		 private Node<T> _head, _tail;
		 
		 public static void main(String[] args){
			 CountingListImpl<Integer> list = new CountingListImpl<Integer>();
			list.add(5);
			list.add(6);
			list.add(8);
			list.add(9);
			list.remove(6);
			list.remove(8);
			System.out.println(list.getCount(8));
			
			
			
			
		 }
		 
		 
		 // Implement me ...
		 public CountingListImpl(){
			 _head = _tail = null; 
			
			 
		 }
		 
		@Override
		public void add(T o) {
			if(!o.equals(null)){
				if(_head == null){
					_head = new Node<T>();
					_head._data = o;
					_tail= _head;
					_head._counter = 1;
					
					 
				}
				else{
					Node<T> currentNode = _head;
						while(currentNode != null){
							if(currentNode._data.equals(o)){
								currentNode._counter++;
								break;
							}else{
								currentNode = currentNode._next;
							}
							
						}
						if(currentNode == null){
						currentNode = new Node<T>();
						currentNode._data = o;
						currentNode._counter = 1;
						currentNode._prev = _tail;
						_tail._next = currentNode;
						_tail = currentNode;	
						}
				}
			}
			
		}

		@Override
		public int getCount(T o) {
			Node<T> currentNode = _head;
			while(currentNode != null){
				if(currentNode._data.equals(o)){
					return currentNode._counter;
				}else{
					currentNode = currentNode._next;
				}
				
			}
			return 0;
		}

		@Override
		public void remove(T o) {
			Node<T> currentNode = _head;
			while(currentNode != null){
				if(currentNode._data.equals(o)){
					currentNode._counter--;
					if(currentNode._counter == 0){
						if(currentNode._next != null  && currentNode._prev !=null){
						currentNode._next._prev = currentNode._prev;
						currentNode._prev._next = currentNode._next;
						}
						else if (currentNode.equals(_head)){
							_head = _head._next;
							_head._prev = null;
						}
						else if (currentNode.equals(_tail)){
							_tail = _tail._prev;
							_tail._next = null;
						}
					}
					break;
				}else{
					currentNode = currentNode._next;
				}
				
			}
			
		}
}
