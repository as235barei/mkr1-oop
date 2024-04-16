#include <string>
#include <vector>
#include <iostream>

// ��������� ��� ������������� �������
struct Cargo {
  std::string name; // ����� �������
  float weight; // ���� �������
  float volume; // ��'�� �������

  Cargo(std::string n, float w, float v) : name(n), weight(w), volume(v) {}
};

// ��������� ��� ������������� ���������
struct Coordinate {
  double latitude; // ������
  double longitude; // �������

  Coordinate(double lat, double lon) : latitude(lat), longitude(lon) {}
};

// ���� "���������"
class Dirigible {
private:
  std::string name; // ����� ���������
  float length; // ������� ���������
  float maxAltitude; // ����������� ������ �������
  int capacity; // ����������������
  std::vector<Cargo> cargo; // ������ ������� �� �����
  Coordinate* route; // ������� ������� ���������
  static float recommendedMaxAltitude; // ������������� ����������� ������ �������
  static float climbRate; // �������� ������ ������ ���������
  static int recommendedPassengerCapacity; // ������������� ������� ��������
  static float recommendedCargoWeight; // ������������� �������� ���� �������

public:
  // ������������
  Dirigible() : name("NoName"), length(0.0), maxAltitude(0.0), capacity(0), route(nullptr) {}

  Dirigible(std::string n, float l, float maxA, int cap) : name(n), length(l), maxAltitude(maxA), capacity(cap), route(nullptr) {

  }

  // ����������� ���������
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

  // ����������
  ~Dirigible() {
    delete route;
		cargo.clear();
  }

  // ������ ��� ������ � ����������
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
    // ��������� ������������ ��������, ���� �� ����
    if (route != nullptr) {
      delete route;
    }

    // ��������� ������ ��������
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

// ����������� ��������� ������
float Dirigible::recommendedMaxAltitude = 3000.0;
float Dirigible::climbRate = 5.0;
int Dirigible::recommendedPassengerCapacity = 50;
float Dirigible::recommendedCargoWeight = 2000.0;

int main() {
  // ������� ������������ ����� Dirigible
  Dirigible airship("Airship1", 50.5, 5000.0, 1000); // ��������� ��'���� ���������
  airship.setName("NewAirship"); // ������������ �����
  airship.setLength(70.0); // ������������ �������
  airship.setMaxAltitude(6000.0); // ������������ ����������� ������ �������
  airship.setCapacity(1200); // ������������ ����������������

  // ��������� �������
  Cargo cargo1("Books", 200.0, 10.0);
  Cargo cargo2("Clothes", 150.0, 15.0);
  airship.addCargo(cargo1);
  airship.addCargo(cargo2);

  // ������������ ��������
  airship.setRoute(40.7128, -74.0060); // ���-����
  airship.setRoute(50.4020, 30.5326); // ���

  airship.printInfo();

  return 0;
}
