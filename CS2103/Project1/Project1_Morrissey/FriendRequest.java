
public class FriendRequest {
private User friendOne;
private User friendTwo;
private Boolean friendOneDecision;
private Boolean friendTwoDecision;
	public FriendRequest(User entity1, User entity2){
		friendOne = entity1;
		friendTwo = entity2;
		friendOneDecision = false;
		friendTwoDecision = false;
		
	}
	
	public void approve (User entity){
		if(entity == friendOne || entity == friendTwo){
			if(entity.equals(friendOne)){
				friendOneDecision = true;
			}
			else if (entity.equals(friendTwo)){
				friendTwoDecision = true;
			}
			if(friendOneDecision == true && friendTwoDecision == true){
				friendOne.addFriend(friendTwo);
				friendTwo.addFriend(friendOne);
			}
		}
		else{
			throw new IllegalArgumentException("The given User is not apart of this friend request!");
		}
		
		
	}
	public User getFriendOne(){
		return friendOne;
	}
	public User getFriendTwo(){
		
		return friendTwo;
	}
}
