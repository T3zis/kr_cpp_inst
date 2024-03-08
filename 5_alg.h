#pragma once
#include "3_abonent_info.h"


class Algorithm {
public:
  void filter_by_lct(const std::vector <AbonentInfo> &abonents_info,
                     std::vector <AbonentInfo> &filtering_by_local_call_time,
                     int min_local_call_time);
  
  void
  filter_by_ict(const std::vector <AbonentInfo> &abonents_info,
                std::vector <AbonentInfo> &filtering_by_intercity_call_time);  

  void filter_by_alf_order(std::vector <AbonentInfo> &abonents_info,
                           std::vector <AbonentInfo> &filtering_by_alph_order);
  
  void output_filtered_list(const std::vector <AbonentInfo> &filtered_list);
};
