#pragma once
#include "../sdk/sdk.hpp"

namespace features {
	namespace prediction {
		void run( const std::function< void( ) >& fn );
	}
}