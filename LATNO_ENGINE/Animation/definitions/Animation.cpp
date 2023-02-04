#pragma once

#include "../declarations/Animation.h"

namespace Latno_Animation {
    
    void Animation::AddFrame(Frame frame)
    {
	    frames.push_back(frame);
    }

	void Animation::play()
	{
		for(Frame i : frames)
		{
			i.Render();
			usleep((__int64)FPS * 1000000);
		}
	}
	
    void Animation::reset()
	{
		frames.clear();
    }
}
