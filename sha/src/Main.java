import ysh.Sha;
public class Main
{
	public static void main(String [] args)
        {
                Sha sha = new Sha();
		System.out.println(sha.sha256("123"));
        }
}
