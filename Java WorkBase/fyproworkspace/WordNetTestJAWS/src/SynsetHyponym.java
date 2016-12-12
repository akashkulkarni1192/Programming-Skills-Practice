import java.util.Scanner;

import edu.smu.tspell.wordnet.AdjectiveSynset;
import edu.smu.tspell.wordnet.NounSynset;
import edu.smu.tspell.wordnet.Synset;
import edu.smu.tspell.wordnet.SynsetType;
import edu.smu.tspell.wordnet.WordNetDatabase;

public class SynsetHyponym
 {
    String a[]=new String[2];
    static Scanner scan = new Scanner(System.in);
    public static void main(String a[])
    {
		System.setProperty("wordnet.database.dir", "/home/akash/programmingArena/Weapons/externalJavaLibraries/NLP/WordNet-3.0/dict/");

        int j=0;
        String s="";
        s = scan.nextLine();
        while(s.equals("*")==false)
        {
        
//            System.setProperty("wordnet.database.dir", "C:\\Program Files\\WordNet\\2.1\\dict");
            NounSynset nounSynset;
            AdjectiveSynset adjSynset;
            AdjectiveSynset[] hyponyms;
            WordNetDatabase database = WordNetDatabase.getFileInstance();
            Synset[] synsets = database.getSynsets(s,SynsetType.ADJECTIVE);
            
             System.out.println("*********************************************\nlength="+synsets.length);
            for (int i = 0; i < synsets.length; i++){
//            	System.out.println("-NounSet-");
//            	nounSynset = (NounSynset)(synsets[i]);
//            	hyponyms = nounSynset.getHyponyms();
//            	System.out.println(nounSynset.getWordForms()[0] +": " + nounSynset.getDefinition() + ") has " + hyponyms.length + " hyponyms");
            	
            	System.out.println("-Ajdective Set-");
            	adjSynset = (AdjectiveSynset)(synsets[i]);
            	//hyponyms = ((NounSynset) adjSynset).getHyponyms();
            	System.out.println(adjSynset.getWordForms()[0] +": " + adjSynset.getDefinition() + ")");// has " + hyponyms.length + " hyponyms");
            }
            System.out.print("Enter word : ");
            s = scan.nextLine();
            System.out.println();

        }
         System.out.println("*********************************************");
    }

}