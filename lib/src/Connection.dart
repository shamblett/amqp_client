/*
 * Package : xml2json
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 12/09/2013
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Connection class
 */

part of amqp_client;

class Connection {
  
  /**
   * Call a private construction function, native extensions 
   * limitation.
   */
  Connection() {
      
    _newConnection();
    
  }
  
  /**
   * Construction function for the native extension
   */
  void _newConnection() native "Connection::Connection";
  
  /**
   * Opens a connection to a broker.
  *
   * @param host the host on which the broker is running.
  *
   * @param port the port on the which the broker is listening.
  *
   * @param uid the userid to connect with.
  *
   * @param pwd the password to connect with (currently SASL
   * PLAIN is the only authentication method supported so this
   * is sent in clear text).
  *
   * @param virtualhost the AMQP virtual host to use (virtual
   * hosts, where implemented(!), provide namespace partitioning
   * within a single broker).
   */
  bool openHost(String host,
            [int port = 5672,
             String uid = '',
             String pwd = '',
             String virtualhost = '/',
             int maxFrameSize = 65535]
             ) native "Connection::openHost";
  
  /**
   * Opens a connection to a broker using a URL.
   * If the URL contains multiple addresses, try each in turn
   * till connection is successful.
   *
   * @url address of the broker to connect to in 0.10 Connection
   * URL format
   *
   * @param uid the userid to connect with.
   *
   * @param pwd the password to connect with (currently SASL
   * PLAIN is the only authentication method supported so this
   * is sent in clear text).
   *
   * @param virtualhost the AMQP virtual host to use (virtual
   * hosts, where implemented(!), provide namespace partitioning
   * within a single broker).
   */
  bool openUrl(String url,
            [String uid = "",
            String pwd = "",
            String virtualhost = "/", 
            int maxFrameSize=65535]) native "Connection::openUrl";
  
  
  /**
   * Opens a connection to a broker using a URL.
   * If the URL contains multiple addresses, try each in turn
   * till connection is successful.
  *
   * @url address of the broker to connect to.
  *
   * @param settings used for any settings not provided by the URL.
   * Settings provided by the url (excepting host and port) are ignored in
   * the settings.
   */
  bool openUrlSettings(String url, 
                       ConnectionSettings settings)  native "Connection::openUrlSettings";
  
  /**
   * Is the connection open
   */
  bool isOpen()  native "Connection::isOpen";
  
  
  /**
   * Close the connection.
  *
   * Any further use of this connection (without reopening it) will
   * not succeed.
   */
  bool close() native "Connection::close";
  
  /**
   * Return the set of client negotiated settings
   */
  ConnectionSettings getNegotiatedSettings() native "Connection::getNegotiatedSettings";
  
}