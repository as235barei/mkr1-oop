#include <string>
#include <vector>
#include <iostream>

// Структура для представлення вантажу
struct Cargo {
  std::string name; // Назва вантажу
  float weight; // Вага вантажу
  float volume; // Об'єм вантажу

  Cargo(std::string n, float w, float v) : name(n), weight(w), volume(v) {}
};

// Структура для представлення координат
struct Coordinate {
  double latitude; // Широта
  double longitude; // Довгота

  Coordinate(double lat, double lon) : latitude(lat), longitude(lon) {}
};

// Клас "Дирижабль"
class Dirigible {
private:
  std::string name; // Назва дирижабля
  float length; // Довжина дирижабля
  float maxAltitude; // Максимальна висота польоту
  int capacity; // Вантажопідйомність
  std::vector<Cargo> cargo; // Список вантажу на борту
  Coordinate* route; // Маршрут польоту дирижабля
  static float recommendedMaxAltitude; // Рекомендована максимальна висота польоту
  static float climbRate; // Швидкість набору висоти дирижабля
  static int recommendedPassengerCapacity; // Рекомендована місткість пасажирів
  static float recommendedCargoWeight; // Рекомендована загальна вага вантажу

public:
  // Конструктори
  Dirigible() : name("NoName"), length(0.0), maxAltitude(0.0), capacity(0), route(nullptr) {}

  Dirigible(std::string n, float l, float maxA, int cap) : name(n), length(l), maxAltitude(maxA), capacity(cap), route(nullptr) {

  }

  // Конструктор копіювання
  Dirigible(const Dirigible& other) {
    name = other.name;
    length = other.length;
    maxAltitude = other.maxAltitude;
    capacity = other.capacity;
    cargo = other.cargo;
    if (other.route)
      route = new Coordinate(*other.route);
    else
      route = nullptr;
  }

  // Деструктор
  ~Dirigible() {
    delete route;
		cargo.clear();
  }

  // Методи для роботи з атрибутами
  void setName(std::string n) {
    name = n;
  }

  void setLength(float l) {
    length = l;
  }

  void setMaxAltitude(float maxA) {
    maxAltitude = maxA;
  }

  void setCapacity(int cap) {
    capacity = cap;
  }

  void addCargo(const Cargo& newCargo) {
    cargo.push_back(newCargo);
  }

  void setRoute(double latitude, double longitude) {
    // Видалення попереднього маршруту, якщо він існує
    if (route != nullptr) {
      delete route;
    }

    // Створення нового маршруту
    route = new Coordinate(latitude, longitude);
  }

  void printInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Length: " << length << " meters" << std::endl;
    std::cout << "Max Altitude: " << maxAltitude << " meters" << std::endl;
    std::cout << "Capacity: " << capacity << " kg" << std::endl;
    std::cout << "Cargo on board:" << std::endl;
    for (const auto& c : cargo) {
      std::cout << "-> " << c.name << ": " << c.weight << " kg, " << c.volume << " m^3" << std::endl;
    }
    if (route) {
      std::cout << "Route: Latitude " << route->latitude << ", Longitude " << route->longitude << std::endl;
    }
    else {
      std::cout << "Route not set." << std::endl;
    }
  }
};

// Ініціалізація статичних змінних
float Dirigible::recommendedMaxAltitude = 3000.0;
float Dirigible::climbRate = 5.0;
int Dirigible::recommendedPassengerCapacity = 50;
float Dirigible::recommendedCargoWeight = 2000.0;

int main() {
  // Приклад використання класу Dirigible
  Dirigible airship("Airship1", 50.5, 5000.0, 1000); // Створення об'єкту дирижабля
  airship.setName("NewAirship"); // Встановлення назви
  airship.setLength(70.0); // Встановлення довжини
  airship.setMaxAltitude(6000.0); // Встановлення максимальної висоти польоту
  airship.setCapacity(1200); // Встановлення вантажопідйомності

  // Додавання вантажу
  Cargo cargo1("Books", 200.0, 10.0);
  Cargo cargo2("Clothes", 150.0, 15.0);
  airship.addCargo(cargo1);
  airship.addCargo(cargo2);

  // Встановлення маршруту
  airship.setRoute(40.7128, -74.0060); // Нью-Йорк
  airship.setRoute(50.4020, 30.5326); // Київ

  airship.printInfo();

  return 0;
}
