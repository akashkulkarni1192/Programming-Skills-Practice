package pack;

import java.util.Iterator;
import java.util.Scanner;

import com.mongodb.BasicDBList;
import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;


public class WallClass {
	//BasicDBObject userFound;
	//Scanner scan;
	DB db;
//	public void displayWall(BasicDBObject userFound) {
//		scan=new Scanner(System.in);
//		this.userFound = userFound;
//		System.out.println("Profile Owner : "+userFound.getString("givenName"));
//		System.out.println("-- WALL PAGE --\n1.Add friend\n2.show onlinefriends");
//		int ch = scan.nextInt();
//		switch(ch){
//			case 1:	addFriend();
//					break;
//			case 2:	displayOnlineFriends();
//					break;
//			default:	System.out.println("Invalid choice");
//		}
//		//Prof pic url
//		//Status
//		//Array of Post
//	}
	public BasicDBList displayOnlineFriends(BasicDBObject userFound){
		db = DataBaseConnector.getDatabase();
		DBCollection coll = db.getCollection("userProfile");
		BasicDBObject findQuery = new BasicDBObject("_id",userFound.getString("_id"));
		DBCursor cursor = coll.find(findQuery);
		BasicDBList friendList = (BasicDBList) cursor.next().get("friendList");
		return friendList;
//		Iterator it = friendList.iterator();
//		System.out.println("Online Friends : ");
//		while(it.hasNext()){
//			BasicDBObject friend = (BasicDBObject) it.next();
//			findQuery = new BasicDBObject("_id",friend.getString("userName"));
//			coll = db.getCollection("registeredUser");
//			cursor = coll.find(findQuery);
//			if(cursor.next().get("isOnline").equals("true")){
//				System.out.println("Friend : "+friend.getString("userName"));
//			}
//		}
	}
	public void addFriend(String userID, String friendID){
		if(friendID.equals(""))
			return;
		db = DataBaseConnector.getDatabase();
		DBCollection coll = db.getCollection("userProfile");
		BasicDBObject findQuery = new BasicDBObject("_id",userID);
		DBCursor cur = coll.find(findQuery);
		BasicDBList exitingFriendList = (BasicDBList) cur.next().get("friendList");
		Iterator it = exitingFriendList.iterator();
		while(it.hasNext()){
			BasicDBObject friend = (BasicDBObject) it.next();
			if(friend.get("userName").equals(friendID))
				return;
		}
		//do{
//			System.out.println("Enter friend ID : ");
//			String friendID = scan.next();
			BasicDBObject listItem = new BasicDBObject("friendList" ,new BasicDBObject("userName",friendID)
				.append("likesCount", 0)
				.append("commentCount",0)
				.append("msgCount",0));
			BasicDBObject query = new BasicDBObject("$push",listItem);
			coll.update(findQuery,query );
			//choice = scan.nextInt();
		//}while(choice!=0);
	}

}
