package com.egt.chat.server;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class ChatRoom {

    private final String name;
    private final ConcurrentMap<Integer, IClient> mapClients;

    public ChatRoom(final String name) {
	this.name = name;
	this.mapClients = new ConcurrentHashMap<>();
    }

    public void addClient(final IClient client) {

	mapClients.putIfAbsent(client.getID(), client);
    }

    public void sendToAll(final String message, final Integer clientID) {

	for (IClient container : mapClients.values()) {
	    if (container == null || container.getID() == clientID) {
		continue;
	    }
	    container.putMsgInStream(message);
	}
    }

    void removeClient(final Integer client) {

	if (mapClients.containsKey(client)) {
	    mapClients.get(client).closeClient();
	    mapClients.remove(client);
	    String quitMsg = "User " + client + " has left.";
	    sendToAll(quitMsg, client);
	}
    }

    public void closeRoom() {

	for (IClient client : mapClients.values()) {
	    client.closeClient();
	}
    }

    @Override
    public int hashCode() {
	final int prime = 31;
	int result = 1;
	result = prime * result + ((name == null) ? 0 : name.hashCode());
	return result;
    }

    @Override
    public boolean equals(final Object obj) {
	if (this == obj)
	    return true;
	if (obj == null)
	    return false;
	if (getClass() != obj.getClass())
	    return false;
	final ChatRoom other = (ChatRoom) obj;
	if (name == null) {
	    if (other.name != null)
		return false;
	} else if (!name.equals(other.name))
	    return false;
	return true;
    }

    @Override
    public String toString() {
	return name;
    }
}