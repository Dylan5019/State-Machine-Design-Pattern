#include <iostream>

class PlayerState;
class PlayerStateContext;
class RunState;
class JumpState;
class IdleState;
class SlideState;
class DashState;


class PlayerState {
public:
	virtual void move(PlayerStateContext *ctx) = 0;
	virtual void moveType() = 0;

  virtual ~PlayerState() {}
};

class RunState : public PlayerState {
public:
	void move(PlayerStateContext *ctx) {
		std::cout << "The Player Is Running\n";
	}
	void moveType() {
		std::cout << "Set to Running\n";
	}
};

class JumpState : public PlayerState {
public:
	void move(PlayerStateContext *ctx) {
		std::cout << "The Player Is Jumping\n";
	}
	void moveType() {
		std::cout << "Set to Jumping\n";
	}
};

class SlideState : public PlayerState {
public:
	void move(PlayerStateContext *ctx) {
		std::cout << "The Player Is Sliding on the Ground\n";
	}
	void moveType() {
		std::cout << "Set to Sliding\n";
	}
};

class DashState : public PlayerState {
public:
	void move(PlayerStateContext *ctx) {
		std::cout << "The Player Dashes Forword\n";
	}
	void moveType() {
		std::cout << "Set to Dashing\n";
	}
};

class IdleState : public PlayerState {
public:
	void move(PlayerStateContext *ctx) {
		std::cout << "The Player Is Doing Nothing\n";
	}
	void moveType() {
		std::cout << "Set to Idle\n";
	}
};

class PlayerStateContext {
private:
	PlayerState *currentState;

public:
	PlayerStateContext(PlayerState *state) {
		currentState = state;
	}

	void setState(PlayerState *state) {
		currentState = state;
	}

	PlayerState *getState() {
		return currentState;
	}

	void move() {
		currentState->move(this);
	}
};



int main() {
    PlayerState* idle = new IdleState;
	PlayerStateContext *stateContext = new PlayerStateContext(idle);
	stateContext->getState()->moveType();
	stateContext->move();

    PlayerState* run = new RunState;
	stateContext->setState(run);
	stateContext->getState()->moveType();
	stateContext->move();

    delete run;
    PlayerState* jump = new JumpState;
    stateContext->setState(jump);
	stateContext->getState()->moveType();
	stateContext->move();

    stateContext->setState(idle);
	stateContext->getState()->moveType();
	stateContext->move();

    delete idle;
    stateContext->setState(jump);
	stateContext->getState()->moveType();
	stateContext->move();

    delete jump;
    PlayerState* slide = new SlideState;
    stateContext->setState(slide);
	stateContext->getState()->moveType();
	stateContext->move();
    delete slide;

    PlayerState* dash = new DashState;
    stateContext->setState(dash);
	stateContext->getState()->moveType();
	stateContext->move();
    delete dash;
 
}
