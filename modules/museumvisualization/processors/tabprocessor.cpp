#include "tabprocessor.h"

namespace inviwo {

	const ProcessorInfo TabProcessor::processorInfo_{
		"TabProcessor",  // Class identifier
		"Tab Processor", // Display name
		"Image Operation",				 // Category
		CodeState::Experimental,  // Code state
		Tags::GL,                 // Tags
	};

	const ProcessorInfo TabProcessor::getProcessorInfo() const {
		return processorInfo_;
	}

	TabProcessor::TabProcessor()
	{
	}


	TabProcessor::~TabProcessor()
	{
	}

	void TabProcessor::process() {

	}

	void TabProcessor::initializeResources() {

	}
}