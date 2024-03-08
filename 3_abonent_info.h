#pragma once
#include "2_entering_values.h"

class AbonentInfo {
private:
  /* |abonent parameters| */
  std::string surname;
  std::string name;
  std::string patronymic;
  std::string address;
  std::string phone_number;
  int local_call_time;
  int long_distance_call_time;

public:
  /* |getters for a class| */
  std::string get_surname() const { return surname; }
  std::string get_name() const { return name; }
  std::string get_patronymic() const { return patronymic; }
  std::string get_address() const { return address; }
  std::string get_phone_number() const { return phone_number; }
  int get_local_call_time() const { return local_call_time; }
  int get_long_distance_call_time() const { return long_distance_call_time; }

  /* |setters for a class| */
  void set_surname(const std::string &new_surname) { surname = new_surname; }
  void set_name(const std::string &new_name) { name = new_name; }
  void set_patronymic(const std::string &new_patronymic) { patronymic = new_patronymic; }
  void set_address(const std::string &new_address) { address = new_address; }
  void set_phone_number(const std::string &new_phone_number) { phone_number = new_phone_number; }
  void set_local_call_time(int new_local_call_time) { local_call_time = new_local_call_time; }
  void set_long_distance_call_time(int new_long_distance_call_time) {
    long_distance_call_time = new_long_distance_call_time;
  }
  
  
  /* |class constructor| */
  AbonentInfo() = default; 
  AbonentInfo(std::string srn, std::string nm, std::string ptrn,
              std::string adrs, std::string phnm, int lct, int ldct)
      : surname(srn), name(nm), patronymic(ptrn), address(adrs),
        phone_number(phnm), local_call_time(lct),
        long_distance_call_time(ldct) {}

  /* |class destructor| */
  ~AbonentInfo() = default;


};
