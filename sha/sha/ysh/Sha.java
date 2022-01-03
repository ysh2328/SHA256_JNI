package ysh;

public class Sha
{
	static
	{
		System.loadLibrary("sha");
	}

	public native String sha256(String input);
}
