package com.egt.chat.server;

import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.atomic.AtomicInteger;

public class Server {

    private final int port;
    private final String host;
    private final Map<String, ChatRoom> mapRooms = ChatServerUtils.getChatRooms();
    private final AtomicInteger clientID = new AtomicInteger(1);
    private ServerSocket serverSocket;
    private List<IClient> clientsPickingRoom;
    private final String quitCommand = "-quit";

    public Server() {

	final Properties prop = new Properties();

	try (final InputStream inputStream = getClass().getResourceAsStream("/com/egt/chat/server/ChatServerConfig.properties")) {
	    prop.load(inputStream);
	} catch (IOException e) {
	    e.printStackTrace();
	}
	this.port = Integer.parseInt(prop.getProperty("port"));
	this.host = prop.getProperty("host");
	this.clientsPickingRoom = new CopyOnWriteArrayList<>();
    }

    public void start() {

	try {
	    final InetAddress address = InetAddress.getByName(host);
	    serverSocket = new ServerSocket(port, 50, address);
	    System.out.println("Listening on: ..." + serverSocket);

	    while (!Thread.currentThread().isInterrupted()) {

		final Socket newSocket = serverSocket.accept();

		System.out.println("Connection established with: " + newSocket);

		final ClientContainer newClient = new ClientContainer(clientID.get(), newSocket);

		new ClientContainerThread(newClient, this).start();

		clientID.incrementAndGet();
		clientsPickingRoom.add(newClient);
	    }

	} catch (IOException e) {
	    System.out.println("Server stopped!");
	   
	}

    }

    public void stop() {

	try {
	    for (ChatRoom room : mapRooms.values()) {
		System.out.println("closing a room");
		room.closeRoom();
	    }
	    for (IClient client : clientsPickingRoom) {
		System.out.println("closing a client");
		client.closeClient();
	    }

	    if (serverSocket != null && !serverSocket.isClosed()) {
		serverSocket.close();
	    }
	} catch (IOException e) {
	    e.printStackTrace();
	}
    }

    boolean putContainerInRoom(final String selectedRoom, final ClientContainer client) {

	if (selectedRoom.contains(quitCommand)) {
	    client.closeClient();
	    return true;
	}

	final ChatRoom chosenRoom = mapRooms.get(selectedRoom);
	if (chosenRoom != null) {
	    chosenRoom.addClient(client);

	    client.setRoom(chosenRoom);
	    client.putMsgInStream("You joined: " + chosenRoom.toString());

	    chosenRoom.sendToAll("User " + client.getID() + " joined room.", client.getID());

	    clientsPickingRoom.remove(client);

	    return true;
	} else {
	    if (!selectedRoom.isEmpty()) {
		client.putMsgInStream("No such room. Please pick again.");
	    }
	    return false;
	}
    }
}
