//----------------------------------------------------------------------------------------------------

#ifndef _TIMER_HPP_A652EE97850A38E089D9DB5989C9DB9B
#define _TIMER_HPP_A652EE97850A38E089D9DB5989C9DB9B
//----------------------------------------------------------------------------------------------------

#include "Timer_fwd.hpp"

#include <SDL2/SDL.h>
//----------------------------------------------------------------------------------------------------

namespace MD2View
{
//----------------------------------------------------------------------------------------------------

class Timer
{
public:
	Timer();

	void resume();
	void pause();
	void pauseResume();

	float getTime() const;
	float getDt() const;

	void update();

private:
	Uint32 startTime {0};
	Uint32 currentTime {0};
	Uint32 currentDt {0};

	bool paused {true};
};
//----------------------------------------------------------------------------------------------------

} // namespace MD2View
//----------------------------------------------------------------------------------------------------

#endif // _TIMER_HPP_A652EE97850A38E089D9DB5989C9DB9B
//----------------------------------------------------------------------------------------------------
