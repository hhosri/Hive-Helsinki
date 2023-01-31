# Minitalk
In this project we got introduced to Unix **Signals**.<br />
![Screenshot](https://github.com/hhosri/Hive-Helsinki/blob/master/Minitalk/screenshot.png) <br />
**For this project the following rules apply:**<br /><br />
-We need to create 2 programs, Server and Client<br />
-When server is run, it will display it's PID<br />
-After running the server we need to run the Client program, with the Server's PID as Arg1 and a message input as a string in Arg2<br />
-The client must be able to send the message input in Arg2 to the server using ONLY SIGUSR1 and SIGUSR2, then the server must print this message on the stdout<br /><br />

-run the **make** rule to generate the programs **Server/Client**<br />
-run the Server with no arguments<br />
-run the Client with the server's PID as a 1st argument and the string to be sent as 2nd argument<br />

