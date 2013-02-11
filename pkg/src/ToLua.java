import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
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
		System.out.println();

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

			if (osName.contains("Windows"))
			{
				cmd = new String[] { "tolua++_d.exe", "-o", pkgName + "Wrapper.cpp", "-H", pkgName + "Wrapper.h", "-n", pkgName, pkgName + ".pkg" };
			}
			else if (osName.contains("Linux"))
			{
				cmd = new String[] { "tolua++5.1", "-o", pkgName + "Wrapper.cpp", "-H", pkgName + "Wrapper.h", "-n", pkgName, pkgName + ".pkg" };
			}

			if (cmd != null)
			{
				try
				{
					System.out.println("Executing: " + Arrays.toString(cmd));
					Process p = Runtime.getRuntime().exec(cmd);

					File prntDir = new File(new File(userDir).getParent());
					Path src = Paths.get(new File(pkgName + "Wrapper.cpp").toURI());
					Path hdr = Paths.get(new File(pkgName + "Wrapper.h").toURI());

					Path srcTarget = Paths.get(new File(prntDir.getAbsolutePath() + File.separator + src.toFile().getName()).toURI());
					Path hdrTarget = Paths.get(new File(prntDir.getAbsolutePath() + File.separator + hdr.toFile().getName()).toURI());

					System.out.println("Moving: " + src.toFile().getAbsolutePath() + " -- " + srcTarget.toFile().getAbsolutePath());
					System.out.println("Moving: " + hdr.toFile().getAbsolutePath() + " -- " + hdrTarget.toFile().getAbsolutePath());
					System.out.println();

					Files.move(src, srcTarget, StandardCopyOption.REPLACE_EXISTING);
					Files.move(hdr, hdrTarget, StandardCopyOption.REPLACE_EXISTING);

					Thread.sleep(10);

					src.toFile().delete();
					hdr.toFile().delete();
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		}
	}
}
