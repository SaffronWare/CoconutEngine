#include "Core.h"



class Sandbox : public Coco::Layer
{
	virtual void Init() override
	{

	}

	virtual void Finish() override
	{

	}

	virtual void Update(double dt) override
	{

	}

	virtual void OnEvent(Coco::Event& event) override
	{

	}
};


int main()
{
	Sandbox* game = new Sandbox();
	Coco::Attach(game);
	Coco::Start("Sandbox");
	Coco::Finish();
	delete game;
}	