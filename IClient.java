package com.egt.chat.server;

public interface IClient {

    public void putMsgInStream(final String msg);

    public void listenFromConsole() throws Exception;

    public void closeClient();

    public int getID();

}
