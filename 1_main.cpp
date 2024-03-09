#include "4_interaction_with_abonents.h"
#include "5_alg.h"


#define GREETINGS							       \
  "Щербаков Сегрей Игоревич\nГруппа 4304\nВариант 13\nТекст задания:\nПервая " \
  "контрольная работа предназначена для приобретения\nпрактического опыта в "  \
  "создании простейших классов с\nиспользованием языка программирования С++. " \
  "Необходимо\nразработать класс для указанной предметной области.\nДоступ к " \
  "данным реализовать с помощью методов Set, Get, Show.\nПредусмотреть "       \
  "необходимые проверки исходных данных.\n";

#define FILTER_INFO							       \
  "\nВыберите один из пунктов для фильтрации:\n1) Вывести список абонентов, "  \
  "у которых время внутригородских разоворов превышает заданное\n2) Вывести "  \
  "список абонентов воспользовавшихся междугородней связью\n3) Вывести "       \
  "список абонентов в алфавитном порядке\n4) Перейти в главное меню\n"

#define CHOICE							               \
  "\n\nВыберите один из пунктов:\n1) Провести тесты для программы\n2) "	       \
  "Выбрать свой файл для фильрации\n3) Заполнить файл для фильтрации через "   \
  "консоль\n4) Выйти из программы\n"


/* |self-written ASSERT. If an error occurs, information about it is displayed
 * and the program returns 1| */

#define ASSERT(condition)                                                      \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "\t\t\t\tТЕСТ ПРОВАЛЕН!!!\n\tПричина: " #condition          \
                << " в файле " << __FILE__ << " строка " << __LINE__           \
                << std::endl;                                                  \
      std::exit(1);                                                            \
    }                                                                          \
  } while (0)


void run_test() {
  Algorithm _alg;

  /* |tests for the filter_by_lct method| */
  /* |test 1.1| */
  std::vector <AbonentInfo> abonents_lct = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12)};
  
  std::vector <AbonentInfo> filtered_list_by_lct;
  int min_lct = 10;
    
  _alg.filter_by_lct(abonents_lct, filtered_list_by_lct, min_lct);

  ASSERT(filtered_list_by_lct.size() == 2);

  abonents_lct.clear();
  filtered_list_by_lct.clear();

  /* |test 1.2| */
  abonents_lct = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
      AbonentInfo("Александров", "Александр", "Александров", "2132",
                  "123451111", 100, 111)};  

  min_lct = 7;

  _alg.filter_by_lct(abonents_lct, filtered_list_by_lct, min_lct);

  ASSERT(filtered_list_by_lct.size() == 3);

  abonents_lct.clear();
  filtered_list_by_lct.clear();

  /* |test 1.3| */
  abonents_lct = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
      AbonentInfo("Александров", "Александр", "Александров", "2132",
                  "123451111", 100, 111),
      AbonentInfo("Бексултанов", "Бексултан", "Бексултанов", "2132",
                  "123433543", 12, 1000)};  
  
  min_lct = 30;
    
  _alg.filter_by_lct(abonents_lct, filtered_list_by_lct, min_lct);

  ASSERT(filtered_list_by_lct.size() == 1);

  abonents_lct.clear();
  filtered_list_by_lct.clear();

  
  /* |tests for the filter_by_ict method| */
  /* |test 2.1| */
  std::vector <AbonentInfo> abonents_ict = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12)};
  
  std::vector <AbonentInfo> filtered_list_by_ict;
    
  _alg.filter_by_ict(abonents_ict, filtered_list_by_ict);
    
  ASSERT(filtered_list_by_ict.size() == 2);

  abonents_ict.clear();
  filtered_list_by_ict.clear();

  /* |test 2.2| */
  abonents_ict = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
      AbonentInfo("Александров", "Александр", "Александров", "2132",
                  "123451111", 100, 111)};
      
  _alg.filter_by_ict(abonents_ict, filtered_list_by_ict);
    
  ASSERT(filtered_list_by_ict.size() == 3);

  abonents_ict.clear();
  filtered_list_by_ict.clear();

  /* |test 2.3| */
  abonents_ict = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 0),
      AbonentInfo("Александров", "Александр", "Александров", "2132",
                  "123451111", 100, 0)};  
      
  _alg.filter_by_ict(abonents_ict, filtered_list_by_ict);
    
  ASSERT(filtered_list_by_ict.size() == 1);

  abonents_ict.clear();
  filtered_list_by_ict.clear();


  /* |tests for the filter_by_alf_order method| */
  /* |test 3.1| */
  std::vector <AbonentInfo> abonents_alf_order = {
    AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
    AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
    AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12)
  };
  std::vector <AbonentInfo> filtered_list_by_alf_order;
    
  _alg.filter_by_alf_order(abonents_alf_order, filtered_list_by_alf_order);

  ASSERT(filtered_list_by_alf_order[0].get_surname() == "Иванов" &&
         filtered_list_by_alf_order[1].get_surname() == "Петров");

  abonents_alf_order.clear();
  filtered_list_by_alf_order.clear();

  /* |test 3.2| */
  abonents_alf_order = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
      AbonentInfo("Александров", "Александр", "Александров", "2132",
                  "123451111", 100, 111)};  

  _alg.filter_by_alf_order(abonents_alf_order, filtered_list_by_alf_order);

  ASSERT(filtered_list_by_alf_order[0].get_surname() == "Александров" &&
         filtered_list_by_alf_order[1].get_surname() == "Иванов");  

  abonents_alf_order.clear();
  filtered_list_by_alf_order.clear();

  /* |test 3.3| */
  abonents_alf_order = {
      AbonentInfo("Иванов", "Иван", "Иванович", "123", "123456789", 15, 0),
      AbonentInfo("Петров", "Петр", "Петрович", "321", "987654321", 5, 20),
      AbonentInfo("Романов", "Роман", "Романович", "213", "123421345", 18, 12),
      AbonentInfo("Александров", "Александр", "Александров", "2132",
                  "123451111", 100, 111),
      AbonentInfo("Бексултанов", "Бексултан", "Бексултанович", "2132",
                  "123433543", 12, 1000)};  

  _alg.filter_by_alf_order(abonents_alf_order, filtered_list_by_alf_order);

  ASSERT(filtered_list_by_alf_order[0].get_surname() == "Александров" &&
         filtered_list_by_alf_order[1].get_surname() == "Бексултанов");

  abonents_alf_order.clear();
  filtered_list_by_alf_order.clear();  
}


