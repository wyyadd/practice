package helloworld.wyyadd.talk;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client2 {
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
			BufferedReader in = new BufferedReader(new InputStreamReader(ClientSocket.getInputStream()));
			String talk = in.readLine();
			System.out.println("Client2 Receive Message:" + talk);
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
		Client2 foo = new Client2();
		foo.open();
		foo.send();
	}
}