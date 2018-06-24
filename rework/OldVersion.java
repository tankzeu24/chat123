package asd;

public class OldVersion {

	// check if service is present in the user PC ,by invkoing the command "service
	// --status-all" if it fails log an error.
	public static boolean isRunning(String service, IApplicationHandler logger) {

		ArrayList<String> command = new ArrayList<String>();
		command.add("service");
		command.add("--status-all");
		try {
			ShellCommandResult res = ApplicationHandlerUtils.executeShellCommand(true, command); // accepts
																									// ArrayList<String>
																									// only

			if (res.isSuccess()) {
				// log the command response
				logger.info(res.toString());

				if (res.getOutput().contains(service)) {
					return true;
				}

			} else {

				logger.error("Failed to find services. Reason: " + res.toString(), null);
			}

		} catch (IOException e) {
			logger.error("Failed to find services.", e);
		}

	}
}
