#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <mqtt_cpp/publisher.hpp>

int main(int argc, char *argv[])
{
  mqttPublisher myPublisher("mqtt_publisher", "hello",  "localhost", 1883);
  boost::asio::io_service io;
  int count = 0;
  while (1)
  {
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(0.1));
    myPublisher.send_message(std::to_string(count).c_str());
    count++;
    t.wait();
  }
  std::cout<< "Exiting" <<std::endl;
  return 0;
}
