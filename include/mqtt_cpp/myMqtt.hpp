#ifndef MY_MQTT_HPP
#define MY_MQTT_HPP

#include <string>
#include <iostream>

#include <mosquittopp.h>

class myMqtt : public mosqpp::mosquittopp
{
public:
  myMqtt(const char *id, const char * topic, const char *host, int port):
    mosquittopp(id),
    id_(id),
    topic_(topic),
    host_(host),
    port_(port),
    keepalive_(60)
  {
    mosqpp::lib_init();
    connect_async(host_, port_, keepalive_);
    // Start Thread, publish, sub etc
    loop_start();
  }

  ~myMqtt(){
    // Kill the thread
    loop_stop();
    // Mosquitto library cleanup
    mosqpp::lib_cleanup();
  }

  void on_connect(int rc){
    if ( rc == 0 ) {
        std::cout<< "myMqtt - connected with server" <<std::endl;
    } else {
        std::cout<< "myMqtt - Impossible to connect with server(" << rc << ")" << std::endl;
    }
  }

  void on_disconnect(int rc){
      std::cout << ">> myMqtt - disconnection(" << rc << ")" <<std::endl;
    this->reconnect();
  }

protected:

  const char* id_;
  const char* topic_;
  const char* host_;
  int port_;
  int keepalive_;

};

#endif //MY_MQTT_HPP
