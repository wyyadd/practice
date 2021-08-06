package helloworld.wyyadd.talk;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
	Socket ClientSocket; 
	public void open(){
		try {
			ClientSocket = new Socket("localhost", 8088);
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	public void send() {
		try {
			PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(ClientSocket.getOutputStream())),true);
			out.println("world");
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void close() {
		try {
			ClientSocket.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Client foo = new Client();
		foo.open();
		foo.send();
	}
}