int main(void)
{
  InputCheck _input;
  EnteringValues _entering;
  AbonentInfo _abonent;
  InterectionWithAbonents _interection;
  Algorithm _alg;
  const int begin_choice = 1, end_choice = 4;
  int choice = 0;

  std::cout << GREETINGS;

  for (;;) {
    /* |main selection menu| */
    std::cout << CHOICE;
    choice = _entering.main_choice();

    while (begin_choice < choice && choice > end_choice) {
      std::cout << "Выберите один из пунктов: ";
      choice = _entering.main_choice();
      std::cout << "\n";
    }
    switch (choice) {
    /* |conducting tests| */
    case 1:
      run_test();
      std::cout << "Тестирование прошло успешно!";
      break;
    /* |filtering subscribers through a file| */
    case 2: {
      std::vector <AbonentInfo> abonents;
      const int begin_choice = 1, end_choice = 4;
      int counter = 0, filter_selection = 0;
      std::string file_location;

      /* |checking the file for correctness| */
      bool valid_file = false;
      while (!valid_file) {
        std::cout << "Введите путь к файлу: ";
        std::cin >> file_location;
        /* |checking the file using good. Is it possible to open it and does it
         * exist| */        
        std::ifstream file_check(file_location);
        if (!file_check.good()) {
	  std::cerr << "Ошибка! Файл не существует или не доступен для чтения.\n";
	  file_check.close();
        } else {
	  /* |checking the file for compliance with the .txt format| */
	  if (file_location.size() < 5 || file_location.substr(file_location.size() - 4) != ".txt"){
	    std::cerr << "Ошибка! Файл должен иметь расширение .txt\n";
          } else {
            /* |checking the file for emptiness. If the beginning of the file is
             * the end, then the file is empty. Carried out through eof| */            
	    file_check.close();
	    file_check.open(file_location);
	    if (file_check.peek() == std::ifstream::traits_type::eof()){
	      std::cerr << "Ошибка! Файл пустой.\n";
            } else {
	      std::string line;
              bool valid_format = true;
	      /* |checking for missing parameter keywords| */              
	      while (std::getline(file_check, line)) {
                if (line.find("Фамилия:") == std::string::npos ||
                    line.find("Имя:") == std::string::npos ||
                    line.find("Отчество:") == std::string::npos ||
                    line.find("Адрес:") == std::string::npos ||
                    line.find("Номер телефона:") == std::string::npos ||
                    line.find("Время внутригородских звонков:") ==
		    std::string::npos ||
                    line.find("Время междугородних звонков:") ==
		    std::string::npos) {
                  
		  valid_format = false;
		  break;
		}

                size_t pos = line.find(":");
		/* |search :| */
		if (pos != std::string::npos) {
                  std::string data = line.substr(pos + 1);
                  /* |checking for data in a string. If the line is empty, then
                   * the format is incorrect| */                  
                  if (data.empty() ||
                      data.find_first_not_of(' ') == std::string::npos) {                    
		    valid_format = false;
		    break;
		  }
		}
	      }
	      if (!valid_format)
		std::cerr << "Ошибка! Формат данных в файле некорректный.\n";
	      else
		valid_file = true;
	    }
	  }
        }
      }
      
      _interection.read_abonents_data(abonents, counter, file_location);

      /* |launching the main program algorithm| */
      for (;;) {
	/* |selecting one of the filtering items| */
	std::cout << FILTER_INFO;
	filter_selection = _input.get_int();

	while (begin_choice < filter_selection && filter_selection > end_choice) {
	  std::cout << "Выберите один из пунктов:";
	  filter_selection = _input.get_int();
	  std::cout << "\n";
	}

        switch (filter_selection) {
	/* |filtering subscribers by local calls| */
        case 1: {
	  std::vector <AbonentInfo> filtering_by_lct;
	  int min_local_call_time = 0;
	  std::cout << "Введите минимальное время для фильтрации абонентов.\n";
	  min_local_call_time = _input.get_int();
	  while (min_local_call_time < 0) {
	    std::cout << "\nВведите положительное число: ";
	    min_local_call_time = _input.get_int();
	    std::cout << "\n";
	  }

	  _alg.filter_by_lct(abonents,filtering_by_lct, min_local_call_time);
	  _alg.output_filtered_list(filtering_by_lct);
    
	  _interection.save_to_file(filtering_by_lct);

	  break;
        }
	/* |filtering subscribers by long-distance calls| */
	case 2: {
	  std::vector <AbonentInfo> filtering_by_ict;

	  _alg.filter_by_ict(abonents, filtering_by_ict);
          
	  _alg.output_filtered_list(filtering_by_ict);
          
	  _interection.save_to_file(filtering_by_ict);

	  break;
        }
	/* |filtering subscribers in alphabetical order| */
	case 3: {
	  std::vector <AbonentInfo> filtering_by_alph_order;
	  _alg.filter_by_alf_order(abonents, filtering_by_alph_order);

	  _alg.output_filtered_list(filtering_by_alph_order);

	  _interection.save_to_file(filtering_by_alph_order);

	  break;
	}
        }
	/*exit the endless loop to the main menu*/
	if (filter_selection == 4) break;
      }
      break;
    }
    /* |filtering subscribers entered through the console| */
    case 3: {
      /* |entering information about subscribers| */
      int num_abonent = 0, filter_selection = 0;
      const int begin_choice = 1, end_choice = 4;
      std::vector <AbonentInfo> abonent_info;

      std::cout << "\nКаково количество абонентов?\n";
      num_abonent = _input.get_int();
      while (num_abonent < 1) {
	std::cout << "Введите количество абонентов >= 1: ";
	num_abonent = _input.get_int();
	std::cout << "\n";
      }
      for (int i = 0; i < num_abonent; i++) {
	std::cout << "\nВведите информацию об абоненте " << i + 1 << ".\n";
	_interection.input_abonent_info(abonent_info);
      }
      /* |launching the main program algorithm| */
      for (;;) {
	std::cout << FILTER_INFO;
	filter_selection = _input.get_int();

	while (begin_choice < filter_selection && filter_selection > end_choice) {
	  std::cout << "Выберите один из пунктов: ";
	  filter_selection = _input.get_int();
	}
        switch (filter_selection) {
	/* |filtering subscribers by local calls| */	          
        case 1: {  
	  std::vector <AbonentInfo> filtering_by_lct;
	  int min_local_call_time = 0;
	  std::cout << "Введите минимальное время для фильтрации абонентов.\n";
	  min_local_call_time = _input.get_int();
	  while (min_local_call_time < 0) {
	    std::cout << "\nВведите положительное число: ";
	    min_local_call_time = _input.get_int();
	  }
          _alg.filter_by_lct(abonent_info, filtering_by_lct,
                             min_local_call_time);
	  _alg.output_filtered_list(filtering_by_lct);

	  _interection.save_to_file(filtering_by_lct);

	  break;
        }
	/* |filtering subscribers by long-distance calls| */          
        case 2: {
	  std::vector <AbonentInfo> filtering_by_ict;

	  _alg.filter_by_ict(abonent_info, filtering_by_ict);
          
	  _alg.output_filtered_list(filtering_by_ict);
          
	  _interection.save_to_file(filtering_by_ict);

	  break;
        }
	/* |filtering subscribers in alphabetical order| */          
	case 3: {
	  std::vector <AbonentInfo> filtering_by_alph_order;
	  _alg.filter_by_alf_order(abonent_info, filtering_by_alph_order);

	  _alg.output_filtered_list(filtering_by_alph_order);

	  _interection.save_to_file(filtering_by_alph_order);

	  break;
        }
// ! db
        }
	/* |exit the endless loop to the main menu| */
	if (filter_selection == 4) break;
      }
      break;
    }
    /* |completion of the program| */
    case 4: exit(0);
    }
  }
}
