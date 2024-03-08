#include "5_alg.h"

void Algorithm::filter_by_lct(
    const std::vector <AbonentInfo> &abonents_info,
    std::vector <AbonentInfo> &filtering_by_local_call_time,
    int min_local_call_time)
{  

  for (const auto& abonent : abonents_info)
    if (abonent.get_local_call_time() > min_local_call_time)
      filtering_by_local_call_time.push_back(abonent);
}


void Algorithm::filter_by_ict(
    const std::vector <AbonentInfo> &abonents_info,
    std::vector <AbonentInfo> &filtering_by_intercity_call_time)
{
  for (const auto& abonent : abonents_info)
    if (abonent.get_long_distance_call_time() > 0)
      filtering_by_intercity_call_time.push_back(abonent);
}

void Algorithm::filter_by_alf_order(
    std::vector <AbonentInfo> &abonents_info,
    std::vector <AbonentInfo> &filtering_by_alph_order)    
{
  filtering_by_alph_order = abonents_info;
  std::sort(filtering_by_alph_order.begin(), filtering_by_alph_order.end(),
            [](const AbonentInfo &a, const AbonentInfo &b) {
	      return a.get_surname() < b.get_surname();
            });  
}

void Algorithm::output_filtered_list(
    const std::vector <AbonentInfo> &filtered_list)    
{
  for (const auto &abonents : filtered_list)
    std::cout << "Фамилия: " << abonents.get_surname()
              << ", Имя: " << abonents.get_name()
              << ", Отчество: " << abonents.get_patronymic()
              << ", Адрес: " << abonents.get_address()
              << ", Номер телефона: " << abonents.get_phone_number()
              << ", Время внутригородских звонков: "
              << abonents.get_local_call_time()
              << ", Время междугородних звонков: "
              << abonents.get_long_distance_call_time() << "\n";  
}    
