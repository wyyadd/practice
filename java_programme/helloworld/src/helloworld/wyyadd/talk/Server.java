package helloworld.wyyadd.talk;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server implements Runnable{
	ServerSocket server;  
	Socket serverSocket; 
	String talk;
	public void open(){
		try {
			server = new ServerSocket(8088);
			serverSocket = server.accept();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void receive() {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
			talk = in.readLine();
			System.out.println("Server Receive Message:" + talk);
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void send() {
		try {
			PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(serverSocket.getOutputStream())),true);
			out.println(talk);
		}catch(Exception e){
			e.printStackTrace();
		}

	}

	public void close() {
		try {
			server.close();
			serverSocket.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	
	public void run() {
		// TODO Auto-generated method stub
		try {
			while(true) {
				open();
				receive();
				close();
				Thread.sleep(1000);
				open();
				send();
				close();
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Server Start\n");
		Thread foo = new Thread(new Server());
		foo.start();
	}
}
