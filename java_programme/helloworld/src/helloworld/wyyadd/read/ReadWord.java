package helloworld.wyyadd.read;

import java.io.*;

public class ReadWord {
    private File file;

    public void Read() throws IOException {
        file = new File("/home/wyyadd/Desktop/word.txt");
        Array
        BufferedReader bufferedReader = new BufferedReader((new FileReader(file)));
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            System.out.println(line);
        }
    }

    public static void main(String[] args) throws IOException {
        ReadWord readWord = new ReadWord();
        readWord.Read();
    }
}