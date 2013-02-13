import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
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

	public static synchronized void main(String[] args)
	{
		ToLua tl = new ToLua();
		tl.run();
	}

	public ToLua()
	{
	}

	public void run()
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

					int exitValue = p.waitFor();
					if (exitValue != 0)
					{
						StringBuilder sb = new StringBuilder();
						BufferedReader esbr = new BufferedReader(new InputStreamReader(p.getErrorStream()));
						String errorLine = esbr.readLine();
						while (errorLine != null)
						{
							sb.append(errorLine);
							errorLine = esbr.readLine();
						}
						System.out.println(sb.toString());
					}

					File parentDirectory = new File(new File(userDir).getParent());
					Path sourceFile = Paths.get(new File(pkgName + "Wrapper.cpp").toURI());
					Path headerFile = Paths.get(new File(pkgName + "Wrapper.h").toURI());

					Path sourceTarget = Paths.get(new File(parentDirectory.getAbsolutePath() + File.separator + sourceFile.toFile().getName()).toURI());
					Path headerTarget = Paths.get(new File(parentDirectory.getAbsolutePath() + File.separator + headerFile.toFile().getName()).toURI());

					System.out.println("Moving: " + sourceFile.toFile().getAbsolutePath() + " -- " + sourceTarget.toFile().getAbsolutePath());
					System.out.println("Moving: " + headerFile.toFile().getAbsolutePath() + " -- " + headerTarget.toFile().getAbsolutePath());
					System.out.println();

					Files.move(sourceFile, sourceTarget, StandardCopyOption.REPLACE_EXISTING);
					Files.move(headerFile, headerTarget, StandardCopyOption.REPLACE_EXISTING);

					sourceFile.toFile().delete();
					headerFile.toFile().delete();
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		}
	}
}
