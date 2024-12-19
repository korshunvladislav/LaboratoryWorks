#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

struct Coordinates {
    double latitude;
    double longitude;
};

class Organization {
public:
    string name;
    Coordinates location;

    Organization(const string& name, const Coordinates location)
        : name(name), location(location) {}

    virtual void displayInfo() const = 0;
};

class Supplier : public Organization {
public:
    vector<string> products;

    Supplier(const string& name, const Coordinates& location, const vector<string>& products)
        : Organization(name, location), products(products) {}

    void displayInfo() const override {
        cout << "Supplier: " << name << "\nProducts: ";
        for (const string& product : products) {
            cout << product << " ";
        }
        cout << endl;
    }
};

class Consumer : public Organization {
public:
    vector<string> consumableProducts;
    string consumptionRate;

    Consumer(const string& name, const Coordinates& location,
             const vector<string>& consumableProducts, const string& consumptionRate)
        : Organization(name, location), consumableProducts(consumableProducts), consumptionRate(consumptionRate) {}

    void displayInfo() const override {
        cout << "Consumer: " << name << "\nConsumable products: ";
        for (const string& product : consumableProducts) {
            cout << product << " ";
        }
        cout << endl << "Consumption rate: " << consumptionRate << endl;
    }
};

class Logistic: public Organization {
public:
    int vehicleCount;

    Logistic(const string& name, const Coordinates& location, int vehicleCount)
        : Organization(name, location), vehicleCount(vehicleCount) {}

    void displayInfo() const override {
        cout << "Logistic: " << name << "\nVehicle count: " << vehicleCount << endl;
    }
};

class AddressDirectory {
private:
    unordered_map<string, unordered_map<string, unordered_map<string, vector<Organization*>>>> data;

public:
    void addAddress(const string& city, const string& street, const string& house, Organization* org) {
        data[city][street][house].push_back(org);
    }

    const auto& getOrganizations(const string& city, const string& street, const string& house) {
        return data[city][street][house];
    }
};

class GeoLocator {
private:
    vector<Organization*> points;

    static double haversineDistance(const Coordinates& a, const Coordinates& b) {
        const double R = 6371.0;

        if (a.latitude < -90.0 || a.latitude > 90.0 || a.longitude < -180.0 || a.longitude > 180.0 ||
            b.latitude < -90.0 || b.latitude > 90.0 || b.longitude < -180.0 || b.longitude > 180.0) {
            throw invalid_argument("Invalid coordinates");
        }

        if (a.latitude == b.latitude && a.longitude == b.longitude) {
            return 0.0;
        }

        double lat1 = a.latitude * M_PI / 180.0;
        double lat2 = b.latitude * M_PI / 180.0;

        double lon1 = a.longitude * M_PI / 180.0;
        double lon2 = b.longitude * M_PI / 180.0;

        double d = 2 * R * asin(sqrt(pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((lon2 - lon1) / 2), 2)));
        return d;
    }

public:
    void addPoint(Organization* org) {
        points.push_back(org);
    }

    Organization* findNearest(const Coordinates& location) {
        double minDistance = numeric_limits<double>::max();
        Organization* nearest = nullptr;

        for (auto* point : points) {
            double distance = haversineDistance(location, point->location);
            if (distance < minDistance) {
                minDistance = distance;
                nearest = point;
            }
        }
        // cout << "Distance: " << minDistance << endl;
        return nearest;
    }
};

int main() {
    AddressDirectory directory;
    GeoLocator geoLocator;

    Supplier supplier1("Unilever Rus", {55.7558, 37.6173}, {"Косметика", "Гигиенические средства", "Бытовая химия"});
    Supplier supplier2("KG Market", {55.7512, 37.6184}, {"Техника Apple", "Смартфоны Xiaomi", "Консоли PlayStation"});
    Supplier supplier3("The Flowers", {55.7602, 37.6226}, {"Цветы", "Растения", "Садовые аксессуары"});

    Consumer consumer1("Шоколадница", {55.7608, 37.6093}, {"Кофе", "Выпечка", "Десерты"}, "Ежедневно");
    Consumer consumer2("Магнит", {55.7517, 37.6286}, {"Продукты питания", "Бытовая химия", "Овощи и фрукты"}, "Еженедельно");
    Consumer consumer3("Эльдорадо", {55.7527, 37.6156}, {"Бытовая техника", "Электроника", "Аксессуары"}, "Ежемесячно");

    Logistic logistic1("СДЭК", {55.7486, 37.6149}, 50);
    Logistic logistic2("Деловые Линии", {55.7542, 37.6096}, 40);
    Logistic logistic3("ПЭК", {55.7550, 37.6200}, 60);

    directory.addAddress("Москва", "Улица Арбат", "10", &supplier1);
    directory.addAddress("Москва", "Тверская улица", "15", &supplier2);
    directory.addAddress("Москва", "Никольская улица", "5", &supplier3);

    directory.addAddress("Москва", "Улица Большая Дмитровка", "20", &consumer1);
    directory.addAddress("Москва", "Улица Петровка", "25", &consumer2);
    directory.addAddress("Москва", "Улица Мясницкая", "30", &consumer3);

    directory.addAddress("Москва", "Садовая улица", "50", &logistic1);
    directory.addAddress("Москва", "Новый Арбат", "55", &logistic2);
    directory.addAddress("Москва", "Кутузовский проспект", "60", &logistic3);

    geoLocator.addPoint(&supplier1);
    geoLocator.addPoint(&supplier2);
    geoLocator.addPoint(&supplier3);

    geoLocator.addPoint(&consumer1);
    geoLocator.addPoint(&consumer2);
    geoLocator.addPoint(&consumer3);

    geoLocator.addPoint(&logistic1);
    geoLocator.addPoint(&logistic2);
    geoLocator.addPoint(&logistic3);

    Coordinates userLocation = {55.7218, 37.8305};
    Organization* nearest = geoLocator.findNearest(userLocation);
    if (nearest) {
        cout << "Nearest Point of Interest:" << endl;
        nearest->displayInfo();
    } else {
        cout << "No Point of Interest Found." << endl;
    }

    return 0;
}