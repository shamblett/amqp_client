
import '../lib/amqp_client.dart';

void main() {
  
 Connection myConnection = new Connection();
 
 bool result = myConnection.openHost("localhost");
 
 print("Open status = $result");
 
 bool open = myConnection.isOpen();
 
 print("isOpen open status = $open");
 
 myConnection.close();
 
 open = myConnection.isOpen();
 
 result = myConnection.openUrl("qpid:@tcp:localhost");
 
 open = myConnection.isOpen();
 
 print("isOpen url status = $open");
 
  myConnection.close();
 
 open = myConnection.isOpen();
 
 print("isOpen url status = $open");
 
}
