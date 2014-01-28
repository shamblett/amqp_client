/*
 * Package : amqp_client
 * Author : S. Hamblett <steve.hamblett@linux.com>
 * Date   : 27/01/2014
 * Copyright :  S.Hamblett@OSCF
 * 
 * Qpid Local Queue class
 */

part of amqp_client;

class AmqpcLocalQueue {
  
  /**
   * Indicates dequeue operations should wait for the queue
   * to become ready.
   */
  static const INFINITE_WAIT = -1;
  
  /** Create a local queue. Subscribe the local queue to a remote broker
   * queue with a SubscriptionManager.
   *
   * LocalQueue is an alternative to implementing a MessageListener
   * which are not used in this implementation
   */
  AmqpcLocalQueue() {
    
    _newLocalQueue();
  }
  
  _newLocalQueue() native "LocalQueue::LocalQueue";
  
  /** Get the next message off the local queue, or wait up to the timeout
   * for message from the broker queue.
   * @param timeout wait up this timeout for a message to appear,
   * units are nanoseconds.
   * @return message from the queue.
   */
  AmqpcMessage get([int timeout = INFINITE_WAIT]) native "LocalQueue::localQueueGet";
  
  /** 
   * Synonym for get() 
   */
  AmqpcMessage pop([int timeout = INFINITE_WAIT]) native "LocalQueue::localQueuePop";

  /** 
   * Return true if the local queue is empty. 
   */
  bool empty() native "LocalQueue::localQueueEmpty";

  /** 
   * Number of messages on the local queue 
   */
  int size() native "LocalQueue::localQueueSize";
  
}