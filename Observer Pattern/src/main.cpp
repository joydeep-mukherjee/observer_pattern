//this program implements the observer pattern

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//observer interface
class Observer {
   public:
      // pure virtual function providing interface
      virtual void update(float temp, float humidity) = 0;

};

//subject interface
class Subject {
public:
	virtual void registerObserver(Observer *)=0;
	virtual void removeObserver(Observer*)=0;
	virtual void notifyObserver()=0;
};

//concrete subject class WeatherData implements abstract class Subject
class WeatherData: public Subject{
	std::vector<Observer *> observers;
	float temp;
	float humidity;
public:
	void registerObserver(Observer *obsv)
	{
		observers.push_back(obsv);
	}
	void removeObserver(Observer *obsv)
	{
	    auto iterator = std::find(observers.begin(), observers.end(), obsv);

	    if (iterator != observers.end()) { // observer found
	        observers.erase(iterator); // remove the observer
	    }
	}
	void notifyObserver()
	{
		 for (Observer *observer : observers) { // notify all observers
		        observer->update(temp, humidity);
		    }
	}
	void SetMeasurements(float temp, float humidity)
	{
		this->temp=temp;
		this->humidity=humidity;
		notifyObserver();
	}
};

//concrete observer class CurrentDsiplayConditions implements abstract class Observer
class CurrentDisplayConditions: public Observer{
	float temp;
	float humidity;
	string name;
public:
	CurrentDisplayConditions(string name)
	{
		this->name=name;
	}
	void update(float temp, float humidity)
	{
		this->temp=temp;
		this->humidity=humidity;
		display();
	}
	void display()
	{
		cout<<"This is the "<<name<<" observer talking: "<<endl;
		cout<<"The temperature is "<<temp<<" and humidity is "<<humidity<<endl;
	}
};

int main()
{
	WeatherData weatherData;
	CurrentDisplayConditions currentConditions1("currentConditionClient_1");
	cout<<endl<<"          *****Registering first observer*****"<<endl;
    weatherData.registerObserver(&currentConditions1);
    cout<<"   Subject Updating Data: "<<endl;
    weatherData.SetMeasurements(80, 35);
    cout<<endl<<"   Subject Updating Data Again: "<<endl;
    weatherData.SetMeasurements(82, 36);
    CurrentDisplayConditions currentConditions2("currentConditionClient_2");
    cout<<endl<<"          *****Registering second observer*****"<<endl;
    weatherData.registerObserver(&currentConditions2);
    cout<<endl<<"   Subject Updating Data Again: "<<endl;
    weatherData.SetMeasurements(84, 37);
}


