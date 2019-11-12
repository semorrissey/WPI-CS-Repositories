import java.util.*;

public class User extends Facebuk {
	//MISSING: TEST CASES FOR getFriendWithWhomIamHappiest, getOverallHappiestMoment, ran out of time to finish!
	
	private ArrayList<User> _userFriends;
	private ArrayList<Moment> _userMoments;

	public User(String name, Image image) {
		_name = name;
		_image = image;
		_userFriends = new ArrayList<User>();
		_userMoments = new ArrayList<Moment>();
	}

	public ArrayList<Moment> getMoments() {
		return _userMoments;
	}

	public void setFriends(ArrayList<User> friends) {
		for (int i = 0; i < friends.size(); i++) {
			_userFriends.add(friends.get(i));
		}
	}

	public void setMoments(ArrayList<Moment> moments) {
		for (int i = 0; i < moments.size(); i++) {
			_userMoments.add(moments.get(i));
		}
	}

	private float handleSmileValues(Moment moment, User friend) {
		for (int i = 0; i < moment.getParticipants().size(); i++) {
			if (moment.getParticipants().get(i).equals(friend)) {
				// fix
				return (float) moment.getSmileValues().get(i);
			}
		}
		return 0;
	}

	private User handleAverage(float[] momentSmileValues) {
		double champion = 0.0;
		int index = 0;
		for (int i = 0; i < momentSmileValues.length; i++) {
			momentSmileValues[i] = momentSmileValues[i] / (float) _userMoments.size();
		}
		for (int j = 0; j < _userFriends.size(); j++) {
			if (momentSmileValues[j] > champion) {
				champion = momentSmileValues[j];
				index = j;
			}

		}

		return _userFriends.get(index);
	}

	public User getFriendWithWhomIAmHappiest() {
		float[] happinessValues = new float[_userFriends.size()];
		for (int f = 0; f < _userFriends.size(); f++) {
			for (int m = 0; m < _userMoments.size(); m++) {
				if (_userMoments.get(m).getParticipants().contains(_userFriends.get(f))) {
					happinessValues[f] += handleSmileValues(_userMoments.get(m), _userFriends.get(f));
				}
			}
		}
		return handleAverage(happinessValues);

	}

	private Moment handleAverageM(float[] momentSmileValues) {
		double champion = 0.0;
		int index = 0;
		for (int i = 0; i < momentSmileValues.length; i++) {
			momentSmileValues[i] = momentSmileValues[i] / (float) _userMoments.size();
		}
		for (int j = 0; j < _userMoments.size(); j++) {
			if (momentSmileValues[j] > champion) {
				champion = momentSmileValues[j];
				index = j;
			}

		}

		return _userMoments.get(index);
	}

	public Moment getOverallHappiestMoment() {
		float[] momentSmileValues = new float[_userMoments.size()];
		if (_userMoments.isEmpty())
			return null;
		else {
			for (int m = 0; m < _userMoments.size(); m++) {
				float momentOfHappiness = 0;
				for (int p = 0; p < _userMoments.get(m).getParticipants().size(); p++) {
					momentOfHappiness += (float) _userMoments.get(m).getSmileValues().get(p);
				}
				momentSmileValues[m] = momentOfHappiness / (float) _userMoments.get(m).getParticipants().size();
			}
			return handleAverageM(momentSmileValues);

		}
	}

	public void addFriend(User friend) {
		_userFriends.add(friend);
	}

	public ArrayList<User> getFriends() {
		return _userFriends;
	}

	   public static ArrayList combination(ArrayList  elements, int K){
	          ArrayList res = new ArrayList();
	              // get the length of the array
	              // e.g. for {'A','B','C','D'} => N = 4
	              int N = elements.size();

	              if(K > N){
	                  System.out.println("Invalid input, K > N");
	                  return new ArrayList();
	              }
	              // calculate the possible combinations
	              // e.g. c(4,2)
	              c(N,K);

	              // get the combination by index
	              // e.g. 01 --> AB , 23 --> CD
	              ArrayList combination = new ArrayList();

	              // position of current index
	              //  if (r = 1)                r*
	              //    index ==>        0    |    1    |    2
	              //    element ==>        A    |    B    |    C
	              int r = 0;
	              int index = 0;

	              while(r >= 0){
	                  // possible indexes for 1st position "r=0" are "0,1,2" --> "A,B,C"
	                  // possible indexes for 2nd position "r=1" are "1,2,3" --> "B,C,D"

	                  // for r = 0 ==> index < (4+ (0 - 2)) = 2
	                  if(index <= (N + (r - K))){
	                          combination.add(r, index);

	                      // if we are at the last position print and increase the index
	                      if(r == K-1){

	                          //do something with the combination e.g. add to list or print
	                          listCreator(combination, elements, K, res);
	                          index++;
	                      }
	                      else{
	                          // select index for next position
	                          index = (int)combination.get(r)+1;
	                          r++;
	                      }
	                  }
	                  else{
	                      r--;
	                      if(r > 0)
	                          index = (int)combination.get(r)+1;
	                      else
	                          index = (int)combination.get(0)+1;
	                  }
	              }
	          return res;
	          }
	        private static int c(int n, int r){
	  int nf=fact(n);
	  int rf=fact(r);
	  int nrf=fact(n-r);
	  int npr=nf/nrf;
	  int ncr=npr/rf;

	  return ncr;
	}

	private static int fact(int n)
	{
	  if(n == 0)
	    return 1;
	  else
	    return n * fact(n-1);
	}
	private static void listCreator(ArrayList combination, ArrayList elements, int i, ArrayList res){

	        ArrayList output = new ArrayList();
	        for(int z = 0 ; z < i;z++){
	            output.add( elements.get((int)combination.get(z)));
	        }
	        res.add(output);
	}

	/*public static boolean isClique(ArrayList<User> set) {
		if (set.isEmpty())
			return true;
		else {
			for (int i = 0; i < set.size(); i++) {
				for (int j = 0; j < set.size(); j++) {

					if (!(i == j) && !set.get(i).getFriends().contains(set.get(j)))
						return false;

				}
			}
			return true;
		}
	}*/
	
	 public static boolean isClique(ArrayList<User> set){
			if(set.isEmpty())
				return true;
			else{
				for(int i=0; i<set.size();i++){
					for(int j=0; j<set.size();j++)
					{
						
							if(!(i==j) && !set.get(i).getFriends().contains(set.get(j)))
								return false;
						
					}				
				}
				return true;
			}
		}

	public void sort(ArrayList<ArrayList<User>> arr) 
    { 
       
        for(int i=0; i<arr.size();i++){
        	ArrayList largestOne = new ArrayList();
        	int index = 0;
        	for(int j=i+1;j<arr.size();j++){
        		if(arr.get(j).size() >= largestOne.size()){
        			index = j;
        			largestOne = arr.get(j);
        		}
        	}
        	if(i < arr.size()-1)
        		arr.add(i, arr.remove(index));
        }
    } 
	
	public ArrayList<User> findMaximumCliqueOfFriends() {
		ArrayList<User> database = this._userFriends;
		ArrayList<ArrayList<User>> a = new ArrayList<ArrayList<User>>();
		for(int i=1;i<database.size();i++)
		              a.addAll(combination(database,i));
		
		
		sort(a);
		System.out.println(a);
		for (int j = 0; j < a.size(); j++) {

			if (User.isClique(a.get(j))) {
				return a.get(j);
			}
		}
		return new ArrayList();
	}

}
