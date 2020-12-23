/*Task: add an observer CurrentHeatCondition that displays only the heat index
 * hint: heat index= temp*humidity
 * remove observers from listening to subject
 * provide observer count
 * provide getter methods such that observers can get values from subject
 */

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Observer {
   public:
      // pure virtual function providing interface
      virtual void update(float temp, float humidity) = 0;

};

class Subject {
public:
	virtual void registerObserver(Observer *)=0;
	virtual void removeObserver(Observer*)=0;
	virtual void notifyObserver()=0;
};


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

class CurrentHeatConditions: public Observer{
	float temp;
	float humidity;
	string name;
public:
	CurrentHeatConditions(string name)
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
		cout<<"The heat index is "<<temp*humidity<<endl;
	}
};

int main()
{
	WeatherData weatherData;
	CurrentDisplayConditions currentConditions("CurrentConditionclient1");
	CurrentHeatConditions currentHeat("CurrentHeatClient1");
    weatherData.registerObserver(&currentConditions);
    weatherData.registerObserver(&currentHeat);
    cout<<"   Subject Updating Data: "<<endl;
    weatherData.SetMeasurements(80, 35);
    cout<<endl<<"   Subject Updating Data Again: "<<endl;
    weatherData.SetMeasurements(82, 36);
}
*/
