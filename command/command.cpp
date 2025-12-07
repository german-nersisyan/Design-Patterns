#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Command {
    
public:
    
    virtual void execute() = 0;
    virtual void undo() = 0;
    
    virtual ~Command() {}
    
};


class TravelToPastCommand : public Command {

public:

    TravelToPastCommand(int year) : year(year) {}

    void execute() override
    {
        std::cout << "Traveling to the year " << year << "...\n";
    }

    void undo() override
    {
        std::cout << "Restoring timeline, canceling time travel to " << year << ".\n";
    }
    
private:

    int year;

};

class AlterBerlinWallEventCommand : public Command {

public:

    AlterBerlinWallEventCommand(const std::string& action) : action(action) {}

    void execute() override
    {
        std::cout << "Altering the event: " << action << " of the Berlin Wall...\n";
    }

    void undo() override
    {
        std::cout << "Restoring the Berlin Wall's fall to its original date in 1989.\n";
    }
    
private:

    std::string action;

};

class RestoreTimelineCommand : public Command {
    
public:

    void execute() override
    {
        std::cout << "Restoring the timeline to its original state...\n";
    }

    void undo() override
    {
        std::cout << "Unable to undo. The timeline is restored.\n";
    }
    
};

class VisitFutureCommand : public Command {
    
public:

    void execute() override
    {
        std::cout << "Visiting the future to observe the effects of past changes...\n";
    }

    void undo() override
    {
        std::cout << "Returning from the future...\n";
    }
    
};

class TimeMachine {

public:

    void executeCommand(const std::shared_ptr<Command>& command)
    {
        command->execute();
        history.push_back(command);
    }

    void undoLastCommand()
    {
        if (!history.empty()) {
            history.back()->undo();
            history.pop_back();
        } else {
            std::cout << "No commands to undo.\n";
        }
    }
    
private:

    std::vector<std::shared_ptr<Command>> history;
    
};

int main() {
    TimeMachine timeMachine;

    std::shared_ptr<Command> travelToPast = std::make_shared<TravelToPastCommand>(1989);
    std::shared_ptr<Command> alterBerlinWall = std::make_shared<AlterBerlinWallEventCommand>("Preventing the Fall");
    std::shared_ptr<Command> restoreTimeline = std::make_shared<RestoreTimelineCommand>();
    std::shared_ptr<Command> visitFuture = std::make_shared<VisitFutureCommand>();

    timeMachine.executeCommand(travelToPast);
    timeMachine.executeCommand(alterBerlinWall);
    timeMachine.executeCommand(visitFuture);

    timeMachine.undoLastCommand();

    timeMachine.executeCommand(restoreTimeline);

    return 0;
}