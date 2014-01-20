
import '../lib/amqp_client.dart';

void main() {
  
 Connection myConnection = new Connection();
 
 bool result = myConnection.open("localhost");
 
 print("Open status = $result");
 
 bool open = myConnection.isOpen();
 
 print("isOpen open status = $open");
 
 myConnection.close();
 
 open = myConnection.isOpen();
 
 print("isOpen closed status = $open");
 
}
