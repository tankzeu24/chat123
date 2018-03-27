package com.egt.chat.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientContainer implements IClient {

    private final int ID;
    private final Socket socket;
    private ChatRoom room;

    private final String quitCommand = "-quit";

    public ClientContainer(final int id, final Socket socket) {
	this.ID = id;
	this.socket = socket;
    }

    public void putMsgInStream(final String msg) {

	try {
	    final PrintWriter stream = new PrintWriter(socket.getOutputStream(), true);

	    stream.println(msg);

	} catch (IOException e) {
	    System.out.println("User disconnected.");
	}
    }

    public void listenFromConsole() throws IOException {

	if (!socket.isClosed()) {
	    final BufferedReader fromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));

	    String message;
	    while ((message = fromClient.readLine()) != null) {
		if (message.contains(quitCommand)) {
		    room.removeClient(ID);
		    break;
		}
		if (message.isEmpty()) {
		    continue;
		}
		final String messageToSend = getID() + " wrote: " + message;
		room.sendToAll(messageToSend, ID);
	    }
	}
    }

    public void disconnectFromRoom() {
	if (room != null) {
	    room.removeClient(ID);
	}
    }

    public void closeClient() {
	try {
	    if (socket != null && !socket.isClosed()) {
		socket.shutdownInput();
		socket.shutdownOutput();
		socket.close();
	    }
	} catch (IOException e) {
	    e.printStackTrace();
	}
    }

    public int getID() {
	return ID;
    }

    public Socket getSocket() {
	return socket;
    }

    /**
     * used by the client, because the thread waits for client input in order to
     * pick a room. If room was final, the server would block for user input
     * indefinitely.
     * 
     * @param room
     */
    public void setRoom(final ChatRoom room) {
	this.room = room;
    }

    @Override
    public int hashCode() {
	final int prime = 31;
	int result = 1;
	result = prime * result + ID;
	return result;
    }

    @Override
    public boolean equals(Object obj) {
	if (this == obj)
	    return true;
	if (obj == null)
	    return false;
	if (getClass() != obj.getClass())
	    return false;
	ClientContainer other = (ClientContainer) obj;
	if (ID != other.ID)
	    return false;
	return true;
    }
}