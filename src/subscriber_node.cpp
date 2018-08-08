#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <mqtt_cpp/subscriber.hpp>

int main(int argc, char *argv[])
{
  mqttSubscriber mySubscriber("mqtt_subscriber", "hello",  "localhost", 1883, 50);

  boost::asio::io_service io;

  while(1)
  {
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(0.1));

    t.wait();
  }
  mosqpp::lib_cleanup();

  std::cout<< "Exiting" <<std::endl;

  return 0;
}

