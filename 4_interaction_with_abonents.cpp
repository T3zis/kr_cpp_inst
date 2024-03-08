#include "4_interaction_with_abonents.h"

void InterectionWithAbonents::input_abonent_info(
    std::vector<AbonentInfo> &abonent_info)
{  
  
  InputCheck _input;

  /* |initializing parameters to pass to the constructor| */  
  std::string _name;
  std::string _surname;
  std::string _patronymic;
  std::string _address;
  std::string _phone_number;
  int _local_call_time;
  int _long_distance_call_time;

  /* |filling in user information via the console + verification| */  
  std::cout << "\nВведите фамилию: ";
  std::cin >> _surname;
  std::cout << "Введите имя: ";
  std::cin  >> _name;
  std::cout << "Введите отчество: ";
  std::cin  >> _patronymic;
  std::cout << "Введите адрес: ";
  std::cin  >> _address;
  std::cout << "Введите номер телефона: ";
  std::cin  >> _phone_number;
  std::cout << "Введите время внутригородских звонков: ";
  _local_call_time = _input.get_int();
  while (_local_call_time < 0) {
    std::cout << "Время не может быть отрицательным, повторите попытку.";
    _local_call_time = _input.get_int();
    std::cout << "\n";
  }
  std::cout << "Введите время междугородних звонков: ";
  _long_distance_call_time = _input.get_int();
  while (_long_distance_call_time < 0) {
    std::cout << "Время не может быть отрицательным, повторите попытку.";    
    _long_distance_call_time = _input.get_int();
    std::cout << "\n";
  }

  /* |filling in an instance of the class through the constructor + passing
   * subscriber parameters to the main vector| */
  AbonentInfo info_input(_surname, _name, _patronymic, _address, _phone_number,
                         _local_call_time, _long_distance_call_time);
  abonent_info.push_back(info_input);  
}

/* |used to read subscriber information from a file| */
void InterectionWithAbonents::read_abonents_data(
    std::vector <AbonentInfo> &abonents, int &counter,
    std::string &file_location)    
{
  bool valid_file = false;
    
  while (!valid_file) {

    std::ifstream input_file(file_location);
        
    if (input_file.is_open()) {
      valid_file = true;
      std::string line;
      while (std::getline(input_file, line)) {
	if (line.empty()) continue;
	AbonentInfo abonent;
	std::stringstream str_stream(line);
	std::string temp;

	while (std::getline(str_stream, temp, ',')) {
	  if (temp.find("Фамилия:") != std::string::npos)
	    abonent.set_surname(temp.substr(temp.find(":") + 1));
	  if (temp.find("Имя:") != std::string::npos)
	    abonent.set_name(temp.substr(temp.find(":") + 1));
	  if (temp.find("Отчество:") != std::string::npos)
	    abonent.set_patronymic(temp.substr(temp.find(":") + 1));
	  if (temp.find("Адрес:") != std::string::npos)
	    abonent.set_address(temp.substr(temp.find(":") + 1));        
	  if (temp.find("Номер телефона:") != std::string::npos)
	    abonent.set_phone_number(temp.substr(temp.find(":") + 1));        
	  if (temp.find("Время внутригородских звонков:") != std::string::npos){
	    std::string time_str = temp.substr(temp.find(":") + 1);
	    try {
	      abonent.set_local_call_time(std::stoi(time_str));
	    } catch (const std::invalid_argument&) {
	      std::cout << "Ошибка преобразования времени внутригородских звонков!\n";
	    }
	  }
	  if (temp.find("Время междугородних звонков:") != std::string::npos) {
	    std::string time_str = temp.substr(temp.find(":") + 1);
	    try {
	      abonent.set_long_distance_call_time(std::stoi(time_str));
	    } catch (const std::invalid_argument&) {
	      std::cout << "Ошибка преобразования времени междугородних звонков!";
	    }
	  }      
	}
	abonents.push_back(abonent);
	++counter;
      }
      if (counter >= 1)
	std::cout << "Файл успешно сканирован!\n";
      input_file.close();
    } else {
      std::cerr << "Ошибка! Не удалось открыть файл для чтения.\n";
    }
  }
}

/* |used to compare the file name with the blocked name| */
bool InterectionWithAbonents::check_blocked_filename(
    const std::string &filename,
    const std::vector<std::string> &blocked_filenames)
{  
  for (const std::string &blocked_filename : blocked_filenames)
    if (filename.find(blocked_filename) != std::string::npos)
      return true;  
  return false;
}

/* |used to save filtered files to a file| */
void InterectionWithAbonents::save_to_file(
    std::vector<AbonentInfo> &filtred_list)    
{
  InputCheck _input;
  const int save = 1, not_save = 0;
  int save_to_file = 0;

  std::cout << "\n\nХотите сохранить отфильтрованный список в файл? (0 - Нет, "
    "1 - Да): ";  
  
  save_to_file = _input.get_int();
  while (save_to_file != not_save && save_to_file != save) {
    std::cout << "Сделайте выбор (0 - Не сохранять в файл, 1 - Сохранить в "
      "файл): ";    
    save_to_file = _input.get_int();
  }  

    
  if (save_to_file == 1) {
    std::string file_name;
    std::cout << "Введите путь к файлу для сохранения отфильтрованных данных: ";    
    std::cin >> file_name;
    std::vector<std::string> blocked_filename = {
        "CON.txt",  "PRN.txt",  "AUX.txt",  "NUL.txt",  "COM1.txt", "COM2.txt",
        "COM3.txt", "COM4.txt", "COM5.txt", "COM6.txt", "COM7.txt", "COM8.txt",
        "COM9.txt", "LPT1.txt", "LPT2.txt", "LPT3.txt", "LPT4.txt", "LPT5.txt",
        "LPT6.txt", "LPT7.txt", "LPT8.txt", "LPT9.txt", "con.txt",  "prn.txt",
        "aux.txt",  "nul.txt",  "com1.txt", "com2.txt", "com3.txt", "com4.txt",
        "com5.txt", "com6.txt", "com7.txt", "com8.txt", "com9.txt", "lpt1.txt",
        "lpt2.txt", "lpt3.txt", "lpt4.txt", "lpt5.txt", "lpt6.txt", "lpt7.txt",
        "lpt8.txt", "lpt9.txt"};    


    while (check_blocked_filename(file_name, blocked_filename)) {
      std::cout << "Введите допустимое имя файла для OC Windows 10:";
      std::cin >> file_name;
      std::cout << "\n";      
    }
    
    std::ofstream output_file(file_name);
    if (output_file.is_open()) {
      for (const auto &abonent : filtred_list) {
        output_file << "Фамилия: " << abonent.get_surname()
                    << ", Имя: " << abonent.get_name()
                    << ", Отчество: " << abonent.get_patronymic()
                    << ", Адрес: " << abonent.get_address()
                    << ", Номер телефона: " << abonent.get_phone_number()
                    << ", Время внутригородских звонков: "
                    << abonent.get_local_call_time()
                    << ", Время междугородних звонков: "
                    << abonent.get_long_distance_call_time() << "\n";        
      }
      std::cout << "Данные успешно сохранены в файл: " << file_name << "\n";      
    }
    else
      std::cerr << "Ошибка! Файл нельзя открыть для записи.\n";    
    output_file.close();
  }
  else
    std::cout << "Данные не будут сохранены в файл\n";  
}
