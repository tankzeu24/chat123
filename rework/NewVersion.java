package asd;

public class NewVersion {

	// check if service is present in the user PC ,by invkoing the command "service
	// --status-all" and if it fails log the error and try with these
	// new commands : "chkconfig" and "systemctl list-units"
	public static boolean isRunning(String service, IApplicationHandler logger) {

		ArrayList<String> command = new ArrayList<String>();
		command.add("service");
		command.add("--status-all");
		try {
			if (isContained(command, service, logger)) {
				return true;
			} else if (isContained(new ArrayList<String>() {
				{
					add("chkconfig");
				}
			}, service, logger)) {
				return true;
			} else if (isContained(new ArrayList<String>() {
				{
					add("systemctl list-units");
				}
			}, service, logger)) {
				return true;
			}

		} catch (IOException e) {
			logger.error("Failed to enumerate Linux daemon services.", e);
		}

	}

	public static isContained(ArrayList<String> command,String searchedString,IApplicationHandler logger) throws IOException
	{
		
		ShellCommandResult res = ApplicationHandlerUtils.executeShellCommand(true, command);

        if (res.isSuccess())
        {
            // log the command response
            logger.info(res.toString());

            if (res.getOutput().contains(searchedString))
            {
                return true;
            }

        }
        else
        {
            
            logger.error("Failed to enumerate Linux daemon services. Reason: " + res.toString(), null);
        }
        return false;
		
		
	}

}
