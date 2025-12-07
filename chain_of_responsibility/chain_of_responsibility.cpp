#include <iostream>
#include <memory>
#include <string>

class PuzzleHandler {
    
public:

    virtual void setNext(std::shared_ptr<PuzzleHandler> nextHandler) = 0;
    virtual void solvePuzzle(const std::string& puzzle) = 0;

    virtual ~PuzzleHandler() = default;
    
};


class HintHandler : public PuzzleHandler {
    
public:

    void setNext(std::shared_ptr<PuzzleHandler> nextHandler) override
    {
        this->nextHandler = nextHandler;
    }

    void solvePuzzle(const std::string& puzzle) override
    {
        std::cout << "Hint: Try looking for hidden patterns!\n";
        if (nextHandler) {
            nextHandler->solvePuzzle(puzzle);
        }
    }
    
private:

    std::shared_ptr<PuzzleHandler> nextHandler;
    
};

class TrapHandler : public PuzzleHandler {

public:

    void setNext(std::shared_ptr<PuzzleHandler> nextHandler) override
    {
        this->nextHandler = nextHandler;
    }

    void solvePuzzle(const std::string& puzzle) override
    {
        std::cout << "Trap: Watch out for the false leads! They can mislead you.\n";
        if (nextHandler) {
            nextHandler->solvePuzzle(puzzle);
        }
    }
    
private:

    std::shared_ptr<PuzzleHandler> nextHandler;
    
};

class RewardHandler : public PuzzleHandler {

public:

    void setNext(std::shared_ptr<PuzzleHandler> nextHandler) override
    {
        this->nextHandler = nextHandler;
    }

    void solvePuzzle(const std::string& puzzle) override
    {
        std::cout << "Reward: Congratulations! You've solved the puzzle! Here's a treasure.\n";
        if (nextHandler) {
            nextHandler->solvePuzzle(puzzle);
        }
    }

private:

    std::shared_ptr<PuzzleHandler> nextHandler;
    
};

class StoryHandler : public PuzzleHandler {

public:

    void setNext(std::shared_ptr<PuzzleHandler> nextHandler) override
    {
        this->nextHandler = nextHandler;
    }

    void solvePuzzle(const std::string& puzzle) override
    {
        std::cout << "Story: The puzzle is part of the ancient treasure hunt. Solve it to uncover the legend!\n";
        if (nextHandler) {
            nextHandler->solvePuzzle(puzzle);
        }
    }
    
private:

    std::shared_ptr<PuzzleHandler> nextHandler;
    
};

int main() {
    auto hintHandler = std::make_shared<HintHandler>();
    auto trapHandler = std::make_shared<TrapHandler>();
    auto rewardHandler = std::make_shared<RewardHandler>();
    auto storyHandler = std::make_shared<StoryHandler>();

    hintHandler->setNext(trapHandler);
    trapHandler->setNext(rewardHandler);
    rewardHandler->setNext(storyHandler);

    std::cout << "Starting the puzzle-solving process...\n\n";
    hintHandler->solvePuzzle("Ancient Puzzle");

    return 0;
}