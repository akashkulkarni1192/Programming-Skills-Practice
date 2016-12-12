import edu.smu.tspell.wordnet.Synset;
import edu.smu.tspell.wordnet.WordNetDatabase;


public class MyWordNetTryout {

	public static void main(String[] args) {
		System.setProperty("wordnet.database.dir", "/home/akash/programmingArena/Weapons/externalJavaLibraries/NLP/WordNet-3.0/dict/");
		new MyWordNetTryout().startTryOut();

	}

	private void startTryOut() {
        WordNetDatabase database = WordNetDatabase.getFileInstance();
        Synset[] sets ;
        sets = database.getSynsets("jovial");
        System.out.println("Collected Synsets :"+sets.length);
        for(Synset s:sets)
        	for(String e:s.getWordForms())
        		System.out.println(e);
		
	}

}
