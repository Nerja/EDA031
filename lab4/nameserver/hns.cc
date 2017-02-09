#include "hns.h"
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

HNS::HNS(size_t size) : data(size) {

}

void HNS::insert(const HostName& name, const IPAddress& ip) {
  size_t index = compute_index(name);
  data[index].push_back(make_pair(name, ip));
}

size_t HNS::compute_index(const HostName& name) const {
  hash<HostName> hash_func;
  size_t index = hash_func(name);
  index = index % data.size();
  return index;
}

bool HNS::remove(const HostName& name) {
  size_t index = compute_index(name);
  auto it = find_if(data[index].begin(), data[index].end(), [name](const pair<HostName, IPAddress>& p){return p.first == name;});
  if(it != data[index].end()) {
    data[index].erase(it);
    return true;
  }
  return false;
}

IPAddress HNS::lookup(const HostName& name) const {
  size_t index = compute_index(name);
  auto it = find_if(data[index].begin(), data[index].end(), [name](const pair<HostName, IPAddress>& p){return p.first == name;});
  return it != data[index].end() ? it->second : NON_EXISTING_ADDRESS;
}
