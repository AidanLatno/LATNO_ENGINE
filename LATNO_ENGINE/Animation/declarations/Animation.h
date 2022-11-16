#pragma once

#include "../declarations/Frame.h"
#include <vector>

namespace Latno_Animation
{
	class Animation
	{
		public:
			double FPS = 2;
			std::vector<Frame> frames;

			void AddFrame(Frame frame);
			void play();
			void reset();
	};
};


//********** EXAMPLE FRAME (LOOKS REALLY COOL) **********\\
// P_Anim::Frame A(37,37);

// A.AddCircle({18,18}, 18, ToChar("red"));
// A.AddCircle({18,18}, 17, ToChar("yellow"));
// A.AddCircle({18,18}, 16, ToChar("green"));
// A.AddCircle({18,18}, 15, ToChar("cyan"));
// A.AddCircle({18,18}, 14, ToChar("blue"));
// A.AddCircle({18,18}, 13, ToChar("purple"));
// A.AddCircle({18,18}, 12, ToChar("red"));
// A.AddCircle({18,18}, 11, ToChar("yellow"));
// A.AddCircle({18,18}, 10, ToChar("green"));
// A.AddCircle({18,18}, 9, ToChar("cyan"));
// A.AddCircle({18,18}, 8, ToChar("blue"));
// A.AddCircle({18,18}, 7, ToChar("purple"));
// A.AddCircle({18,18}, 6, ToChar("red"));
// A.AddCircle({18,18}, 5, ToChar("yellow"));
// A.AddCircle({18,18}, 4, ToChar("green"));
// A.AddCircle({18,18}, 3, ToChar("cyan"));
// A.AddCircle({18,18}, 2, ToChar("blue"));
// A.AddCircle({18,18}, 1, ToChar("purple"));

// A.Update();
// A.Render();