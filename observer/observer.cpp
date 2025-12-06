#include <iostream>
#include <vector>
#include <string>

class Observer {
    
public:

    virtual void update(const std::string& message) = 0;
    
    virtual ~Observer() = default;

};

class Subject {
    
public:

    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    
    virtual ~Subject() = default;
    
};

class MovieDatabase : public Subject {
    
public:

    void addMovie(const std::string& movie)
    {
        movies.push_back(movie);
        std::cout << "New Christmas movie added: " << movie << std::endl;
        notifyObservers();
    }
    
    const std::vector<std::string>& getMovies() const
    {
        return movies;
    }
    
    void addObserver(Observer* observer) override
    {
        observers.push_back(observer);
    }
    
    void removeObserver(Observer* observer) override
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    
    void notifyObservers() override
    {
        for(Observer* observer : observers) {
            observer->update("A new Christmas movie has been added!");
        }
    }

private:

    std::vector<Observer*> observers;
    std::vector<std::string> movies;

};

class Viewer : public Observer {
    
public:

    Viewer(const std::string& name) : name(name) {}
    
    void update(const std:: string& message) override
    {
        std::cout << name << " received notification: " << message << std::endl;
    }
    
private:

    std::string name;

};

int main()
{
    MovieDatabase movieDatabase;
    
    Viewer viewer1("Alice");
    Viewer viewer2("Bob");
    Viewer viewer3("Charlie");
    
    movieDatabase.addObserver(&viewer1);
    movieDatabase.addObserver(&viewer2);
    movieDatabase.addObserver(&viewer3);
    
    movieDatabase.addMovie("It's a Wonderful Life");
    movieDatabase.addMovie("The Family Man");
    movieDatabase.addMovie("While You Were Sleeping");
    movieDatabase.addMovie("Serendipity");
    movieDatabase.addMovie("The Holiday");
    movieDatabase.addMovie("Miracle on 34th Street");
    movieDatabase.addMovie("Scrooged");
    movieDatabase.addMovie("I'll Be Home for Christmas");
    
    movieDatabase.removeObserver(&viewer2);
    
    movieDatabase.addMovie("Love Actually");
    return 0;
}