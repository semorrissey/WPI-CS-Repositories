package exam;
//CountingList: Doubly-linked list that additionally stores the
//number of times an element was added. 
public interface CountingList<T> {
	// add: Either adds o to the list (if o was is already in the
	 // list), or increments the counter associated with o by 1 (if o is
	 // already in the list). o cannot be null.
	 void add (T o);
	 // getCount: Returns the value of the counter associated with o. If
	 // o is not in the list, then this method returns 0 (zero).
	 int getCount (T o);
	 // remove: Decrements the counter associated with o by 1. If the
	 // counter reaches 0 (zero), then o is removed from the list;
	 // otherwise, o remains in the list. If o was not contained in the
	 // list, then this method has no effect.
	 void remove (T o);
}
