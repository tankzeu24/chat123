package asd;

import java.util.ArrayList;
import java.util.List;

public class NewVersion {

	// check if service is present in the user PC ,by invkoing the command "service
	// --status-all" and if it fails log the error and try with these
	// new commands : "chkconfig" and "systemctl list-units"
	public static boolean isRunning(String service, IApplicationHandler logger) {

		ArrayList<String> command = new ArrayList<String>();
		command.add("service");
		command.add("--status-all");		
		List<ArrayList<String>> commands = ArrayList<ArrayList<String>>();
		ArrayList<String> serviceCommand = new ArrayList<String>();
		command.add("service");
		command.add("--status-all");
		commands.add(serviceCommand);
		ArrayList<String> chkCommand = new ArrayList<String>();
		chkCommand.add("chkconfig");
		commands.add(chkCommand);
		ArrayList<String> systemctlCommand = new ArrayList<String>();
		systemctlCommand.add("systemctl");
		systemctlCommand.add("list-units");
		commands.add(systemctlCommand);
		try {
			
			for(int i=0;i<commands.size();i++)
				{
					if(isContained(commands.get(i),service,logger))
					{
						return true;
					}
				}

		} catch (IOException e) {
			logger.error("Failed to find services.", e);
		}

	}

	public static boolean isContained(ArrayList<String> command, String searchedString, IApplicationHandler logger)
			throws IOException {

		ShellCommandResult res = ApplicationHandlerUtils.executeShellCommand(true, command);

		if (res.isSuccess()) {
			// log the command response
			logger.info(res.toString());

			if (res.getOutput().contains(searchedString)) {
				return true;
			}

		} else {

			logger.error("Failed to find services. Reason: " + res.toString(), null);
		}
		return false;

	}

}
