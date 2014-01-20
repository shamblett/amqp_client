/*
 * Package : xml2json
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 12/09/2013
 * Copyright :  S.Hamblett@OSCF
 */

part of amqp_client;

class Connection {
  
  Connection() {
      
    _newConnection();
    
  }
  
  void _newConnection() native "Connection::Connection";
  
  bool open(String host,
            [int port = 5672,
             String uid = '',
             String pwd = '',
             String virtualhost = '/',
             int maxFrameSize = 65535]
             ) native "Connection::open";
  
  bool isOpen()  native "Connection::isOpen";
  
  bool close() native "Connection::close";
  
}