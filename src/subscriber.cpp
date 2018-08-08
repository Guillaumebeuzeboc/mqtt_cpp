#include <cstring>

#include <mqtt_cpp/subscriber.hpp>

mqttSubscriber::mqttSubscriber(const char *id, const char * topic, const char *host, int port, int max_payload):
  myMqtt(id, topic, host, port),
  max_payload_(max_payload)
{
}

void mqttSubscriber::startSubscribe()
{
  this->subscribe(NULL, topic_);
}

void mqttSubscriber::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    std::cout<< "mqttSubscribe - Message (" << mid << ") succeed to subscribe" <<std::endl;
}

void mqttSubscriber::on_message(const struct mosquitto_message *message)
{
  int payload_size = max_payload_ + 1;
  char buf[payload_size];
  std::cout<< "a message is received" <<std::endl;

  if(!strcmp(message->topic, topic_))
  {
    memset(buf, 0, payload_size * sizeof(char));

    /* Copy N-1 bytes to ensure always 0 terminated. */
    memcpy(buf, message->payload, max_payload_ * sizeof(char));
    std::cout<< "message received: "<< buf <<std::endl;
  }
}

void mqttSubscriber::on_connect(int rc)
{
  if ( rc == 0 ) {
      std::cout<< "myMqtt - connected with server" <<std::endl;
    this->startSubscribe();
  }else{
      std::cout<< "myMqtt - Impossible to connect with server(" << rc << ")" <<std::endl;
  }
}
