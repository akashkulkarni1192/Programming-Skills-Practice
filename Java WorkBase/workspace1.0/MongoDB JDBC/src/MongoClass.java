import java.util.Set;

import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.MongoClient;

public class MongoClass{
   public static void main( String args[] ){
      try{   
		 // To connect to mongodb server
         MongoClient mongoClient = new MongoClient( "localhost" , 27017 );
         // Now connect to your databases
         DB db = mongoClient.getDB( "test" );
		 System.out.println("Connect to database successfully");
        
		 
		 Set<String> colls = db.getCollectionNames();

		 for (String s : colls) {
		     System.out.println(s);
		 }
		 DBCollection coll = db.getCollection("testCollection");
		 
		 BasicDBObject doc = new BasicDBObject("name", "MongoDB")
	        .append("type", "database")
	        .append("count", 1)
	        .append("info", new BasicDBObject("x", 203).append("y", 102));
		 coll.insert(doc);
		 DBCursor cursor = coll.find();
		 try {
		    while(cursor.hasNext()) {
		        System.out.println(cursor.next());
		    }
		 } finally {
		    cursor.close();
		 }
      }catch(Exception e){
	     System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	  }
   }
}