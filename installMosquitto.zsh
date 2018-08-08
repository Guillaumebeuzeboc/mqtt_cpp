sudo apt install -y mosquitto mosquitto-clients
version=$(cmake --version | awk 'NR==1' | awk '{print $3}' | grep -e "..." -o)
sudo cp cfg/FindMosquittopp.cmake /usr/share/cmake-${version}/Modules/
