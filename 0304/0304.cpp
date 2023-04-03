#include <iostream> 
#include <ctime> 
#include <list> 
#include <windows.h> 
using namespace std;




class Food // некий базовый абстрактный тип данных, который сообщает о том, что это продукт питания (но без конкретики)
{
protected:
	string description = "";
public:
	virtual void Print() = 0;
};

// пицца является продуктом питания, вполне пригодным для завтрака
class Pizza : public Food {
public:
	virtual void Print()
	{
		description = "pizza margarita";
		cout << description << "\n";
		system("start https://thumbs.dreamstime.com/b/pizza-rustic-italian-mozzarella-cheese-basil-leaves-35669930.jpg");
	}
};

class Sushi : public Food {
public:
	virtual void Print()
	{
		description = "harakiri set";
		cout << description << "\n";
		system("start https://api.sushishishki.com.ua/uploads/2021_08_14_13_15_17_49a5b8a4a3.jpg");
	}
};

class Person
{
	string name;
	string surname;
	// ...
public:
	void HaveBreakfast(Food* product)
	{
		cout << "have breakfast...\n";
		product->Print();
	}
};

// отдельный тип, который берёт на себя задачи по работе с датами (и возможно временем)

class Date
{

private:
	int year;
	int day;
	int month;

public:
	Date(int day = 0, int month = 0, int year = 0)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void Setyear(int year)
	{
		if (year < 0 || year > 2023)
			cout << "netu" << endl;
		else
			this->year = year;
	}
	void Setday(int day)
	{
		if (day < 1 || day > 31)
			cout << "netu" << endl;
		else
			this->day = day;
	}
	void Setmonth(int month)
	{
		if (month < 1 || month > 12)
			cout << "netu" << endl;
		else
			this->month = month;
	}


	int Getyear() const
	{
		return this->year;
	}
	int Getday() const
	{
		return this->day;
	}
	int Getmonth() const
	{
		return this->month;
	}

};

class Rate
{
private:
	int rate; // 1-12
	Date date;
	string subj;
	string prepod;
	int less;
public:
	Rate(int rate = 1, string prepod = "Alex", string subj = "UML", Date date = Date(), int less = 1)
	{
		this->rate = rate;
		this->date = date;
		this->subj = subj;
		this->prepod = prepod;
		this->less = less;
	}

	void Setrate(int rate)
	{
		if (rate < 1 || rate > 12)
			throw "Incorrect rate!";
		else
			this->rate = rate;
	}
	int Getrate()
	{
		return this->rate;
	}


	void Setdate(Date date)
	{
		this->date = date;
	}
	Date Getdate()
	{
		return this->date;
	}

	void Setsubj(string subj)
	{
		this->subj = subj;
	}
	string Getsubj()
	{
		return this->subj;
	}


	void SetPrepod(string prepod)
	{
		this->prepod = prepod;
	}
	string GetPrepod()
	{
		return this->prepod;
	}


	void SetLesson(int less)
	{
		this->less = less;
	}
	int GetLesson()
	{
		return this->less;
	}




};

class RateCollection
{
	list<Rate> rates;
public:
	int point = 0;
	void AddRate(int rate, Date date, string prepod, string subj, int less)
	{
		if (rate < 0 || rate > 12) throw "Error rate!";
		else if (date.Getday() < 1 || date.Getday() > 31 || date.Getmonth() < 1 || date.Getmonth() > 12 || date.Getyear() < 1 || date.Getyear() > 2023)
		{
			throw "Error date!";
		}
		else if (prepod == "")
		{
			throw "Error prepod!";
		}
		else if (subj == "")
		{
			throw "Error subj!";
		}
		else if (less <= 0)
		{
			throw "Error less!";
		}
		else
		{
			Rate obj = Rate(rate, Date(date.Getday(), date.Getmonth(), date.Getyear()), prepod, subj, less);
			this->rates.push_back(obj);
		}
	}

	void ChangeRate(int num)
	{
		int rate;
		int day;
		int month;
		int year;
		string prepod;
		string subj;
		int less;
		cout << "Vvedite znaxh: " << endl;
		cin >> rate;
		while (rate < 1 || rate > 12)
		{

			cin >> rate;
		}

		cout << "Vvedite day: " << endl;
		cin >> day;
		while (day < 1 || day > 31)
		{

			cin >> day;
		}
		cout << "Vvedite month: " << endl;
		cin >> month;
		while (month < 1 || month > 12)
		{

			cin >> month;
		}
		cout << "Vvedite year: " << endl;
		cin >> year;
		while (year < 1 || year > 2023)
		{

			cin >> year;
		}
		cout << "Vvedite prepod: " << endl;
		while (prepod == "")
		{

			cin >> prepod;
		}
		cout << "Vvedite subj: " << endl;
		while (subj == "")
		{

			cin >> subj;
		}
		cout << "Vvedite less: " << endl;
		cin >> less;
		while (less < 0)
		{

			cin >> less;
		}
		Rate obj = Rate(rate, Date(day, month, year), prepod, subj, less);
		int counter = 0;
		for (Rate znach1 : rates)
		{
			Rate znach2 = znach1;
			cout << znach2.GetPrepod() << endl;
			if (counter == num)
			{
				rates.remove(znach1);
				rates.push_back(obj);
				break;
			}
			num++;
		}
	}


