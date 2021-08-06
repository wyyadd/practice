package helloworld.wyyadd.railway;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Train implements Runnable{
	private int id = 1;
	public synchronized void run() {
		// TODO Auto-generated method stub
		//get name
		char name = Thread.currentThread().getName().charAt(Thread.currentThread().getName().length()-1);
		if(id > 200) {
			System.out.println("售票点" + name + " 售罄");
			return;
		}
		System.out.println("售票点" + name + " 正在售出火车票NO."+id++);
	};
	public static void main(String[] args) throws InterruptedException {
		//set thread_pool size = 10
		ExecutorService thread_pool = Executors.newFixedThreadPool(10);
		Train foo = new Train();
		for(int i = 0; i < 210; ++i) {
			thread_pool.execute(foo);
		}
		thread_pool.shutdown();
		thread_pool.awaitTermination(3, TimeUnit.SECONDS);
	}
		}
