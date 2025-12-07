#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <algorithm>

class ElevatorState {
    
public:

    virtual void handleRequest() = 0;
    virtual void buttonPressed(int floor) = 0;
    virtual void doorOperation() = 0;
    virtual void moveElevator() = 0;
    virtual bool isIdle() = 0;
    
    virtual ~ElevatorState() = default;
    
};

class IdleState : public ElevatorState {
    
public:

    void handleRequest() override
    {
        std::cout << "Elevator is idle.\n";
    }

    void buttonPressed(int floor) override
    {
        std::cout << "Requesting to go to floor " << floor << "\n";
    }

    void doorOperation() override
    {
        std::cout << "Doors are closed. Ready to move.\n";
    }

    void moveElevator() override
    {
        std::cout << "No movement yet. Elevator is idle.\n";
    }

    bool isIdle() override
    {
        return true;
    }
    
};

class MovingUpState : public ElevatorState {

public:

    MovingUpState(int floor) : currentFloor(floor) {}

    void handleRequest() override
    {
        std::cout << "Elevator is moving up from floor " << currentFloor << ".\n";
    }

    void buttonPressed(int floor) override
    {
        std::cout << "Elevator is moving. Cannot process new requests.\n";
    }

    void doorOperation() override
    {
        std::cout << "Doors are closed while moving up.\n";
    }

    void moveElevator() override
    {
        std::cout << "Elevator is still moving up...\n";
    }

    bool isIdle() override
    {
        return false;
    }
    
private:

    int currentFloor;
    
};

class MovingDownState : public ElevatorState {

public:

    MovingDownState(int floor) : currentFloor(floor) {}

    void handleRequest() override
    {
        std::cout << "Elevator is moving down from floor " << currentFloor << ".\n";
    }

    void buttonPressed(int floor) override
    {
        std::cout << "Elevator is moving. Cannot process new requests.\n";
    }

    void doorOperation() override
    {
        std::cout << "Doors are closed while moving down.\n";
    }

    void moveElevator() override
    {
        std::cout << "Elevator is still moving down...\n";
    }

    bool isIdle() override
    {
        return false;
    }
    
private:

    int currentFloor;
    
};

class DoorsOpenState : public ElevatorState {
    
public:

    void handleRequest() override
    {
        std::cout << "Elevator doors are open.\n";
    }

    void buttonPressed(int floor) override
    {
        std::cout << "Please wait until doors are closed.\n";
    }

    void doorOperation() override
    {
        std::cout << "Closing doors.\n";
    }

    void moveElevator() override
    {
        std::cout << "Cannot move elevator while doors are open.\n";
    }

    bool isIdle() override
    {
        return false;
    }
    
};

class DoorsClosedState : public ElevatorState {
    
public:

    void handleRequest() override
    {
        std::cout << "Elevator doors are closed.\n";
    }

    void buttonPressed(int floor) override 
    {
        std::cout << "Moving to requested floor " << floor << ".\n";
    }

    void doorOperation() override
    {
        std::cout << "Doors are closed and ready to move.\n";
    }

    void moveElevator() override
    {
        std::cout << "Elevator is now moving...\n";
    }

    bool isIdle() override
    {
        return false;
    }
    
};

class Elevator {

public:

    Elevator(int id, int floor) : id(id), currentFloor(floor), currentState(std::make_shared<IdleState>()) {}

    void setState(std::shared_ptr<ElevatorState> state) 
    {
        currentState = state;
    }

    void handleRequest()
    {
        currentState->handleRequest();
    }

    void buttonPressed(int floor)
    {
        currentState->buttonPressed(floor);
    }

    void doorOperation()
    {
        currentState->doorOperation();
    }

    void moveElevator()
    {
        currentState->moveElevator();
    }

    void moveToFloor(int targetFloor) 
    {
        if (targetFloor > currentFloor) {
            setState(std::make_shared<MovingUpState>(currentFloor));
            currentFloor = targetFloor;
        } else if (targetFloor < currentFloor) {
            setState(std::make_shared<MovingDownState>(currentFloor));
            currentFloor = targetFloor;
        } else {
            setState(std::make_shared<DoorsOpenState>());
        }
        moveElevator();
    }

    int getId() const
    {
        return id;
    }

    int getCurrentFloor() const
    {
        return currentFloor;
    }

    void openDoors()
    {
        setState(std::make_shared<DoorsOpenState>());
        doorOperation();
    }

    void closeDoors()
    {
        setState(std::make_shared<DoorsClosedState>());
        doorOperation();
    }

    bool isIdle()
    {
        return currentState->isIdle();
    }
    
private:

    std::shared_ptr<ElevatorState> currentState;
    int currentFloor;
    int id;
    
};

class ElevatorControlSystem {

public:

    ElevatorControlSystem(int numElevators, int floors)
    {
        for (int i = 0; i < numElevators; ++i) {
            elevators.push_back(std::make_shared<Elevator>(i + 1, 1));
        }
    }

    void requestFloor(int floor)
    {
        floorRequests.push(floor);
        std::cout << "Request received for floor " << floor << "\n";
        assignElevatorToFloor();
    }

    void assignElevatorToFloor()
    {
        if (floorRequests.empty()) return;

        int requestedFloor = floorRequests.front();
        floorRequests.pop();

        std::shared_ptr<Elevator> closestElevator = nullptr;
        int minDistance = INT_MAX;

        for (auto& elevator : elevators) {
            if (elevator->isIdle()) {
                int distance = std::abs(elevator->getCurrentFloor() - requestedFloor);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestElevator = elevator;
                }
            }
        }

        if (closestElevator) {
            std::cout << "Assigning Elevator " << closestElevator->getId() << " to floor " << requestedFloor << "\n";
            closestElevator->moveToFloor(requestedFloor);
            closestElevator->openDoors();
            closestElevator->closeDoors();
        }
    }

    void callElevator(int floor)
    {
        std::cout << "Elevator is called to floor " << floor << "\n";
        requestFloor(floor);
    }

    void printElevatorStatus()
    {
        for (auto& elevator : elevators) {
            std::cout << "Elevator " << elevator->getId() << " is at floor " << elevator->getCurrentFloor() << "\n";
        }
    }
    
private:

    std::vector<std::shared_ptr<Elevator>> elevators;
    std::queue<int> floorRequests;
    
};

int main() {
    ElevatorControlSystem system(3, 10);

    system.printElevatorStatus();

    system.callElevator(5);
    system.callElevator(3);
    system.callElevator(8);

    system.printElevatorStatus();

    return 0;
}