	void RemoveRate(int index)
	{

		for (Rate znach1 : rates)
		{
			Rate znach2 = znach1;
			if (point == index)
			{
				rates.remove(znach2);
			}
		}
	}



};


class Group
{
	string special;
	string grname;
	int kurs;
public:
	Group(string special = "Design", string grname = "KN-D-211", int kurs = 2)
	{
		this->special = special;
		this->grname = grname;
		this->kurs = kurs;
	}
};

class Adress
{
	string country;
	string region;
	string city;
	string street;
	int house_number;
	int flat_number;
	int postal_index;
public:
	Adress(string country = "Ukraine",
		string region = "Odesska obl",
		string city = "Odesa",
		string street = "Tramvaina",
		int house_number = 1,
		int flat_number = 1,
		int postal_index = 65016,
		string email = "miramavs@gmail.com",
		string university = "IT Step"
	)


	{
		this->country = country;
		this->region = region;
		this->city = city;
		this->street = street;
		this->house_number = house_number;
		this->flat_number = flat_number;
		this->postal_index = postal_index;
		//this->email = email;

	}
};


class Student
{
	string name;
	string lastname;
	string fathername;
	Date* birthday;
	// нарушение ВЫСОКОГО СЦЕПЛЕНИЯ:
	// студент берёт на себя задачи, которые решать не должен!!!
	// вместо этих трёх полей ЛУЧШЕ...
	//int birth_day = 15; // 1-31
	//int birth_month = 10; // 1-12
	//int birth_year = 1998;


	// ЭТИ ПОЛЯ убираем вообще, они студенту не нужны!!!
	//string eyes_color;
	//string hair_color;
	//double growth;
	//double weight;

	// int homeworks[100]; // со статическим массивом есть очень много проблем:
	// 1) память расходуется сразу, при том что изначально оценок нет вообще
	// 2) добавить 101-ый элемент в массив нельзя
	// 3) даже если сделать динамический массив, то возникает вопрос: почему тип данных Студент должен брать на себя ответственность за ВЫДЕЛЕНИЕ ПАМЯТИ под массив, ПЕРЕВЫДЕЛЕНЕИЕ, проверку диапазонов баллов от 1 до 12

	RateCollection homeworks; // гораздо лучше предусмотреть отдельный тип данных для работы с коллекцией оценок (там будут методы ДОБАВЛЕНИЯ, РЕДАКТИРОВАНИЯ, УДАЛЕНИЯ, просмотра)
	RateCollection practices; // сама по себе оценка - это тоже отдельный тип данных со своими деталями
	RateCollection kursachies;
	RateCollection exams;

	/*		*/
	double average_rate; // средний балл
	string group_name = "kn-d-211";
	int kurs = 2;
	string speciality = "design";
	string country = "Ukraine";
	string region = "Odesska";
	string city = "Odesa";
	string street = "Tramvaina";
	int house_number = 1;
	int flat_number = 1;
	int postal_index = 65016;
	int start_day = 1;
	int start_month = 9;
	int start_year = 2023;
	string university = "IT Step";
	string email = "miramavs@gmail.com";
	string phone_numbers[3] = { "+380980321134", "+380980321134" };
	string avatar = "https://www.google.com/url?sa=i&url=https%3A%2F%2Fnaturerussia.travel%2Fredbook%2Fanimals%2F14917%2F&psig=AOvVaw2jxwha--nuo2Svxn4B-3Kp&ust=1680641063362000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCIjVtIrKjv4CFQAAAAAdAAAAABA5";

	Student(string name, string lastname, string fathername, Date birthday, RateCollection homeworks, RateCollection practices, RateCollection kursachies, RateCollection exams,
		double average_rate, Date timeOfLearning)
	{
		this->name = name;
		this->lastname = lastname;
		this->fathername = fathername;
		this->exams = exams;
		this->homeworks = homeworks;
		this->practices = practices;
		this->kursachies = kursachies;


	}


};

class Cat
{
	int lapki = 4;
};

int main()
{
	setlocale(0, ""); // для кириллицы
	srand(time(0)); // для генерации случайных чисел

	Person alex;
	//Pizza pizza;
	//pizza.Print();
	//Sushi sushi;
	//sushi.Print();
	Rate obj = Rate(Date(3, 5, 11), "NAME", "NAME", 2);
	Date secObj = obj.Getdate();
	/*
	// rand() >>> целое случайное число в диапазоне 0...32767
	if (rand() % 2 == 0) // возможные результаты при делении по модулю - или 0, или 1
		alex.HaveBreakfast(new Pizza);
	else // если выпало 1
		alex.HaveBreakfast(new Sushi);

*/
//alex.HaveBreakfast(new Cat);
}