#ifndef IVW_TABPROCESSOR_H
#define IVW_TABPROCESSOR_H

#include <modules/basegl/baseglmoduledefine.h>
#include <inviwo/core/common/inviwo.h>
#include <inviwo/core/processors/canvasprocessor.h>

namespace inviwo {

	class TabProcessor : public CanvasProcessor
	{
	public:
		virtual const ProcessorInfo getProcessorInfo() const override;
		static const ProcessorInfo processorInfo_;

		TabProcessor();
		virtual ~TabProcessor();

		virtual void process() override;
	protected:
		virtual void initializeResources() override;

	private:
		
	};

} // namespace

#endif // IVW_TABPROCESSOR_H