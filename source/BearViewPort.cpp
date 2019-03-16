#include "BearGraphics.hpp"
extern BEARGRAPHICS_API BearRHI::BearRHIFactory*RHIFactoty ;

void BearGraphics::BearViewport::Create(void * win, bsize width, bsize height, bool fullscreen, bool vsync)
{
	BEAR_ASSERT(Empty());
	if(RHIFactoty)
	viewport=RHIFactoty->CreateViewport((void*)win, width, height, fullscreen, vsync);
}

BearGraphics::BearViewport::BearViewport()
{
	viewport = 0;
}


BearGraphics::BearViewport::~BearViewport()
{
	if (viewport)
	RHIFactoty->DestroyViewport(viewport);
}


void BearGraphics::BearViewport::Resize(bsize wigth, bsize height)
{
	if (viewport)
	viewport->Resize(wigth, height);
}

void BearGraphics::BearViewport::SetFullScreen(bool fullscreen)
{
	if (viewport)
	viewport->SetFullScreen(fullscreen);
}

void BearGraphics::BearViewport::SetVsync(bool vsync)
{
	if (viewport)
	viewport->SetVsync(vsync);
}

void BearGraphics::BearViewport::Swap()
{
	if (viewport)
	viewport->Swap();
}

void BearGraphics::BearViewport::ClearColor(const BearCore::BearColor & color)
{
	if (viewport)
	viewport->ClearColor(color);
}

void BearGraphics::BearViewport::ClearDepth(float debpt)
{
	if (viewport)
		viewport->ClearDepth(debpt);
}

void BearGraphics::BearViewport::ClearStencil(uint8 mask)
{
	if (viewport)
		viewport->ClearStencil(mask);
}

bool BearGraphics::BearViewport::Empty() const
{
	return !viewport;
}
