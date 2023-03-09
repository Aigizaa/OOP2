#include <iostream>

using namespace std;

class City {
protected:
	int area;
	int population_th;

public:
	City() { //конструктор по умолчанию
		cout << "\n1. City()\n";
		area = 100;
		population_th = 100;
	}

	City(int area, int population) { //конструктор с параметрами
		cout << "2. City(int area, int population)\n";
		this->area = area;
		this->population_th = population;
	}

	City(const City& c) { //конструктор копирования
		cout << "3. City(const City& c)\n";
		area = c.area;
		population_th = c.population_th;
	}

	~City() { //деструктор
		cout << "\nDestruction City\n" << "area = " << area << "\t population = " << population_th << endl;
	}

	void growth(int area_plus, int popul_plus) {
		area += area_plus;
		population_th += popul_plus;
		cout << "growth(int area_plus, int popul_plus)\n";
	}

	void print();
};

void City::print() {
	cout << "\narea = " << area << "\t population = " << population_th << endl;
}

class Megalopolis: public City {
protected:
	int metro_station;
public:
	Megalopolis() : City() { //конструктор по умолчанию
		cout << "\n1. Megalopolis()\n";
		metro_station = 10;
	}

	Megalopolis(int area, int population, int metro_st) : City(area, population) { //конструктор с параметрами
		cout << "2. Megalopolis(int area, int population, int metro_st)\n";
		this->metro_station = 10;
	}

	Megalopolis(const Megalopolis& A) { //конструктор копирования
		cout << "3. Megalopolis(const Megalopolis& A)\n";
		area = A.area;
		population_th = A.population_th;
		metro_station = A.metro_station;
	}

	~Megalopolis() { //деструктор
		cout << "\nDestruction Megalopolis" << "\narea = " << area << "\tpopulation = " << population_th << "\tmetro stations = " << metro_station << endl;
	}

	void new_station(int station) { //прибавление к начальному кол-ву станций новое число станций
		cout << "new station +" << station << endl;
		metro_station += station;
	}

	void decrease(int area_min, int population_min, int stations) { //уменьшение характеристик города
		cout << "decrease " << area_min << "\t" << population_min << "\t" << stations << "\n";
		area -= area_min;
		population_th -= population_min;
		metro_station -= stations;
		
	}
	void print() { //вывод характеристик
		cout << "area = " << area << "\tpopulation = " << population_th << "\tmetro stations = " << metro_station << endl;
	}
};

class Country {
protected:
	City* city1;
	City* city2;
public:
	Country() { //конструктор по умолчанию
		cout << "\n1. Country()\n";
		city1 = new City;
		city2 = new City;
	}
	Country(int area1, int population1, int area2, int population2) { //конструктор с параметрами
		cout << "2. Country(int area1, int population1, int area2, int population2)\n";
		city1 = new City(area1, population1);
		city2 = new City(area2, population2);
	}
	Country(const Country& B) { //конструктор копирования
		cout << "3. Country(const Country& B)\n";
		city1 = new City(*(B.city1));
		city2 = new City(*(B.city2));
	}
	~Country() { //деструктор
		delete city1;
		delete city2;
		cout << "\nDestruction Country\n";
	}

};

int main() {
	setlocale(0, "");
	int choice=-1;
	cout << "Сделайте выбор\n";
w:
	cout << "\n1 - статическое создание\n2 - динамическое создание\n3 - демонстрация методов\n4 - наследование\n5 - композиция\n0 - закончить\n";
	cin >> choice;
	switch (choice) {
		case 1: { //статическое создание 
			City a;
			City a2(200, 150);
			City a3(a2);
			goto w;
			break;
		}
		case 2: { //динамоческое создание
			City* a1 = new City();
			City* a2 = new City(150, 200);
			City* a3 = new City(*a2);
			delete a1;
			delete a2;
			delete a3;
			goto w;
			break;
		}
		case 3: { //демонстрация методов
			Megalopolis a1(100, 100, 10);
			a1.print(); //вывод данных
			a1.decrease(10, 10, 1); //уменьшение параметров
			a1.print(); //вывод
			a1.new_station(5); //увеличения кол-ва станций метро
			goto w;
			break;
		}
		case 4: {
			Megalopolis a1(100, 100, 10); //создание класса, который наследует другой
			goto w;
			break;
		}
		case 5: { // создание класса, который содержит в себе другие
			Country* b1 = new Country;
			Country* b2 = new Country(*b1);
			delete b1;
			delete b2;
			goto w;
			break;
		}
	}
}