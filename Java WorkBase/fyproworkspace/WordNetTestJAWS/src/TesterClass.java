import edu.smu.tspell.wordnet.SynsetType;
import edu.smu.tspell.wordnet.WordNetDatabase;
import edu.smu.tspell.wordnet.impl.file.Morphology;


public class TesterClass {

	public static void main(String[] args) {
		System.setProperty("wordnet.database.dir", "/home/akash/programmingArena/Weapons/externalJavaLibraries/NLP/WordNet-3.0/dict/");
		WordNetDatabase database = WordNetDatabase.getFileInstance();
 
		Morphology id = Morphology.getInstance();
 
		String[] arr = id.getBaseFormCandidates("implements", SynsetType.VERB);
 
		System.out.println(arr.length);
 
		for(String a: arr)
			System.out.println(a);

	}

}
