/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 12/09/2013
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Connection Settings class
 */

part of amqp_client;

class AmqpcConnectionSettings {

    AmqpcConnectionSettings();

    /**
     * The protocol used for the connection (defaults to 'tcp')
     */
    String _protocol;
    String get protocol => _protocol;
    set protocol(type) => _protocol = type;

    /**
     * The host (or ip address) to connect to.
     */
    String _host = "localhost";
    String get host => _host;
    set host(String name) => _host = name;
    
    /**
     * The port to connect to.
     */
    int _port = 5672;
    int get port => _port;
    set port(int value) => _port = value;
    
    /**
     * Allows an AMQP 'virtual host' to be specified for the
     * connection.
     */
    String _virtualHost;
    String get virtualHost => _virtualHost;
    set virtualHost(String name) => _virtualHost = name;

    /**
     * The username to use when authenticating the connection. If not
     * specified the current users login is used if available.
     */
    String _username;
    String get username => _username;
    set username(String name) => _username = name;
    
    /**
     * The password to use when authenticating the connection.
     */
    String _password;
    String get password => _password;
    set password(String pass) => _password = pass;
    
    /**
     * The SASL mechanism to use when authenticating the connection;
     * the options are currently PLAIN or ANONYMOUS.
     */
    String _mechanism;
    String get mechanism => _mechanism;
    set mechanism(String type) => _mechanism = type;
    
    /**
     * Allows a locale to be specified for the connection.
     */
    String _locale;
    String get locale => _locale;
    set locale(String name) => _locale = name;
    
    /**
     * Allows a heartbeat frequency to be specified
     */
    int _heartbeat;
    int get heartbeat => _heartbeat;
    set heartbeat(int frequency) => _heartbeat = frequency;
    
    /**
     * The maximum number of channels that the client will request for
     * use on this connection.
     */
    int _maxChannels;
    int get maxChannels => _maxChannels;
    set maxChannels(int max) => _maxChannels = max;
    
    /**
     * The maximum frame size that the client will request for this
     * connection.
     */
    int _maxFrameSize;
    int get maxFrameSize => _maxFrameSize;
    set maxFrameSize(int size) => _maxFrameSize = size;
    
    /**
     * Limit the size of the connections send buffer . The buffer
     * is limited to bounds * maxFrameSize.
     */
    int _bounds;
    int get bounds => _bounds;
    set bounds(int bound) => _bounds = bound;
    
    /**
     * If true, TCP_NODELAY will be set for the connection.
     */
    bool _tcpNoDelay;
    bool get tcpNoDelay => _tcpNoDelay;
    set tcpNoDelay(bool allow) => _tcpNoDelay = allow;
    
    /**
     * SASL service name
     */
    String _service;
    String get service => _service;
    set service(String name) => _service = name;
    
    /**
     * Minimum acceptable strength of any SASL negotiated security
     * layer. 0 means no security layer required.
     */
    int _minSsf;
    int get minSsf => _minSsf;
    set minSsf(int strength) => _minSsf = strength;
    
    /**
     * Maximum acceptable strength of any SASL negotiated security
     * layer. 0 means no security layer allowed.
     */
    int _maxSsf;
    int get maxSsf => _maxSsf;
    set maxSsf(int strength) => _maxSsf = strength;
    
    /**
     * SSL cert-name for the connection. Overrides global SSL
     * settings. Used only when a client connects to the broker.
     */
    String _sslCertName;
    String get sslCertName => _sslCertName;
    set sslCertName(String name) => _sslCertName = name;

    /**
     * == operator, must have exact match for equality
     */
    bool operator==(other) {
      
      if (other is! AmqpcConnectionSettings) return false;
      
      if ( protocol != other.protocol ) return false;
      if ( host != other.host ) return false;
      if ( port != other.port ) return false;
      if ( virtualHost != other.virtualHost ) return false;
      if ( username != other.username ) return false;
      if ( password != other.password ) return false;
      if ( mechanism != other.mechanism ) return false;
      if ( locale != other.locale ) return false;
      if ( heartbeat != other.heartbeat ) return false;
      if ( maxChannels != other.maxChannels) return false;
      if ( maxFrameSize != other.maxFrameSize ) return false;
      if ( bounds != other.bounds ) return false;
      if ( tcpNoDelay != other.tcpNoDelay ) return false;
      if ( service != other.service ) return false;
      if ( minSsf != other.minSsf ) return false;
      if ( maxSsf != other.maxSsf ) return false;
      if ( sslCertName != other.sslCertName ) return false;
      
      return true;
      
      
    }
}
