package com.egt.chat.server;

import java.util.HashMap;
import java.util.Map;

public class ChatServerUtils {

    private static final Map<String, ChatRoom> chatRooms = new HashMap<>();
    static {

	chatRooms.put("English", new ChatRoom("English"));
	chatRooms.put("Bulgaria", new ChatRoom("Bulgaria"));
    }

    public static Map<String, ChatRoom> getChatRooms() {
	return chatRooms;
    }
}
