import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;

public class ToLua
{
	private static final String userDir = System.getProperty("user.dir");
	private static final String osName = System.getProperty("os.name");

	public static void main(String[] args)
	{
		File currDir = new File(userDir);
		ArrayList<File> pkgs = new ArrayList<File>();
		
		System.out.println("OS: " + osName);
		System.out.println("Current Dir: " + userDir);		
		
		for (File file : currDir.listFiles())
		{
			if (file.getName().contains(".pkg"))
			{
				pkgs.add(file);
			}
		}
		
		for (File pkg : pkgs)
		{
			String[] cmd = null;
			String pkgName = pkg.getName().replace(".pkg", "");

			if (osName.contains("windows"))
			{
				
			}
			else
			{
				cmd = new String[]{"tolua++5.1", "-o", pkgName + "Wrapper.cpp", "-H", pkgName + "Wrapper.h", "-n", pkgName, pkgName + ".pkg"};
			}
			

			try
			{
				System.out.println("Executing: " + Arrays.toString(cmd));
				Process p = Runtime.getRuntime().exec(cmd);
				Thread.sleep(10);
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}			
			
			File src = new File(pkgName + "Wrapper.cpp");
			File hdr = new File(pkgName + "Wrapper.h");
			src.renameTo(new File("..//" + src.getName()));
			hdr.renameTo(new File("..//" + hdr.getName()));
			src.delete();
			hdr.delete();
		}
	}
}
