import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import opennlp.tools.sentdetect.SentenceDetectorME;
public class OpenNlpTest{
	public static void main(String[] args) {
		
	}
	public static void SentenceDetect() throws IOException {
		String paragraph = "Hi. How are you? This is Mike.";
		
		// always start with a model, a model is learned from training data
		InputStream is = new FileInputStream("en-sent.bin");
		SentenceModel model = new SentenceModel(is);
		SentenceDetectorME sdetector = new SentenceDetectorME(model);
		
		String sentences[] = sdetector.sentDetect(paragraph);
		
		System.out.println(sentences[0]);
		System.out.println(sentences[1]);
		is.close();
	}
}