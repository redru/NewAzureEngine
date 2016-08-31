#pragma once
#include <iostream>

namespace azr {
	
	class __declspec(dllexport) Engine {

	public:
		// Singleton
		static azr::Engine& getInstance() {
			static Engine instance;
			return instance;
		}

		void saySomething();

	private:
		azr::Engine() {};

	};

}
