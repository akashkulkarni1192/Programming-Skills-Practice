import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

import opennlp.tools.namefind.NameFinderME;
import opennlp.tools.namefind.TokenNameFinderModel;
import opennlp.tools.postag.POSModel;
import opennlp.tools.postag.POSTaggerME;
import opennlp.tools.sentdetect.SentenceDetectorME;
import opennlp.tools.sentdetect.SentenceModel;
import opennlp.tools.tokenize.Tokenizer;
import opennlp.tools.tokenize.TokenizerME;
import opennlp.tools.tokenize.TokenizerModel;
import opennlp.tools.util.Span;

import org.tartarus.snowball.ext.PorterStemmer;

import stemmer.Porter;
public class NLPClass {
	
	public void sentenceDetectorDemo(){
		System.out.println("\n -- Sentence Detector DEMO --");
		
		System.out.println("Input : Is Akash doing good? Hrithik is the champ. But gandhi ji is the baap");
		InputStream modelIn = null;
		try {
			modelIn = new FileInputStream("en-sent.bin");
			SentenceModel model = new SentenceModel(modelIn);
			SentenceDetectorME sentenceDetector = new SentenceDetectorME(model);
			String sentences[] = sentenceDetector.sentDetect(" Is Akash doing good? Hrithik is the champ. But gandhi ji is the baap ");
			for (String s:sentences){
				System.out.println("Sentence : "+s);
			}
		} 
		catch (Exception e) {
		  e.printStackTrace();
		}
	}
	public void tokenizerDemo(){
		System.out.println("\n -- Tokenizing DEMO -- ");
		System.out.println("Input : This is is book");
		try {
			InputStream modelIn = new FileInputStream("en-token.bin");
			TokenizerModel model = new TokenizerModel(modelIn);
			Tokenizer tokenizer = new TokenizerME(model);
			String tokens[] = tokenizer.tokenize("This is is book");
			for(String t:tokens){
				System.out.println("Token : "+t);
			}
			double tokenProbs[] = ((TokenizerME) tokenizer).getTokenProbabilities();
			for(double tP : tokenProbs){
				System.out.println("Token Prob : "+tP);
			}
			Span tokenSpans[] = tokenizer.tokenizePos("This is is book");
			for(Span tS : tokenSpans){
				System.out.println("Span : "+tS);
			}
		}
		catch (IOException e) {
		  e.printStackTrace();
		}
	}

	public void nameEntityFinder(){
		System.out.println("\n -- Name Entity Finding DEMO");
		System.out.println("Input : Taj Mahal is in India");
		try {
			InputStream is = new FileInputStream("en-ner-person.bin");
			TokenNameFinderModel model = new TokenNameFinderModel(is);
			NameFinderME nameFinder = new NameFinderME(model);
		 
			String []sentence = new String[]{
				  "Taj","Mahal","is","in","India"
				    };
		 
				Span nameSpans[] = nameFinder.find(sentence);
		 
				for(Span s: nameSpans)
					System.out.println("Name Entity : "+s.toString());
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		 
		

		try {
			System.out.println("Input : Pierre Vinken is 61 years old");
			InputStream modelIn = new FileInputStream("en-ner-person.bin");
			TokenNameFinderModel model = new TokenNameFinderModel(modelIn);
			NameFinderME nameFinder = new NameFinderME(model);
			String[] sentence = new String[]{
				    "Pierre",
				    "Vinken",
				    "is",
				    "61",
				    "years",
				    "old",
				    "."
				    };

				Span nameSpans[] = nameFinder.find(sentence);
				for(Span s: nameSpans)
					System.out.println("Name Entity : "+s.toString());
		}
		catch (IOException e) {
		  e.printStackTrace();
		}
	}
	public void stemmingDemo(){
		System.out.println("\n -- Stemming DEMO -- ");
		Porter PorterStemmer = new Porter();
		String w ;
		PorterStemmer stemmer = new PorterStemmer();
	
		while((w = new Scanner(System.in).nextLine())!=null){
			//System.out.println(w + " stemmed to "+PorterStemmer.stripAffixes(w) );
			stemmer.setCurrent(w); //set string you need to stem
			stemmer.stem();  //stem the word
			System.out.println("stemmed to " + stemmer.getCurrent());//get the stemmed word
		}
//		System.out.println("Developed stemmed to "+PorterStemmer.stripAffixes("developed") );
//		System.out.println("Spying stemmed to "+PorterStemmer.stripAffixes("spying") );
//		System.out.println("working stemmed to "+PorterStemmer.stripAffixes("working") );
		
	}
	public void POSTaggingDemo(){
		System.out.println("\n -- POS Tagging DEMO -- ");
		System.out.println("Input : India is the greatest country");
		try {
			InputStream modelIn = null;
			modelIn = new FileInputStream("en-pos-maxent.bin");
			POSModel model = new POSModel(modelIn);
			POSTaggerME tagger = new POSTaggerME(model);
			String sent[] = new String[]{"India","is","the","greatest","country"};		  
			String tags[] = tagger.tag(sent);
			System.out.println("Word \t:\tPOSTag");
			for(int i=0;i<tags.length;i++)
				System.out.println(sent[i]+ " \t:\t"+tags[i]);
		}
		catch (IOException e) {
		  // Model loading failed, handle the error
		  e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		System.out.println("\n -- NLP Basic Tasks -- ");
		NLPClass obj = new NLPClass();
		//obj.sentenceDetectorDemo();
		//obj.tokenizerDemo();
		//obj.nameEntityFinder();
		obj.stemmingDemo();
		//obj.POSTaggingDemo();
	}
	
}
