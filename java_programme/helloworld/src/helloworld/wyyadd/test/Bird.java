package helloworld.wyyadd.test;

public class Bird {
	public String name = "Bird";

	public void show() {
		Fly();
	}

	protected void Fly() {
		System.out.println("The super class" + name + "fly");
	}
	public void Tweet() {
		System.out.println("Jiu~ Jiu");
	}

}
