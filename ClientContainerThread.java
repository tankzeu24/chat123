package com.egt.chat.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



public class ClientContainerThread extends Thread {

    private final ClientContainer client;
    private final Server server;

    public ClientContainerThread(final ClientContainer container, final Server server) {

	this.server = server;
	this.client = container;
    }

    @Override
    public void run() {

	try (final BufferedReader fromClient = new BufferedReader(new InputStreamReader(client.getSocket().getInputStream()));) {
	    final String pickMessage = "Type '-quit' for exit.\nPick a room: 'English' or 'Bulgaria'";
	    client.putMsgInStream(pickMessage);

	    pickRoom(fromClient);

	    client.listenFromConsole();

	    // if this point is reached - the ClientContainer's
	    // listenFromConsole has
	    // returned, which means the client is disconnected from the server
	    System.out.println("User " + client.getID() + " disconnected from server.");
	    client.disconnectFromRoom();

	} catch (IOException e) {

	    System.out.println("Client thread terminated.");
	    e.printStackTrace();
	}
    }

    /**
     * Helper method which blocks and waits for user input in order to pick a
     * room to enter.
     * 
     * @param stream
     * @throws IOException
     */
    private void pickRoom(final BufferedReader stream) throws IOException {
	String message;
	while ((message = stream.readLine()) != null) {
	    if (message != null && server.putContainerInRoom(message, client)) {
		break;
	    }
	}
    }
}
