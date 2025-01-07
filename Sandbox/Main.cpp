#include "Core.h"



class Sandbox : public Coco::Layer
{
	Coco::Cube cube;
	Coco::Cube cube2;
	float t;

	virtual void Init() override
	{
		cube.Init();
		cube2.position = glm::vec3(2, 0, 0);
		cube2.Init();
		t = 0;
	}

	virtual void Finish() override
	{

	}

	virtual void Update() override
	{
		t += dt;
		//cube.rotation += glm::float32(dt) * glm::vec3(0.0f, 1.0f, 1.0f);
		Coco::renderer.RenderObject(&cube);
		Coco::renderer.RenderObject(&cube2);
	}

	virtual void OnKeyEvent(Coco::KeyEvent& event) override
	{
		coco_GameCamera.DefaultEventHandling(event, (float)dt);
	}
	virtual void OnWindowEvent(Coco::WindowEvent& event) override
	{
	}
	virtual void OnMouseEvent(Coco::MouseEvent& event) override
	{
		coco_GameCamera.DefaultEventHandling(event, (float)dt);
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