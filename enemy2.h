
#pragma once
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include<AnimationPlayer.hpp>
#include<Sprite.hpp>
#include<Vector2.hpp>



namespace godot {
	class enemy2 : public KinematicBody2D
	{

		//  Structure Godot
	private:
		GODOT_CLASS(enemy2, KinematicBody2D)


	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
		void _on_Area2D_body_entered(Node* body);


		enemy2();
		~enemy2();
		// Constantes
	public:
		const int speed = 100;
		const int GRAVITY = 30;
		int dir = -1;
		


	private:
		Vector2 velocity;
	};
}
