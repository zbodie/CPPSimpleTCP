## CPPSimpleTCP
This project contains Visual Studio projects for a client/server application.  The application currently only builds on Windows.  This code is based off of the [MSDN sample winsock code.](https://msdn.microsoft.com/en-us/library/windows/desktop/ms737591%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396)

#### SimpleTCPServer
After building, run the executable generated.  The server will wait for a connection from a client and will print every message sent to it to the command line  
  
Running the application:  
Run SimpleTCPServer.exe from /Debug
  
#### SimpleTCPClient  
Execute this program after the server has been started.  In the command window, enter text and send to the server by pressing "enter."  When you are done, type "quit" in the window and hit enter.  
  
Running the application:  
```SimpleTCPClient.exe <serverip>```  
  
#### SimpleTCPServer_unix  
Port of SimpleTCPServer for unix platforms.  
  
To Build:  
```g++ Server.cpp```  
  
To Run:  
```./a.out ```  
  
#### SimpleTCPServer_unix  
Port of SimpleTCPClient for unix platforms.  
  
To Build:  
```g++ Client.cpp```  
  
To Run:  
```./a.out <serverip>```  
