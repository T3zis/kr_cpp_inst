#include "3_abonent_info.h"



/* |successor of the AbonentInfo class. Used to maanipulate subscriber data| */
class InterectionWithAbonents {
public:
  void input_abonent_info(std::vector <AbonentInfo> &abonent_info);

  void read_abonents_data(std::vector <AbonentInfo> &abonents, int &counter,
                          std::string &file_location);  

  void save_to_file(std::vector <AbonentInfo> &filtred_list);

  bool check_blocked_filename(const std::string &filename, const std::vector <std::string> &blocked_filenames);
};
